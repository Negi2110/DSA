#include <iostream>
#include <vector>
#include <algorithm> // required for sort
using namespace std;

// Function to check if the vector contains any duplicates
bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Step 1: sort the array

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1]) // Step 2: check consecutive elements
            return true;            // duplicate found
    }

    return false;                   // no duplicates
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool ans = containsDuplicate(nums);
    cout << ans;                    // Output: 1 (true)
    return 0;
}

/*
COMPLEXITY ANALYSIS (Sorting Approach):

Time Complexity:
- Sorting the array: O(n log n)
- Traversing the array once to check consecutive elements: O(n)
=> Total Time Complexity: O(n log n)

Space Complexity:
- Sorting can be done in-place, so auxiliary space is O(1) (or O(n) depending on sorting algorithm)
=> Total Space Complexity: O(1) or O(n)
*/
