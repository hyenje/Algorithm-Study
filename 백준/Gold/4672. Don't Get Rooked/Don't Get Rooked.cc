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

int n;
vector<vector<int>> arr;
int visited[10][10], vis[10][10];
int traverse(int x, int y)
{
    int l = 1, r = 1, u = 1, d = 1;
    for (int i = 1; i < n; i++)
    {
        if (l)
        {
            if (arr[x - i][y] == 2)
                l = 0;
            else if (arr[x - i][y] == 1)
                return 1;
        }
        if (r)
        {
            if (arr[x + i][y] == 2)
                r = 0;
            else if (arr[x + i][y] == 1)
                return 1;
        }
        if (u)
        {
            if (arr[x][y - i] == 2)
                u = 0;
            else if (arr[x][y - i] == 1)
                return 1;
        }
        if (d)
        {
            if (arr[x][y + i] == 2)
                d = 0;
            else if (arr[x][y + i] == 1)
                return 1;
        }
    }

    return 0;
}

int go(int x, int y, int cnt)
{
    if (x == 0 || x > n || y == 0 || y > n || arr[x][y] == 2 || visited[x][y])
        return cnt;
    visited[x][y] = 1;
    vis[x][y] = 1;

    int answer = 0;
    if (traverse(x, y) == 0)
    {
        arr[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i], ny = y + my[i];
            answer = max(answer, go(nx, ny, cnt + 1));
        }
        arr[x][y] = 0;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + mx[i], ny = y + my[i];
        answer = max(answer, go(nx, ny, cnt));
    }
    visited[x][y] = 0;

    return answer;
}

int solve()
{
    if (n == 0)
        return 1;

    arr = vector<vector<int>>(n + 2, vector<int>(n + 2, 2));
    int answer = 0, val = 0;
    string S;

    for (int i = 1; i <= n; i++)
    {
        cin >> S;
        for (int j = 0; j < n; j++)
            if (S[j] == '.')
                arr[i][j + 1] = 0;
    }

    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= n + 1; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j])
                answer += go(i, j, 0);
        }
        // cout << answer << ' ';
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            vis[i][j] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j])
                val += go(i, j, 0);
        }
        // cout << answer << ' ';
    }
    cout << max(answer, val) << '\n';

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    while (true)
    {
        cin >> n;
        if (solve())
            break;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                vis[i][j] = 0;
    }

    return 0;
}
/*
 */