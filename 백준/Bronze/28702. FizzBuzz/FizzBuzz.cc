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

void solve()
{
    int idx = 0, val;
    string s;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        if (s[0] <= '9')
        {
            val = stoi(s);
            idx = 3 - i;
        }
    }

    val += idx;
    if (val % 3 == 0 && val % 5 == 0)
        cout << "FizzBuzz" << '\n';
    else if (val % 3 == 0)
        cout << "Fizz" << '\n';
    else if (val % 5 == 0)
        cout << "Buzz" << '\n';
    else
        cout << val << ' ';
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