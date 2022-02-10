#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용

using namespace std;

//round-off 테크닉 : 0.5를 더한뒤에 int 형변환 해주기
//[ex] 6.25 * 100 => 625.00004는 625가 되지만 624.999998 은 624가 되므로 0.5를 더해줌
int ans(int N, int M) {
	int i, j, temp_N, temp_M, cost;
	double m;

	vector<pair<int, int>> candy;
	vector<int> money;
	money.resize(M+1, 0);
	for (i = 0; i < N; i++) {
		cin >> temp_N >> m;
		temp_M = int(m * 100 + 0.5);
		candy.push_back(pair<int,int>(temp_N, temp_M));
	}
	for (i = 0; i < M; i++) {
		for (j = 0; j < candy.size(); j++) {
			cost = i + candy[j].second; //비용
			if (cost <= M) money[cost] = max(money[cost], money[i] + candy[j].first);
		}
	}
	return money[M];
}

//알고리즘 : DP, 배낭 문제
int main() {
	int N,M;
	double m;
	while (true) {
		cin >> N >> m;
		if ((N == 0) && (int(m + 0.5) == 0)) break;
		M = int(m * 100 + 0.5);
		cout << ans(N, M) << endl;
	}
	return 0;
}
