/*
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define LL_INF 9'223'372'036'854'775'807
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 998'244'353
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    double x, y, d, t, dis, cp, time = 0;
    cin >> x >> y >> d >> t;
    cp = dis = sqrt(pow(x, 2) + pow(y, 2));
    if (cp >= d)
    {
        int cnt = 0;
        while (cp >= d)
        {
            cp -= d;
            time += t;
        }
        time = min(time + cp, time + t);
    }
    else
        time = t + (d - dis);

    if (d * 2 > dis)
        time = min(time, t * 2);

    printf("%.11lf", min(time, dis));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */