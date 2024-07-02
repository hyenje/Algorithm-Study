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
#define NUM 1'000'000

const int mx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[8] = {0, 0, -1, 1, 1, -1, 1, -1};

vector<int> arr(1'000'123), visited(1'000'123, 1);

int solve()
{
    int a, b;
    cin >> a >> b;
    if (a == -1 && b == -1)
        return 1;

    cout << a << ' ' << b << ' ';
    a = max(a, 0);
    b = max(b, 0);
    cout << visited[b] - visited[a - 1] << ' ' << arr[b] - arr[a - 1] << '\n';

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j * j + i * i <= 1'000'000; j++)
            arr[i * i + j * j] = 1;

    visited[0] = visited[1] = 0;
    for (int i = 2; i < 500'123; i++)
    {
        if (!visited[i])
            continue;
        for (int j = 2; i * j <= NUM; j++)
            visited[i * j] = 0;
    }

    for (int i = 1; i < 1'000'123; i++)
        arr[i] = (arr[i] & visited[i]) + arr[i - 1];

    for (int i = 1; i < 1'000'123; i++)
        visited[i] = visited[i] + visited[i - 1];

    // ll t;
    // cin >> t;
    while (true)
    {
        if (solve())
            break;
    }

    return 0;
}
/*
 */