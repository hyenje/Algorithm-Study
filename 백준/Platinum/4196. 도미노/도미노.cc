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

vector<vector<int>> arr, brr;
int finished[100'123], parent[100'123], id = 1;
vector<vector<int>> answer;
stack<int> s;

int go(int nd)
{
    parent[nd] = id++;
    s.push(nd);

    int p = parent[nd];
    for (auto i : arr[nd])
    {
        if (!parent[i])
            p = min(p, go(i));
        else if (!finished[i])
            p = min(p, parent[i]);
    }

    if (p == parent[nd])
    {
        vector<int> scc;
        while (nd)
        {
            int node = s.top();
            s.pop();
            scc.push_back(node);
            finished[node] = 1;
            if (nd == node)
                break;
        }
        sort(scc.begin(), scc.end());
        answer.push_back(scc);
    }
    return p;
}

void solve()
{
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    arr.resize(n + 1);
    vector<int> uni(n + 1), cnt;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!parent[i])
            go(i);

    sort(answer.begin(), answer.end());
    // for (auto i : answer)
    // {
    //     for (auto j : i)
    //         cout << j << ' ';
    //     cout << "-1\n";
    // }

    int num = 0;
    for (auto i : answer)
    {
        for (int j = 0; j < i.size(); j++)
            uni[i[j]] = num;
        num++;
    }
    brr.resize(answer.size());
    cnt.resize(answer.size());

    for (int i = 1; i < arr.size(); i++)
    {
        for (auto j : arr[i])
        {
            if (uni[i] != uni[j])
            {
                brr[uni[i]].push_back(uni[j]);
                cnt[uni[j]]++;
            }
        }
    }
    // cout << '\n';
    // for (auto i : brr)
    // {
    //     for (auto j : i)
    //         cout << j << ' ';
    //     cout << "-1\n";
    // }

    for (auto i : cnt)
        if (i == 0)
            ans++;
    cout << ans << '\n';

    memset(finished, 0, sizeof(finished));
    memset(parent, 0, sizeof(parent));
    brr.clear();
    answer.clear();
    arr.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */