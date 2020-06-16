#include <bits/stdc++.h>
using namespace std;
long long n, h[1000200], dp[1000020], k;
long long fun(long long n)
{
    if (n <= 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fun(n - 1) + abs(h[n - 1] - h[n]);
    for (long long x = n - 1; x >= n - k && x > 0; x--)
        dp[n] = min(dp[n], fun(x) + abs(h[n] - h[x]));
    return dp[n];
}
int main()
{
    long long x, y, z, i, j;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for (x = 1; x <= n; x++)
        cin >> h[x];
    long long ans = fun(n);
    cout << ans << endl;
}