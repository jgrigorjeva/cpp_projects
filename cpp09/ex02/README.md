<!-- link the references using pandoc
bash:
pandoc notes.md  --citeproc -t markdown -o README.md
-->

# Merge insertion sort

*a method discovered by Lester Ford, Jr. and Selmer Johnson*

Note: In this article, I will assume that a *record* is one-dimentional,
it is just a number. Therefore, I will use the term *element* or
*number* instead of a record and *value* instead of key.

## 1. Binary insertion sort:

When inserting a number ($b$) into an already sorted list ($a_1$, $a_2$,
$a_3$, ... $a_i$), we can go the primitive way: compare $b$ with $a_1$,
if $b$ \> $a_1$, compare it with $a_1$, if $b$ \> $a_1$, compare it with
$a_1$, etc. Or we can **reduce the number of comparisons** by finding an
element in the middle of the $a$ list, comparing $b$ with $a_{middle}$,
if $b < a_{middle}$, find an element in the middle of the left sublist
(first-quarter) and compare $b$ with $a_{first quarter}$. If
$b > a_{middle}$, compare $b$ with $a_{last-quarter}$. Continue this way
by shortening the interval, until there is only one element left to
compare with. This binary approach reduces the complexity for
comparisons from $O(n^2)$ (worst-case scenario) to $O(log_2 n)$
(worst-case scenario in the primitive approach).

Let's illustrate the number of comparisons needed to perform the binary
insertion sort:

insert $b$ into:

$(a_1)$ → 1 comparison

$(a_1, a_2)$ → max 2 comparisons

$(a_1, a_2, a_3)$ → 2 comparisons

$(a_1, a_2, a_3, a_4)$ → max 3 comparisons

$(a_1, a_2, a_3, a_4, a_5)$ → max 3 comparisons

**The binary insertion cost depends only on the size of the search
interval**

Binary search on:

1 element → 1 comparison

2--3 elements → 2 comparisons

4--7 elements → 3 comparisons

8--15 elements → 4 comparisons

etc.

**Notice the pattern:**

$cost=⌈log⁡_2(n+1)⌉$

**The cost increases only when we cross powers of two.**

$cost = k$ when $n+1 = 2^k$, i.e. $n = 2^k - 1$

where $n$ is the number of elements in the search interval. This will be
an important point when we start inserting elements in the
merge-insertion.

## 2. Sorting by merging

Sorting by merging assumes combining two sorted files/arrays into one
sorted array. For example (from (Knuth 1998)), we can start with these
two arrays:

$$
\begin{cases}
    503, 703, 765 \\ 
    087, 512, 677
\end{cases}
$$

Now we only need to compare the first elements from each array:

$503:087$

Output the smaller element:

$$
087 \begin{cases}
    503, 703, 765 \\
    512, 677
\end{cases}
$$

Continue comparing the two smallest elements and outputting the result:

