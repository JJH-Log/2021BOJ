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

int step(int X) {
	int result;
	int temp;
	result = 0;
	while (X) {
		temp = X % 10;
		result += temp * temp;
		X /= 10;
	}
	return result;
}

int check(int A, int B) {
	map<int, int> m;
	int i, now, next;
	now = A; i = 1;
	while (true) {
		m[now] = i;
		i++;
		next = step(now);
		if (m.count(next)) break;
		else now = next;
	}
	now = B; i = -1;
	if (!m.count(now)) {
		while (true) {
			m[now] = i;
			i--;
			next = step(now);
			if (m.count(next)) break;
			else now = next;
		}
	}
	else next = now;
	if (m[next] > 0) return m[next] - i;
	else return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, A, B, now, next;
	int ans1, ans2;
	while (true) {
		cin >> A >> B;
		if (!A && !B) break;
		cout << A << ' ' << B << ' ';
		cout << min(check(A, B), check(B, A)) << '\n';
	}
	
	return 0;
}