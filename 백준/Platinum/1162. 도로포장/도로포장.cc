/*
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define LL_INF 9'223'372'036'854'775'807
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 1'000'000'007
const int mx[5] = {1, -1, 0, 0};
const int my[5] = {0, 0, -1, 1};

vector<vector<pair<ll, ll>>> arr(10'123);
vector<vector<ll>> len(10'123, (vector<ll>(21, LL_INF)));

struct node
{
    ll to, len, lay;

    node() : to(0), len(0), lay(0) {}
    node(ll a, ll b, ll c) : to(a), len(b), lay(c) {}
};

bool operator<(const node &a, const node &b)
{
    return a.len > b.len;
}

void solve()
{
    ll n, m, k, answer = LL_INF;

    cin >> n >> m >> k;

    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    priority_queue<node> pq;
    pq.push(node(1, 0, 0));

    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        if (len[tmp.to][tmp.lay] <= tmp.len)
            continue;
        len[tmp.to][tmp.lay] = tmp.len;

        // cout << tmp.to << ' ' << tmp.lay << ' ' << tmp.len << '\n';

        for (auto &i : arr[tmp.to])
        {
            pq.push(node(i.first, tmp.len + i.second, tmp.lay));
            if (tmp.lay < k)
                pq.push(node(i.first, tmp.len, tmp.lay + 1));
        }
    }

    for (int i = 0; i <= k; i++)
    {
        answer = min(answer, len[n][i]);
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