#!/bin/bash

BINARY="./PmergeMe"
VALGRIND="valgrind --leak-check=full --error-exitcode=1"

run_test() {
    local description="$1"
    local args="$2"
    echo "Testing: $description"
    $VALGRIND $BINARY $args 2>&1
    if [ $? -eq 0 ]; then
        echo "PASS: $description"
    else
        echo "FAIL: $description"
    fi
    echo "---"
}

# Hello world: basic sort
run_test "basic sort" "3 1 4 1 5 9 2 6"

# Edge cases
run_test "single element" "42"
run_test "two elements" "2 1"
run_test "already sorted" "1 2 3 4 5"
run_test "reverse sorted" "5 4 3 2 1"
run_test "large input" "$(seq 100 -1 1 | tr '\n' ' ')"