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

void solve()
{
    int n, a, b;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> visited(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> a >> b;

    queue<pii> q;
    q.push({a, 0});
    visited[a] = 1;

    while (!q.empty())
    {
        int val = q.front().F, num = q.front().S;
        if (val == b)
        {
            cout << num << '\n';
            return;
        }
        q.pop();
        for (int i = val % arr[val]; i <= n; i += arr[val])
        {
            if (i == 0 || visited[i])
                continue;
            q.push({i, num + 1});
            visited[i] = 1;
        }
    }

    cout << -1 << '\n';
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