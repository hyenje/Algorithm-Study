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
#define SIZE 100'123
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int arr[30][SIZE];
int depth[SIZE], visited[SIZE];
vector<vector<int>> root(SIZE);

void go(int nd, int len)
{
    depth[nd] = len;
    visited[nd] = 1;
    for (auto i : root[nd])
    {
        if (visited[i])
            continue;
        go(i, len + 1);
        arr[0][i] = nd;
    }
}

int change(int a, int val)
{
    while (val)
    {
        for (int i = 0; i < 30; i++)
        {
            if (val & (1 << i))
            {
                a = arr[i][a];
                val -= 1 << i;
            }
        }
    }
    return a;
}
void solve()
{
    int n, m, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        root[a].push_back(b);
        root[b].push_back(a);
    }
    go(1, 0);
    arr[0][1] = 1;

    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= 30; j++)
    //         cout << arr[j][i] << ' ';
    //     cout << '\n';
    // }
    cin >> m;
    while (m--)
    {
        int answer = -1;
        cin >> a >> b;

        if (depth[a] > depth[b])
            swap(a, b);
        int dif = depth[b] - depth[a], dis = depth[a];
        b = change(b, dif);
        if (b == a)
        {
            cout << a << '\n';
            continue;
        }
        for (int i = 29; i >= 0; i--)
        {
            if (dis >= (1 << i))
            {
                if (arr[i][a] != arr[i][b])
                {
                    dis -= 1 << i;
                    answer = arr[i][a];
                    if (i == 0)
                        break;
                    a = arr[i][a], b = arr[i][b];
                }
            }
        }
        if (answer == -1)
            cout << arr[0][a] << '\n';
        else
            cout << arr[0][answer] << '\n';
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