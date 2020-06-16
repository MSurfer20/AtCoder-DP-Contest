#include <bits/stdc++.h>
using namespace std;
long long dp[3010][3010];
string s, t;
long long fun(long long x, long long y)
{
    if (x < 0 || y < 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (s[x] == t[y])
        return dp[x][y] = 1 + fun(x - 1, y - 1);
    return dp[x][y] = max(fun(x - 1, y), fun(x, y - 1));
}
int main()
{

    cin >> s;
    cin >> t;
    long long l1 = s.length(), l2 = t.length();
    memset(dp, -1, sizeof(dp));
    long long ans = fun(l1 - 1, l2 - 1);
    // cout << ans << endl;
    string fin = "";
    fin.clear();
    long long x = l1 - 1, y = l2 - 1;
    while (x >= 0 && y >= 0)
    {
        if (s[x] == t[y])
        {
            fin = s[x] + fin;
            x--, y--;
        }
        else
        {
            if (x == 0)
                y--;
            else if (y == 0)
                x--;
            else if (dp[x - 1][y] > dp[x][y - 1])
                x--;
            else
                y--;
        }
    }
    cout << fin;
}