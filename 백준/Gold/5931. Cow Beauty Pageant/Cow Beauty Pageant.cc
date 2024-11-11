/*
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

vector<vector<int>> num(500, vector<int>(500, -1)), arr(500, vector<int>(500, -1));

int n, m;
bool re(int a, int b)
{
    return (a > 0) && (a < n + 1) && (b > 0) && (b < m + 1);
}

int solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i + 1][j + 1] = (c != '.');
            num[i + 1][j + 1] = INF;
        }
    }

    int val = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != 1)
                continue;
            queue<pii> q;
            q.push({i, j});
            arr[i][j] = val++;
            while (q.size())
            {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < n; i++)
                {
                    int nx = x + mx[i], ny = y + my[i];
                    if (!re(nx, ny))
                        continue;
                    if (arr[nx][ny] != 1)
                        continue;
                    q.push({nx, ny});
                    arr[nx][ny] = arr[x][y];
                }
            }
        }
    }

    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 2)
            {
                num[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= m + 1; j++)
    //         cout << num[i][j] << ' ';
    //     cout << '\n';
    // }
    while (q.size())
    {
        int x = q.front().F, y = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i], ny = y + my[i];
            if (!re(nx, ny))
                continue;
            if (arr[nx][ny] == 3)
                return num[x][y];
            if (num[nx][ny] > num[x][y] + 1 && num[nx][ny] != 2)
            {
                num[nx][ny] = num[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    cout << solve();

    return 0;
}
/*
 */