#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else
        return dp[n][W] = knapsack(wt, val, W, n - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << "enter number of values" << endl;
    int n;
    vector<int> wt;
    vector<int> val;
    cin >> n;
    cout << "enter weights" << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        wt.push_back(temp);
    }
    cout << "enter values" << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        val.push_back(temp);
    }
    int W;
    cout << "Enter knapsack capacity" << endl;
    cin >> W;

    int maxprofit = knapsack(wt, val, W, n);
    cout << "maximum profit is " << maxprofit << endl;
}