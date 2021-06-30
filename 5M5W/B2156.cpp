#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;
vector<int> b;
vector<int> n;

int tmax(int x, int y, int z) {
	if (x >= y && x >= z) return x;
	else if (y >= x && y >= z) return y;
	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j;
	cin >> N;
	v.resize(N, 0);
	b.resize(3, -1);
	for (i = 0; i < N; i++) cin >> v[i];
	b[0] = 0; b[1] = v[0];
	for (i = 1; i < N; i++) {
		n.clear();
		n.resize(3, 0);
		n[0] = tmax(b[0], b[1], b[2]);
		n[1] = b[0] + v[i];
		n[2] = b[1] + v[i];
		swap(b, n);
	}
	cout << tmax(b[0], b[1], b[2]);
	return 0;
}