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

void solve() {
    ll n, m, answer = 0, t = 0, val, num = 0;
    cin >> n >> m;
    vector<pll > arr(n);
    string s;

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].F >> s;

        answer += arr[i].F;
        if (arr[i].F == 0)
            arr[i].S = 1ll, num++;
        else if (arr[i].F == m)
            arr[i].S = 0ll, num--;
        else if (s == "U")
            arr[i].S = 1, num++;
        else
            arr[i].S = 0, num--;


        if (arr[i].S == 1) {
            mp[m - arr[i].F]--;
            mp[(2 * m) - arr[i].F]++;
        } else {
            mp[arr[i].F]++;
            mp[arr[i].F + m]--;
        }
    }
    val = answer;

    // cout << num << ' ' << val << '\n';

    for (auto i: mp) {
        val += num * (i.F - t);
        // cout << i.F << ' ' << i.S << ' ' << num << ' ' << val << '\n';
        num += i.S * 2;
        t = i.F;
        answer = max(answer, val);
    }

    cout << answer << endl;
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
