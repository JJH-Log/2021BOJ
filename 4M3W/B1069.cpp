#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<vector<int>> v;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int X, Y, D, T, k;
	double length;
	double result = 100000000;
	scanf("%d %d %d %d", &X, &Y, &D, &T);
	//cin >> X >> Y >> D >> T;
	length = sqrt(X * X + Y * Y);
	if (T >= D)  result = length;
	else {
		k = int(length / D);
		if (k <= 1) result = 2 * T;
		else result = (k + 1) * T;
		result = min(result, length - k * D + k * T);
		result = min(result, (k + 1) * D - length + (k + 1) * T);
		//printf("%.10f", min((length - k * D) + k * T, ((k + 1) * D - length) + (k + 1) * T));
		//cout << min((length - k * D) + k * T, ((k + 1) * D - length) + (k + 1) * T);
	}
	printf("%.10f", result);
	return 0;
}
