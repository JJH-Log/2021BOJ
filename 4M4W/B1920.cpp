#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N;
int binary_search(int target) {
	int l = 0;
	int r = N - 1;
	int mid;
	while (true) {
		mid = (l + r + 1) / 2;
		if (v[mid] == target) return 1;
		if (v[mid] > target) r = mid - 1;
		else l = mid + 1;
		if (l > r) return 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, temp, M;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> temp;
		cout << binary_search(temp) << "\n";
	}
}
