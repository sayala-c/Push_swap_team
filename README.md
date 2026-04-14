*This project has been created as part of the 42 curriculum by oduran-m and sayala-c.*

## Description 

The core of the project is to sort a stack with the minimum number of operations. The logic follows a multi-strategy flow depending on the input size and the flags used:

1. **Parsing:** The program analyzes the input arguments to verify they are valid integers, within limits, and contains no duplicates.
2. **Stack Creation:** Once validated, Stack A is initialized with the provided arguments.
3. **Disorder Index Calculation:** The program calculates a **Global Disorder Index** (a decimal value) for the entire stack. This metric represents the current state of "unsortedness," helping the program assess the complexity of the input.
4. **Node Indexing (Coordinate Compression):** Each node is assigned a unique **index** (from 0 to N-1) based on its value relative to the others. This normalization allows the algorithms to work independently of the raw values, handling negative numbers and gaps seamlessly.
5. **Dispatching:** Based on the **number of arguments** and the **Disorder Index**, the program automatically selects the most efficient algorithm, unless overridden by a flag.

### Algorithms

* **Simple algorithm:** for a disorder index smaller than 0.20% or up to 5 arguments in the stack
<<<<<<< HEAD
    * `Hardcoded Logic`: for 2 to 5 numbers.
    * `Selection Sort:` for small sets, identifying the minimum element and pushing it to Stack B. This is preferred over Bubble Sort as it drastically reduces the number of operations by performing only one "push" per element instead of constant adjacent swaps.
* **Medium algorithm:** for a disorder index equal or higher than 0.20% and smaller than 0.50%.
    * `Chunks Algorithm`: For medium sets, dividing the stack into value blocks to reduce rotation costs.
* **Complex algorithm:**  for a disorder index equal or higher than 0.50%.
    * `Radix Sort`: for large sets, sorting bit by bit based on the node indices.
=======
	* `Hardcoded Logic`: for 2 to 5 numbers.
	* `Selection Sort:` for small sets, identifying the minimum element and pushing it to Stack B. This is preferred over Bubble Sort as it drastically reduces the number of operations by performing only one "push" per element instead of constant adjacent swaps.
* **Medium algorithm:** for a disorder index equal or higher than 0.20% and smaller than 0.50%. 
	* `Chunks Algorithm`: For medium sets, dividing the stack into value blocks to reduce rotation costs.
* **Complex algorithm:**  for a disorder index equal or higher than 0.50%.
	* `Radix Sort`: for large sets, sorting bit by bit based on the node indices.
>>>>>>> e6c9c0e (readme)
* **Adaptive algorith:** it automatically selects an algorithm based on the number of arguments introduced and the disorder index mentioned before.

### Custom Flags

We have implemented system of flags run and test different strategies:
* `--bench`: displays the disorder index (% with two decimal places), the name of the strategy used and its theoretical complexity class, the total number of operations used and the number of operations of each type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) used during the sorting process.
* `--adaptive`: Automatically detects the stack size and chooses the best algorithm (Small, Selection, Chunks, or Radix).
* `--simple`: forces the use of the **Hardcoded Logic** and **Selection Sort** algorihm.
* `--medium`: forces the use of the **Chunks-based** algorithm.
* `--complex`: forces the use of the **Radix Sort** algorithm.

<<<<<<< HEAD
=======
### Contributions

>>>>>>> e6c9c0e (readme)
