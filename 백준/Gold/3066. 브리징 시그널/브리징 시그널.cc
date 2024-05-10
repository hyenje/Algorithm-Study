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
    cin >> n;
    vector<int> arr(n + 1), answer;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    answer.push_back(arr[1]);

    for (int i = 2; i <= n; i++)
    {
        auto idx = upper_bound(answer.begin(), answer.end(), arr[i]) - answer.begin();
        // cout << idx << '\n';
        if (idx >= answer.size())
            answer.push_back(arr[i]);
        else if (idx >= 0)
            answer[idx] = arr[i];
    }

    // for (auto i : answer)
    //     cout << i << ' ';
    // cout << '\n';

    cout << answer.size() << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */