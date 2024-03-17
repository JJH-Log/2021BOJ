#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용


//배운점이 많은 코드
//1. 자료형을 vector<vector<int>> 선언 후 NxN 크기로 할당하니 메모리 초과
//2. 자료형을 vector<vector<char>> 선언 후 int <-> char 변환, 시간초과
//3. 자료형을 vector<vector<pair<int,int>> 로 변경, 시간초과
//4. priority_queue 도입, 시간초과
//5. cin을 scanf로 변경, 성공!!!



using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> cost;
priority_queue<pair<int, int>> pq;

int main() {
	int i, N, M;
	int start;
	int x, y, d;
	int now_y, now_d;

	scanf("%d %d \n %d", &N, &M, &start);
	v.resize(N + 1); //간선을 저장할 벡터 (distance, nodeName) 형식
	cost.resize((N + 1), 10000000); //비용

	for (i = 0; i < M; i++) {
		scanf("%d %d %d",&x,&y,&d);
		v[x].push_back(make_pair(-d, y));
	}

	cost[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		now_y = pq.top().second;
		now_d = -pq.top().first;
		pq.pop();
		if (cost[now_y] < now_d) continue;
		for (i = 0; i < v[now_y].size(); i++) {
			y = v[now_y][i].second;
			d = cost[now_y] - v[now_y][i].first;
			if (cost[y] > d) {
				cost[y] = d;
				pq.push(make_pair(-d, y));
			}
		}
	}

	for (i = 1; i <= N; i++) {
		if (cost[i] == 10000000) printf("INF\n");
		else printf("%d\n",cost[i]);
	}
	return 0;
}
