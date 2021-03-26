#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용

using namespace std;


bool sosu(int X) {
	//2,3,4 일 경우에도 성립
	if (X == 1) return false;
	bool flag = true;
	for (int i = 2; i <= int(sqrt(X)+0.5); i++) {
		if (X % i == 0) flag = false;
	}
	return flag;
}

bool pdrome(int X) {
	string x;
	x = to_string(X);
	reverse(x.begin(), x.end());
	return (x == to_string(X));
}

int main() {
	int N;
	cin >> N;
	int result = N;
	if (result >= 98690) result = 1003001;
	while (true) {
		if (sosu(result) && pdrome(result)) break;
		else result++;
	}
	cout << result;
	return 0;
}
