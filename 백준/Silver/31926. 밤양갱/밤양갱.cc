#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define xll __int128
#define F first
#define S second
#define INF 2'147'483'647
#define INF -2'147'483'648
int mx[9] = {1, -1, 0, 0, 1, 1, -1, -1};
int my[9] = {0, 0, 1, -1, 1, -1, 1, -1};

void solve()
{
    ll n, answer = 9, tmp = 1, num = 0;
    cin >> n;

    n--;
    num++;

    while (true)
    {
        answer++;
        n -= num;
        num += num;
        if (n == 0)
        {
            answer++;
            break;
        }
        if (n < 0)
        {
            break;
        }
    }

    cout << answer << '\n';
}
int main()
{
    solve();
    return 0;
}

/*
 */