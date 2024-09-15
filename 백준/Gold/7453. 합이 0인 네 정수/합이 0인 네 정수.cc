/*
 */
#include <bits/stdc++.h>
using namespace std;
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
    int n;
    ll answer = 0;
    cin >> n;
    vector<ll> arr(n), brr(n), crr(n), drr(n);
    vector<ll> ma, mb;

    for (int i = 0; i < n; i++)
        cin >> arr[i] >> brr[i] >> crr[i] >> drr[i];

    for (auto i : arr)
        for (auto j : brr)
            ma.push_back(i + j);
    for (auto i : crr)
        for (auto j : drr)
            mb.push_back(i + j);

    sort(ma.begin(), ma.end());
    sort(mb.rbegin(), mb.rend());

    ma.push_back(-LL_INF);
    mb.push_back(-LL_INF);

    // for (auto i : ma)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto i : mb)
    //     cout << i << ' ';
    // cout << '\n';

    ll l = 0, r = 0, val = n * n, lc = 1, rc = 1;
    while (l < val && r < val)
    {
        while (l < val && ma[l] == ma[l + 1])
        {
            lc++;
            l++;
        }
        while (r < val && mb[r] == mb[r + 1])
        {
            rc++;
            r++;
        }
        // cout << l << ": " << ma[l] << ' ' << r << ": " << mb[r] << " = " << ma[l] + mb[r];

        if (ma[l] + mb[r] == 0)
        {
            l++;
            r++;
            answer += lc * rc;
            lc = rc = 1;
        }
        else if (ma[l] + mb[r] < 0)
        {
            l++;
            lc = 1;
        }
        else
        {
            r++;
            rc = 1;
        }
        // cout << "  answer :" << answer << '\n';
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