#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<bool> v;
int N, result;

void ans(int num, int digit) {
	int i, now, s;
	if (digit == 6) return;
	for (i = 0; i < 10; i++) {
		if (v[i]) {
			now = 10 * num + i;	
			result = min(result, abs(N - now) + digit + 1);
			if ((digit != 0) || (i != 0)) ans(now, digit + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, M, temp;
	cin >> N >> M;
	v.resize(10, true);
	result = abs(N - 100);
	for (i = 0; i < M; i++) {
		cin >> temp;
		v[temp] = false;
	}
	ans(0, 0);
	cout << result;
	return 0;
}

