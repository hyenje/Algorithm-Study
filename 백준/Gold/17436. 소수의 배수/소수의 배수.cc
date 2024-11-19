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

vector<ll> v[20];

void solve()
{
    ll n, m, answer = 0;
    cin >> n >> m;
    vector<ll> arr(n);

    for (auto &i : arr)
        cin >> i;

    for (int i = 1; i < (1 << n); i++)
    {
        ll val = 0, num = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                val++;
                num *= arr[j];
            }
        }
        v[val].push_back(num);
    }

    // for (auto i : v)
    // {
    //     for (auto j : i)
    //         cout << j << ' ';
    //     cout << '\n';
    // }

    for (int i = 1; i <= n; i++)
    {
        for (auto j : v[i])
        {
            if (i % 2)
                answer += m / j;
            else
                answer -= m / j;
        }
    }

    cout << answer << '\n';
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