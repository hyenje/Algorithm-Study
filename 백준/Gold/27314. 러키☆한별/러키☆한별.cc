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
    int n, m, answer = 0;
    pii start, player;

    cin >> n >> m;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 1)), visited;
    vector<pii> xy;
    queue<pii> a, q;
    string s;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == '.')
                arr[i][j] = 0;
            else if (s[j - 1] == 'P')
            {
                arr[i][j] = 0;
                xy.push_back({i, j});
            }
            else if (s[j - 1] == 'H')
            {
                arr[i][j] = 0;
                player.F = i;
                player.S = j;
            }
            else if (s[j - 1] == '#')
            {
                arr[i][j] = 0;
                a.push({i, j});
            }
        }
    }

    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= m + 1; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }

    while (!a.empty())
    {
        visited = vector<vector<int>>(n + 2, vector<int>(m + 2, INF));
        int tmp = 0;

        q.push(a.front());
        visited[a.front().F][a.front().S] = 1;
        // cout << a.front().F << ' ' << a.front().S << '\n';
        a.pop();
        while (!q.empty())
        {
            int x = q.front().F, y = q.front().S;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + mx[i], ny = y + my[i];
                if (arr[nx][ny] || visited[nx][ny] != INF)
                    continue;
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
        for (auto i : xy)
        {
            if (visited[player.F][player.S] >= visited[i.F][i.S] && visited[player.F][player.S] != INF)
                tmp++;
        }
        // cout << visited[player.F][player.S] << ' ' << tmp << '\n';
        answer = max(answer, tmp);
    }

    cout << answer << '\n';
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