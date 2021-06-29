#include <iostream>
#include <vector>
using namespace std;

vector<long long int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, K, N;
	long long l, r, mid, temp;
	cin >> K >> N;
	v.resize(K, 0);
	for (i = 0; i < K; i++) cin >> v[i];
	l = 1; r = INT32_MAX;
	while (true) {
		mid = (l + r + 1) / 2;
		temp = 0;
		for (i = 0; i < K; i++) temp += v[i] / mid;
		if (temp < N) r = mid - 1;
		else l = mid;
		if (l == r) break;
	}
	cout << l;
}
