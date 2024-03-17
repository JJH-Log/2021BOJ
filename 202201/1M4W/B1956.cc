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
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[400][400];
int V, E;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			v[i][j] = 1e8;
		}
	}
	int x, y, d;
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> d;
		v[x - 1][y - 1] = d;
	}
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	int result = 1e8;
	for (int i = 0; i < V; i++) result = min(result, v[i][i]);
	if (result == 1e8) cout << -1;
	else cout << result;
	
	return 0;
}
