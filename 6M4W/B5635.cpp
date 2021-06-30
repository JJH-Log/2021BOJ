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

struct pf {
	int yy;
	int mm;
	int dd;
	string s;
};

bool cmp(pf& A, pf& B) {
	if (A.yy == B.yy) {
		if (A.mm == B.mm) return A.dd < B.dd;
		else return A.mm < B.mm;
	}
	else return A.yy < B.yy;
}

vector<pf> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, N;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i].s >> v[i].dd >> v[i].mm >> v[i].yy;
	sort(v.begin(), v.end(), cmp);
	cout << v[N - 1].s << '\n' << v[0].s;
	return 0;
}