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

int p[20][40'123], depth[40'123], dis[20][40'123];
vector<vector<pii>> arr(40'123);

void go(int pa, int nd, int dep, int dist)
{
    p[0][nd] = pa;
    depth[nd] = dep;
    dis[0][nd] = dist;

    for (auto i : arr[nd])
        if (i.F != pa)
            go(nd, i.F, dep + 1, i.S);
}

int find(int a, int b)
{
    int answer = 0;
    if (depth[a] > depth[b])
        swap(a, b);
    int dif = depth[b] - depth[a];
    for (int i = 0; i < 20; i++)
    {
        if (dif & (1 << i))
        {
            dif -= (1 << i);
            answer += dis[i][b];
            b = p[i][b];
        }
    }
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (p[i][a] && p[i][a] != p[i][b])
            {
                answer += dis[i][a] + dis[i][b];
                a = p[i][a], b = p[i][b];
                // cout << answer << ' ';
            }
        }
        answer += dis[0][a] + dis[0][b];
    }
    return answer;
}

void solve()
{
    int n, m, a, b, c;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    go(0, 1, 0, 0);

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i - 1][j])
            {
                p[i][j] = p[i - 1][p[i - 1][j]];
                dis[i][j] = dis[i - 1][j] + dis[i - 1][p[i - 1][j]];
            }
        }
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     for (int j = 0; j < 20; j++)
    //         cout << p[i][j] << ' ';
    //     cout << '\n';
    // }
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        cout << find(a, b) << '\n';
    }
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