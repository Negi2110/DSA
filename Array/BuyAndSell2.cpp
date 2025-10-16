#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum profit from stock prices
int maxProfit(vector<int>& prices) {
    int ans = 0;          // Initialize maximum profit to 0
    int n = prices.size(); // Number of days / prices

    // Check all possible pairs of buy (i) and sell (j) days
    for (int i = 0; i < n - 1; i++) {        // Loop over all buy days
        for (int j = i + 1; j < n; j++) {    // Loop over all sell days after buy day
            ans = max(ans, prices[j] - prices[i]); // Update maximum profit
        }
    }

    return ans; // Return the maximum profit found
}

int main() {
    vector<int> prices = {7, 6, 4, 3, 1}; // Example stock prices
    // vector<int> prices = {7, 1, 5, 3, 6, 4}; // Another example

    int ans;
    ans = maxProfit(prices); // Call function to find max profit
    cout << ans;             // Print the result
    return 0;
}

/*
Complexity Analysis:

Time Complexity: O(n^2)
- Two nested loops over the array of size n.
- For each buy day, we check all possible sell days after it.
- Worst-case: n*(n-1)/2 iterations → O(n^2)

Space Complexity: O(1)
- Only a few variables are used (ans, n, i, j).
- No extra space proportional to input size.
*/
