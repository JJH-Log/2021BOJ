#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<int> v[2000];
vector<bool> vtd;
int p[2000], q[1000];
int N, M;

bool binMatch(int now) {
	vtd[now] = true;
	for (auto tar : v[now]) {
		if (q[tar] == -1 || !vtd[q[tar]] && binMatch(q[tar])) {
			p[now] = tar;
			q[tar] = now;
			return true;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, task;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> task;
			v[2 * i].push_back(task - 1);
			v[2 * i + 1].push_back(task - 1);
		}
	}
	for (int i = 0; i < M; i++) q[i] = -1;

	int result = 0;
	for (int i = 0; i < 2 * N; i++) {
		vtd.resize(2 * N, false);
		result += binMatch(i);
		vtd.clear();
	}
	cout << result;
	
	return 0;
}