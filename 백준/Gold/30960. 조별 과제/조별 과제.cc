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
    ll n, answer = 0;
    cin >> n;
    vector<ll> arr(n), d(n), dif(n);

    for (auto &i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());

    if (n == 3)
    {
        cout << arr[2] - arr[0] << '\n';
        return;
    }

    for (ll i = 1; i < n; i++)
        d[i] = arr[i] - arr[i - 1];
    dif[1] = d[1];
    for (ll i = 3; i < n; i++)
        dif[i] += d[i] + dif[i - 2];

    // for (auto i : arr)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto i : d)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto i : dif)
    //     cout << i << ' ';
    // cout << '\n';

    answer = dif[n - 1] - dif[2] + arr[2] - arr[0];
    for (ll i = 4; i < n; i += 2)
    {
        // cout << answer << '\n';
        answer = min(answer, dif[i - 3] + arr[i] - arr[i - 2] + dif[n - 1] - dif[i]);
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