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
    ll n, h, val;
    cin >> n >> h;
    map<ll, ll> up, down;

    for (ll i = 0; i < n; i++) {
        cin >> val;
        if (i % 2) down[h - val + 1]++;
        else up[val + 1]++;
    }
    ll cnt = (n + 1) / 2, answer = INFINITY, node_cnt = 0;

    for (int i = 1; i <= h; i++) {
        cnt = cnt - up[i] + down[i];
        if (answer > cnt)
            node_cnt = 1, answer = cnt;
        else if (answer == cnt)
            node_cnt++;
        // cout << cnt << ' ';
    }
    // cout << endl;
    cout << answer << ' ' << node_cnt << endl;
}

/*
 *  -  -  -
 *  -  -
 *  -  - -
 *  -    -
 *  - -  -
 *    -  -
 * -  -  -
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
