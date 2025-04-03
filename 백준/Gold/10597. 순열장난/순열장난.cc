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
#define MID 200'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

string s;
int len = 0;
map<int, int> ma;
vector<int> answer;

int go(int n, string num)
{
    if (n == s.size())
    {
        if (ma.size() == len + 1)
        {
            for (auto i : answer)
                cout << i << ' ';
            cout << '\n';
            return 1;
        }
        return 0;
    }
    num = num + s[n];
    int val = stoi(num);

    if (val > len)
        return 0;
    else if (ma[val] == 0 && val <= len)
    {
        answer.push_back(val);
        ma[val] = 1;
        if (go(n + 1, ""))
            return 1;
        answer.pop_back();
        ma.erase(val);
    }

    return go(n + 1, num);
}

void solve()
{
    ma[0] = 1;
    cin >> s;
    int val = s.size();
    len += min(9, val), val -= 9;
    if (val > 0)
        len += val / 2;
    go(0, "");
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