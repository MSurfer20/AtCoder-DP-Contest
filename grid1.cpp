#include <bits/stdc++.h>
using namespace std;
long long dp[1010][1010], h, w, mod = 1e9 + 7;
char arr[1010][1010];

long long fun(long long x, long long y)
{
    // cout << x << " " << y << endl;
    if (x < 0 || y < 0)
        return 0;
    if (x == 0 && y == 0)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    int flag1 = 1, flag2 = 1;
    if (arr[x - 1][y] == '#')
        flag1 = 0;
    if (arr[x][y - 1] == '#')
        flag2 = 0;
    return dp[x][y] = (flag1 * (fun(x - 1, y) % mod) + flag2 * (fun(x, y - 1) % mod)) % mod;
}

int main()
{
    cin >> h >> w;
    long long ans, x, y;
    for (x = 0; x < h; x++)
        for (y = 0; y < w; y++)
            cin >> arr[x][y];
    memset(dp, -1, sizeof(dp));
    ans = fun(h - 1, w - 1);
    cout << ans << endl;
}