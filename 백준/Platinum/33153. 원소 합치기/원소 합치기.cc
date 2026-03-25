/*
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tr<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define rep(i,k,n) for(int i=k;i<n;i++)
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
#define MOD 10'007
#define MID 200'000
#define LM_INF 1'000'000'000'000'000

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll answer = 0;
    ll bit = 32;
    while (bit >= 0) {
        int cnt = 0;
        ll num = answer | (1LL << bit), s = 0;
        for (ll i = 0; i < n; i++) {
            s |= a[i];
            if ((s & num) == num)
                s = 0;
            else
                cnt++;
        }
        bit--;
        if (cnt > k)
            continue;
        answer = num;
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}

/*
 */
