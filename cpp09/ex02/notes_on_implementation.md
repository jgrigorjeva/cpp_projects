# The general approach
1. take an array of numbers
2. load them into the container of choice, each element of the container should be a pair or a tuple (to store the value and the index/reference)
   1. maybe we could even have a tuple with three values: the value itself, the original index, the value representing which pair the element belongs to
3. make pairs: either split the array into two halves or take the pairs of neighbouring elements
4. sort elements in each pair, the bigger elements go to the left (to the main chain)
5. add a note to each element (the second part of a pair/tuple) to save an info of what is the second element in the pair
6. take the elements from the main chain (just their values) and recursively sort them
7. the output of the sort should be an array of indexes
8. use the resulting array of indexes to sort both chains (such that the pairs have the same position within their chain)
9.  maybe update the indexes to reflect the current positions within the chain
10. calculate the Jacobsthal numbers
11. start inserting the elements from the secondary chain to the main chain
12. get the sorted container
13. return the order of original indexes
14. the calling function sorts the original array based on the order of the original indexes

## Containers of choice
deque and vector

## Number of comparisons
record them using a global variable