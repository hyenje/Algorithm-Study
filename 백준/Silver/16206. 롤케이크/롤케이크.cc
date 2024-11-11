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
    int n, m, val, answer = 0;
    vector<int> arr, ten;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val % 10)
            arr.push_back(val);
        else
            ten.push_back(val);
    }

    sort(ten.begin(), ten.end());
    sort(arr.begin(), arr.end());

    for (auto i : ten)
    {
        while (m && i > 10)
        {
            m--;
            answer++;
            i -= 10;
        }
        if (i == 10)
            answer++;
    }
    for (auto i : arr)
    {
        while (m && i > 10)
        {
            m--;
            answer++;
            i -= 10;
        }
        if (i == 10)
            answer++;
    }

    cout << answer << '\n';
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