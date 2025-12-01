//
// Created by 신현재 on 25. 12. 1.
//
/*
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tr<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define rep(i,k,n) for(int i=k;i<n;i++)
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
#define MOD 1'000'000'007
#define MID 200'000
#define LM_INF 1'000'000'000'000'000

const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void coordinate_compress(vector<pii > &arr, vector<int> &x_c, vector<int> &y_c) {
    sort(x_c.begin(), x_c.end());
    x_c.erase(unique(x_c.begin(), x_c.end()), x_c.end());
    sort(y_c.begin(), y_c.end());
    y_c.erase(unique(y_c.begin(), y_c.end()), y_c.end());
    for (auto &i: arr) {
        i.F = upper_bound(x_c.begin(), x_c.end(), i.F) - x_c.begin();
        i.S = upper_bound(y_c.begin(), y_c.end(), i.S) - y_c.begin();
    }
}

void init(vector<int> &v, int l, int r, int node, int index) {
    if (l > index || r < index)
        return;
    if (l == r) {
        v[node]++;
        return;
    }
    int mid = (l + r) / 2;
    init(v, l, mid, node * 2, index);
    init(v, mid + 1, r, node * 2 + 1, index);
    v[node] = v[node << 1] + v[(node << 1) + 1];
}

int query(vector<int> &v, int l, int r, int nd, int ql, int qr) {
    if (r < ql || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return v[nd];
    int mid = (l + r) / 2;
    return query(v, l, mid, nd << 1, ql, qr) + query(v, mid + 1, r, (nd << 1) + 1, ql, qr);
}

bool compare(pii a, pii b) {
    return a.F > b.F ? true : (a.F == b.F ? a.S < b.S : false);
}

void solve() {
    int n;
    ll answer = 0;
    cin >> n;

    vector<pii > arr(n);
    vector<int> x_c, y_c;

    map<pii, ll> mp;
    for (auto &i: arr) {
        cin >> i.F >> i.S;
        x_c.push_back(i.F);
        y_c.push_back(i.S);
    }

    coordinate_compress(arr, x_c, y_c);
    sort(arr.begin(), arr.end());

    vector<int> left_tree(2'000'123, 0);
    vector<int> right_tree(2'000'123, 0);

    rep(i, 0, n) {
        mp[arr[i]] = query(left_tree, 0, n - 1, 1, arr[i].S + 1, 400'123);
        init(left_tree, 0, n - 1, 1, arr[i].S);
    }

    sort(arr.begin(), arr.end(), compare);

    rep(i, 0, n) {
        answer = (answer + mp[arr[i]] * query(right_tree, 0, n - 1, 1, arr[i].S + 1, 400'123)) % MOD;
        // cout << arr[i].F << ' ' << arr[i].S << ' ' << mp[arr[i]] << ' ' << query(
        //     right_tree, 0, n - 1, 1, arr[i].S + 1, 400'123) << '\n';
        init(right_tree, 0, n - 1, 1, arr[i].S);
    }

    cout << answer << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // int t;
    // std::cin >> t;
    // while (t--)
    solve();

    return 0;
}
