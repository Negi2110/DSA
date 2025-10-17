#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool cotainsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp; // stores value -> index

    for (int i = 0; i < nums.size(); i++)
    {
        // If current value already seen before
        if (mp.find(nums[i]) != mp.end())
        {
            int index = mp[nums[i]];
            // Check if indices difference is within range k
            if (abs(index - i) <= k)
            {
                return true; // Found nearby duplicate
            }
        }
        // Update or insert the current index for this value
        mp[nums[i]] = i;
    }
    return false; // No nearby duplicates found
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    bool ans = cotainsNearbyDuplicate(nums, 3);
    cout << ans;
    return 0;
}

/*
📊 Complexity Analysis

⏱ Time Complexity:
- Each iteration does a constant-time hash lookup and insertion (`O(1)` average).
- The loop runs `n` times (for each element in nums).
✅ Therefore, total time complexity = O(n)

⚠️ Note: In worst case (due to hash collisions), unordered_map operations can degrade to O(n),
but average case remains O(1) per operation.

💾 Space Complexity:
- The unordered_map stores at most `n` key-value pairs (one for each element).
✅ Space complexity = O(n)

🧠 Summary:
| Complexity Type | Big-O | Explanation |
|-----------------|-------|-------------|
| Time Complexity | O(n)  | One pass + O(1) average hash ops |
| Space Complexity| O(n)  | Stores value→index for each unique element |
| Best Case       | O(1)  | Duplicate found early |
| Worst Case      | O(n)  | No duplicates or all unique elements |

*/
