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

ll dp[124][2][124][124];
vector<vector<ll>> arr(124, vector<ll>(4));
ll n, a, b, q, w, e, r, answer = 0;

ll go(ll nd, bool rest, ll nursing, ll study)
{
    if (nd == n)
    {
        if (study >= b)
            return 0;
        return -999999;
    }
    if (dp[nd][rest][nursing][study] != -1)
        return dp[nd][rest][nursing][study];

    ll val = -999999;
    if (rest == 0)
        val = max(val, go(nd + 1, 1, nursing, study) + arr[nd][1]);
    if (nursing < a)
        val = max(val, go(nd + 1, 0, nursing + 1, study) + arr[nd][2]);
    val = max(val, go(nd + 1, 0, nursing, study + 1) + arr[nd][0]);

    dp[nd][rest][nursing][study] = val;
    return dp[nd][rest][nursing][study];
}

void solve()
{
    cin >> n >> a >> b;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> q >> w >> e >> r;
        i[0] = max(q, w), i[1] = e, i[2] = r;
    }

    fill(&dp[0][0][0][0], &dp[123][1][123][124], -1);

    cout << go(0, 0, 0, 0) << '\n';
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