#include <bits/stdc++.h>
using namespace std;
long long wt[110], val[110], dp[100020][110];
long long fun(long long n, long long i)
{
    if (n <= 0)
        return 0;
    if (i < 0)
        return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    if (wt[i] > n)
        return dp[n][i] = fun(n, i - 1);
    return dp[n][i] = max(val[i] + fun(n - wt[i], i - 1), fun(n, i - 1));
}
int main()
{
    long long n, tot, x;
    cin >> n >> tot;
    for (x = 0; x < n; x++)
        cin >> wt[x] >> val[x];
    memset(dp, -1, sizeof(dp));
    long long ans = fun(tot, n - 1);
    cout << ans << endl;
}