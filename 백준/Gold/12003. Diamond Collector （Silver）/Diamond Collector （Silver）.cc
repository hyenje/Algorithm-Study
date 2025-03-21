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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    ll n, k, answer = 0;
    cin >> n >> k;

    vector<ll> arr(n), cnt(n + 1), big(n + 1);

    for (auto &i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        cnt[i] = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - i;

    big[n - 1] = cnt[n - 1];
    for (int i = n - 2; i >= 0; i--)
        big[i] = max(cnt[i], big[i + 1]);

    for (int i = 0; i < n; i++)
        answer = max(answer, cnt[i] + big[i + cnt[i]]);

    // for (auto i : cnt)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto i : big)
    //     cout << i << ' ';
    // cout << '\n';

    cout << answer << '\n';
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