#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;
vector<int> vi;
vector<int> trap;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(101, 0);
	vi.resize(101, 0);
	trap.resize(101, 0);
	int i, a, b, N, M, temp;
	cin >> N >> M;
	for (i = 1; i <= 100; i++) v[i] = i + 1;
	for (i = 0; i < N + M; i++) {
		cin >> a >> b;
		v[a] = b;
		trap[a] = 1;
	}
	q.push(1);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (i = 1; i <= 6; i++) {
			if (temp + i <= 100) {
				if (trap[temp + i]) {
					if ((vi[temp + i] == 0) && (vi[v[temp + i]] == 0)) {
						vi[temp + i] = vi[temp] + 1;
						vi[v[temp + i]] = vi[temp] + 1;
						q.push(v[temp + i]);
					}
				}
				else {
					if (vi[temp + i] == 0) {
						vi[temp + i] = vi[temp] + 1;
						q.push(temp + i);
					}
				}
			}
		}
	}
	cout << vi[100];
	return 0;
}