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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

ll t[300'123];
vector<ll> arr;

void solve()
{
    int n;
    ll mi = 0, pl = 0;

    cin >> n;
    arr.resize(n);
    t[0] = 1;
    for (int i = 1; i < 300'123; i++)
        t[i] = (t[i - 1] << 1) % MOD;

    for (auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {

        if (i != n - 1)
            mi = (mi + arr[i] * (t[n - i - 1] - 1)) % (ll)MOD;
        if (i != 0)
            pl = (pl + arr[i] * (t[i] - 1)) % (ll)MOD;
        // cout << pl << ' ' << mi << '\n';
    }
    if (pl < mi)
        pl += (ll)MOD;
    cout << pl - mi << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */