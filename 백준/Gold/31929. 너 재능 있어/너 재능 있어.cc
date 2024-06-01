#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define INF 2'147'483'647
#define MINF -1'000'000'000
#define pii pair<int, int>
int mx[9] = {1, -1, 0, 0, 1, 1, -1, -1};
int my[9] = {0, 0, 1, -1, 1, -1, 1, -1};

queue<pii> p;
vector<ll> win(2048), lose(2048);
vector<vector<ll>> arr(2048, vector<ll>(2048, MINF));

void solve()
{
    ll n, m, k, tmp;
    cin >> n;

    for (ll i = 0; i < n; i++)
        cin >> win[i];

    cin >> m;
    for (ll i = 0; i < m; i++)
        cin >> lose[i];
    cin >> k;

    p.push({0, 0});
    arr[0][0] = 0;

    while (!p.empty())
    {
        pii tmp = p.front();
        ll x = tmp.F, y = tmp.S;

        p.pop();
        if (x >= n + 2 || y >= m + 2)
            break;
        if (x + 1 <= n && arr[x + 1][y] < arr[x][y] + win[x])
        {
            arr[x + 1][y] = arr[x][y] + win[x];
            p.push({x + 1, y});
        }

        if (arr[x][y] % k == 0 && y + 1 <= m && arr[x][y + 1] < arr[x][y] - min(lose[y], k))
        {
            arr[x][y + 1] = arr[x][y] - min(lose[y], k);
            p.push({x, y + 1});
        }
        else if (arr[x][y] < 0 && y + 1 <= m && arr[x][y + 1] < arr[x][y] - min(lose[y], k - ((-arr[x][y]) % k)))
        {
            arr[x][y + 1] = arr[x][y] - min(lose[y], k - ((-arr[x][y]) % k));
            p.push({x, y + 1});
        }
        else if (arr[x][y] > 0 && y + 1 <= m && arr[x][y + 1] < arr[x][y] - min(lose[y], arr[x][y] % k))
        {
            arr[x][y + 1] = arr[x][y] - min(lose[y], arr[x][y] % k);
            p.push({x, y + 1});
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << arr[n][m];
}
int main()
{
    solve();
    return 0;
}

/*
 */