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

vector<vector<int>> arr(20, vector<int>(20, 0));
int v[20][20] = {};
int go[100];

void paint(int x, int y, int num)
{
    queue<pii> q;
    q.push({x, y});
    int visited[20][20] = {};
    arr[x][y] = num;
    while (q.size())
    {
        auto [a, b] = q.front();
        q.pop();
        visited[a][b] = 1;
        v[a][b] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = a + mx[i], ny = b + my[i];
            if (visited[nx][ny] || arr[nx][ny] == -1 || arr[nx][ny] == 0)
                continue;
            arr[nx][ny] = num;
            q.push({nx, ny});
        }
    }
}

int find(int i)
{
    if (go[i] == i)
        return i;
    return go[i] = find(go[i]);
}

int unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return 1;
    if (a > b)
        swap(a, b);
    go[b] = a;
    return 0;
}

void solve()
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int n, m, num = 1, answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!v[i][j] && arr[i][j] == 1)
                paint(i, j, num++);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int be = 0, by = 0, d;
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] >= 1)
            {
                if (be > 0 && be != arr[i][j])
                {
                    d = j - by - 1;
                    if (d > 1)
                        pq.push({d, {be, arr[i][j]}});
                }
                be = arr[i][j];
                by = j;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int be = 0, by = 0, d;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j][i])
            {
                if (be > 0 && be != arr[j][i])
                {
                    d = j - by - 1;
                    if (d > 1)
                        pq.push({d, {be, arr[j][i]}});
                }
                be = arr[j][i];
                by = j;
            }
        }
    }
    for (int i = 0; i <= num; i++)
        go[i] = i;
    int cnt = 0;
    while (pq.size())
    {
        auto [a, b] = pq.top();
        pq.pop();
        if (unite(b.F, b.S))
            continue;
        answer += a;
        cnt++;
        // cout << b.F << ' ' << b.S << ' ' << a << ' ' << answer << '\n';
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << "\n";
    // }
    // cout << cnt << ' ';
    if (answer == 0 || cnt < num - 2)
        cout << -1 << '\n';
    else
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