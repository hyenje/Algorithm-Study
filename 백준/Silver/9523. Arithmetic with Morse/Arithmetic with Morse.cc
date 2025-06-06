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
    string s;
    int n, val = 0, oper = 0, answer = 0;
    getline(cin, s);
    getline(cin, s);
    s += '+';
    vector<int> arr;
    for (char i : s)
    {
        if (i == '=')
            val += 10;
        else if (i == '.')
            val += 1;
        else if (i == ':')
            val += 2;
        else if (i == '-')
            val += 5;
        else if (i == '+')
        {
            if (oper < 1)
                arr.push_back(val);
            else
                arr[arr.size() - 1] *= val;
            val = 0, oper = 0;
        }
        else if (i == '*')
        {
            if (oper < 1)
                arr.push_back(val);
            else
                arr[arr.size() - 1] *= val;
            val = 0, oper = 1;
        }
    }
    for (auto i : arr)
        answer += i;

    cout << answer << '\n';
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