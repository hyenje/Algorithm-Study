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
    vector<pii> arr;
    int n, a, b, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());

    vector<int> l;
    for (int i = 0; i < n; i++)
        l.push_back(arr[i].S);

    while (l.size())
    {
        answer++;
        int val = -123'123;
        for (int i = 0; i < l.size();)
        {
            if (l[i] >= val)
            {
                val = l[i];
                l.erase(l.begin() + i);
            }
            else
                i++;
        }
    }
    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */