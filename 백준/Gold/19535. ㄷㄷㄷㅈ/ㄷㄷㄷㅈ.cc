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
    int n, a, b;
    ll answer1 = 0, answer2 = 0;
    cin >> n;
    vector<vector<int>> arr(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i].size() >= 2)
        {
            for (auto j : arr[i])
            {
                if (arr[j].size() >= 2)
                    answer1 += (arr[i].size() - 1) * (arr[j].size() - 1);
            }
        }
        if (arr[i].size() >= 3)
            answer2 += (ll)(arr[i].size()) * (ll)(arr[i].size() - 1) * (ll)(arr[i].size() - 2) / 6ll;
    }

    if (answer1 > answer2 * 6ll)
        cout << "D\n";
    else if (answer1 == answer2 * 6ll)
        cout << "DUDUDUNGA\n";
    else
        cout << "G\n";
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