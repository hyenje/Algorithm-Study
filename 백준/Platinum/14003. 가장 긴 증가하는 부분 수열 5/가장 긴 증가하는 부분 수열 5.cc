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

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n), dp, indice(n);
    for (auto &i : arr)
        cin >> i;

    dp.push_back(arr[0]);
    indice[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (idx == dp.size())
            dp.push_back(arr[i]);
        else
            dp[idx] = arr[i];
        indice[i] = idx;
    }

    int sz = dp.size();
    dp.clear();
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (sz - 1 == indice[i])
        {
            dp.push_back(arr[i]);
            sz--;
        }
    }
    cout << dp.size() << '\n';
    for (int i = dp.size() - 1; i >= 0; i--)
        cout << dp[i] << ' ';
}

int main()
{
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