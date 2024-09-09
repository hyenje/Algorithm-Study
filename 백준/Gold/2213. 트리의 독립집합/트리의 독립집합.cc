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

vector<int> arr(10'123), visited(10'123);
vector<vector<int>> t(10'123), dp(10'123, vector<int>(2, 0));

vector<vector<int>> go(int node)
{
    vector<vector<int>> v(2);
    visited[node] = 1;
    dp[node][1] = arr[node];

    for (auto i : t[node])
    {
        if (visited[i])
            continue;
        vector<vector<int>> tmp = go(i);
        if (dp[i][0] > dp[i][1])
            for (int j = 0; j < tmp[0].size(); j++)
                v[0].push_back(tmp[0][j]);
        else
            for (int j = 0; j < tmp[1].size(); j++)
                v[0].push_back(tmp[1][j]);
        for (int j = 0; j < tmp[0].size(); j++)
            v[1].push_back(tmp[0][j]);
        dp[node][0] += max(dp[i][0], dp[i][1]);
        dp[node][1] += dp[i][0];
    }

    v[1].push_back(node);
    return v;
}

void solve()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    vector<vector<int>> answer = go(1);
    sort(answer[0].begin(), answer[0].end());
    sort(answer[1].begin(), answer[1].end());

    cout << max(dp[1][0], dp[1][1]) << '\n';
    if (dp[1][0] > dp[1][1])
        for (int i = 0; i < answer[0].size(); i++)
            cout << answer[0][i] << ' ';
    else
        for (int i = 0; i < answer[1].size(); i++)
            cout << answer[1][i] << ' ';
    // cout << answer[0].size() << ' ' << answer[1].size() << '\n';
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