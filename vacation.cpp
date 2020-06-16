#include <bits/stdc++.h>
using namespace std;
long long arr[100020][3], dp[100020][3];
long long fun(long long x, long long i)
{
    if (x <= 0)
        return 0;
    if (i > 2)
        return 0;
    if (dp[x][i] != -1)
        return dp[x][i];
    return dp[x][i] = arr[x][i] + max(fun(x - 1, (i + 1) % 3), fun(x - 1, (i + 2) % 3));
}
int main()
{
    long long n, x, y;
    cin >> n;
    for (x = 1; x <= n; x++)
        cin >> arr[x][0] >> arr[x][1] >> arr[x][2];
    memset(dp, -1, sizeof(dp));
    long long ans = max(fun(n, 0), max(fun(n, 1), fun(n, 2)));
    cout << ans << endl;
}