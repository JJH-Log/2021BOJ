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
stack<pair<int, int>> s;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, temp;
	cin >> N;
	v.resize(N, -1);
	for (i = 0; i < N; i++) {
		cin >> temp;
		while (!s.empty() && s.top().first < temp) {
			v[s.top().second] = temp;
			s.pop();
		}
		s.push({ temp, i });
	}
	for (i = 0; i < N; i++) cout << v[i] << ' ';
	return 0;
}