//
// Created by 신현재 on 25. 7. 10.
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
#define MOD 1'000'000'007
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int solve() {
    int n;
    cin >> n;
    if (n == 0)
        return 0;
    vector<vector<int> > arr(n + 1);
    for (int i = 0; i <= n; i++) {
        int m;
        int x, y, a, b, flag;
        cin >> m;
        cin >> x >> y;
        cin >> a >> b;
        if (x == a && y < b)
            flag = 1;
        else if (x == a && y > b)
            flag = 2;
        else if (x < a && y == b)
            flag = 3;
        else
            flag = 4;
        arr[i].push_back(abs(x - a + y - b));
        x = a, y = b;
        for (int j = 2; j < m; j++) {
            cin >> a >> b;
            int direc;
            if (x == a && y < b)
                direc = 1;
            else if (x == a && y > b)
                direc = 2;
            else if (x < a && y == b)
                direc = 3;
            else
                direc = 4;

            if (flag == 1) {
                if (direc == 3)
                    arr[i].push_back(0);
                else if (direc == 4)
                    arr[i].push_back(-1);
            } else if (flag == 2) {
                if (direc == 3)
                    arr[i].push_back(-1);
                else if (direc == 4)
                    arr[i].push_back(0);
            } else if (flag == 3) {
                if (direc == 1)
                    arr[i].push_back(-1);
                else if (direc == 2)
                    arr[i].push_back(0);
            } else {
                if (direc == 1)
                    arr[i].push_back(0);
                else if (direc == 2)
                    arr[i].push_back(-1);
            }
            arr[i].push_back(abs(x - a + y - b));

            flag = direc;
            x = a, y = b;
        }
    }


    for (int i = 1; i <= n; i++) {
        int flag = 0;
        if (arr[i] == arr[0])
            flag = 1;
        for (int k = 0; k < arr[i].size() / 2; k++) {
            swap(arr[i][k], arr[i][arr[i].size() - k - 1]);
        }
        for (int k = 0; k < arr[i].size(); k++) {
            if (k % 2) {
                if (arr[i][k] == 0)
                    arr[i][k] = -1;
                else
                    arr[i][k] = 0;
            }
        }
        if (arr[i] == arr[0])
            flag = 1;
        if (flag)
            cout << i << '\n';
    }
    // for (int i = 0; i <= n; i++) {
    //     for (auto j: arr[i])
    //         cout << j << ' ';
    //     cout << '\n';
    // }
    cout << "+++++\n";

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    while (solve());

    return 0;
}

/*

*/
