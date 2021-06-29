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

#define zz 101000
//브루트포스
vector<int> v;
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(zz, 0);
	int A, B, temp, step;
	cin >> A >> B;
	while (A < zz) {
		q.push(A), v[A] = 1, A *= 2;
		if (!A) break;
	}
	while (true) {
		temp = q.front();
		step = v[temp];
		if (temp == B) break;
		temp++;
		while (temp >= 0 && temp < zz) {
			if (!v[temp]) q.push(temp), v[temp] = step + 1;
			if (!temp) break;
			temp *= 2;
		}
		temp = q.front() - 1;
		while (temp >= 0 && temp < zz) {
			if (!v[temp]) q.push(temp), v[temp] = step + 1;
			if (!temp) break;
			temp *= 2;
		}
		q.pop();
	}
	cout << step - 1;
	return 0;
}