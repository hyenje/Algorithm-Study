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

void solve()
{
    ll n, a, b, d;
    int answer = 0;
    cin >> n;
    vector<pii> arr(n);
    vector<int> brr;
    for (auto &i : arr)
    {
        cin >> i.F >> i.S;
        if (i.F > i.S)
            swap(i.F, i.S);
    }
    sort(arr.begin(), arr.end());

    // for (auto i : arr)
    //     cout << i.F << ' ';
    // cout << '\n';
    // for (auto i : arr)
    //     cout << i.S << ' ';
    // cout << '\n';

    cin >> d;
    ll end = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        int line = arr[i].F + d;
        while (pq.size() && pq.top().F <= line)
        {
            q.push(pq.top().S);
            pq.pop();
        }
        while (q.size() && q.top() < arr[i].F)
            q.pop();
        for (; end < n && arr[end].F < line; end++)
        {
            if (arr[end].S <= line)
                q.push(arr[end].F);
            else
                pq.push({arr[end].S, arr[end].F});
        }
        answer = max(answer, (int)q.size());
        // cout << i << ' ' << q.size() << '\n';
        // vector<int> tmp;
        // while (q.size())
        // {
        //     tmp.push_back(q.top());
        //     q.pop();
        // }
        // for (auto i : tmp)
        // {
        //     cout << i << ' ';
        //     q.push(i);
        // }
        // cout << '\n';
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