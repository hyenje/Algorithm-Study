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
#define MOD 998'244'353
#define MID 200'000
#define LM_INF 1'000'000'000'000'000

const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int solve() {
    ll a, p, mod, val, answer = 1;
    cin >> p >> a;
    if (p == 0 && a == 0)return 0;

    mod = p;
    val = a;

    // cout << a << ' ' << p;


    int flag = 1;
    for (ll i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            flag = 0;
            break;
        }
    }
    while (p) {
        if (p & 1)
            answer = (val * answer) % mod;
        val = (val * val) % mod;
        p >>= 1;
    }
    // cout << ' ' << answer << ' ' << a << " ";

    if (answer == a && flag == 0)
        cout << "yes\n";
    else
        cout << "no\n";

    return 1;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // int t;
    // std::cin >> t;
    while (solve()) {
    }

    return 0;
}
