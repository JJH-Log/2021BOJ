#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, B, temp, result, rfloor;
	int before, after;
	v.resize(257, 0);
	cin >> N >> M >> B;
	for (i = 0; i < N * M; i++) {
		cin >> temp;
		v[temp]++;
	}
	result = 2100000000;
	for (i = 0; i <= 256; i++) {
		before = 0; after = 0;
		for (j = 0; j < i; j++) before += v[j] * (i - j);
		for (j = i + 1; j <= 256; j++) after += v[j] * (j - i);
		//cout << i << " " << before << " " << after << endl;
		if ((before <= B + after) && ((before + 2 * after) <= result)) {
			result = before + 2 * after;
			rfloor = i;
		}
	}
	cout << result << " " << rfloor;
}

