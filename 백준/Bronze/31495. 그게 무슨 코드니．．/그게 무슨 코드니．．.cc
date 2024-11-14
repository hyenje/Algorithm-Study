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
    string s;
    getline(cin, s);

    int flag = 0, flag2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '\"')
        {
            flag++;
            continue;
        }
        if (flag == 0 || flag == 2)
            flag = MINF;
    }

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] != ' ')
            flag2 = 1;
    }

    if (flag < 2 || !flag2)
        cout << "CE\n";
    else
    {
        for (int i = 1; i < s.size() - 1; i++)
            cout << s[i];
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