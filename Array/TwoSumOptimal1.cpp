#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two indices whose elements sum to target
vector<int> twoSum(vector<int> arr, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < arr.size(); i++) {
        int findEl = target - arr[i];
        //auto it = mp.find(findEl); // O(1) average lookup in unordered_map
        if (mp.find(findEl) != mp.end()) {
            return {mp[findEl], i}; // return indices
        }
        mp[arr[i]] = i; // store value with its index
    }
    return {};
}

int main() {
    vector<int> arr = {1, 8, 15, 2, 5};
    vector<int> ans = twoSum(arr, 13);
    if (!ans.empty()) {
        cout << ans[0] << " and " << ans[1];
    } else {
        cout << "not found";
    }
}

/*
Complexity Analysis:

Time Complexity: O(n)
- Each element is visited once.
- Lookup and insertion in unordered_map are O(1) on average.
- Total: O(n)

Space Complexity: O(n)
- We store up to n elements in the hash map.
- No other significant extra space is used.
*/
