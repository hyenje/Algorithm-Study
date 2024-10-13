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
#define MID 50'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<int>> arr(100'123);
int parent[100'123], unite[100'123], id = 1, num = 1;
int n, m, a, b;
stack<int> s;

int go(int nd)
{
    int p = parent[nd] = id++;
    s.push(nd);

    for (auto i : arr[nd])
    {
        if (!parent[i])
            p = min(p, go(i));
        else if (!unite[i])
            p = min(p, parent[i]);
    }

    if (parent[nd] == p)
    {
        int node;
        do
        {
            node = s.top();
            s.pop();
            unite[node] = num;
        } while (nd != node);
        num++;
    }
    return p;
}
int Neg(int a) { return a > n ? a - n : a + n; }

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        if (a < 0)
            a = -a + n;
        if (b < 0)
            b = -b + n;
        arr[Neg(a)].push_back(b);
        arr[Neg(b)].push_back(a);
    }

    for (int i = 1; i <= n * 2; i++)
        if (!parent[i])
            go(i);

    int flag = 1;
    for (int i = 1; i <= n * 2; i++)
        if (unite[i] == unite[i + n])
            flag = 0;

    cout << flag << '\n';
    if (flag)
        for (int i = 1; i <= n; i++)
            cout << (unite[i] < unite[i + n]) << ' ';
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