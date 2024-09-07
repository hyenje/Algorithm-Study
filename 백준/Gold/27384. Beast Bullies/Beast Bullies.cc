/*
 */
#include <bits/stdc++.h>
using namespace std;
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
    ll n, val = 0, idx, att;
    cin >> n;
    vector<ll> arr(n + 1), sum(n + 2);

    for (size_t i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    for (int i = n; i; i--)
        sum[i] = sum[i + 1] + arr[i];
    sum[0] = 0;
    idx = n;
    int cnt = 0;
    while (idx > 0)
    {
        // if (cnt++ == 100)
        //     break;
        int tmp = upper_bound(sum.begin(), sum.end(), sum[idx] * 2, greater<ll>()) - sum.begin();
        if (tmp == 0)
            break;
        idx = tmp - 1;
        // cout << idx << ' ';
    }

    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << sum[i] << ' ';
    // cout << endl
    //      << idx << '\n';

    cout << n - idx + 1;
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