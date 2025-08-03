//
// Created by 신현재 on 25. 8. 3.
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

ll value;

bool safe_lcm(xll a, xll b, xll n) {
    xll g = gcd(a, b);
    if (a > n / (b / g)) return false;
    value = a * (b / g);
    return true;
}

void solve() {
    ll n, m, val, answer = 0;
    cin >> n >> m;
    vector<ll> arr(m);
    for (ll i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<ll> number;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) continue;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] % arr[i] == 0)
                arr[j] = 0;
        }
    }

    for (ll i = 0; i < arr.size(); i++)
        if (arr[i])
            number.push_back(arr[i]);

    for (ll i = 1; i < (1 << number.size()); i++) {
        value = 1;
        ll cnt = 0;
        bool ok = 1;
        for (int j = 0; j < number.size(); j++) {
            if ((i & (1 << j))) {
                cnt++;
                if (!safe_lcm(value, number[j], n))
                    ok = false;
            }
        }

        if (ok == 0)
            continue;
        answer += (n / value) * (cnt % 2 ? 1 : -1);
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
