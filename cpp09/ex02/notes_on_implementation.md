# The general approach
1. take an array of numbers (vector or deque)
2. load them into the container of choice, each element of the container should be a pair
   1. Each pair contains the integer value (key) and an indice (its index in the array)
3. make pairs (of pairs): I took neighbouring values. Each pair looks like `((key1, indice1), (key2, indice2))`. If there is an odd number of elements, the last element becomes `((-1,-1), (last_key, last_indice))`
4. sort elements in each pair, the bigger elements become the first pair in each pair of pairs (to the main chain). Each pair looks like `((larger_key, larger_indice), (smaler_key, smaller_indice))`.
5. take the elements from the main chain (just their values) and recursively sort them
6. the output of the sort should be an array of indices
7. use the resulting array of indices to sort the pairs of pairs. Now we have `((larger_key1, larger_indice1), (smaler_key1, smaller_indice1)), ... ((larger_key_n, larger_indice_n), (smaler_key_n, smaller_indice_n))`, with `larger_key1 < larger_key2 < ... < larger_key_n`
8.  calculate the Jacobsthal numbers (only a certain number of them). Calculate the filling numbers to the sequence, the largest number in the sequence is equal to the number of pairs to be sorted. Let's call the result **J**
9.  start inserting the elements from the secondary chain to the main chain. For example, if a pair of pairs is `((larger_key, larger_indice), (smaler_key, smaller_indice))`,  the smaller key is inserted, and the sequence becomes: `((smaler_key, smaller_indice), (-1,-1)), ((larger_key, larger_indice), (smaler_key, smaller_indice))`. With each insertion, uptate the values in **J**. For instance, if a `smaller_key` is inserted into the main chain to the position 5, all numbers with values > 5 in the **J** are increased by 1. (see The inserting part)
10. get the sorted container
11. return the order of original indexes
12. the calling function sorts the original array based on the order of the original indexes

## Containers of choice
deque and vector

## Number of comparisons
record them using a global variable
The number of comparisons is not required by the subject, but is useful for the evaluation. Use the DEBUG compilation mode to calculate the number of comparisons on demand.

## The inserting part
Once I have my Jacobstahl (filled) sequence calculated, it basically tells me which element to insert next. I have my a_i and b_i stored in pairs in the container, so when looking up an element a index i, I can just find the container[i]. Since there will be some elements added before element container[i] and it basically becomes i+1, I can reflect each insertion by changing the Jacobstahl sequence. So if an element is added before position i, i becomes i+1 and all the indexes J >= i should become J+1.