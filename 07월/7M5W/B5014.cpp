#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	v.resize(F + 1, -1);

	v[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		if (now == G) break;
		q.pop();
		if (now - D > 0 && v[now - D] == -1) v[now - D] = v[now] + 1, q.push(now - D);
		if (now + U <= F && v[now + U] == -1) v[now + U] = v[now] + 1, q.push(now + U);
	}
	if (v[G] == -1) cout << "use the stairs";
	else cout << v[G];

	return 0;
}