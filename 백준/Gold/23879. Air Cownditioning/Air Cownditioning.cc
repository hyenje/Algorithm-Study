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

ll answer = 0;

void solve()
{
    vector<int> arr;
    int n, val;
    ll cnt = 0;

    cin >> n;

    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    arr.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        arr[i] -= val;
    }

    for (int i = 0; i <= n; i++)
        answer += max(arr[i] - arr[i + 1], arr[i + 1] - arr[i]);

    cout << answer / 2 << '\n';
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