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

char arr[1502][1502];
int day[1502][1502], visited[1502][1502];
queue<pii> node;

void solve()
{
    int n, m, num = 0;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++)
    {
        arr[i][0] = arr[i][m + 1] = '#';
        day[i][0] = day[i][m + 1] = INF;
    }
    for (int j = 0; j <= m + 1; j++)
    {
        arr[0][j] = arr[n + 1][j] = '#';
        day[0][j] = day[n + 1][j] = INF;
    }

    vector<pii> swan;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#' || arr[i][j] == 'X')
                continue;

            if (arr[i][j] == 'L')
                swan.push_back({i, j});
            node.push({i, j});
        }
    }

    while (node.size())
    {
        num++;
        int sz = node.size();
        while (sz--)
        {
            int x = node.front().F, y = node.front().S;
            node.pop();
            if (day[x][y])
                continue;
            day[x][y] = num;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + mx[i], ny = y + my[i];
                if (arr[nx][ny] == 'X')
                    node.push({nx, ny});
            }
        }
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < m + 1; j++)
    //         cout << day[i][j];
    //     cout << '\n';
    // }

    int answer = 1, cnt = 0;
    node.push(swan[0]);
    while (true)
    {
        queue<pii> q;
        while (node.size())
        {
            int x = node.front().F, y = node.front().S;
            node.pop();
            if (visited[x][y])
                continue;
            visited[x][y] = 1;
            if (arr[x][y] == 'L')
            {
                cnt++;
                // cout << x << ' ' << y << '\n';
            }
            if (cnt == 2)
                break;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + mx[i], ny = y + my[i];
                if (answer + 1 == day[nx][ny])
                    q.push({nx, ny});
                else if (answer >= day[nx][ny])
                    node.push({nx, ny});
            }
        }

        while (q.size())
        {
            node.push(q.front());
            q.pop();
        }

        if (cnt == 2)
            break;
        answer++;
    }
    cout << answer - 1 << '\n';
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