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

int dp[250'123][2], n;
vector<int> arr;

void go(int node) {
    if (node == n)
        return;
    go(node + 1);

    dp[node][1] = dp[node + 1][0] + 1;
    dp[node][0] = max(dp[node + 1][1] + arr[node], dp[node + 1][0] + arr[node]);
    // cout << n << ' ' << dp[node][0] << ' ' << dp[node][1] << ' ' << arr[node] << endl;
}

void solve() {
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr.push_back(arr[0]);
    arr.push_back(arr[1]);

    go(0);

    if (arr[n - 1]) {
        cout << max(dp[0][0], dp[0][1]) << endl;
    } else
        cout << dp[0][0] << endl;
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
