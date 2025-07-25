//
// Created by 신현재 on 25. 7. 25.
//
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
#define MOD 97'654'321
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll arr[256][256][53];

int change(char a) {
    if (a >= 'a' && a <= 'z')
        return a - 'a';
    return a - 'A' + 26;
}

void solve() {
    int n, m, l;
    cin >> m >> n >> l;
    string s;
    vector<vector<char> > brr(53);
    for (int i = 0; i < l; i++) {
        cin >> s;
        int num = change(s[0]);
        int num2 = change(s[1]);

        if (num < 26 && num2 < 26)
            arr[2][0][num2]++;
        else if (num < 26 && num2 >= 26)
            arr[1][1][num2]++;
        else if (num2 >= 26)
            arr[0][2][num2]++;
        else
            arr[1][1][num2]++;
        brr[num].push_back(s[1]);
    }

    // for (auto i: brr) {
    //     for (auto j: i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if ((i == 0 && j == 0) || (i == n && j == m))
                continue;

            for (int k = 0; k < 52; k++) {
                for (auto x: brr[k]) {
                    int num = change(x);
                    if (num < 26)
                        arr[i + 1][j][num] = (arr[i + 1][j][num] + arr[i][j][k]) % MOD;
                    else
                        arr[i][j + 1][num] = (arr[i][j + 1][num] + arr[i][j][k]) % MOD;
                }
            }
            // cout << i << " " << j << '\n';
            // for (int k = 0; k < 52; k++) {
            //     cout << arr[i][j][k] << ' ';
            // }
            // cout << '\n';
        }
    }
    // cout << n << " " << m << '\n';
    // for (int k = 0; k < 52; k++) {
    //     cout << arr[n][m][k] << ' ';
    // }
    // cout << '\n';

    ll answer = 0;
    for (int i = 0; i < 52; i++) {
        answer = (answer + arr[n][m][i]) % MOD;
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
