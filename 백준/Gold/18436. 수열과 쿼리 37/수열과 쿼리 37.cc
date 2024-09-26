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

int t[4'000'123], arr[1'000'123];

void init(int nd, int l, int r)
{
    if (l == r)
    {
        t[nd] = arr[l] % 2;
        return;
    }
    int mid = l + r >> 1;
    init(nd << 1, l, mid);
    init(nd << 1 | 1, mid + 1, r);

    t[nd] = t[nd << 1] + t[nd << 1 | 1];
}

void change(int nd, int l, int r, int index)
{
    if (index < l || index > r)
        return;
    if (l == r)
    {
        t[nd] = arr[l] % 2;
        return;
    }
    int mid = l + r >> 1;
    change(nd << 1, l, mid, index);
    change(nd << 1 | 1, mid + 1, r, index);
    t[nd] = t[nd << 1] + t[nd << 1 | 1];
}

int sum(int nd, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return 0;
    if (r <= qr && l >= ql)
        return t[nd];
    int mid = l + r >> 1;
    return sum(nd << 1, l, mid, ql, qr) + sum(nd << 1 | 1, mid + 1, r, ql, qr);
}
void solve()
{
    int n, m, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1);
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            arr[b - 1] = c;
            change(1, 0, n - 1, b - 1);
        }
        else if (a == 2)
            cout << c - b + 1 - sum(1, 0, n - 1, b - 1, c - 1) << '\n';
        else
            cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
    }
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