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

int finished[100'123], parent[100'123];
vector<vector<int>> arr;
vector<vector<int>> answer;
stack<int> s;
int id;

int go(int nd)
{
    parent[nd] = id++;
    s.push(nd);

    int p = parent[nd];
    for (auto i : arr[nd])
    {
        if (parent[i] == 0)
            p = min(p, go(i));
        else if (finished[i] == 0)
            p = min(p, parent[i]);
    }

    if (parent[nd] == p)
    {
        int node = 0;
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
    id = 1;

    arr.resize(n);
    vector<int> nidx(n), cnt, ans;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
        if (!parent[i])
            go(i);

    sort(answer.begin(), answer.end());
    cnt.resize(answer.size());

    for (int i = 0; i < answer.size(); i++)
        for (auto j : answer[i])
            nidx[j] = i;

    for (int i = 0; i < n; i++)
        for (auto j : arr[i])
            if (nidx[i] != nidx[j])
                cnt[nidx[j]]++;

    for (int i = 0; i < cnt.size(); i++)
    {
        if (cnt[i] == 0)
            ans.push_back(i);
    }

    if (ans.size() == 1)
    {
        for (int i = 0; i < n; i++)
            if (nidx[i] == ans[0])
                cout << i << '\n';
    }
    else
        cout << "Confused\n";

    arr.clear();
    answer.clear();
    memset(finished, 0, sizeof(finished));
    memset(parent, 0, sizeof(parent));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
/*
 */