---
bibliography: references.bib
csl: apa.csl
---

<!-- bash:
pandoc Readme.md --citeproc --csl=apa.csl -s -t gfm -o README.md -->

# Merge insertion sort

*a method discovered by Lester Ford, Jr. and Selmer Johnson* \## 1.
Binary insertion sort:

When inserting a number ($`b`$) into an already sorted list ($`a_1`$,
$`a_2`$, $`a_3`$, … $`a_i`$), we can go the primitive way: compare $`b`$
with $`a_1`$, if $`b`$ \> $`a_1`$, compare it with $`a_1`$, if $`b`$ \>
$`a_1`$, compare it with $`a_1`$, etc. Or we can **reduce the number of
comparisons** by finding an element in the middle of the $`a`$ list,
comparing $`b`$ with $`a_{middle}`$, if $`b < a_{middle}`$, find an
element in the middle of the left sublist (first-quarter) and compare
$`b`$ with $`a_{first quarter}`$. If $`b > a_{middle}`$, compare $`b`$
with $`a_{last-quarter}`$. Continue this way by shortening the interval,
until there is only one element left to compare with. This binary
approach reduces the complexity for comparisons from $`O(n^2)`$
(worst-case scenario) to $`O(log_2 n)`$ (worst-case scenario in the
primitive approach).

Let’s illustrate the number of comparisons needed to perform the binary
insertion sort:

insert $`b`$ into:

$`(a_1)`$ → 1 comparison

$`(a_1, a_2)`$ → max 2 comparisons

$`(a_1, a_2, a_3)`$ → 2 comparisons

$`(a_1, a_2, a_3, a_4)`$ → max 3 comparisons

$`(a_1, a_2, a_3, a_4, a_5)`$ → max 3 comparisons

**The binary insertion cost depends only on the size of the search
interval**

Binary search on:

1 element → 1 comparison

2–3 elements → 2 comparisons

4–7 elements → 3 comparisons

8–15 elements → 4 comparisons

etc.

**Notice the pattern:**

$`cost=⌈log⁡_2(n+1)⌉`$

**The cost increases only when we cross powers of two.**

$`cost = k`$ when $`n+1 = 2^k`$, i.e. $`n = 2^k - 1`$

where $`n`$ is the number of elements in the search interval. This will
be an important point when we start inserting elements in the
merge-insertion.

## 2. Sorting by merging

The original algorithm assumes combining two sorted files/arrays into
one sorted array. For example (from (Knuth, 1998))

## References

<div id="refs" class="references csl-bib-body hanging-indent"
entry-spacing="0" line-spacing="2">

<div id="ref-Knuth1998" class="csl-entry">

Knuth, D. Ervin. (1998). *The art of computer programming. Volume 3,
sorting and searching* (Vol. 3, p. 158). Addison-Wesley.

</div>

</div>
