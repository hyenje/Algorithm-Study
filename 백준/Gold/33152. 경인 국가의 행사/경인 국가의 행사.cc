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

void solve()
{
    int n;
    ll s = 0, h = 0;
    cin >> n;
    vector<pll> arr(n);
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        arr[i].S = i;
    for (auto &i : arr)
        cin >> i.F;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        // cout << arr[i].F << ' ';
        if (i <= n / 2)
        {
            a[arr[i].S] += arr[i].F / 2;
            b[arr[i].S] += arr[i].F / 2 + 1;
            if (arr[i].F % 2 == 0 && arr[i].F > 1)
                a[arr[i].S]--;
        }
        else
            a[arr[i].S] += arr[i].F;
        s += a[arr[i].S];
        h += b[arr[i].S];
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i <= n / 2; i++)
        {
            if (arr[i].F % 2 == 0)
            {
                a[arr[i].S] = arr[i].F / 2;
                b[arr[i].S] = arr[i].F / 2;
                s++;
                h--;
                break;
            }
        }
    }
    if (s > h)
    {
        cout << "YES\n";
        for (auto i : a)
            cout << i << ' ';
        cout << '\n';
        for (auto i : b)
            cout << i << ' ';
        cout << '\n';
    }
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */