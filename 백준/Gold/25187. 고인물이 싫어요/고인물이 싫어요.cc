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

int visited[100'123];

void solve()
{
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<int> arr(n + 1), ans(n + 1);
    vector<vector<int>> go(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    while (m--)
    {
        cin >> a >> b;
        go[a].push_back(b);
        go[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int num = 0;
            queue<int> nd, q;
            q.push(i);

            while (q.size())
            {
                int s = q.front();
                q.pop();
                if (visited[s])
                    continue;
                visited[s] = 1;
                num += arr[s] ? 1 : -1;
                nd.push(s);
                for (auto l : go[s])
                    q.push(l);
            }

            while (nd.size())
            {
                int s = nd.front();
                nd.pop();
                ans[s] = num;
            }
        }
    }

    while (k--)
    {
        cin >> a;
        // cout << ans[a] << ' ';
        cout << (ans[a] > 0) << '\n';
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