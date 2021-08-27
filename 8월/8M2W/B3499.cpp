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

struct pp {
	int num; //DNA number
	bool vg, vl; //vg - female : true, vl - live : true
};

vector<pp> v;
vector<int> dna;
map<int, int> m;
set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, M, K;
	char c;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> c;
		if (c == 'M') v.push_back({ -i, true, true });
		else v.push_back({ -i, false, true });
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> x;
		if (x < 0) v[-x - 1].vl = false;
		else {
			cin >> y >> c;
			x--, y--;
			if (v[y].vg) swap(x, y);
			if (c == 'M') v.push_back({ v[y].num, true, true });
			else v.push_back({v[y].num, false, true});
		}
	}

	cin >> K;
	for (i = 0; i < K; i++) {
		cin >> x >> y;
		m[v[x - 1].num] = y;
	}

	for (i = 0; i < v.size(); i++) {
		if (v[i].vl) {
			if (m.count(v[i].num)) s.insert(m[v[i].num]);
			else s.insert(v[i].num);
		}
	}

	if (s.size() == 1) cout << "YES";
	else {
		int cnt = 0;
		for (auto it = s.begin(); it != s.end(); it++) if ((*it) > 0) cnt++;
		if (cnt > 1) cout << "NO";
		else cout << "POSSIBLY";
	}

	return 0;
}