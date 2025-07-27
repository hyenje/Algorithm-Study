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
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    vector<int> left, right;
    for (auto &i: arr)
        cin >> i;

    int l, r;
    cin >> l;
    left.resize(l);
    for (auto &i: left)
        cin >> i;
    cin >> r;
    right.resize(r);
    for (auto &i: right)
        cin >> i;
    sort(left.rbegin(), left.rend());
    sort(right.rbegin(), right.rend());

    l = left[0];
    r = right[0];

    int rez = INF;
    for (int i = 0; i < arr.size(); ++i)
        rez = min(rez, max(l + arr[i], r + n - arr[i]) + max(arr[i], n - arr[i]));

    cout << rez << '\n';
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
