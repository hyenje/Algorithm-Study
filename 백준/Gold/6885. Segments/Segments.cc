//
// Created by 신현재 on 25. 7. 26.
//
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
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<ll> > dp(20'123, vector<ll>(2, INF));

void solve() {
    int n;
    cin >> n;
    ll answer = n - 1;
    vector<pll > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;

    dp[0][1] = a[0].S - 1;
    dp[0][0] = (a[0].S << 1) - a[0].F;
    // cout << dp[0][1] << ' ' << dp[0][0] << endl;
    for (int i = 1; i < n; i++) {
        ll len = a[i].S - a[i].F;
        dp[i][0] = min(
            dp[i - 1][0] + len + llabs(a[i].S - a[i - 1].F),
            dp[i - 1][1] + len + llabs(a[i].S - a[i - 1].S)
        );
        dp[i][1] = min(
            dp[i - 1][0] + len + llabs(a[i].F - a[i - 1].F),
            dp[i - 1][1] + len + llabs(a[i].F - a[i - 1].S)
        );
        // cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    // cout << answer << endl;
    cout << answer + min(dp[n - 1][0] + n - a[n - 1].F, dp[n - 1][1] + n - a[n - 1].S) << endl;
}

/*
 */

int main() {
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
