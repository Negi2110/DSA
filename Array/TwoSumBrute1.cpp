//  arr=[2,7,11,15]
// target=9,return 0,1
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int find = target - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == find)
            {
                return {i, j}; // return the indices
            }
        }
    }
    return {}; // return empty vector if not found
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    vector<int> asp = twoSum(arr, 9);

    // Optional: print result
    if (!asp.empty())
        cout << "Indices: " << asp[0] << ", " << asp[1] << endl;
    else
        cout << "No pair found." << endl;
}

// ⚙️ Time Complexity
// 1. Outer Loop (for (int i = 0; i < n; i++))

// Runs n times in the worst case.

// 2. Inner Loop (for (int j = i + 1; j < n; j++))

// Runs approximately (n - i - 1) times for each i.

// 3. Total Operations

// The total number of comparisons =
// 1 + 2 + 3 + ... + (n - 1) = n(n - 1) / 2
// → O(n²) in worst case.

// ✅ Time Complexity:

// Best Case: O(1) — if the pair is found early (e.g., first two elements).

// Worst Case: O(n²) — if the pair is found at the end or not present.

// Average Case: O(n²)

// 💾 Space Complexity

// Only a few variables (n, find, i, j) are used → O(1) auxiliary space.

// The returned vector {i, j} has constant size → O(1).

// ✅ Space Complexity: O(1)