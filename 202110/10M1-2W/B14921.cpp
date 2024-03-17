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

	int i, j, N, result, FLAG;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	i = 0, j = N - 1;
	result = 2e9 + 1;
	while (i != j) {
		if (abs(v[i] + v[j]) < result) {
			if (v[i] + v[j] < 0) FLAG = -1;
			else FLAG = 1;
			result = abs(v[i] + v[j]);
		}
		if (v[i] + v[j] <= 0) i++;
		else j--;
	}
	cout << FLAG * result;


	return 0;
}