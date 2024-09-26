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
string s, a;
int arr[2'000'123];

int solve()
{
    a.clear();
    cin >> s;
    if (s == ".")
        return 0;

    int m = s.size();
    int index = 0, i = -1;
    while (index < m)
    {
        if (i == -1 || s[i] == s[index])
            arr[++index] = ++i;
        else
            i = arr[i];
    }
    // for (int i = 0; i <= m + 1; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';

    int answer = m - arr[m];
    // cout << answer << ' ' << m << ' ';
    if (m % answer)
        cout << 1 << '\n';
    else
        cout << (m / answer) << '\n';
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    arr[0] = -1;
    while (solve())
        ;

    return 0;
}
/*
 */