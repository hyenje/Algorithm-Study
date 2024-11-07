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

vector<ll> lawn;
ll arr[512][512];

void solve()
{
    ll n, m, l, a, b, c;
    cin >> n >> m >> l;

    memset(arr, l_INF, sizeof arr);

    while (m--)
    {
        cin >> a;
        lawn.push_back(a);
    }

    for (int i = 0; i < l; i++)
    {
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    ll answer, big = LL_INF;
    for (int i = 1; i <= n; i++)
    {
        ll val = 0;
        arr[i][i] = 0;

        for (auto j : lawn)
            val += arr[i][j];
        if (big > val)
        {
            big = val;
            answer = i;
        }
    }

    cout << answer << '\n';
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