#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#include <regex>
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

queue<int> line;
stack<int> space;
int N, X, tar;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	tar = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		line.push(X);
	}
	while (tar < N) {
		if (!space.empty() && space.top() == tar) {
			space.pop();
			tar++;
		}
		else if (!line.empty()) {
			if (line.front() == tar) {
				line.pop();
				tar++;
			}
			else {
				space.push(line.front());
				line.pop();
			}
		}
		else {
			cout << "Sad";
			return 0;
		}
	}
	cout << "Nice";

	return 0;
}