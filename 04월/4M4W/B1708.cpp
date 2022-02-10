#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

struct point{
	pair<int, int> pos; //x, y
	pair<int, int> dpos; //dx, dy from smallest point
};

bool compare(point A, point B) { 
	if ((long long)A.dpos.first * B.dpos.second == (long long)B.dpos.first * A.dpos.second) { // Adx/Ady 와 Bdx/Bdy 를 Compare
		if (A.dpos.second == B.dpos.second) return A.dpos.first < B.dpos.first; //dy가 같을 때, dx가 작은 점 (가까운 점)이 선호출되도록
		else return A.dpos.second < B.dpos.second; //dy가 다르다면 dy가 작은 점(가까운 점)이 선호출되도록
	}
	else return (long long)A.dpos.first * B.dpos.second > (long long)B.dpos.first * A.dpos.second; //기울기가 같지 않다면, 기울기 크기 내림차순 정렬
}

vector<point> v;
vector<int> idx;

bool isOnLeft(int a, int b, int c) {
	//(x2 - x1)(y3 - y1) > (y2 - y1)(x3 - x1)
	return ((long long)v[b].pos.first - v[a].pos.first) * ((long long)v[c].pos.second - v[a].pos.second) > ((long long)v[c].pos.first - v[a].pos.first) * ((long long)v[b].pos.second - v[a].pos.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x, y, i;
	pair<int, int> mpos{ 40001, 40001 }; //최솟값 가지는 점 찾기
	point temp;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		if (y < mpos.second) mpos = make_pair(x, y);
		if (y == mpos.second && x < mpos.first) mpos = make_pair(x, y); //최솟값 탐색
		temp.pos = make_pair(x, y); //dpos Constructor 만드는 대신 그냥 point struct 에 값넣고 때려넣기
		v.push_back(temp);
	}
	// dx, dy 구하기
	for (i = 0; i < N; i++) {
		v[i].dpos.first = v[i].pos.first - mpos.first;
		v[i].dpos.second = v[i].pos.second - mpos.second;
	}  
	// compare에 따른 정렬
	sort(v.begin(), v.end(), compare);

	// 맨끝점 = 원점 (Curvex Hull Start Point == End Point)
	v.push_back(v[0]);
	
	for (i = 0; i < N + 1; i++) {
		if (idx.size() < 2) idx.push_back(i); //점이 2개 미만이면 push_back
		else {
			if (isOnLeft(idx[idx.size() - 2], idx[idx.size() - 1], i)) idx.push_back(i); //왼쪽에 있으면(볼록하면) push_back 
			else {idx.pop_back(); i--;} //같거나 오른쪽에 있으면 pop 및 i감소(형태 유지)
		}
	}
	cout << idx.size() - 1; //원점, 맨끝점 중복 제거 (-1)
}

