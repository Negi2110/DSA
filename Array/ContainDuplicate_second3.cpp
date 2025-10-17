#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to check if nums contains nearby duplicate within distance k
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> st; // stores elements in the current window of size k

    for (int i = 0; i < nums.size(); i++) {
        // Check if current element is already in the set
        // Time complexity: O(log k) for set lookup
        if (st.find(nums[i]) != st.end()) {
            return true;
        }

        // Add current element to the set
        // Time complexity: O(log k) for insertion
        st.insert(nums[i]);

        // Maintain the window size <= k
        if (st.size() > k) {
            // Remove the element that's now out of the sliding window
            // Time complexity: O(log k) for deletion
            st.erase(nums[i - k]);
        }
    }

    return false; // No nearby duplicates found
}

/*
Time Complexity Analysis:
- Loop runs 'n' times where n = nums.size().
- Each operation inside the loop (find, insert, erase) takes O(log k) in a set.
- Overall time complexity: O(n * log k)

Space Complexity Analysis:
- The set stores at most k elements at any time (sliding window size).
- Space complexity: O(k)
*/

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << (containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;
    return 0;
}



// The unordered_map version does not explicitly maintain a window; it just checks the index difference whenever a duplicate is found.

// If your array is huge but k is small, the sliding window is more memory-efficient.

// If k is large (or comparable to n), the unordered_map version is generally faster because it avoids O(log k) operations.

// 💡 Rule of thumb:

// Use sliding window when you need to limit memory to k elements.

// Use hash map last index when you want faster lookups and memory isn’t a concern.