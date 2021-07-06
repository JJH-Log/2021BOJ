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


int ccw(int dx1, int dy1, int dx2, int dy2) {
	int cross = dy2 * dx1 - dy1 * dx2;
	if (cross > 0) return 1;
	else if (cross < 0) return -1;
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << ccw(x2 - x1, y2 - y1, x3 - x2, y3 - y2);
	return 0;
}