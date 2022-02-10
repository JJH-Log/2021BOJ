#include <iostream>
#include <vector>
#include <algorithm> //reverse 사용
using namespace std;
vector<int> v;
int g(int X) {while (!v[X]) X--; return X;}
int f(int X) {if (v[X]) return v[X]; else return f(X - g(X));}
int main() {
	int N;
	cin >> N;
	v.resize(N + 1, 0);
    v[1] = 1;
	int p = 1, q = 1;
	while (1) {
		p += q;
		if (p > N) break;
		v[p] = p;
		swap(p, q);
	}
	if (v[N] == N) cout << -1;
	else cout << f(N);
	return 0;
}