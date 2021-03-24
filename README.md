# HW1_Problem_5
By Y.S.

HW1__Problem_5
For this problem I used 2 different sorts together, one inside the other in order to sort arrays. 
I’ve used quicksort as the main sort and inside the quicksort I used insertionSort to sort array whenever the number of elements
was less than 100. I compared the running times with a regular quicksort and with the sort() function from the standard 
library using timing function in the main method. Interestingly standard library sort was by far the fastest, followed by 
regular quicksort and my implementation of quicksort with the insertionSort was a little slower than the regular quicksort.
Adjusting the size of the array did not change the order of which sorting method was faster, the standard library sort was always 
the quickest, and quicksort was always a little faster than quicksort with insertionSort. 

