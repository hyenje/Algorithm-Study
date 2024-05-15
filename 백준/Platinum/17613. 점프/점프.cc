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

map<pll, ll> m;

ll dp(ll l, ll r)
{
    if (m[{l, r}] || (l == 0 && r == 0))
        return m[{l, r}];

    ll val = 0;
    for (ll i = 1; ((1 << i) - 1) <= r; i++)
    {
        ll s = (1 << i) - 1, e = s << 1;
        if (e < l)
            continue;

        ll nl = max(s, l);
        ll nr = min(e, r);
        val = max(val, i + dp(nl - s, nr - s));
    }
    return m[{l, r}] = val;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    cout << dp(x, y) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll val = 2;
    for (int i = 1; i < 40; i++, val <<= 1)
        m[{val - 1, val - 1}] = i;

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */