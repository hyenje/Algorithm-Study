//
// Created by 신현재 on 25. 9. 18.
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

void solve() {
    int n, m, val;
    cin >> n >> m;
    queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll> > pq, num;
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
        pq.push(val);
        if (q.size() > m) {
            num.push(q.front());
            q.pop();
        }

        while (!num.empty() && pq.top() == num.top()) {
            pq.pop();
            num.pop();
        }

        cout << pq.top() << " ";
    }
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
