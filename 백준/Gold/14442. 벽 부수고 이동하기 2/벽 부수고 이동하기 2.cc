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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<char>> arr(1024, vector<char>(1024, '#'));
vector<vector<vector<int>>> brr(11, vector<vector<int>>(1024, vector<int>(1024, INF)));

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    queue<vector<int>> q;
    q.push({1, 1, k, 1});
    brr[k][1][1] = 1;

    while (q.size())
    {
        vector<int> t = q.front();
        q.pop();
        int x = t[0], y = t[1], K = t[2], num = t[3];
        if (num > brr[K][x][y])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i], ny = y + my[i];
            if (arr[nx][ny] == '#' || (K == 0 && arr[nx][ny] == '1'))
                continue;

            if (arr[nx][ny] == '1' && brr[K - 1][nx][ny] > num + 1)
            {
                q.push({nx, ny, K - 1, num + 1});
                brr[K - 1][nx][ny] = num + 1;
            }
            else if (arr[nx][ny] == '0' && brr[K][nx][ny] > num + 1)
            {
                q.push({nx, ny, K, num + 1});
                brr[K][nx][ny] = num + 1;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << brr[0][i][j] << ' ';
    //     cout << '\n';
    // }
    int answer = INF;

    for (int i = 0; i <= k; i++)
        answer = min(answer, brr[i][n][m]);
    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */