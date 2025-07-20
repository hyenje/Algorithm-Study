//
// Created by 신현재 on 25. 7. 20.
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
    vector<int> arr(1123, 2);
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    vector<vector<int> > brr(m + 1, vector<int>(4));
    for (int i = 1; i <= m; i++) {
        cin >> brr[i][0] >> brr[i][1] >> brr[i][2] >> brr[i][3];
        if (brr[i][3] == 1) {
            arr[brr[i][0]] = arr[brr[i][1]] = arr[brr[i][2]] = 1;
        }
    }

    // for (int i = 1; i <= (a + b + c); i++)
    //     cout << arr[i] << "\n";
    // cout << endl;

    for (int i = 1; i <= m; i++) {
        if (brr[i][3] == 0) {
            if (arr[brr[i][0]] == 1 && arr[brr[i][1]] == 1)
                arr[brr[i][2]] = 0;
            if (arr[brr[i][2]] == 1 && arr[brr[i][1]] == 1)
                arr[brr[i][0]] = 0;
            if (arr[brr[i][2]] == 1 && arr[brr[i][0]] == 1)
                arr[brr[i][1]] = 0;
        }
    }
    for (int i = 1; i <= (a + b + c); i++)
        cout << arr[i] << "\n";
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
