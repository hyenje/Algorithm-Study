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
#define MID 200'000
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int solve()
{
    int n, m, answer = 0;
    cin >> m >> n;
    if (n == 0 && m == 0)
        return 0;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 0)), visited(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] || arr[i][j] == 0)
                continue;
            answer++;
            queue<pii> q;
            q.push({i, j});
            while (q.size())
            {
                int x = q.front().F, y = q.front().S;
                q.pop();

                if (visited[x][y] || arr[x][y] == 0)
                    continue;
                visited[x][y] = 1;

                for (int k = 0; k < 8; k++)
                {
                    int nx = x + mx[k], ny = y + my[k];
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << answer << '\n';

    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    while (solve())
        ;

    return 0;
}
/*

*/