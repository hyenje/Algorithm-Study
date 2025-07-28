//
// Created by 신현재 on 25. 7. 28.
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

vector<vector<pll > > arr;
vector<vector<ll> > dist(200'123, vector<ll>(8, INF));
vector<int> nd(7), visited(100);

ll go(int node) {
    ll val = LL_INF;

    for (int i = 0; i < nd.size(); i++) {
        if (visited[i])
            continue;
        visited[i] = 1;
        // cout << node << ' ' << nd[i] << ' ' << dist[nd[i]][node] << endl;
        val = min(val, go(i) + dist[nd[i]][node]);
        visited[i] = 0;
    }

    if (val == LL_INF)
        return 0;
    return val;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    for (int i = 0; i < 7; i++)
        cin >> nd[i];
    sort(nd.begin(), nd.end());
    nd.erase(unique(nd.begin(), nd.end()), nd.end());

    vector<ll> d(200'123, LL_INF);
    priority_queue<pll, vector<pll >, greater<pll > > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll distance = pq.top().F, node = pq.top().S;
        pq.pop();
        if (distance >= d[node])
            continue;
        d[node] = distance;
        for (auto i: arr[node]) {
            pq.push({distance + i.S, i.F});
        }
    }

    for (int i = 0; i < nd.size(); i++) {
        while (pq.size())
            pq.pop();
        pq.push({0, nd[i]});
        while (!pq.empty()) {
            ll distance = pq.top().F, node = pq.top().S;
            pq.pop();
            if (distance >= dist[node][i])
                continue;
            dist[node][i] = distance;
            for (auto j: arr[node]) {
                pq.push({distance + j.S, j.F});
            }
        }
    }

    // for (int i = 0; i < nd.size(); i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << dist[j][i] << " ";
    //     cout << endl;
    // }
    ll answer = LL_INF;
    for (int i = 0; i < nd.size(); i++) {
        visited[i] = 1;
        answer = min(answer, d[nd[i]] + go(i));
        // cout << d[nd[i]] << " " << go(i) << ' ' << answer << endl;
        visited[i] = 0;
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
