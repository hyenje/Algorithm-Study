//
// Created by 신현재 on 25. 12. 2.
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
#define MOD 998'244'353
#define MID 200'000
#define LM_INF 1'000'000'000'000'000

const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};


vector<ll> segtree(2'000'000, 0), cnt(2'000'000, 0);
vector<vector<ll> > arr;
vector<ll> y;

void init(ll nd, ll start, ll end, ll l, ll r, ll val) {
    if (start > r || l > end) return;
    ll mid = (start + end) >> 1;
    if (l <= start && end <= r) {
        cnt[nd] += val;
    } else {
        init((nd << 1), start, mid, l, r, val);
        init((nd << 1) + 1, mid + 1, end, l, r, val);
    }
    if (cnt[nd])
        segtree[nd] = y[end] - y[start - 1];
    else {
        if (start == end) segtree[nd] = 0;
        else segtree[nd] = segtree[(nd << 1)] + segtree[(nd << 1) + 1];
    }
}

void solve() {
    ll n, a, b, c, d;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        c++, d++;
        arr.push_back({a, c, d, 1});
        arr.push_back({b, c, d, -1});
        y.push_back(c);
        y.push_back(d);
    }
    sort(arr.begin(), arr.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    ll answer = 0, diff_x;

    for (ll i = 0; i < arr.size(); i++) {
        if (i > 0) {
            diff_x = arr[i][0] - arr[i - 1][0];
            answer += segtree[1] * diff_x;
        }
        ll y1_idx = lower_bound(y.begin(), y.end(), arr[i][1]) - y.begin();
        ll y2_idx = lower_bound(y.begin(), y.end(), arr[i][2]) - y.begin();
        init(1, 1, y.size(), y1_idx + 1, y2_idx, arr[i][3]);
        // cout << arr[i][0] << ' ' << y1_idx << ':' << y[y1_idx] << ' ' << y2_idx << ':' << y[y2_idx] << ' ' << answer <<
        //         ' ' << arr[i][3] << endl;
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
