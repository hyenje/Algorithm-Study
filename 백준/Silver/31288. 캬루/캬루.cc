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
    int n, cnt = 0, num = 0;
    int arr[1000] = {};
    string s;

    cin >> n >> s;
    if (n == 1)
    {
        cout << 4 << ' ' << 2 << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
        num += s[i] - '0';

    num %= 3;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (s[i] >= '5')
            s[i] -= num;
        else
            s[i] += 3 - num;
        cout << s << ' ' << 3 << '\n';
        s[i] = c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */