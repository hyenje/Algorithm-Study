//
// Created by 신현재 on 25. 7. 19.
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

void solve() {
    ll n, m, answer = 0, l = 1, r = 0;
    cin >> n >> m;
    vector<ll> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    while (l <= r) {
        ll mid = (l + r) / 2, node = 0;
        // cout << mid << ' ';
        for (const auto i: arr) {
            node += i / mid + ((i % mid) ? 1 : 0);
            // cout << node << ' ';
        }
        // cout << endl;
        if (node > n)
            l = mid + 1;
        else {
            answer = mid;
            r = mid - 1;
        }
    }

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

