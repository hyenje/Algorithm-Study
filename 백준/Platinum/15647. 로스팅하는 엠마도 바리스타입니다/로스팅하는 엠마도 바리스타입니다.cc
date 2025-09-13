//
// Created by 신현재 on 25. 9. 11.
//
/*
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tr<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

vector<vector<pii > > arr(300'123);
vector<int> cnt(300'123, 1);
vector<ll> dist(300'123, -1);
vector<ll> dp_down(300'123, 0);
vector<ll> dp_up(300'123, 0);
vector<ll> visited(300'123, 0);

int n, a, b, c;

ll bottom_up(int node, int d) {
    dist[node] = d;
    visited[node] = 1;
    for (auto i: arr[node]) {
        if (visited[i.F]) continue;
        dp_down[node] += bottom_up(i.F, i.S);
        cnt[node] += cnt[i.F];
    }
    return dp_down[node] + dist[node] * cnt[node];
}

void top_down(int node) {
    visited[node] = 1;
    for (auto i: arr[node]) {
        if (visited[i.F]) continue;
        dp_up[i.F] = dp_up[node] + dp_down[node] - dp_down[i.F] + dist[i.F] * (n - cnt[i.F] * 2);
        top_down(i.F);
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    bottom_up(1, 0);
    visited = vector<ll>(300'123, 0);
    top_down(1);

    // for (int i = 1; i <= n; i++)
    //     cout << dp_down[i] << ' ' << dp_up[i] << endl;
    for (int i = 1; i <= n; i++)
        cout << dp_down[i] + dp_up[i] << '\n';
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
