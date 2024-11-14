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

vector<int> s;
void solve()
{
    int n, val = INF;
    cin >> n;
    vector<int> brr(n);
    for (auto &i : brr)
        cin >> i;
    sort(brr.begin(), brr.end());

    for (int i = 0; i < s.size() - n + 1; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
            tmp += max(brr[j] - s[i + j], -brr[j] + s[i + j]);
        val = min(val, tmp);
    }
    cout << val << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(100'123);
    for (int i = 2; i < 100'123; i++)
        for (int j = 2; j * i < 100'123; j++)
            arr[i * j] = 1;

    for (int i = 2; i < 100'123; i++)
        if (arr[i] == 0)
            s.push_back(i);

    // for (int i = 0; i < s.size(); i++)
    //     if (s[i] == 73)
    //         cout << i << ' ';
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */