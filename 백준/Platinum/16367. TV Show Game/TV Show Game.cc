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
#define MID 5'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<int>> arr(10'123);
int parent[10'123], unite[10'123], id = 1, num = 1;
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

void solve()
{
    int n, m, a, b, c;
    char a1, b1, c1;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> a1 >> b >> b1 >> c >> c1;
        a = (a1 == 'R') ? a : -a;
        b = (b1 == 'R') ? b : -b;
        c = (c1 == 'R') ? c : -c;
        arr[MID - a].push_back(MID + b);
        arr[MID - b].push_back(MID + a);
        arr[MID - c].push_back(MID + b);
        arr[MID - b].push_back(MID + c);
        arr[MID - a].push_back(MID + c);
        arr[MID - c].push_back(MID + a);
    }

    for (int i = MID + 1; i <= MID + n; i++)
        if (!parent[i])
            go(i);
    for (int i = MID - n; i < MID; i++)
        if (!parent[i])
            go(i);
    int flag = 1;
    for (int i = MID + 1; i <= MID + n; i++)
        if (unite[i] == unite[(MID << 1) - i])
            flag = -1;

    if (flag == 1)
        for (int i = MID + 1; i <= MID + n; i++)
            cout << ((unite[i] < unite[(MID << 1) - i]) ? 'R' : 'B');
    else
        cout << flag << '\n';
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