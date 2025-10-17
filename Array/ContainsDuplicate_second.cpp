#include <iostream>
#include <vector>
using namespace std;
bool cotainsNearbyDuplicate(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
       
        for (int j = i + 1; j <= i + k && j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool ans = cotainsNearbyDuplicate(nums, 3);
    cout << ans;
    return 0;
}
/*
📊 Complexity Analysis

⏱ Time Complexity:
- Outer loop → runs n times.
- Inner loop → runs up to k times for each iteration of the outer loop.
- Therefore, total ≈ n * k comparisons in the worst case.

✅ Worst-case time complexity: O(n × k)
✅ Best-case: O(1) if a duplicate is found early.

💾 Space Complexity:
- Only a few integer variables (i, j, k) are used → constant extra space.

✅ Space complexity: O(1)

🧠 Summary:
| Complexity Type | Big-O     | Explanation                    |
|-----------------|-----------|--------------------------------|
| Time Complexity | O(n × k)  | Double loop, inner loop up to k |
| Space Complexity| O(1)      | No extra data structures        |
| Best Case       | O(1)      | If duplicate found early        |
| Worst Case      | O(n × k)  | No duplicates found             |

*/