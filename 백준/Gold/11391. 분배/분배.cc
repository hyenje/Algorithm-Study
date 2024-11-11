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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr((1 << m));

    int k = 0, val = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        if (k == 0 && i != 0 && i != ((1 << n) - 1))
        {
            arr[k].push_back(i++);
            val = 1;
        }
        else if (k == ((1 << m) - 1))
        {
            arr[k].push_back(i++);
            val = -1;
        }
        arr[k].push_back(i);
        k += val;
    }

    for (int i = 0; i < (1 << m); i++)
    {
        for (auto j : arr[i])
            cout << j << ' ';
        cout << '\n';
    }
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