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
#define NUM 3'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int parent[200'123][20], visited[200'123], len[200'123];
int n, m, a, b;
deque<int> node;
vector<vector<int>> arr(200'123);

void go(int pre, int f)
{
    visited[pre] = 1, len[pre] = f;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) > node.size())
            break;
        parent[pre][i] = node[(1 << i) - 1];
    }
    node.push_front(pre);
    for (auto i : arr[pre])
    {
        if (visited[i])
            continue;
        go(i, f + 1);
    }
    node.pop_front();
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    go(1, 0);
    // for (int i = 1; i <= 15; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < 5; j++)
    //         cout << parent[i][j] << ' ';
    //     cout << '\n';
    // }
    // for (int i = 1; i <= 14; i++)
    //     cout << len[i] << ' ';
    // cout << '\n';

    cin >> m;
    while (m--)
    {
        cin >> a >> b;

        if (len[a] >= len[b])
            cout << parent[a][0] << '\n';
        else
        {
            int val = b;
            // cout << b << ' ';
            while (len[b] > len[a] + 1)
            {
                for (int i = 0; i < 20; i++)
                {
                    // cout << len[parent[b][i]] << ' ' << len[a] + 1 << '\n';
                    if (len[parent[b][i]] == len[a] + 1)
                    {
                        b = parent[b][i];
                        break;
                    }
                    else if (len[parent[b][i]] < len[a] + 1)
                    {
                        b = parent[b][i - 1];
                        break;
                    }
                }
            }
            if (parent[b][0] == a)
                cout << b << '\n';
            else
                cout << parent[a][0] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    len[0] = -1;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*

*/