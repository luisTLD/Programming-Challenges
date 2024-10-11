# Subset Sum Problem

## Description

This program solves the **Subset Sum Problem**, which determines whether there is a subset of a given set of numbers that sums up to a target value.

## Logic

The program uses **Dynamic Programming (DP)** to solve the problem. It constructs a DP table where:

- The rows represent the elements of the input array.
- The columns represent all possible sums from `0` to the target value.

### Steps:
1. **DP Table Initialization**: The first column (sum = 0) is always `true` because a sum of `0` can be achieved by an empty subset.
2. **Filling the DP Table**: For each number in the array, the table is filled by checking whether the current number can contribute to achieving the current target sum. The result for each target is updated by considering both including and excluding the current number.
3. **Subset Reconstruction**: If a subset with the target sum exists, the program backtracks through the DP table to reconstruct the subset that achieves the target sum.

## Time Complexity

- **Time Complexity**: `O(n * target)` where `n` is the number of elements in the array and `target` is the desired sum.
  - The DP table is of size `(n + 1) x (target + 1)`, and we fill it in `O(n * target)` time.
  
- **Space Complexity**: `O(n * target)` due to the storage of the DP table.