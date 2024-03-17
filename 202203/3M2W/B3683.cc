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

struct info {
	int ty, x, y;
};

info getInfo(string s1, string s2) { return { s1[0] - 'C', stoi(s1.substr(1)) - 1, stoi(s2.substr(1)) - 1 }; }

vector<int> w[500];
int par[500];
bool vtd[500];
info v[500];
int C, D, V, res;

bool bipartite(int X) {
	vtd[X] = 1;
	for (auto tar : w[X]) {
		if (par[tar] == -1 || !vtd[par[tar]] && bipartite(par[tar])) {
			par[tar] = X;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	string s1, s2;

	cin >> T;
	while (T--) {
		cin >> C >> D >> V;
		for (int i = 0; i < V; i++) {
			cin >> s1 >> s2;
			v[i] = getInfo(s1, s2);
		}
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (v[i].ty != v[j].ty && v[i].x == v[j].y) {
					w[i].push_back(j);
					w[j].push_back(i);
				}
			}
		}
		memset(par, -1, sizeof par);
		res = 0;
		for (int i = 0; i < V; i++) {
			memset(vtd, 0, sizeof vtd);
			if (v[i].ty == 0 && bipartite(i)) res++;
		}
		cout << V - res << '\n';
		for (int i = 0; i < V; i++) w[i].clear();
	}



	return 0;
}