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

string s;
vector<string> arr(10);
set<ll> se;
ll answer = -1;
int n, m;

void go(int a, int b, int r, int d)
{
    if (a >= n || b >= m || b < 0 || a < 0)
    {
        ll a = 0, b = 0, val = 1;
        for (int i = 0; i < s.size(); i++)
        {
            a += val * (ll)(s[i] - '0');
            val *= 10ll;
        }
        val /= 10;
        for (int i = 0; i < s.size(); i++)
        {
            b += val * (ll)(s[i] - '0');
            val /= 10ll;
        }
        // cout << a << ' ' << b << '\n';
        while (a)
        {
            if (se.find(a) != se.end())
                answer = max(answer, a);
            a /= 10;
        }
        while (b)
        {
            if (se.find(b) != se.end())
                answer = max(answer, b);
            b /= 10;
        }
    }
    else
    {
        s.push_back(arr[a][b]);
        go(a + r, b + d, r, d);
        s.pop_back();
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '0')
                answer = 0;
        }
    }

    for (ll i = 0; i < 100000; i++)
        se.insert((i * i));

    for (int i = -n; i <= n; i++)
    {
        for (int j = -m; j <= m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            for (int k = 0; k < n; k++)
                for (int l = 0; l < m; l++)
                    go(k, l, i, j);
        }
    }
    cout << answer;
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