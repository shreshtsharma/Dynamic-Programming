//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        return solve(arr, sum, 0);
    }
    bool solve(vector<int> &arr, int sum, int ind)
    {
        if (ind == arr.size())
        {
            if (sum == 0)
            {
                return true;
            }
            else
                return false;
        }
        if (solve(arr, sum - arr[ind], ind + 1))
        {
            return true;
        }
        if (solve(arr, sum, ind + 1))
            return true;

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends