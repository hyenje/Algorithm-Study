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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int compare(pii a, pii b)
{
    return a.S > b.S;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pii> arr(n), brr;
    for (auto &i : arr)
        cin >> i.F >> i.S;
    brr = arr;
    sort(arr.rbegin(), arr.rend());
    sort(brr.begin(), brr.end(), compare);
    // for (auto i : arr)
    //     cout << i.F << ' ' << i.S << '\n';
    // cout << '\n';
    // for (auto i : brr)
    //     cout << i.F << ' ' << i.S << '\n';
    // cout << '\n';

    map<pii, int> ma;
    ll cnt = 0, answer = 0;
    for (int i = 0; i < k; i++)
    {
        ma[brr[i]] = 1;
        answer += brr[i].F;
    }
    // cout << answer << '\n';
    for (int i = 0; i < n; i++)
    {
        if (ma[arr[i]] == 0 && cnt < m)
        {
            answer += arr[i].F;
            cnt++;
        }
    }

    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
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