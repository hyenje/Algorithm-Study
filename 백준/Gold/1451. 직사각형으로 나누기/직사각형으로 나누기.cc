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

ll arr[100][100];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> input(n);
    for (auto &i: input)
        cin >> i;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            arr[i][j] = input[i - 1][j - 1] - '0';
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    ll answer = 0;

    for (int i = 1; i <= m; i++)
        for (int k = i + 1; k <= m; k++)
            answer = max(answer, arr[n][i] * (arr[n][k] - arr[n][i]) * (arr[n][m] - arr[n][k]));
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            answer = max(answer, arr[i][m] * (arr[j][m] - arr[i][m]) * (arr[n][m] - arr[j][m]));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            answer = max(answer, arr[n][i] * (arr[j][m] - arr[j][i]) * (arr[n][m] - arr[n][i] - arr[j][m] + arr[j][i]));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            answer = max(answer, (arr[n][m] - arr[n][i]) * arr[j][i] * (arr[n][i] - arr[j][i]));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            answer = max(answer, arr[i][m] * (arr[n][j] - arr[i][j]) * (arr[n][m] - arr[i][m] - arr[n][j] + arr[i][j]));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            answer = max(answer, arr[i][j] * (arr[i][m] - arr[i][j]) * (arr[n][m] - arr[i][m]));
    cout << answer << endl;
    return;
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
