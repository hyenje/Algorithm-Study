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

vector<vector<int>> loop(200'123, vector<int>(30));

void solve()
{
    int n, m, a, b, cnt = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> loop[i][0];

    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            loop[j][i] = loop[loop[j][i - 1]][i - 1];
        }
    }

    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        int nd = b;
        while (a)
        {
            for (int i = 0; i < 30; i++)
            {
                if (a & (1 << i))
                {
                    // cout << nd << ' ';
                    a -= 1 << i;
                    nd = loop[nd][i];
                }
            }
            cout << nd << '\n';
        }
    }
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