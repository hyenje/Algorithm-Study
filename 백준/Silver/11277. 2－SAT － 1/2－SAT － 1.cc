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
#define MID 100'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<int>> arr(200'123), answer;
int finished[200'123], parent[200'123], unite[200'123], id = 0;
stack<int> s;

int go(int nd)
{
    int p = parent[nd] = id++;
    s.push(nd);

    for (auto i : arr[nd])
    {
        if (!parent[i])
            p = min(p, go(i));
        else if (!finished[i])
            p = min(p, parent[i]);
    }

    if (parent[nd] == p)
    {
        int node;
        vector<int> scc;
        do
        {
            node = s.top();
            s.pop();
            scc.push_back(node);
            finished[node] = 1;

        } while (node != nd);
        sort(scc.begin(), scc.end());
        answer.push_back(scc);
    }
    return p;
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        arr[MID - a].push_back(MID + b);
        arr[MID - b].push_back(MID + a);
    }

    for (int i = MID - n; i <= MID + n; i++)
    {
        if (!parent[i] && arr[i].size())
            go(i);
    }

    // cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    int flag = 1;
    for (int i = 0; i < answer.size(); i++)
    {
        for (auto j : answer[i])
            unite[j] = i + 1;
        for (auto j : answer[i])
        {
            if (unite[j] == unite[MID + (MID - j)])
            {
                // cout << j - MID << ' ' << MID - j << '\n';
                flag = 0;
            }
        }
    }

    // for (int i = MID - n; i <= MID + n; i++)
    //     cout << unite[i] << ' ';
    // cout << '\n';

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