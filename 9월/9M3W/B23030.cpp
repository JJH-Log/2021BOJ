#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<pair<int, int>>> w;
vector<int> v;
int N, M, K, T;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp, p1, p2, q1, q2;
	pair<int, int> now;
	cin >> N;
	w.resize(50 * N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 1; j < temp; j++) {
			w[i * 50 + j - 1].push_back({ i * 50 + j , 1 });
			w[i * 50 + j].push_back({ i * 50 + j - 1 , 1 });
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> q1 >> p2 >> q2;
		w[50 * p1 + q1 - 51].push_back({50 * p2 + q2 - 51 , 0 });
		w[50 * p2 + q2 - 51].push_back({ 50 * p1 + q1 - 51 , 0 });
	}
	cin >> K;
	while (K--) {
		cin >> T >> p1 >> q1 >> p2 >> q2;
		v.resize(50 * N, 1e9);
		v[50 * p1 + q1 - 51] = 0;
		pq.push({ 0, 50 * p1 + q1 - 51 });
		while (!pq.empty()) {
			now = pq.top();
			pq.pop();
			if (now.first == v[now.second]) {
				for (auto next : w[now.second]) {
					if (v[next.first] > v[now.second] + next.second + (next.second ^ 1) * T) {
						v[next.first] = v[now.second] + next.second + (next.second ^ 1) * T;
						pq.push({ v[next.first], next.first });
					}
				}
			}
		}
		cout << v[50 * p2 + q2 - 51] << '\n';
		v.clear();
	}

	
	
	return 0;
}