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

struct node
{
    ll nx_node, dis, time;

    node() {}
    node(ll a, ll b, ll c) : nx_node(a), dis(b), time(c) {}
};

vector<vector<node>> arr;

void solve()
{
    ll n, m, answer = -1;

    cin >> n >> m;
    arr.resize(n + 1);

    ll a, b, c, d;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        arr[a].push_back(node(b, c, d));
        arr[b].push_back(node(a, c, d));
    }

    ll l = 0, r = INF;

    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        bool flag = 0;

        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<ll> len(n + 1, INF);
        q.push({mid, 1});
        len[1] = mid;

        while (!q.empty())
        {
            ll idx = q.top().S, d = q.top().F;
            q.pop();
            if (len[idx] < d)
                continue;
            if (idx == n)
            {
                flag = 1;
                break;
            }

            for (auto i : arr[idx])
            {
                if (len[i.nx_node] <= d + i.dis || i.time < d + i.dis)
                    continue;
                len[i.nx_node] = d + i.dis;
                q.push({len[i.nx_node], i.nx_node});
            }
        }
        if (flag)
        {
            answer = max(answer, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */