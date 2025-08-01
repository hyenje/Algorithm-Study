//
// Created by 신현재 on 25. 8. 1.
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

int arr[9][9], w[9][10], h[9][10], sq[3][3][10];
vector<pii > brr;

int go(int idx) {
    if (idx == brr.size()) return 1;

    int x = brr[idx].F, y = brr[idx].S;
    for (auto i = 1; i <= 9; i++) {
        if (w[x][i] || h[y][i] || sq[x / 3][y / 3][i]) continue;

        w[x][i] = h[y][i] = sq[x / 3][y / 3][i] = 1;
        arr[x][y] = i;
        if (go(idx + 1)) return 1;
        arr[x][y] = w[x][i] = h[y][i] = sq[x / 3][y / 3][i] = 0;
    }
    return 0;
}

void solve() {
    int flag = 0;
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            arr[i][j] = s[j] - '0';
            if (arr[i][j] == 0)
                brr.push_back({i, j});
            else {
                if (w[i][arr[i][j]] || h[j][arr[i][j]] || sq[i / 3][j / 3][arr[i][j]])
                    flag = 1;
                w[i][arr[i][j]] = h[j][arr[i][j]] = sq[i / 3][j / 3][arr[i][j]] = 1;
            }
        }
    }

    if (go(0) && flag == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << arr[i][j];
            cout << endl;
        }
        cout << endl;
    } else
        cout << "Could not complete this grid.\n\n";

    brr.clear();
    for (int i = 0; i < 9; i++) for (int j = 0; j < 10; j++) w[i][j] = h[i][j] = sq[i / 3][i % 3][j] = 0;
}

/*
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

/*

*/
