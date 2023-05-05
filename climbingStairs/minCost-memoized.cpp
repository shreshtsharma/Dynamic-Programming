#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main()
{
    vector<int> arr;
    int n;
    cout << "enter size of array" << endl;
    cin >> n;
    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    Solution obj;
    int ans = obj.minCostClimbingStairs(arr);
    cout << "minimum cost is " << ans;
}