#define _CRT_SECURE_NO_WARNINGS
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
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


priority_queue<pair<int, int>> pq;
vector<int> v;

int find(int X) {
	if (v[X] == X) return X;
	else return v[X] = find(v[X]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, p, d;
	v.resize(200001, 0);
	cin >> N;
	for (int i = 0; i < 200001; i++) v[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> d >> p;
		pq.push({ p, d });
	}
	pair<int, int> now;
	lld result = 0;
	while (!pq.empty()) {
		now = pq.top();
		pq.pop();
		d = find(now.second);
		if (d) {
			result += now.first;
			v[d] = find(d - 1);
		}
	}
	cout << result;
	return 0;
}