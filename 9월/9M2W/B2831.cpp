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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v, w;
vector<int> sv, sw;
int N;


int solve() {
	if (v.size() == 0 || w.size() == 0) return 0;
	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), greater<int>());
	int l, r, result;
	l = r = result = 0;
	while (true) {
		if (l == v.size() || r == w.size()) break;
		if (v[l] + w[r] < 0) result++, l++;
		r++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, temp, result;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0) v.push_back(temp);
		else sw.push_back(temp);
	}
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0) sv.push_back(temp);
		else w.push_back(temp);
	}
	result = solve();
	v = sv;
	w = sw;
	result += solve();
	cout << result;
	return 0;
}