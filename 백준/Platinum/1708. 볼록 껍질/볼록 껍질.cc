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

struct node
{
    ll x, y;
    bool operator<(const node &a) { return y == a.y ? x < a.x : y < a.y; }
};

vector<node> arr(1024);

ll ccw(const node &a, const node &b, const node &c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(node a, node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(const node &a, const node &b)
{
    ll c = ccw(arr[0], a, b);
    if (c == 0)
        return dist(arr[0], a) < dist(arr[0], b);
    return c > 0;
}

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);

    for (auto &i : arr)
        cin >> i.x >> i.y;
    sort(arr.begin(), arr.end());
    sort(arr.begin() + 1, arr.end(), cmp);

    vector<node> answer;
    answer.push_back(arr[0]);
    answer.push_back(arr[1]);
    for (int i = 1; i < arr.size(); i++)
    {
        while (answer.size() >= 2 && ccw(answer[answer.size() - 2], answer[answer.size() - 1], arr[i]) <= 0)
            answer.pop_back();
        answer.push_back(arr[i]);
    }

    // for (auto i : answer)
    //     cout << i.x << ' ' << i.y << '\n';

    cout << answer.size() << '\n';
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */