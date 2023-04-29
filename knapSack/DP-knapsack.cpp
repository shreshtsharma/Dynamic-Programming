#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

/********************************************* TOP-DOWN Apprach *****************************************************/
int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
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
