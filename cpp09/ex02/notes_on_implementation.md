# The general approach
1. take an array of numbers
2. load them into the container of choice, each element of the container should be a pair or a tuple (to store the value and the index/reference)
   1. maybe we could even have a tuple with three values: the value itself, the original index, the value representing which pair the element belongs to
   2. or other people do pairs in which the larger value is first in the pair, smaller is the second. I suppose that when the larger elements are sorted, the container sorts the pairs and the insertion can be then done in the same container, just the second element in a the new pair will be some dummy value (-1)
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
? do we even need to record it?

## The inserting part
Once I have my Jacobstahl (filled) sequence calculated, it basically tells me which element to insert next. I have my a_i and b_i stored in pairs in the container, so when looking up an element a index i, I can just find the container[i]. Since there will be some elements added before element container[i] and it basically becomes i+1, I can reflect each insertion by changing the Jacobstahl sequence. So if an element is added before position i, i becomes i+1 and all the indexes J >= i should become J+1.