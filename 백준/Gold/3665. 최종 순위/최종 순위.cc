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

bool compare(pii a, pii b)
{
    return a.S > b.S;
}

void solve()
{
    int n, m, a, b, cnt, val;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> edge(512, vector<int>(512));
    vector<pii> num(n);
    cnt = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        num[arr[i] - 1].F = arr[i];
        num[arr[i] - 1].S = --cnt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            edge[arr[i] - 1][arr[j] - 1] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        if (edge[a][b])
        {
            edge[a][b] = 0;
            edge[b][a] = 1;
            num[a].S--;
            num[b].S++;
        }
        else
        {
            edge[a][b] = 1;
            edge[b][a] = 0;
            num[b].S--;
            num[a].S++;
        }
    }

    sort(num.begin(), num.end(), compare);
    bool flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (num[i - 1].S - 1 != num[i].S)
            flag = 1;
    }

    // for (int i = 0; i < n; i++)
    //     cout << num[i].S << ' ';
    // cout << '\n';

    if (flag)
        cout << "IMPOSSIBLE\n";
    else
    {

        for (int i = 0; i < n; i++)
            cout << num[i].F << ' ';
        cout << '\n';
    }
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