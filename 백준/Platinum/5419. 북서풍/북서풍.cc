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

void coordinate_compress(vector<pii> &arr, vector<int> &x_c, vector<int> &y_c)
{
    sort(x_c.begin(), x_c.end());
    x_c.erase(unique(x_c.begin(), x_c.end()), x_c.end());
    sort(y_c.begin(), y_c.end());
    y_c.erase(unique(y_c.begin(), y_c.end()), y_c.end());
    for (auto &i : arr)
    {
        i.F = upper_bound(x_c.begin(), x_c.end(), i.F) - x_c.begin();
        i.S = upper_bound(y_c.begin(), y_c.end(), i.S) - y_c.begin();
    }
}

bool compare(pii a, pii b)
{
    return a.F < b.F ? 1 : (a.F == b.F) ? a.S > b.S
                                        : 0;
}

vector<ll> t;

void init(int nd, int index, int l, int r)
{
    if (l > index || r < index)
        return;
    if (r == l)
    {
        t[nd]++;
        return;
    }

    int mid = (l + r) >> 1;
    init(nd << 1, index, l, mid);
    init(nd << 1 | 1, index, mid + 1, r);
    t[nd] = t[nd << 1] + t[nd << 1 | 1];
    return;
}

int get_val(int nd, int ql, int qr, int l, int r)
{
    if (l > qr || r < ql)
        return 0;
    if (r <= qr && ql <= l)
        return t[nd];
    int mid = (l + r) >> 1;
    return get_val(nd << 1, ql, qr, l, mid) + get_val(nd << 1 | 1, ql, qr, mid + 1, r);
}

void solve()
{
    int n;
    ll answer = 0;
    cin >> n;
    vector<pii> arr(n);
    vector<int> x_c, y_c;
    t.resize(n << 3);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].F >> arr[i].S;
        x_c.push_back(arr[i].F);
        y_c.push_back(arr[i].S);
    }
    coordinate_compress(arr, x_c, y_c);
    sort(arr.begin(), arr.end(), compare);

    for (auto i : arr)
    {
        answer += get_val(1, i.S - 1, n - 1, 0, n - 1);
        // cout << t[1] << ' ';
        init(1, i.S - 1, 0, n - 1);
    }
    // cout << '\n';
    cout << answer << '\n';
    t.clear();
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