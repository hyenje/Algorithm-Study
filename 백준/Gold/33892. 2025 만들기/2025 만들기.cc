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
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    int n;
    cin >> n;
    if (n < 7)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        int val = n - 7;
        if (n % 2 == 0)
        {
            int cnt = 0;
            cout << "8 - 4\n";
            for (int i = 9; i < n; i += 2)
            {
                cout << i + 1 << " - " << i << '\n';
                cnt++;
            }
            for (int i = 0; i < cnt; i++)
                cout << "1 * 1\n";
        }
        else
        {
            int cnt = 0;
            for (int i = 8; i < n; i += 2)
            {
                cout << i + 1 << " - " << i << '\n';
                cnt++;
            }
            for (int i = 0; i < cnt; i++)
                cout << "1 * 1\n";
        }

        cout << "1 + 4\n";
        cout << "5 * 5\n";
        cout << "2 + 7\n";
        cout << "3 + 6\n";
        cout << "9 * 9\n";
        cout << "25 * 81\n";
    }
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