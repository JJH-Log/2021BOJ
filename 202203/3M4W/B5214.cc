#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int tube[1000][1000];
vector<int> cn[100001]; //Which tube connected
int N, K, M;
int dist[100001];
bool used[1000]; // check used of tube

queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> tube[i][j];
			cn[tube[i][j]].push_back(i);
		}
	}
	dist[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto tb : cn[now]) {
			if (used[tb]) continue;
			used[tb] = true;
			for (int i = 0; i < K; i++) {
				int next = tube[tb][i];
				if (!dist[next]) {
					dist[next] = dist[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << (dist[N] ? dist[N] : -1);

	return 0;
}