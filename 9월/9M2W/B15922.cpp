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

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, r, result;
	cin >> N;
	r = -1000000001;
	result = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (r == -1000000001) {
			result += y - x;
			r = y;
		}
		else if (r <= y) {
			result += y - max(x, r);
			r = y;
		}
	}
	cout << result;
	
	return 0;
}