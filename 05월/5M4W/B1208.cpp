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
map<int, int> A;
map<int, int> B;

void _sub(map<int, int>* m, int l, int r, int T, int FLAG) {
	for (int i = l; i <= r; i++) _sub(m, i + 1, r, T + v[i], 1);
	if (FLAG) {
		if (!(*m).count(T)) (*m)[T] = 1;
		else (*m)[T]++;
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, S, temp;
	long long result;
	map<int, int>::iterator iA, iB;
	cin >> N >> S;
	v.resize(N, 0);
	if (N == 1) {
		cin >> temp;
		if (temp == S) cout << 1;
		else cout << 0;
		return 0;
	}
	for (i = 0; i < N; i++) cin >> v[i];
	_sub(&A, 0, (N / 2) - 1, 0, 0);
	_sub(&B, (N / 2), N - 1, 0, 0);
	iA = A.begin(); iB = B.end(); result = 0;
	iB--;
	while (true) {
		temp = iA->first + iB->first;
		if (temp <= S) {
			if (temp == S) result += (long long)iA->second * iB->second;
			iA++;
			if (iA == A.end()) break;
		}
		else {
			if (iB == B.begin()) break;
			iB--;
		}
	}
	if (A.count(S)) result += A[S];
	if (B.count(S)) result += B[S];
	cout << result;
	return 0;
}
