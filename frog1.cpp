#include <bits/stdc++.h>
using namespace std;
long long n, h[100020], dp[100020];
long long fun(long long n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return dp[n] = abs(h[2] - h[1]);
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = min(fun(n - 1) + abs(h[n] - h[n - 1]), fun(n - 2) + abs(h[n] - h[n - 2]));
}
int main()
{
    long long x, y, z, i, j;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (x = 1; x <= n; x++)
        cin >> h[x];
    long long ans = fun(n);
    cout << ans << endl;
}