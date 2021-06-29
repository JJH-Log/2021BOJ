#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
using namespace std;


vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	v.resize(500001, 0);
	v[1] = 1;
	v[2] = 2;
	cin >> N;
	for (i = 3; i <= N; i++) {
		if (i % 2 == 0) v[i] = 2 * v[i / 2];
		else v[i] = 2 * (v[(i + 1) / 2] - 1);
	}
	cout << v[N];
}

