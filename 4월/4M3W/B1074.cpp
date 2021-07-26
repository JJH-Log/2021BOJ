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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, r, c;
	long long result, temp;
	cin >> N >> r >> c;
	result = 0;
	temp = 1;
	while ((r != 0) || (c != 0)) {
		result += temp * (long long)((r % 2) * 2 + (c % 2));
		temp *= 4;
		r = r >> 1;
		c = c >> 1;
	}
	cout << result;
	return 0;
}
