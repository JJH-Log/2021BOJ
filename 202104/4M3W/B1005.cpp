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

vector<vector<int>> p; //내가 가리키는
vector<vector<int>> q; //나를 가르키는
vector<int> cost; //cost
vector<int> qs; //psize
vector<int> M; //제일 큰 cost
queue<int> order;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, T, N, K;
	int t1, t2, temp;
	int target;
	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> N >> K;

		p.clear();
		q.clear();
		qs.clear();
		cost.clear();
		M.clear();
		while (!order.empty()) order.pop();

		p.resize(N + 1, vector<int>(0, 0));
		q.resize(N + 1, vector<int>(0, 0));
		qs.resize(N + 1, 0);
		cost.resize(N + 1, 0);
		M.resize(N + 1, 0);

		for (j = 1; j <= N; j++) cin >> cost[j];
		for (j = 1; j <= K; j++) {
			cin >> t1 >> t2;
			p[t1].push_back(t2);
			q[t2].push_back(t1);
			qs[t2]++;
		}

		for (j = 1; j <= N; j++) {
			if (qs[j] == 0) order.push(j);
		}

		cin >> target;
		while (qs[target] != 0) {
			temp = order.front();
			order.pop();
			M[temp] = M[temp] + cost[temp];
			for (j = 0; j < p[temp].size(); j++) {
				M[p[temp][j]] = max(M[p[temp][j]], M[temp]);
				qs[p[temp][j]] --;
				if (qs[p[temp][j]] == 0) order.push(p[temp][j]);
			}
		}
		cout <<  M[target] + cost[target] << "\n";

	}
	
	
	return 0;
}
