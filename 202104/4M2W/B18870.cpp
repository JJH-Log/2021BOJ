#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


vector<int> v;
vector<int> sv;
set<int> s;

int divcon(int left, int right, int target) {
	int mid = (left + right + 1) / 2;
	if (left == right) return left;
	if (sv[mid - 1] >= target) return divcon(left, mid - 1, target);
	else if (sv[mid] <= target) return divcon(mid, right, target);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp;
	cin >> N;

	v.resize(N, 0);
	//sv.resize(N, 0);
	for (i = 0; i < N; i++) {
		cin >> temp;
		v[i] = temp;
		s.insert(temp);
	}
	for (auto it = s.begin(); it != s.end(); ++it) sv.push_back(*it);
	for (i = 0; i < N; i++) {
		cout << divcon(0, sv.size() - 1, v[i]) << " ";
	}

	return 0;
}
