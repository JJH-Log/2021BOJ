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


vector<int> v;
int pri[1000001];
int ti[1000001];
set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, now, before;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) {
		cin >> v[i];
		ti[v[i]]++;
		s.insert(v[i]);
	}
	for (auto it = s.begin(); it != s.end(); it++) pri[(*it)] = 0;
	before = 0;
	for (i = N - 1; i >= 0; i--) {
		now = v[i];
		if (now > before) pri[now] = pri[before] + 1;
		else pri[now] = max(pri[now] + 1, pri[before]);
		before = now;
	}

	cout << s.size() << '\n';
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << (*it) << ' ' << ti[(*it)] << ' ' << pri[(*it)] << '\n';
	}



	return 0;
}