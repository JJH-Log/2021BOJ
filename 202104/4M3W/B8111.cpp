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

vector<bool> v;
queue<pair<string, int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, t;
	int temp_m, x1, x2;
	string temp_s;
	string result;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		v.clear();
		v.resize(N + 1, true);
		while (!q.empty()) q.pop();
		result = "BRAK";
		q.push(make_pair("1", 1));
		v[1] = false;
		while (!q.empty()) {
			temp_s = q.front().first;
			temp_m = q.front().second;
			q.pop();
			if (temp_m == 0) {
				result = temp_s;
				break;
			}
			temp_m = (temp_m * 10) % N;
			if (v[temp_m]) {
				v[temp_m] = false;
				q.push(make_pair(temp_s + "0", temp_m));
			}
			temp_m = (temp_m + 1) % N;
			if (v[temp_m]) {
				v[temp_m] = false;
				q.push(make_pair(temp_s + "1", temp_m));
			}
		}
		cout << result << "\n";
	}

	return 0;
}
