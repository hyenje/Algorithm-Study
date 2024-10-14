#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define L_INF 1'123'123'123'123'123'123
#define INF 2'147'483'647
#define l_INF 1'000'000'007
#define MINF -2'147'483'648
#define MOD 998'244'353
const int mx[5] = {1, -1, 0, 0};
const int my[5] = {0, 0, -1, 1};

deque<vector<pair<ll, ll>>> arr(2'000'123);
queue<pair<ll, ll>> q;

void solve()
{
    int n, k;
    cin >> n >> k;

    ll a, b, answer = 0, mul = 1;
    int cnt = 0;

    k = min(k, n);
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        arr[b].push_back({++cnt, a});
    }
    for (int i = k; i < n; i++)
    {
        cin >> a >> b;
        q.push({a, b});
    }

    while (!arr.empty())
    {
        while (!arr.empty() && arr[0].empty())
            arr.pop_front();

        if (arr.empty())
            break;

        sort(arr[0].begin(), arr[0].end());

        for (int i = arr[0].size() - 1; i >= 0; i--)
        {
            answer += mul++ * arr[0][i].second;
            // cout << arr[0][i].second << ' ' << answer << '\n';
        }

        pair<ll, ll> tmp;
        for (auto &i : arr[0])
        {
            if (q.empty())
                break;
            tmp = q.front();
            q.pop();
            arr[tmp.second].push_back({i.first, tmp.first});
        }

        arr.pop_front();
    }

    cout << answer << '\n';
}

int main()
{
    // // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
/*
 */