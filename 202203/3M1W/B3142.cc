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
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};
pos p[200];
double v[200][200];
double d[200][200];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(3);

	int t_case = 1;
	while (true) {
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
		pos a, b;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a = p[i], b = p[j];
				v[i][j] = v[j][i] = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
				d[i][j] = v[i][j];
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == k || j == k) continue;
					if (d[i][j] > max(d[i][k], d[k][j])) {
						d[i][j] = max(d[i][k], d[k][j]);
					}
				}
			}
		}
		cout << "Scenario #" << t_case << '\n';
		cout << "Frog Distance = " << d[0][1] << '\n';
		cout << '\n';
		t_case++;
	}

	return 0;
}
