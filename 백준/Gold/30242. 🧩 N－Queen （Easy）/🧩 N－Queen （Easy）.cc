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

int n, val;
int answer[50];

int go(int a)
{
    if (answer[a])
        return go(a + 1);
    if (a > n)
    {
        for (int i = 1; i <= n; i++)
            cout << answer[i] << ' ';
        return 1;
    }

    int flag = 0;
    vector<int> tmp(22);
    for (int i = 1; i <= n; i++)
    {
        if (!answer[i] || a == i)
            continue;

        if (answer[i] + a - i > 0 && answer[i] + a - i <= n)
            tmp[answer[i] + a - i] = 1;
        if (answer[i] - a + i > 0 && answer[i] - a + i <= n)
            tmp[answer[i] - a + i] = 1;
        tmp[answer[i]] = 1;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << answer[i] << ' ';
    // cout << '\t';
    // for (int i = 1; i <= n; i++)
    //     cout << tmp[i] << ' ';
    // cout << '\n';

    for (int i = 1; i <= n && flag == 0; i++)
    {
        if (!tmp[i])
        {
            answer[a] = i;
            flag = go(a + 1);
            answer[a] = 0;
        }
    }
    return flag;
}

int solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> answer[i];
    return go(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    if (!solve())
        cout << -1 << '\n';

    return 0;
}
/*
 */