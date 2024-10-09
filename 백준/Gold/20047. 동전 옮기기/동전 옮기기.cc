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

int n, l, r;
int dp[10'123][3];
string s, t, two;

int go(int idx1, int idx2, int status)
{
    int &ret = dp[idx2][status];
    if (ret != -1)
        return ret;
    if (idx2 == n)
    {
        if (status == 2)
            return ret = 1;
        return ret = 0;
    }

    ret = 0;

    if (status < 2)
        if (t[idx2] == two[status])
            ret |= go(idx1, idx2 + 1, status + 1);

    if (s[idx1] == t[idx2])
        if (idx1 < n - 2)
            ret |= go(idx1 + 1, idx2 + 1, status);

    return ret;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    string x;
    cin >> n >> x >> t >> l >> r;

    two += x[l], two += x[r];

    for (int i = 0; i < n; i++)
        if (i != l && i != r)
            s += x[i];

    if (go(0, 0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
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