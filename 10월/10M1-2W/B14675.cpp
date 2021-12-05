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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	v.resize(N, 0);

	int x, y;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		v[x - 1]++, v[y - 1]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (x == 1 && v[y - 1] == 1) cout << "no\n";
		else cout << "yes\n";
	}



	return 0;
}