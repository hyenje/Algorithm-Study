//
// Created by 신현재 on 25. 8. 9.
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

bool comp(pii a, pii b) {
    if (a.S == b.S) return a.F < b.F;
    return a.S < b.S;
}

void solve() {
    set<pii > se;
    vector<pii > arr(4), brr;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j < 14; j++)
            se.insert({i, j});

    for (int i = 0; i < 4; i++) {
        cin >> arr[i].F >> arr[i].S;
        se.erase(arr[i]);
    }

    vector<vector<pii > > answer(10);

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            if (se.find({i, j}) == se.end())
                continue;
            brr = arr;
            brr.push_back({i, j});
            sort(brr.begin(), brr.end());

            int flag = 1;
            for (int k = 1; k < 5; k++) {
                if (brr[k].F != brr[k - 1].F || brr[k].S - 1 != brr[k - 1].S)
                    flag = 0;
            }
            if (flag)
                answer[0].push_back({i, j});

            map<int, int> m;
            // cout << m.size() << ' ';
            for (int k = 0; k < 5; k++)
                m[brr[k].S]++;
            for (auto k: m)
                if (k.S == 4) answer[1].push_back({i, j});

            int two = 0, three = 0;
            for (auto k: m) {
                if (k.S == 2)
                    two++;
                if (k.S == 3)
                    three++;
            }
            if (two && three)
                answer[2].push_back({i, j});

            flag = 1;
            for (int k = 1; k < 5; k++)
                if (brr[k].F != brr[k - 1].F)
                    flag = 0;
            if (flag)
                answer[3].push_back({i, j});

            sort(brr.begin(), brr.end(), comp);
            flag = 1;
            for (int k = 1; k < 5; k++)
                if (brr[k].S - 1 != brr[k - 1].S)
                    flag = 0;
            if (flag)
                answer[4].push_back({i, j});

            if (three)
                answer[5].push_back({i, j});
            if (two)
                answer[6].push_back({i, j});
        }
    }

    for (int i = 0; i < 10; i++) {
        sort(answer[i].rbegin(), answer[i].rend(), comp);
        for (auto j: answer[i]) {
            cout << j.F << " " << j.S << endl;
            return;
        }
    }
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
