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