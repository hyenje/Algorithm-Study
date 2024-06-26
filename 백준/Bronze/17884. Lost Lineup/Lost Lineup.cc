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
    cin >> n;
    vector<pii> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i].F;
        arr[i].S = i + 2;
    }

    // for (auto i : arr)
    //     cout << i.F << ' ' << i.S << '\n';
    sort(arr.begin(), arr.end());

    cout << 1 << ' ';
    for (auto i : arr)
        cout << i.S << ' ';
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