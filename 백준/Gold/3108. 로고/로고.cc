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

int p[1'024];
vector<vector<int>> arr(1024, vector<int>(4));

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
bool meet(int i, int j)
{
    vector<int> a = arr[i];
    vector<int> b = arr[j];
    if (b[3] > a[3] && a[2] < b[2] && a[1] > b[1] && b[0] < a[0])
        return false;
    if (a[3] > b[3] && b[2] < a[2] && b[1] > a[1] && b[0] > a[0])
        return false;
    if (b[1] > a[3] || b[0] > a[2] || a[1] > b[3] || b[2] < a[0])
        return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (meet(i, j))
                unite(i, j);

    set<int> s;
    for (int i = 0; i <= n; i++)
        s.insert(find(p[i]));
    cout << s.size() - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    for (int i = 0; i < 1'024; i++)
        p[i] = i;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */