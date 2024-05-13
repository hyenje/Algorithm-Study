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

vector<int> arr[333'555], visited(333'555);

ll go(int node)
{
    visited[node] = 1;
    ll val[3] = {}, num;
    for (auto i : arr[node])
    {
        if (!visited[i])
            val[go(i)]++;
    }

    if (val[1] == 0 && val[2] == 0)
        num = 1;
    else if (val[1] == 1 && val[2] == 0)
        num = 2;
    else if ((val[1] == 2 && val[2] == 0) || (val[1] == 0 && val[2] == 1))
        num = 0;
    else
    {
        cout << "U\n";
        exit(0);
    }
    // cout << node << ' ' << val[0] << ' ' << val[1] << ' ' << val[2] << '\n';

    return num;
}

vector<int> unite(int node)
{
    visited[node] = 1;
    vector<int> answer;
    if (arr[node].size() == 0)
    {
        answer.push_back(node);
        return answer;
    }

    answer.push_back(node);
    for (auto i : arr[node])
    {
        if (visited[i])
            continue;
        vector<int> tmp = unite(i);
        if (tmp.size())
            for (auto j : tmp)
                answer.push_back(j);
    }

    if (answer.size() == 3)
    {
        cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << '\n';
        answer = vector<int>();
    }
    return answer;
}

void solve()
{
    int n, start;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    go(1);
    cout << "S\n";
    visited = vector<int>(333'555);
    unite(1);
    // for (int i = 1; i <= n; i++)
    //     cout << num[i] << ' ';
    // cout << '\n';
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