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
    ll n, m, flag = 0;
    cin >> n;
    vector<int> arr(n), cp;
    for (auto &i : arr)
        cin >> i;
    cin >> m;
    vector<tuple<int, int, int>> v(m);

    for (auto &[l, r, c] : v)
    {
        cin >> l >> r >> c;
        l--, r--;
    }

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    map<vector<int>, int> dis;
    pq.push({0, arr});
    cp = arr;
    sort(arr.begin(), arr.end());

    if (arr == cp)
    {
        cout << 0 << '\n';
        return;
    }

    while (pq.size())
    {
        auto [cst, vec] = pq.top();
        pq.pop();
        for (auto [l, r, c] : v)
        {
            swap(vec[l], vec[r]);
            if (dis[vec] == 0 || dis[vec] > c + cst)
            {
                pq.push({cst + c, vec});
                dis[vec] = cst + c;
            }
            swap(vec[l], vec[r]);
        }
    }
    if (dis[arr])
        cout << dis[arr] << '\n';
    else
        cout << -1 << '\n';
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