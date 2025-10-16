#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm> // for max()
using namespace std;

// Function to calculate maximum profit
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; //we can also intilise it with a[0]// Minimum price seen so far
    int maxProfit = 0;      // Maximum profit so far

    for (int price : prices) {      // Iterate over each day's price
        if (price < minPrice) {     // Update minPrice if current price is lower
            minPrice = price;
        }
        // Calculate profit if sold today and update maxProfit
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit; // Return the maximum profit
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {7, 6, 4, 3, 1};

    int ans = maxProfit(prices); // Call function
    cout << ans;                 // Print result
    return 0;
}

/*
Optimal Complexity Analysis:

Time Complexity: O(n)
- Single pass through the prices array.
- For each price, we do constant time operations (comparison and subtraction).

Space Complexity: O(1)
- Only two extra variables are used: minPrice and maxProfit.
- No extra space proportional to input size.
*/
