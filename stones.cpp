#include <bits/stdc++.h>
using namespace std;
long long n, k, arr[110], dp[100100];
int fun(long long x)
{
    if (x < 0)
        return 1;
    if (dp[x] != -1)
        return dp[x];
    for (long long y = 0; y < n; y++)
        if (fun(x - arr[y]) == 0)
            return dp[x] = 1;
    return dp[x] = 0;
}
int main()
{
    long long x, y;
    cin >> n >> k;
    for (x = 0; x < n; x++)
        cin >> arr[x];
    memset(dp, -1, sizeof(dp));
    long long ans = fun(k);
    if (dp[k] == 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}