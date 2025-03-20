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

bool compare(string &a, string &b)
{
    if (a == b)
        return 0;

    string ab = a + b;
    string ba = b + a;

    return ab > ba;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    string answer;

    for (auto &i : arr)
        cin >> i;

    sort(arr.begin(), arr.end(), compare);

    // for (auto i : arr)
    //     cout << i << '\n';

    for (auto i : arr)
        answer += i;

    if (answer[0] == '0')
        cout << 0 << '\n';
    else
        cout << answer << '\n';
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