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

vector<pair<int, int>> v;
vector<pair<int, int>> w; //for answer
vector<int> a;
vector<int> b;
queue<pair<int, int>> q;

int lbound(int l, int r, int X) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	int result = -1;
	// if (w[mid].second == X) return mid;  -> No same case
	if (w[mid].second > X) result = lbound(l, mid, X);
	if (w[mid].second < X) result = lbound(mid + 1, r, X);
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp, before;
	cin >> N;
	v.resize(N, pair<int, int>(0, 0));
	b.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	w.push_back({ -1, -1 }); a.push_back(-1);
	for (i = 0; i < N; i++) {
		temp = lbound(0, w.size() - 1, v[i].second);
		if (w[temp].second < v[i].second) {
			w.push_back(v[i]);
			a.push_back(i);
			b[i] = a[temp];
		}
		else {
			w[temp] = v[i];
			a[temp] = i;
			b[i] = a[temp - 1];
		}
	}
	cout << N - w.size() + 1 << '\n';
	temp = a[w.size() - 1];
	while (temp != -1) {
		before = temp;
		temp = b[temp];
		b[before] = -2;
	}
	for (i = 0; i < N; i++) if (b[i] != -2) cout << v[i].first << '\n';
	


	return 0;
}
