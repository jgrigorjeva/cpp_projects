We are supposed to load an argument in the Reversed Polish notation (for instance  "8 9 * 9 - 9 - 9 - 4 - 1 +"); 
<!-- Two vectors seem to be a good choice to store the numbers and the oparators separately. -->
Let's use the stack since the vector is taken in the last exercise. Also, the original algorithm to calculate using RPN literally uses a stack (LIFO), so it is a nobrainer.

# Resources
the algorithm: https://medium.com/@interviewbuddies/reverse-polish-notation-b88524252960