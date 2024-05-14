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

vector<int> num(100'123), visited(100'123), answer;
vector<vector<int>> ans;
void go(int node)
{
    if (visited[node])
        return;
    visited[node] = 1;
    go(num[node]);
}

void dfs(int node)
{
    if (visited[node])
        return;
    answer.push_back(node);
    visited[node] = 1;
    dfs(num[node]);
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] || num[i] == i)
            continue;
        answer.push_back(i);
        go(i);
    }
    // for (int i = 1; i <= 50; i++)
    //     cout << num[i] << ' ';
    // cout << '\n';
    if (answer.size() > 1)
    {
        ans.push_back(answer);
        int a = num[answer[0]], b;
        for (int i = 0; i < answer.size() - 1; i++)
        {
            b = num[answer[i + 1]];
            num[answer[i + 1]] = a;
            a = b;
        }
        num[answer[0]] = a;
    }
    // for (int i = 1; i <= 50; i++)
    //     cout << num[i] << ' ';
    // cout << '\n';
    answer.clear();
    visited = vector<int>(100'123);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        break;
    }
    if (answer.size() > 1)
        ans.push_back(answer);

    cout << ans.size() << '\n';
    for (auto i : ans)
    {
        cout << i.size() << ": ";
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */