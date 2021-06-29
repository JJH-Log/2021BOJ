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

vector<pair<int, int>> p;
pair<int, int> p_sum;
pair<int, int> p_temp;
double result;
int N;

double get_lengths(int x, int y) {
	return sqrt((double)x * x + (double)y * y);
}

void ans(int cnt, int idx) {
	int i, j;
	for (i = idx; i < N; i++) {
		p_temp.first += p[i].first;
		p_temp.second += p[i].second;
		if (cnt == N / 2 - 1) result = min(result, get_lengths((p_sum.first - 2 * p_temp.first), (p_sum.second - 2 * p_temp.second)));
		else ans(cnt + 1, i + 1);
		p_temp.first -= p[i].first;
		p_temp.second -= p[i].second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, i, t, x, y;
	cin >> T;

	for (t = 0; t < T; t++) {
		cin >> N;
		p.clear();
		p_sum = make_pair(0, 0);
		p_temp = make_pair(0, 0);
		result = 100000000.0;
		for (i = 0; i < N; i++) {
			cin >> x >> y;
			p.push_back(make_pair(x, y));
			p_sum.first += x;
			p_sum.second += y;
		}
		if (N == 2) {
			result = get_lengths(p[0].first - p[1].first, p[0].second - p[1].second);
		}
		else {
			p_temp.first += p[0].first;
			p_temp.second += p[0].second;
			ans(1, 1);
		}
		printf("%.7f\n", result);
	}
	return 0;
}
