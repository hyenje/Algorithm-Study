/*
 */
#include <bits/stdc++.h>
using namespace std;
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

vector<vector<int>> arr(20'123);
vector<int> cl(20'123), visited(20'123);
int flag = 0;

void go(int in)
{
    if (visited[in] || flag)
        return;
    visited[in] = 1;

    for (auto &i : arr[in])
    {
        if (cl[i] == cl[in])
            flag = 1;
        cl[i] = -cl[in];
    }
    for (auto &i : arr[in])
        go(i);
}

void solve()
{
    int v, e;
    cin >> v >> e;

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
    {
        if (cl[i] == 0)
            cl[i] = 1;
        go(i);
    }

    if (flag)
        cout << "NO\n";
    else
        cout << "YES\n";

    flag = 0;
    for (int i = 0; i < 20'123; i++)
    {
        cl[i] = visited[i] = 0;
        arr[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */