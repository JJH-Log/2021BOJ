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
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
vector<int> w;
int N;

lld merge_sort(int l, int r) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	lld result = 0;
	result += merge_sort(l, mid);
	result += merge_sort(mid + 1, r);
	int i, j, now;
	i = now = l;
	j = mid + 1;
	for (int t = l; t <= r; t++) {
		if (i == mid + 1) w[now++] = v[j++];
		else if (j == r + 1) w[now++] = v[i++];
		else {
			if (v[i] <= v[j]) w[now++] = v[i++];
			else {
				result += j - now;
				w[now++] = v[j++];
			}
		}
	}
	for (int t = l; t <= r; t++) v[t] = w[t];
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);
	w.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << merge_sort(0, N - 1);

	return 0;
}