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
vector<int> w;
vector<int> a;
vector<int> b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp, before;
	cin >> N;
	v.resize(N, 0);
	b.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	w.push_back((int)-2e9); a.push_back(-1);
	for (i = 0; i < N; i++) {
		temp = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
		if (temp == w.size()) {
			w.push_back(v[i]);
			a.push_back(i);
		}
		else {
			w[temp] = v[i];
			a[temp] = i;
		}
		b[i] = a[temp - 1];
	}

	temp = a[a.size() - 1];
	while (temp != -1) {
		before = temp;
		temp = b[temp];
		b[before] = -2;
	}
	cout << w.size() - 1 << '\n';
	for (i = 0; i < N; i++) if (b[i] == -2) cout << v[i] << " ";

	return 0;
}
