#include <bits/stdc++.h>
using namespace std;
double arr[3010], dp[3010][3010], n;
double fun(long long x, long long y)
{
    // cout << x << endl;
    if (y > x)
        return 0;
    if (x < 0 || y < 0)
        return 0;
    if (x == 0 && y == 0)
        return 1;
    if (dp[x][y] > -1)
        return dp[x][y];
    return dp[x][y] = arr[x] * fun(x - 1, y - 1) + (1 - arr[x]) * fun(x - 1, y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double ans;
    long long x, y;
    cout.precision(15);
    cin >> n;
    for (x = 1; x <= n; x++)
        cin >> arr[x];
    for (x = 0; x < 3010; x++)
        for (y = 0; y < 3010; y++)
            dp[x][y] = -100.1;
    ans = 0;
    for (x = n / 2 + 1; x <= n; x++)
    {
        ans = ans + fun(n, x);
    }
    cout << ans << endl;
    return 0;
}