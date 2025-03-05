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

string num;
ll k;
pair<string, int> answer;
vector<int> c(11);

void go(int n, int t)
{
    if (t == 0 || n == num.size())
        return;
    vector<int> arr;
    arr.push_back(n);

    for (int i = n + 1; i < num.size(); i++)
    {
        if (num[arr.front()] < num[i])
        {
            arr.clear();
            arr.push_back(i);
        }
        else if (num[i] != num[n] && num[arr.front()] == num[i])
            arr.push_back(i);
    }
    if (arr.front() == n)
        arr.clear();

    for (auto i : arr)
    {
        string tmp = num;
        swap(num[n], num[i]);
        if (stoi(num) > stoi(answer.F))
            answer = {num, t - 1};
        go(n + 1, t - 1);
        swap(num[n], num[i]);
    }

    go(n + 1, t);
}

void solve()
{
    cin >> num >> k;

    for (auto i : num)
        c[i - '0']++;

    if ((num.size() == 2 && c[0]) || num.size() == 1)
    {
        cout << -1 << '\n';
        return;
    }

    answer = {num, k};
    go(0, k);
    k = answer.S;
    num = answer.F;
    // cout << k << ' ';
    // cout << num << '\n';
    // for (auto i : c)
    //     cout << i << ' ';
    if (k % 2)
    {
        int flag = 0;
        for (int i = 0; i < 10; i++)
            if (c[i] > 1)
                flag = 1;
        if (!flag)
            swap(num[num.size() - 1], num[num.size() - 2]);
    }

    cout << num << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // ll t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
/*
 */