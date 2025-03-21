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
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

int p[1'000'123];

int solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
        return 1;
    vector<int> arr(n);
    map<int, vector<int>> son;
    int cnt = -1;
    for (auto &i : arr)
        cin >> i;

    p[arr[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1] + 1)
            cnt++;
        son[arr[cnt]].push_back(arr[i]);
        p[arr[i]] = arr[cnt];
    }
    int parent = p[m], grand = p[parent];
    // cout << parent << ' ' << grand << '\n';
    if (grand == 0 || parent == 0)
        cout << 0 << '\n';
    else
    {
        ll answer = 0;
        for (auto i : son[grand])
        {
            if (i == parent)
                continue;
            answer += son[i].size();
        }
        cout << answer << '\n';
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    while (true)
    {
        if (solve())
            break;
    }

    return 0;
}
/*

 */