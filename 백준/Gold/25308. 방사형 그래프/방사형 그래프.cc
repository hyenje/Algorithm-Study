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

double CCW(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
void solve()
{
    int answer = 0;
    int num = 200'000;
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
        arr[i] += num * i;
    }
    do
    {
        int flag = 0;
        for (int i = 0; i < 8; i++)
        {
            if (CCW(0, (double)(arr[i] % num), (double)(arr[(i + 1) % 8] % num) / sqrt(2), (double)(arr[(i + 1) % 8] % num) / sqrt(2), (double)(arr[(i + 2) % 8] % num), 0) > 0)
                flag = 1;
        }
        if (flag == 0)
            answer++;
    } while (next_permutation(arr.begin(), arr.end()));

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