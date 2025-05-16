/*
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include <map>
using namespace std;
#define INF 2147483647


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s, a; cin >> n >> m >> s;
	// - >  priority_queue<int, vector<int>, less<int>> pq;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<vector<pair<int, int>>> go(20001);
	vector<int> dosi(20001, INF);
	bool visit[20001] = {0};

	int f, t, b;
	for (int i = 0; i < m; i++) {
		cin >> f >> t >> b;
		go[f].push_back(make_pair(t,b));
	}

	q.push(make_pair(0, s));
	dosi[s] = 0;

	while (!q.empty()) {
		int money = q.top().first;
		int start = q.top().second;
		q.pop();
		if (visit[start])
			continue;
		visit[start] = 1;

		for (int i = 0; i < go[start].size(); i++) {
			int next_start = go[start][i].first;
			int next_money = go[start][i].second + money;
			if (dosi[next_start] > next_money) {
				q.push({next_money, next_start});
				dosi[next_start] = next_money;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dosi[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dosi[i] << '\n';
	}

	return 0;
}