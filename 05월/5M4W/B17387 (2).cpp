#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

int outer(pair<int, int> a, pair<int, int> b) {
	long long r = (long long)b.second * a.first - (long long)a.second * b.first;
	if (r > 0) return 1; //cw
	if (r < 0) return -1; //ccw
	return 0; //parallel
}

pair<int, int> dxy(pair<int, int> a, pair<int, int>b) {
	return { b.second - a.second, b.first - a.first };
}

int isIntersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int ab = outer(dxy(a, b), dxy(a, c)) * outer(dxy(a, b), dxy(a, d));
	int cd = outer(dxy(c, d), dxy(c, a)) * outer(dxy(c, d), dxy(c, b));
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	vector<pair<int, int>> v;
	v.resize(4, pair<int, int>({ 0,0 }));
	for (i = 0; i < 4; i++) cin >> v[i].first >> v[i].second;
	cout << isIntersect(v[0], v[1], v[2], v[3]);

	return 0;
}
