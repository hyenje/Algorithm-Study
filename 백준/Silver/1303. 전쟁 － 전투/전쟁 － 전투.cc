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

char arr[128][128];
vector<vector<int>> visited(128, vector<int>(128, 1));
ll answer[2] = {0};

ll go(ll x, ll y)
{
    ll cnt = 0;
    queue<pii> q;
    q.push({x, y});

    while (!q.empty())
    {
        ll a = q.front().F, b = q.front().S;
        q.pop();
        if (visited[a][b])
            continue;
        // cout << a << ' ' << b << '\n';
        visited[a][b] = 1;
        cnt++;

        for (ll i = 0; i < 4; i++)
        {
            ll nx = a + mx[i], ny = b + my[i];
            if (arr[nx][ny] != arr[a][b])
                continue;
            q.push({nx, ny});
        }
    }
    // cout << cnt << '\n';
    return cnt * cnt;
}

void solve()
{
    ll n, m, state;
    string s;
    cin >> m >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s;
        for (ll j = 0; j < m; j++)
        {
            arr[i][j + 1] = s[j];
            visited[i][j + 1] = 0;
        }
    }

    queue<pii> q;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (visited[i][j])
                continue;
            // cout << arr[i][j] << '\n';
            if (arr[i][j] == 'W')
                state = 0;
            else
                state = 1;
            answer[state] += go(i, j);
        }
    }

    cout << answer[0] << ' ' << answer[1] << '\n';
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