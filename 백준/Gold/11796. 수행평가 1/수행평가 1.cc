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

ll POW(ll val, ll para)
{
    if (para == 0)
        return 1;
    ll a = val, b = 1;

    while (para)
    {
        if (para & 1)
            b = (b * a) % MOD;
        a = (a * a) % MOD;
        para >>= 1;
    }

    return b % MOD;
}

void solve()
{
    ll n, k, val, answer = 0, number = 0;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n + 1 << ' ' << 1 << '\n';
        return;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 1, r = min(40ll, n);

    while (l < r)
    {
        int mid = l + r >> 1;
        deque<int> d;
        set<deque<int>> s;
        ll val = (ll)POW(k, mid);
        for (auto i : arr)
        {
            if (d.size() == mid)
                d.pop_front();
            d.push_back(i);
            if (d.size() == mid)
                s.insert(d);
        }

        if (s.size() < val)
        {
            r = mid;
            answer = mid;
            number = (val + MOD - s.size()) % MOD;
            // for (auto i : s)
            // {
            //     for (auto j : i)
            //         cout << j << ' ';
            //     cout << '\n';
            // }
            // cout << '\n';
        }
        else
            l = mid + 1;
    }

    cout << answer << ' ' << number << '\n';
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