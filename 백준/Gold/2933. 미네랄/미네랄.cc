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

vector<vector<char>> arr(124, vector<char>(124, '.'));

void solve()
{
    int n, m, k, h, flag = 1;
    cin >> n >> m;

    for (int j = 0; j < 124; j++)
        arr[0][j] = '#';
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    cin >> k;

    while (k--)
    {
        cin >> h;
        if (flag)
            for (int i = 0; i < m; i++)
            {
                if (arr[h][i] == 'x')
                {
                    arr[h][i] = '.';
                    break;
                }
            }
        else
            for (int i = m; i >= 0; i--)
            {
                if (arr[h][i] == 'x')
                {
                    arr[h][i] = '.';
                    break;
                }
            }
        flag = !flag;

        queue<pii> q;
        vector<vector<int>> visited(128, vector<int>(128, 0));

        for (int i = 1; i <= m; i++)
            if (arr[1][i] == 'x')
                q.push({1, i});
        while (q.size())
        {
            int x = q.front().F, y = q.front().S;
            q.pop();
            if (visited[x][y])
                continue;
            visited[x][y] = 1;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + mx[i], ny = y + my[i];
                if (arr[nx][ny] == 'x' && !visited[nx][ny])
                    q.push({nx, ny});
            }
        }

        vector<pii> idx;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (arr[i][j] == 'x' && visited[i][j] == 0)
                    idx.push_back({i, j});

        // for (int i = n; i >= 1; i--)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << visited[i][j];
        //     cout << '\n';
        // }

        // vector<vector<char>> tmp(128, vector<char>(128, '.'));

        // for (auto i : idx)
        //     tmp[i.F][i.S] = 'x';

        // for (int i = n; i >= 1; i--)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << tmp[i][j];
        //     cout << '\n';
        // }
        // cout << '\n';

        int find = 0;
        while (!find && idx.size())
        {
            for (int i = 0; i < idx.size(); i++)
            {
                idx[i].F--;
                if (idx[i].F == 1 || visited[idx[i].F - 1][idx[i].S])
                    find = 1;
            }
        }
        for (auto i : idx)
            visited[i.F][i.S] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (visited[i][j])
                    arr[i][j] = 'x';
                else
                    arr[i][j] = '.';
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
            cout << arr[i][j];
        cout << '\n';
    }
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

........
........
.....x..
...xxx..
...xx...
..x.xx..
..x...x.
..xx..x.
6 6 4 3 1
........
........
........
........
.....x..
..xxxx..
..xxx.x.
..xxxxx.
 */