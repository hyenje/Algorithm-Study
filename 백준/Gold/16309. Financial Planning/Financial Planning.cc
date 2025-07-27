//
// Created by 신현재 on 25. 7. 27.
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
    ll n, m;
    ll answer = 0;
    cin >> n >> m;
    vector<pll > arr(n);
    for (auto &i: arr)
        cin >> i.first >> i.second;
    ll l = 0, r = INF;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll val = 0;;
        // cout << mid << endl;

        for (auto &i: arr) {
            if (i.S < i.F * mid)
                val += i.F * mid - i.S;
            if (val >= m)
                break;
        }

        if (val >= m) {
            answer = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << answer << endl;
}

/*
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();

    return 0;
}

/*

*/
