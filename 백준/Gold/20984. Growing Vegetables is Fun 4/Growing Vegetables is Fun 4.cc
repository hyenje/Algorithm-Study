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
    int n;
    ll answer = LL_INF;
    cin >> n;
    vector<ll> arr(n), l(n), r(n);
    for (auto &i : arr)
        cin >> i;

    for (int i = 1; i < n; i++)
        l[i] = l[i - 1] + max(arr[i - 1] - arr[i] + 1, 0ll);
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] + max(arr[i + 1] - arr[i] + 1, 0ll);

    for (int i = 0; i < n; i++)
        answer = min(answer, max(l[i], r[i]));
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