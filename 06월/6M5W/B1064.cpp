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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int istri(int x1, int y1, int x2, int y2, int x3, int y3) {
	if ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)) return 1;
	else return 0;
}

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double trimax(double A, double B, double C) {
	if (A >= B && A >= C) return A;
	else if (B >= A && B >= C) return B;
	else return C;
}

double trimin(double A, double B, double C) {
	if (A <= B && A <= C) return A;
	else if (B <= A && B <= C) return B;
	else return C;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	//cout.precision(100);
	int x1, x2, x3, y1, y2, y3;
	double d1, d2, d3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	if (istri(x1, y1, x2, y2, x3, y3)) {
		d1 = dist(x1, y1, x2, y2);
		d2 = dist(x2, y2, x3, y3);
		d3 = dist(x3, y3, x1, y1);
		printf("%.10f", 2 * (trimax(d1, d2, d3) - trimin(d1, d2, d3)));
	}
	else cout << -1.0;
	return 0;
}