# Quicksort

Application of Quicksort Algorithm

The following techniques are claimed to improve the performance over the basic Quick Sort algorithm: 
a) Randomize pivot element 
b) Median-of-three partition 
c) Directly using Insertion Sort when a partition is small (say < 10 elements) 
d) Technique a) plus Technique c) 
e) Technique b) plus Technique c) 

Objective:
Implement the basic Quick Sort algorithm and the above improvements. 
Run experiments to determine the percentages of key comparisons saved in each case over the basic Quick Sort algorithm, using randomly generated integer arrays of size 100,000 as inputs. 

Files 					
-------------------------------------------------
quicksort ->					General quicksort algorithm

quicksort_with_insertion -> Uses insertion sort if input size is less than 10

randomized_quicksort	->	Uses random element as pivot for partiotioning

random_and_insertion	->	Uses random element as pivot and insertion sort if input size less than 10

median_quicksort	->		Uses median of 3(first, middle, last) element as pivot for partiotioning

median_with_insertion	->	Uses median of 3 and insertion sort for lower size inputs

quicksort_all_applications ->	Prints out key comparision count for all the above implementation of quicksort

** Compile and run quicksort_all_applications to get the key comparision count for each method as output.
