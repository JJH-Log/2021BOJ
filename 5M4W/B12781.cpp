#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;

int clw(int x1, int y1, int x2, int y2) {
	long long result = (long long)x1 * y2 - (long long)x2 * y1;
	if (result > 0) return 1;
	else if (result < 0) return -1;
	return 0;
}

int dx(int a, int b) { return v[b][0] - v[a][0]; }
int dy(int a, int b) { return v[b][1] - v[a][1]; }

int ans(int a, int b, int c) {
	return clw(dx(a, b), dy(a, b), dx(a, c), dy(a, c));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, r1, r2, r3, r4, FLAG;
	v.resize(4, vector<int>(2, 0));
	for (i = 0; i < 4; i++) cin >> v[i][0] >> v[i][1];

	r1 = ans(0, 1, 2) * ans(0, 1, 3);
	r2 = ans(1, 0, 2) * ans(1, 0, 3);
	r3 = ans(2, 3, 0) * ans(2, 3, 1);
	r4 = ans(3, 2, 0) * ans(3, 2, 1);

	if ((r1 >= 0) || (r2 >= 0) || (r3 >= 0) || (r4 >= 0)) FLAG = 0;
	else FLAG = 1;
	cout << FLAG;
	return 0;
}
