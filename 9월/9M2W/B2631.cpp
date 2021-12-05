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

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, idx, temp, N;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
		if (idx == v.size()) v.push_back(temp);
		else v[idx] = temp;
	}
	cout << N - v.size();
	return 0;
}