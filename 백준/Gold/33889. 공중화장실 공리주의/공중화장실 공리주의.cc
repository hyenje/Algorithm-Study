/*
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
#define MOD 1'000'000'007
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll fact[200'123], inv[200'123];

ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
void precompute()
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i < 200'123; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = power(fact[i], MOD - 2);
    }
}
ll nCr(ll n, ll r)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void solve()
{
    precompute();

    ll n, m;
    cin >> n >> m;
    // cout << n - m + 1 << ' ' << m << '\n';
    if (((n + 1) / 2) < m)
    {
        m = n - m;
        cout << nCr(n - m - 1, m) % MOD << '\n';
    }
    else
        cout << nCr(n - m + 1, m) % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*

*/