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
    ll n, m, a, b, s, e, answer = 0, lst1 = 0, lower = INF;
    cin >> n >> m;
    vector<pll> back;
    lst1 = m;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        lst1 = max(lst1, max(a, b));
        if (a > b)
            back.push_back({b, a});
    }

    sort(back.begin(), back.end());

    s = e = INF;
    for (auto i : back)
    {
        if (s == INF)
        {
            s = i.F;
            e = i.S;
        }
        else if (i.F > e)
        {
            if (e <= m)
                answer += (e - s) << 1ll;
            else if (s < m)
            {
                answer = m - s;
                lower = s;
            }
            s = i.F;
            e = i.S;
        }
        else if (i.S > e)
            e = i.S;
    }
    answer += 2ll * lst1 - m;
    if (e <= m)
        answer += (e - s) << 1ll;
    else if (s < m)
    {
        answer = m - s;
        lower = s;
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