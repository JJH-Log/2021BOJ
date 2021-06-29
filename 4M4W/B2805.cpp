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

	long long i, N, M;
	long long temp, mid, l, r;
	cin >> N >> M;

	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];

	l = 0;
	r = 1000000000;
	while (true) {
		//cout << l << " " << r << endl;
		temp = 0;
		mid = (l + r + 1) / 2;
		for (i = 0; i < N; i++) temp += max((long long)0, v[i] - mid);
		if (temp < M) r = mid - 1;
		else l = mid;
		if (l == r) break;
	}
	cout << l;
}