$$
087, 503 \begin{cases}
    703, 765 \\ % & is your "\tab"-like command (it's a tab alignment character)
    512, 677
\end{cases}
$$

$$
087, 503, 512 \begin{cases}
    703, 765 \\
    677
\end{cases}
$$

$$
087, 503, 512, 677 \begin{cases}
    703, 765   
\end{cases}
$$

Now we have a sorted array. This approach can be used to sort a single
unsorted array, for example as in the Straight two-way merge sorting
(Knuth 1998) (there are many flavours to Merge sorting, and this is one
of them)

<center>
`<img src='./Straight_merge_sort.PNG' width='700' />`{=html}
</center>

The vertical lines denote margins of arrays being compared. You can see
that we start comparing single elements from both ends, thus creating
sorted arrays of length 2. With each round, the size of the sorted
sub-arrays doubles, until there is only one array left.

You may notice that the Insertion sort is a special case of the Merge
sort when a one-element array is merged with a sorted n-element array.

I will not go into the Merge sort any further since its connection to
the Merge-insertion sort is rather loose. If you are interested in more
types of the Merge sort, have a look in (Knuth 1998), it provides a
detailed analysis of them as well.

## 3. Finally, all together: Merge-insertion sort

Here we actually need the records to contain not only the key, but also
a reference to another record. We will illustrate the algorithm on
sorting 21 elements. \### The algorithm 1. start with an unsorted array
of records $x_1, x_2, ..., x_{21}$ 2. create ten pairs of elements and
compare their keys: $K_1:K_2, K_3:K_4, ..., K_{19}:K_{20}$. We need to
keep track of the pairs. 3. sort the larger elements using merge
insertion (therefore recursively). For clarity, we will denote the
sorted larger elements as $a_1, a_2, ..., a_{10}$, and the smaller
elements will be $b_1, b_2, ..., b_{11}$. Thus we obtain the following
representation:

    b₁      b₂      b₃     b₄     b₅      b₆      b₇      b₈     b₉     b₁₀     b₁₁
    ↓       ↓       ↓      ↓      ↓       ↓       ↓       ↓      ↓      ↓       
    a₁  →   a₂  →   a₃  →  a₄  →  a₅  →   a₆  →   a₇  →   a₈  →  a₉  →  a₁₀  

In this notation, the arrow always points from the smaller element to
the larger element: $a_1 → a_2$ if $a_1 < a_2$

4.  now start inserting the $b_i$ into the sorted $a_j$ array. We will
    use the binary insertion for that. In order to optimize the number
    of comparisons needed in the insertion of each element, the $b_i$
    will be inserted in a **specific order**.

### What specific order?

When inserting a $b$ elenemt into the sorted array, we know that
$b_i < a_i$, therefore $b_i$ must go to the left from $a_i$. The array
$b_i$ is inserted into, contains all the smaller $a$ elements
($a_1, a_2, ..., a_{i-1}$), and also some of the $b$ elements inserted
previously. After insertion of $b_1$, the configuration is:

                   b₂      b₃     b₄     b₅      b₆      b₇      b₈     b₉     b₁₀     b₁₁
                   ↓       ↓      ↓      ↓       ↓       ↓       ↓      ↓      ↓       
    b₁  →  a₁  →   a₂  →   a₃  →  a₄  →  a₅  →   a₆  →   a₇  →   a₈  →  a₉  →  a₁₀  

Now, if we continue by inserting $b_2$, the number of comparisons for
its correct placement is up to 2 (we are inserting into an array of
length 2). The resulting configuration will be

                                  b₃     b₄     b₅      b₆      b₇      b₈     b₉     b₁₀     b₁₁
                                  ↓      ↓       ↓       ↓       ↓      ↓      ↓       
    c₁  →  c₂  →   c₃  →   c₄  →  a₃  →  a₄  →  a₅  →   a₆  →   a₇  →   a₈  →  a₉  →  a₁₀  

(We changed the labels on $a_1, a_2, b_1, b_2$ to $c_1, ..., c_4$ since
we don't exactly where each $b$ goes). If we then continue by inserting
$b_3$, now it is inserted in an array of four elements\` therefore, the
maximum number of comparisons in this case is 3. **This is not
optimal.**

**Instead, if we inserted $b_3$ first, and only then $b_2$,** we would
be inserting into the array of 3 elements for $b_3$ and $b_2$,
therefore, there will be only 2 comparisons in each case. If we went
with this analysis further, we would realize that the number of
comparisons for inserting $b_4, ..., b_{11}$ would be minimal if they
were done in this order:

$b_5,b_4,b_{11},b_{10},b_9,b_8,b_7,b_6$

That is because the new array size each $b_i$ is inserted into will grow
in this sequence (starting from $b_1$):
$0, 3, 3, 7, 7, 15, 15, 15, 15, 15, 15$. We always aim at the array size
that is $n = 2^k - 1$, just before crossing the next power of 2. Indexes
that meet this rule follow a specific sequence which jumps to the next
"boundary number" (let's label it as $J_n$), then keeps subtracting one
until the previous "boundary number" ($J_{n-1}$) is reached. All the
$J$s follow the **Jacobsthal sequence**:

$1,3,2,5,4,11,10,9,8,7,6,21,...$

or

$J_n​=J_{n−1}​+2J_{n−2}​$

## References {#references .unnumbered}

:::: {#refs .references .csl-bib-body .hanging-indent}
::: {#ref-Knuth1998 .csl-entry}
Knuth, Donald Ervin. 1998. *The Art of Computer Programming. Volume 3,
Sorting and Searching*. Vol. 3. Addison-Wesley.
:::
::::
