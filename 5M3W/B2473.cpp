#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, tar, temp;
	int x, y, z;
	long long result;
	cin >> N;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	result = 4e9;
	for (k = 1; k < N - 1; k++) {
		i = 0, j = N - 1;
		tar = -v[k];
		while (i != j) {
			if (i == k) { i++; continue; }
			if (j == k) { j--; continue; }
			temp = v[i] + v[j];
			if (temp == tar) {
				x = i; y = j; z = k;
				break;
			}
			if ((abs)((long long)temp - tar) < result) {
				result = (abs)((long long)temp - tar);
				x = i; y = j; z = k;
			}
			if (temp < tar) i++;
			if (temp > tar) j--;
		}
	}
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
	cout << v[x] << " " << v[y] << " " << v[z];
	return 0;
}