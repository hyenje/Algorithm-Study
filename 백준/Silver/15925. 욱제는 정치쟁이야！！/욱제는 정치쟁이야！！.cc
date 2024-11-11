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

int arr[50][50];

void solve()
{
    int n, m, flag = 1;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    while (flag)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += (m == arr[i][j]);
            if (cnt != n && cnt > n - cnt)
            {
                for (int j = 0; j < n; j++)
                    arr[i][j] = m;
                flag = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += (m == arr[j][i]);
            if (cnt != n && cnt > n - cnt)
            {
                for (int j = 0; j < n; j++)
                    arr[j][i] = m;
                flag = 1;
            }
        }
    }

    flag = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            flag += (arr[i][j] != m);

    if (flag)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */