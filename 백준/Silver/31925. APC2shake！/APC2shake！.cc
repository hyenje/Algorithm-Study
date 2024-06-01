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

vector<pair<int, string>> arr;

void solve()
{
    int n, num;
    cin >> n;
    string s;
    pair<int, string> tmp;
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        int flag = 0;

        cin >> s;
        tmp.S = s;

        cin >> s;
        if (s == "hewhak")
            flag = 1;

        cin >> s;
        if (s == "winner")
            flag = 1;

        cin >> num;
        if (num <= 3 && num > 0)
            flag = 1;

        cin >> num;
        tmp.F = num;

        if (flag == 0)
            arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < min(10, (int)arr.size()); i++)
        answer.push_back(arr[i].S);

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
}
int main()
{

    solve();
    return 0;
}

/*
 */