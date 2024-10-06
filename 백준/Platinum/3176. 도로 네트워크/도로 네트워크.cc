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

vector<vector<int>> mini(20, vector<int>((SIZE), INF)), maxi(20, vector<int>((SIZE), 0));
vector<vector<int>> parent(20, vector<int>(SIZE));
vector<vector<pii>> arr(SIZE);
int depth[SIZE];

void go(int pa, int nd, int d)
{
    parent[0][nd] = pa;
    depth[nd] = d;

    for (auto i : arr[nd])
    {
        if (i.F == pa)
        {
            mini[0][nd] = i.S;
            maxi[0][nd] = i.S;
        }
        else
            go(nd, i.F, d + 1);
    }
}

void find(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);
    int dif = depth[b] - depth[a];
    int mina = INF, maxa = 0;
    for (int i = 0; i < 20; i++)
    {
        if (dif & (1 << i))
        {
            mina = min(mina, mini[i][b]);
            maxa = max(maxa, maxi[i][b]);
            b = parent[i][b];
        }
    }

    // cout << ": " << mina << ' ' << maxa << " : ";
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (parent[i][a] && parent[i][a] != parent[i][b])
            {
                mina = min(mina, min(mini[i][b], mini[i][a]));
                maxa = max(maxa, max(maxi[i][b], maxi[i][a]));
                a = parent[i][a], b = parent[i][b];
            }
        }
        maxa = max(maxa, max(maxi[0][b], maxi[0][a]));
        mina = min(mina, min(mini[0][b], mini[0][a]));
    }
    cout << mina << ' ' << maxa << '\n';
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

    go(0, 1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << i << ' ';
    // cout << '\n';

    // for (int i = 1; i <= n; i++)
    //     cout << depth[i] << ' ';
    // cout << '\n'
    //      << endl;

    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[k - 1][i])
            {
                parent[k][i] = parent[k - 1][parent[k - 1][i]];
                mini[k][i] = min(mini[k - 1][i], mini[k - 1][parent[k - 1][i]]);
                maxi[k][i] = max(maxi[k - 1][i], maxi[k - 1][parent[k - 1][i]]);
            }
        }
    }

    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        find(a, b);
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