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

int go[1024];

int find(int a)
{
    if (go[a] == a)
        return a;
    return go[a] = find(go[a]);
}

int unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a < b)
        swap(a, b);
    if (a == b)
        return 1;

    go[b] = a;
    return 0;
}
void solve()
{
    int n, m, k, c;
    cin >> n >> m;
    double a, b, answer = 0;
    vector<pair<double, double>> arr(n + 1);
    priority_queue<pair<double, pii>, vector<pair<double, pii>>, greater<pair<double, pii>>> pq;

    for (int i = 0; i <= n; i++)
        go[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> k >> c;
        unite(k, c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pq.push({sqrt(pow(arr[i].F - arr[j].F, 2) + pow(arr[i].S - arr[j].S, 2)), {i, j}});

    while (pq.size())
    {
        pair<double, pii> val = pq.top();
        double dis = val.F;
        int s = val.S.F, e = val.S.S;
        pq.pop();

        if (unite(s, e))
            continue;
        answer += dis;
    }

    printf("%.2f\n", answer);
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