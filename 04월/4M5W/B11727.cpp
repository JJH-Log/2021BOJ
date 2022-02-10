#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	cin >> N;
	v.resize(max(2, N), 0);
	v[0] = 1;
	v[1] = 3;
	for (i = 2; i < N; i++) v[i] += (v[i - 1] + v[i - 2] * 2) % 10007;
	cout << v[N - 1];
	return 0;
}