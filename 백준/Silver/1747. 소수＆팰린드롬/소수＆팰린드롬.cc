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
vector<int> v(2'000'123);

void solve()
{
    set<int> se;
    for (int i = 2; i < 1'000'123; i++)
    {
        if (v[i])
            continue;
        for (int j = 2; j * i <= 2'000'000; j++)
            v[i * j] = 1;
    }

    for (int i = 2; i < 2000002; i++)
    {
        if (v[i])
            continue;
        int flag = 0;
        string s = to_string(i);
        // cout << s << ' ';
        for (int j = 0; j < s.size() / 2; j++)
        {
            if (s[j] != s[s.size() - 1 - j])
                flag = 1;
        }
        if (!flag)
            se.insert(i);
    }

    int val;
    cin >> val;
    // for (auto i : se)
    //     cout << i << ' ';
    // cout << '\n';

    auto answer = se.lower_bound(val);
    cout << *answer << '\n';
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