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

int ccw(pll p1, pll p2, pll p3)
{
    ll s = p1.F * p2.S + p2.F * p3.S + p3.F * p1.S - (p1.S * p2.F + p2.S * p3.F + p3.S * p1.F);

    if (s > 0)
        return 1;
    else if (s == 0)
        return 0;
    else
        return -1;
}
bool isIntersect(pll one, pll two, pll three, pll four)
{
    ll onetwo = ccw(one, two, three) * ccw(one, two, four);
    ll threefour = ccw(three, four, one) * ccw(three, four, two);

    if (onetwo == 0 && threefour == 0)
    {
        if (one > two)
            swap(two, one);
        if (three > four)
            swap(three, four);

        if (three <= two && one <= four)
            return 1;
        else
            return 0;
    }

    if (onetwo <= 0 && threefour <= 0)
        return 1;
    else
        return 0;
}

void solve()
{
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2 || (x1 == x2 && y1 > y2))
        swap(x1, x2), swap(y1, y2);
    if (x3 > x4 || (x3 == x4 && y3 > y4))
        swap(x3, x4), swap(y3, y4);

    if (isIntersect({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}))
    {
        cout << 1 << '\n';

        long double a1 = (long double)x1, b1 = (long double)y1, a2 = (long double)x2, b2 = (long double)y2, a3 = (long double)x3, b3 = (long double)y3, a4 = (long double)x4, b4 = (long double)y4;
        long double i1 = (b1 - b2) / (a1 - a2), i2 = (b3 - b4) / (a3 - a4);
        long double x = (i2 * a3 - i1 * a1 + b1 - b3) / (i2 - i1);
        long double y = i1 * (x - a1) + b1;
        if ((!isnan(x) && !isnan(y)))
            printf("%.11Lf %.11Lf\n", x, y);
        else if (x1 == x4 && y1 == y4)
            printf("%.11Lf %.11Lf\n", a1, b1);
        else if (x2 == x3 && y2 == y3)
            printf("%.11Lf %.11Lf\n", a2, b2);
        else if (a1 == a2 && a3 == a4 && (b1 != b4 || b3 != b2))
            return;
        else if (a1 == a2)
            printf("%.11Lf %.11Lf\n", a1, i2 * (a1 - a3) + b3);
        else if (a3 == a4)
            printf("%.11Lf %.11Lf\n", a3, i1 * (a3 - a1) + b1);

        // printf("%.11Lf %.11Lf %.11Lf %.11Lf %.11Lf %.11Lf %.11Lf %.11Lf\n", a1, b1, a2, b2, a3, b3, a4, b4);
        // printf("%.11Lf %.11Lf %.11Lf %.11Lf %.11Lf %.11Lf\n", a1, a2, b1, b2, i1, i2);
        // printf("%.11Lf %.11Lf\n", x, y);
    }
    else
        cout << 0 << '\n';
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