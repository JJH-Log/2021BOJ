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
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; (i + k) < N && (j + k) < M; k++) {
				if (v[i][j] == v[i + k][j] && v[i][j] == v[i][j + k] && v[i][j] == v[i + k][j + k]) result = max(result , (k + 1) * (k + 1));
			}
		}
	}
	cout << result;

	return 0;
}