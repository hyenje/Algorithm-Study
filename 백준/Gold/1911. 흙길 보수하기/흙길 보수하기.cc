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
#define MOD 1'000'000'007
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    ll n, m, answer = 0, idx = 0;
    cin >> n >> m;
    vector<pll> arr(n);

    for (auto &i : arr)
    {
        cin >> i.F >> i.S;
        if (i.F > i.S)
            swap(i.F, i.S);
    }

    sort(arr.begin(), arr.end());

    for (auto i : arr)
    {
        idx = max(idx, i.F);
        if (idx >= i.S)
            continue;
        int num = (i.S - idx) / m;
        if ((i.S - idx) % m)
            num++;
        answer += num;
        idx += m * num;
    }

    cout << answer << '\n';
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