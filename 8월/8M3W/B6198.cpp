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

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, N;
	lld result = 0;

	cin >> N;
	s.push(2e9);
	for (i = 0; i < N; i++) {
		cin >> t;
		while (t >= s.top()) s.pop();
		result += (s.size() - 1);
		s.push(t);
	}
	cout << result;
	return 0;
}