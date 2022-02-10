#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> pos;

int ans(int x, int y) {
	if (x == 0 && y == 0) return 1;
	int area, result, base, gap;
	area = -1, result = -1; base = -1, gap = -1;
	if (x + y > 0 && x - y >= 0) area = 0;
	else if (x + y <= 0 && x - y > 0) area = 1;
	else if (x + y < 0 && x - y <= 0) area = 2;
	else if (x + y >= 0 && x - y < 0) area = 3;
	if (area == 0) base = x, gap = x - y; //(2x + 1)^2 - (x - y);
	else if (area == 1) base = -y, gap = -x - y; //(2|y| + 1)^2 - 2|y| - (|y| - x);
	else if (area == 2) base = -x, gap = -x + y; //(2|x| + 1) * (2|x| + 1) - 4|x| - (|x| + y);
	else if (area == 3) base = y, gap = x + y; //(2y + 1)^2 - 6y - (x + y);
	return (2 * base + 1) * (2 * base + 1) - 2 * area * base - gap;
}

int getDigit(int X) {
	int cnt = 0;
	while (X) {
		X /= 10, cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, digit;
	pos.resize(4, 0);
	for (i = 0; i < 4; i++) cin >> pos[i];

	digit = 0;
	digit = max(digit, ans(pos[0], pos[1]));
	digit = max(digit, ans(pos[0], pos[3]));
	digit = max(digit, ans(pos[2], pos[1]));
	digit = max(digit, ans(pos[2], pos[3]));
	digit = getDigit(digit);

	for (i = pos[0]; i <= pos[2]; i++) {
		for (j = pos[1]; j <= pos[3]; j++) {
			cout.width(digit);
			cout.fill(' ');
			cout << ans(i, j) << ' ';
		}
		cout << '\n';
	}
	return 0;
}