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
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int m[1010][1010];
int deg[1010], tar[1010];
bool vtd[1010];
int N;

void getEuler(int now) {
	for (int& next = tar[now]; next < N; next++) {
		while(m[now][next]){
			m[now][next]--;
			m[next][now]--;
			getEuler(next);
		}
	}
	cout << now + 1 << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			deg[i] += m[i][j];
		}
	}
	int startPoint;
	for (int i = 0; i < N; i++) {
		if (deg[i] % 2) {
			cout << -1;
			return 0;
		}
	}
	fill(tar, tar + 1010, 0);
	getEuler(0);

	return 0;
}
