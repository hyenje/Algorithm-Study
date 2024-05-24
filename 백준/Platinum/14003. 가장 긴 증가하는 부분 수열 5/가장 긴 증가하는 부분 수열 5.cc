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

vector<int> arr, answer, indice;

void solve()
{
    int n;
    cin >> n;

    arr.resize(n);
    indice.resize(n);

    for (auto &i : arr)
        cin >> i;
    int last_index = 0;
    for (int i = 0; i < n; i++)
    {
        auto iter = lower_bound(answer.begin(), answer.end(), arr[i]) - answer.begin();
        if (iter == answer.size())
        {
            answer.push_back(arr[i]);
            last_index = i;
        }
        else
            answer[iter] = arr[i];
        indice[i] = iter;
    }
    int num = answer.size() - 1;
    answer.clear();
    for (int i = last_index; i >= 0; i--)
    {
        if (indice[i] == num)
        {
            answer.push_back(arr[i]);
            num--;
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << indice[i] << ' ';
    // cout << '\n';
    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i] << ' ';
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