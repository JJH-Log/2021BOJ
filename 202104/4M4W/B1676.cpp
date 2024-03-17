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

	int i, N;
	cin >> N;
	v.resize(N + 1, 0);
	for (i = 1; i <= N; i++) {
		if (i % 5 == 0) {
			if (i % 25 == 0) {
				if (i % 125 == 0)  v[i] = v[i - 1] + 3;
				else  v[i] = v[i - 1] + 2;
			}
			else v[i] = v[i - 1] + 1;
		}
		else v[i] = v[i - 1];
	}
	cout << v[N];
	return 0;
}

