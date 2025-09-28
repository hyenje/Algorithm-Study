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
#define MOD 998'244'353
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll dp[500][500];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'B') {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll val = 0;
            if (arr[i - 1][max(0, j - 1)] != 'W')
                val = max(val, dp[i - 1][max(0, j - 1)]);
            if (arr[i - 1][j] != 'W')
                val = max(val, dp[i - 1][j]);
            if (arr[i - 1][min(j + 1, m - 1)] != 'W')
                val = max(val, dp[i - 1][min(j + 1, m - 1)]);
            dp[i][j] += val;
        }
    }

    ll answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 'W')
                answer = max(answer, dp[i][j]);
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
