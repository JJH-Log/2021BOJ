#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> A;
vector<int> B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, a, b;
	cin >> a >> b;
	A.resize(a + 1, 0);
	B.resize(b + 1, 0);
	for (i = 0; i < a; i++) cin >> A[i];
	for (i = 0; i < b; i++) cin >> B[i];
	A[a] = MOD, B[b] = MOD;
	i = 0, j = 0;
	while (true) {
		if (A[i] == MOD && B[j] == MOD) break;
		if (A[i] <= B[j]) cout << A[i++] << ' ';
		else cout << B[j++] << ' ';
	}
	return 0;
}