#include <iostream>
#include <vector>

// Function to check if a subset with the given target sum exists
bool subsetSum(std::vector<int> &nums, int target);

int main()
{
    int n, target;

    // Read the number of elements
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Verifica se n é válido
    if (n <= 0)
    {
        std::cout << "Invalid number of elements." << std::endl;
        return 1;
    }

    std::vector<int> nums(n);

    // Read the numbers into the vector
    std::cout << "Enter the " << n << " numbers: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    // Read the target value
    std::cout << "Enter the target value: ";
    std::cin >> target;

    // Verifica se target é válido
    if (target < 0)
    {
        std::cout << "Invalid target value." << std::endl;
        return 1;
    }

    // Call the function to solve the subset sum problem
    if (subsetSum(nums, target)) std::cout << "Yes, there is a subset with the given target sum." << std::endl;
    else std::cout << "No, there is no subset with the given target sum." << std::endl;

    return 0;
}

// Check if a subset sums to the target
bool subsetSum(std::vector<int> &nums, int target)
{
    int n = nums.size();
    
    // Create DP table (rows = numbers, cols = possible sums)
    std::vector<std::vector<bool>> matrix_dp(n + 1, std::vector<bool>(target + 1, false));

    // Sum of 0 is always possible with an empty subset
    for (int i = 0; i <= n; ++i) matrix_dp[i][0] = true;

    // Fill DP table: For each number and each target sum
    for (int j = 1; j <= target; ++j)  // For each target from 1 to 'target'
    {
        for (int i = 1; i <= n; ++i)  // For each number in 'nums'
        {
            // Exclude the number (carry over the previous result)
            matrix_dp[i][j] = matrix_dp[i - 1][j];

            // If we can include the current number, check if it helps
            if (j - nums[i - 1] >= 0)
            {
                matrix_dp[i][j] = matrix_dp[i - 1][j - nums[i - 1]] || matrix_dp[i][j];
            }
        }
    }

    // Check if the target sum is not achievable (i.e., if the last cell in the DP table is false)
    if (!matrix_dp[n][target]) return false;

    // Start reconstructing the subset by tracking the current target sum
    int current_row = target;
    std::vector<int> subset;

    // Iterate backwards through the DP table
    for (int i = n; i > 0; --i)
    {
        // If the current value in the DP table is different from the value above it,
        // it means the current number (nums[i - 1]) was included in the subset
        if (matrix_dp[i][current_row] != matrix_dp[i - 1][current_row])
        {
            // Add the number to the subset
            subset.push_back(nums[i - 1]);
            
            // Reduce the target sum by the current number to track the remaining sum
            current_row -= nums[i - 1];
        }
    }

    // Print the subset
    std::cout << "Subset with target sum: ";
    for (int num : subset)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Return true, as the target sum can be achieved with some subset
    return true;
}
