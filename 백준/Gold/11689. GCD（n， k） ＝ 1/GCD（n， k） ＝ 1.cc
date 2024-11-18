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
#define MOD 998'244'353
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

bool eratos[1'000'123];
map<ll, ll> m;

void solve()
{
    ll n, answer = 1;
    cin >> n;
    ll boundary = sqrt(n);

    for (ll i = 2; i <= boundary; i++)
    {
        if (eratos[i])
            continue;
        while (n % i == 0)
        {
            n /= i;
            m[i]++;
        }
    }

    if (n != 1)
        m[n]++;

    for (auto i : m)
    {
        auto [val, k] = i;
        answer *= (ll)pow(val, k - 1) * (val - 1);
    }

    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    for (int i = 2; i < 1'000'123; i++)
        for (int j = 2; j * i < 1'000'123; j++)
            eratos[i * j] = 1;

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */