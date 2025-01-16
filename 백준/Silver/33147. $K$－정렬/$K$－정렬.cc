#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FASTIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)

void solve()
{
    int n, k, flag = 0;
    cin >> n >> k;

    int val = __gcd(n, k);
    vector<int> arr(n);
    vector<map<int, int>> brr(val);
    for (auto &i : arr)
        cin >> i;

    for (int i = 0; i < n; i++)
        brr[i % val][i] = 1;

    for (int i = 0; i < n; i++)
    {
        if (brr[i % val][arr[i]])
            continue;
        else
            flag = 1;
    }

    if (flag)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    FASTIO;

    solve();
    return 0;
}