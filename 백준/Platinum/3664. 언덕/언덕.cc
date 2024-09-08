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
    int n;
    double a, b, v, f, dis = 0, x, y, alpha;

    cin >> a >> b >> v >> f;
    cin >> n;
    vector<double> vel(n), road(n);
    f *= 1000;
    // v /= 1000.0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        // x /= 1000.0;
        // y /= 1000.0;
        road[i] = sqrt(x * x + y * y);
        dis += road[i];
        if (y < 0)
            vel[i] = min(v, b * (-y) / (x * a));
        else if (y > 0)
            f -= y * b * road[i] / (x);
    }

    if (f < 0.0)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    else if (f == 0.0)
    {
        for (int i = 0; i < n; i++)
        {
            if (vel[i] == 0.0)
            {
                printf("IMPOSSIBLE\n");
                return;
            }
        }
    }
    double l = 0, r = v, answer = 0;
    int cnt = 500;
    // for (int i = 0; i < n; i++)
    //     pre += road[i] * vel[i];
    // cout << pre << ' ' << f << '\n';
    while (cnt--)
    {
        double mid = (l + r) / 2.0;
        double use = f;
        double t = 0;
        for (int i = 0; i < n; i++)
        {
            if (vel[i] > mid)
                continue;
            use -= a * (mid - vel[i]) * road[i];
        }
        // cout << use << '\n';

        if (use < 0)
            r = mid;
        else
            l = mid;
    }

    for (int i = 0; i < n; i++)
        answer += road[i] / max(l, vel[i]);
    printf("%.6lf\n", answer / 1000.0);
    // cout << answer / 1000.0 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/*
 */