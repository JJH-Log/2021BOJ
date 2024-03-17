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

vector<lld> v;
lld result;
int N, K;

lld getNum(int x, int y) {
	int s = x + y;
	if (s < N) {
		if (s % 2) return v[s] - y;
		else return v[s] - x;
	}
	else {
		if (s % 2) return v[s] - (y - (s - (N - 1)));
		else return v[s] - (x - (s - (N - 1)));
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	string s;

	cin >> N >> K;
	cin >> s;

	int cnt = 1;
	v.resize(2 * N - 1, 0);
	v[0] = 1;
	for (i = 1; i < N; i++) v[i] = v[i - 1] + i + 1;
	for (i = N; i < 2 * N - 1; i++) v[i] = v[i - 1] + 2 * N - 1 - i;

	int x, y;
	x = y = 0;
	result = 1;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'D') x++;
		if (s[i] == 'R') y++;
		if (s[i] == 'U') x--;
		if (s[i] == 'L') y--;
		result += getNum(x, y);
	}
	cout << result;

	return 0;
}