#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to check if the vector contains any duplicates
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    // Traverse each element in the vector
    for (int num : nums){
        mp[num]++;             // Increment count for this number
        if(mp[num] > 1){       // If count > 1, duplicate found
            return true;       // Return true immediately
        }
    }

    return false;              // No duplicates found
}

int main()
{
    vector<int> nums = {1, 2, 3,1};
    bool ans;
    ans = containsDuplicate(nums);
    cout << ans;               // Output: 1 (true)
    return 0;
}

/*
COMPLEXITY ANALYSIS:

Time Complexity:
- We traverse all 'n' elements in the vector exactly once.
- Each insertion/access in unordered_map is O(1) on average.
=> Total Time Complexity: O(n)

Space Complexity:
- We store each unique element in the unordered_map.
- In the worst case, all elements are unique.
=> Total Space Complexity: O(n)
*/


// Not exactly — `count` and `find` **serve similar purposes** (checking keys), but they **behave differently** and are used in different scenarios. Here’s a clear breakdown:

// ---

// ### **1. `count(key)`**

// * **Purpose:** Check **how many elements** have the given key.
// * **Return value:**

//   * For **`map` / `unordered_map`** → `0` (key absent) or `1` (key exists).
//   * For **`multimap` / `unordered_multimap`** → number of elements with that key (can be >1).
// * **Example:**

// ```cpp
// unordered_map<int,int> mp;
// mp[10] = 5;

// if(mp.count(10) > 0)  // true
//     cout << "Key exists" << endl;
// ```

// ---

// ### **2. `find(key)`**

// * **Purpose:** Get an **iterator to the element** with the given key.
// * **Return value:**

//   * Iterator pointing to the element if found
//   * `.end()` if key not found
// * **Example:**

// ```cpp
// auto it = mp.find(10);
// if(it != mp.end())  // key exists
//     cout << "Value: " << it->second << endl;
// ```

// ---

// ### **3. Key Differences**

// | Feature          | `count(key)`                                     | `find(key)`                       |
// | ---------------- | ------------------------------------------------ | --------------------------------- |
// | Return           | integer (0/1 or more)                            | iterator                          |
// | Use case         | Quick **existence check**                        | Access **value or element**       |
// | Multimap support | Counts duplicates                                | Can point to **first occurrence** |
// | Efficiency       | O(log n) for `map`, O(1) avg for `unordered_map` | Same as `count`                   |

// ---

// ### ✅ **Rule of Thumb**

// * Use `count(key)` → when you **only need to know if the key exists** (or number of occurrences).
// * Use `find(key)` → when you **need to access or modify the value** associated with the key.

// ---

// If you want, I can make a **tiny code snippet comparing `count` vs `find` in `unordered_map` and `multimap`** so it’s crystal clear. Do you want me to do that?

