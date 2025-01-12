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

void solve()
{
    int a, b, n, m, flag = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a != b)
            flag = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a != b)
            flag = 2;
    }

    if (flag == 0)
        cout << "Accepted";
    else if (flag == 1)
        cout << "Wrong Answer";
    else
        cout << "Why Wrong!!!";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */