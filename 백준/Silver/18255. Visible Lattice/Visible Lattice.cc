//
// Created by 신현재 on 25. 7. 18.
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

ll arr[123];

void solve() {
    int n;
    cin >> n;
    cout << arr[n] << endl;
}

/*
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    set<pair<ll,pll > > s;
    for (int i = 1; i < 101; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                ll num = gcd(k, gcd(i, j));
                s.insert({i / num, {j / num, k / num}});
                s.insert({j / num, {i / num, k / num}});
                s.insert({j / num, {k / num, i / num}});
            }
        }
        arr[i] = s.size();
    }

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

/*

*/
