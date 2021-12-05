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


int N, M;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, result;
	cin >> N >> M;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	if (!M) {
		cout << 0;
		return 0;
	}

	i = j = 0;
	result = 2e9 + 1;
	while (j != N) {
		if (v[j] - v[i] >= M) result = min(result, v[j] - v[i]), i++;
		else j++;
	}
	cout << result;


	return 0;
}