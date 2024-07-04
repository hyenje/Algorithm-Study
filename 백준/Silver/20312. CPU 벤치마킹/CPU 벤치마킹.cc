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
#define MOD 1'000'000'007
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    int n;
    ll answer = 0, val;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        answer = (answer + (arr[i - 1] + 1) * val) % (ll)MOD;
        arr[i] = (arr[i - 1] * val + val) % (ll)MOD;
        // cout << answer << ' ' << arr[i] << '\n';
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