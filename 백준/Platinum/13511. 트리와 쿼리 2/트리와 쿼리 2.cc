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

vector<vector<pll>> arr(100'123);
int depth[100'123];
ll dist[20][100'123], parent[20][100'123];

void go(int pa, int nd, int dep, int dis)
{
    parent[0][nd] = pa;
    depth[nd] = dep;
    dist[0][nd] = dis;

    for (auto i : arr[nd])
        if (i.F != pa)
            go(nd, i.F, dep + 1, i.S);
}

ll find_dis(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);
    int dif = depth[b] - depth[a];
    ll answer = 0;
    for (int i = 0; i < 20; i++)
    {
        if (dif & (1 << i))
        {
            answer += dist[i][b];
            b = parent[i][b];
        }
    }
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (parent[i][a] && parent[i][a] != parent[i][b])
            {
                answer += dist[i][a] + dist[i][b];
                a = parent[i][a], b = parent[i][b];
            }
        }
        answer += dist[0][a] + dist[0][b];
    }
    return answer;
}

int find_nd(int q, int r, int k)
{
    int a = q, b = r, mid, answer;
    if (a == b || k == 0)
        return a;
    if (depth[a] > depth[b])
        swap(a, b);
    int dif = depth[b] - depth[a];
    for (int i = 0; i < 20; i++)
        if (parent[i][b] && (dif & (1 << i)))
            b = parent[i][b];
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
            if (parent[i][a] && parent[i][a] != parent[i][b])
                a = parent[i][a], b = parent[i][b];
        mid = parent[0][a];
    }
    else
        mid = a;
    // cout << mid << ' ';
    a = q, b = r, k--;
    int s = depth[a] - depth[mid], e = depth[b] - depth[mid];
    // cout << k << ' ' << s << ' ' << e << ' ' << a << ' ' << b << ' ';
    if (k <= s)
    {
        answer = a;
        for (int i = 19; i >= 0; i--)
        {
            if (k & (1 << i))
                answer = parent[i][answer];
        }
    }
    else
    {
        answer = b;
        e -= k - s;
        for (int i = 19; i >= 0; i--)
            if (e & (1 << i))
                answer = parent[i][answer];
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
        for (int j = 1; j <= n; j++)
            if (parent[i - 1][j])
            {
                dist[i][j] = dist[i - 1][j] + dist[i - 1][parent[i - 1][j]];
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }

    cin >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 1)
            cout << find_dis(b, c) << '\n';
        else
        {
            cin >> a;
            cout << find_nd(b, c, a) << '\n';
        }
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