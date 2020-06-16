#include <bits/stdc++.h>
using namespace std;
long long n;
double dp[310][310][310];
double fun(long long on, long long tw, long long th)
{
    if (on < 0 || tw < 0 || th < 0)
        return 0;
    if (on == 0 && tw == 0 && th == 0)
        return 0;
    if (dp[on][tw][th] > -1)
        return dp[on][tw][th];
    return dp[on][tw][th] = 1.0 * n / (on + tw + th) + fun(on - 1, tw, th) + fun(on + 1, tw - 1, th) + fun(on, tw + 1, th - 1);
}
int main()
{
    long long v, on, tw, th;
    on = tw = th;
    cin >> n;
    for (long long x = 0; x < n; x++)
    {
        cin >> v;
        if (v == 1)
            on++;
        if (v == 2)
            tw++;
        if (v == 3)
            th++;
    }
    memset(dp, -100, sizeof(dp));
    double ans = fun(on, tw, th);
    cout << ans << endl;
}