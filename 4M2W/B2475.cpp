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
	int temp;
	int ans = 0;

	for (int i = 0; i < 5; i++) {
		cin >> temp;
		ans += temp * temp;
	}
	cout << ans % 10;
	return 0;
}