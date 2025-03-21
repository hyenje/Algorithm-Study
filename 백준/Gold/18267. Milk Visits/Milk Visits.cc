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

int p[100'123], visited[100'123];
vector<vector<int>> arr(100'123);
string s;

int find(int a)
{
    if (p[a] == a)
        return a;
    return p[a] = find(p[a]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a > b)
        swap(a, b);
    p[b] = a;
}

void go(int nd)
{
    if (visited[nd])
        return;
    visited[nd] = 1;

    for (auto i : arr[nd])
    {
        if (s[nd] == s[i])
        {
            unite(nd, i);
            go(i);
        }
    }
}

void solve()
{
    int n, m, a, b;
    char c;
    cin >> n >> m;
    cin >> s;
    s = " " + s + " ";

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        go(i);

    while (m--)
    {
        cin >> a >> b >> c;
        if (find(a) == find(b))
            cout << (c == s[a]);
        else
            cout << 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    iota(p, p + 100'123, 0);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*

 */