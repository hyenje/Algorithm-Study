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
#define MID 5000

const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<int>> arr(10'000), answer;
int finished[10'000], parent[10'000], unite[10'000], id = 0;
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

void solve(int n, int m)
{
    int a, b;
    // cout << n << ' ' << m << '\n';
    while (m--)
    {
        scanf("%d %d", &a, &b);
        if (a == -1)
            arr[MID + a].push_back(MID + b);
        else
            arr[MID - a].push_back(MID + b);
        if (b == -1)
            arr[MID + b].push_back(MID + a);
        else
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
            if (unite[j] == unite[MID + (MID - j)])
                flag = 0;
    }
    if (flag)
        printf("yes\n");
    else
        printf("no\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        arr.resize(10'000);
        solve(n, m);
        for (int i = 0; i < 10000; i++)
            finished[i] = parent[i] = unite[i] = 0;
        answer.clear();
        arr.clear();
        id = 0;
        while (s.size())
            s.pop();
    }

    return 0;
}
/*
 */