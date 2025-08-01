//
// Created by 신현재 on 25. 8. 1.
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

ll dp[250'123][2], n;
vector<ll> arr;

void solve() {
    cin >> n;
    arr.resize(n);
    ll answer = 0;

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    dp[0][0] = arr[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
        dp[i][1] = dp[i - 1][0] + 1;
    }
    answer = max(answer, max(dp[n - 1][0], dp[n - 1][1]));

    // cout << answer << endl;

    dp[0][0] = 0;
    dp[0][0] = 1;
    dp[1][0] = 1 + arr[1];
    dp[1][1] = arr[1];
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
        dp[i][1] = dp[i - 1][0] + 1;
    }
    answer = max(answer, dp[n - 1][0]);

    cout << answer << endl;
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
