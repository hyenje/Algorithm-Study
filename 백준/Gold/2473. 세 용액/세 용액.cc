#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include <map>
#include <stack>
#include <deque>
#include <functional>
#include <cmath>
using namespace std;
#define ll long long int
#define L_INF 1123123123123123123
#define INF 2147483647
#define l_INF 1000000007
#define MINF -2147483648
const int mx[5] = { 1,-1,0,0 };
const int my[5] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<ll> arr(5000);
	ll gotoZero = L_INF;
	int n; cin >> n;
	arr.resize(n);

	for (auto& i : arr)
		cin >> i;

	sort(arr.begin(), arr.end());

	vector<int> answer(3);
	for (int i = 0; i < n - 2; i++) {
		ll sum;
		int l = i + 1, r = n - 1;
		while (l < r) {
			sum = arr[i] + arr[l] + arr[r];

			if (gotoZero > abs(sum)) {
				answer[0] = i, answer[1] = l, answer[2] = r;
				gotoZero = abs(sum);
			}

			if (sum > 0)
				r--;
			else if (sum < 0)
				l++;
			else {
				cout << arr[i] << ' ' << arr[l] << ' ' << arr[r];
				return 0;
			}
		}
	}

	for (auto& i : answer)
		cout << arr[i] << ' ';

	return 0;
}