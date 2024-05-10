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

vector<ll> arr;

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;

    ll num = 0, answer = 0;
    for (int i = 0; i < n; i++)
        num = max(0ll, arr[i] - 1 + num);
    for (int i = 0; i < n; i++)
    {
        if (num == 0)
            break;
        num = max(0ll, arr[0] - 1 + num);
        rotate(arr.begin(), arr.begin() + 1, arr.end());
    }
    for (int i = 0; i < n; i++)
    {
        answer += (arr[i] + num - 1) * (arr[i] + num) * ((arr[i] + num - 1) * 2 + 1) / 6 - (num - 1) * num * (num * 2 - 1) / 6;
        num = max(0ll, arr[i] - 1 + num);
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