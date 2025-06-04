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
#define LM_INF 1'000'000'000'000'000
const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve()
{
    string a, b;
    int n = 0, idx = 0;
    cin >> a >> b;

    string tmp;

    for (idx = 0; idx < a.size(); idx++)
    {
        if (a[idx] != 'C' && a[idx] != 'D' && a[idx] != 'M')
            break;
        tmp.push_back(a[idx]);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'C')
            n += 100;
        else if (tmp[i] == 'D')
        {
            if (i > 0 && tmp[i - 1] == 'C')
            {
                n += 400;
                i--;
            }
            else
                n += 500;
        }
        else
        {
            if (i > 0 && tmp[i - 1] == 'C')
            {
                n += 900;
                i--;
            }
            else
                n += 1000;
        }
    }
    tmp.clear();
    for (; idx < a.size(); idx++)
    {
        if (a[idx] != 'C' && a[idx] != 'X' && a[idx] != 'L')
            break;
        tmp.push_back(a[idx]);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'X')
            n += 10;
        else if (tmp[i] == 'L')
        {
            if (i > 0 && tmp[i - 1] == 'X')
            {
                n += 40;
                i--;
            }
            else
                n += 50;
        }
        else
        {
            n += 90;
            i--;
        }
    }
    tmp.clear();
    for (; idx < a.size(); idx++)
        tmp.push_back(a[idx]);
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'I')
            n++;
        else if (tmp[i] == 'V')
        {
            if (i > 0 && tmp[i - 1] == 'I')
            {
                n += 4;
                i--;
            }
            else
                n += 5;
        }
        else
        {
            n += 9;
            i--;
        }
    }

    tmp.clear();
    for (idx = 0; idx < b.size(); idx++)
    {
        if (b[idx] != 'C' && b[idx] != 'D' && b[idx] != 'M')
            break;
        tmp.push_back(b[idx]);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'C')
            n += 100;
        else if (tmp[i] == 'D')
        {
            if (i > 0 && tmp[i - 1] == 'C')
            {
                n += 400;
                i--;
            }
            else
                n += 500;
        }
        else
        {
            if (i > 0 && tmp[i - 1] == 'C')
            {
                n += 900;
                i--;
            }
            else
                n += 1000;
        }
    }
    tmp.clear();
    for (; idx < b.size(); idx++)
    {
        if (b[idx] != 'C' && b[idx] != 'X' && b[idx] != 'L')
            break;
        tmp.push_back(b[idx]);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'X')
            n += 10;
        else if (tmp[i] == 'L')
        {
            if (i > 0 && tmp[i - 1] == 'X')
            {
                n += 40;
                i--;
            }
            else
                n += 50;
        }
        else
        {
            n += 90;
            i--;
        }
    }
    tmp.clear();
    for (; idx < b.size(); idx++)
        tmp.push_back(b[idx]);
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 'I')
            n++;
        else if (tmp[i] == 'V')
        {
            if (i > 0 && tmp[i - 1] == 'I')
            {
                n += 4;
                i--;
            }
            else
                n += 5;
        }
        else
        {
            n += 9;
            i--;
        }
    }

    cout << n << '\n';

    while (n >= 1000)
    {
        n -= 1000;
        cout << "M";
    }

    if (n >= 900)
    {
        n -= 900;
        cout << "CM";
    }
    else if (n >= 500)
    {
        cout << "D";
        n -= 500;
    }
    else if (n >= 400)
    {
        cout << "CD";
        n -= 400;
    }
    while (n >= 100)
    {
        n -= 100;
        cout << "C";
    }

    if (n >= 90)
    {
        n -= 90;
        cout << "XC";
    }
    else if (n >= 50)
    {
        cout << "L";
        n -= 50;
    }
    else if (n >= 40)
    {
        cout << "XL";
        n -= 40;
    }
    while (n >= 10)
    {
        n -= 10;
        cout << "X";
    }

    if (n >= 9)
    {
        n -= 9;
        cout << "IX";
    }
    else if (n >= 5)
    {
        cout << "V";
        n -= 5;
    }
    else if (n >= 4)
    {
        cout << "IV";
        n -= 4;
    }
    while (n >= 1)
    {
        n--;
        cout << "I";
    }
}

// 기호	I	V	X	L	C	D	M
// 값	1	5	10	50	100	500	1000

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