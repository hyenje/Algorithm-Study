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
    int n, val;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    cin >> n;

    cin >> val;
    pq1.push(val);
    cout << val << '\n';
    cin >> val;
    if (pq1.top() <= val)
        pq2.push(val);
    else
    {
        pq2.push(pq1.top());
        pq1.pop();
        pq1.push(val);
    }
    cout << pq1.top() << '\n';

    for (int i = 3; i <= n; i++)
    {
        cin >> val;
        if (i % 2)
        {
            if (val <= pq1.top())
                pq1.push(val);
            else
            {
                pq2.push(val);
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        else
        {
            if (val <= pq1.top())
            {
                pq1.push(val);
                pq2.push(pq1.top());
                pq1.pop();
            }
            else
                pq2.push(val);
        }
        cout << pq1.top() << '\n';
    }
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