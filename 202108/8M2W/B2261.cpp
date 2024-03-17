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

vector<pair<int, int>> v;

int getDS(pair<int, int> x, pair<int, int> y) { //Distance Square
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

pair<int, int> rev(pair<int, int> x) {
	return { x.second, x.first };
}

bool isInRange(int i, int j, int dist) {
	if (i == j) return false;
	return (v[i].first - v[j].first) * (v[i].first - v[j].first) > dist;
}

set<pair<int,int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N;
	int d, bidx; //shortest distance, bound index
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	d = getDS(v[0], v[1]);
	s.insert(rev(v[0]));
	s.insert(rev(v[1]));
	bidx = 0;
	
	for (i = 2; i < N; i++) {
		while (isInRange(bidx, i, d)) s.erase(rev(v[bidx++]));

		auto start = s.lower_bound({ v[i].second - sqrt(d), MININT });
		auto end = s.lower_bound({ v[i].second + sqrt(d), MAXINT });
		for (auto it = start; it != end; it++) d = min(d, getDS(rev(*it), v[i]));
		
		s.insert(rev(v[i]));
	}
	
	cout << d;

	return 0;
}