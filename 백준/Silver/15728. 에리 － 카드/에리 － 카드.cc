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
    int x, y, val;

    node() {}
    node(int a, int b, int v) : x(a), y(b), val(v) {}
    bool operator<(node &a)
    {
        return this->val > a.val;
    }
};

void solve()
{
    int n, k, ans, cnt = 0;
    cin >> n >> k;
    vector<int> visited(n);
    vector<node> answer;
    vector<int> arr(n), brr(n);

    for (auto &i : arr)
        cin >> i;
    for (auto &i : brr)
        cin >> i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer.push_back(node(i, j, arr[i] * brr[j]));
    sort(answer.begin(), answer.end());

    // for (auto i : answer)
    //     cout << i.val << ' ';

    int flag = 0;
    for (auto i : answer)
    {
        if (visited[i.y])
            continue;
        ans = i.val;

        if (flag)
            break;

        visited[i.y] = 1;
        cnt++;
        if (cnt == k)
            flag = 1;
    }
    cout << ans << '\n';
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