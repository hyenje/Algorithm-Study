/*
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define L_INF 1'123'123'123'123'123'123
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 1'000'000'007
const int mx[5] = {1, -1, 0, 0};
const int my[5] = {0, 0, -1, 1};

void solve()
{
    int N, D;
    ll answer = MINF, tmp, value;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> pq;
    cin >> N >> D;

    pq.push({0, 0});
    for (int i = 1; i <= N; i++)
    {
        cin >> value;
        while (i - pq.top().second > D)
            pq.pop();

        tmp = max(pq.top().first + value, value);
        answer = max(tmp, answer);
        pq.push({tmp, i});
    }

    while (!pq.empty())
    {
        answer = max(pq.top().first, answer);
        pq.pop();
    }

    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
/*
 */