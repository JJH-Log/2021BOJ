#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

bool robot[100];
int belt[200];
int N, K;

void rotate(){
	int tmp = belt[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; i--) belt[i] = belt[i - 1];
	belt[0] = tmp;

	for (int i = N - 2; i >= 0; i--){
		if(robot[i]){
			if(i != N - 2) robot[i + 1] = true;
			robot[i] = false;
		}
	}
}

void move(){
	for (int i = N - 2; i >= 0; i--){
		if(robot[i] && !robot[i + 1] && belt[i + 1]){
			belt[i + 1]--;
			if(i != N - 2) robot[i + 1] = true;
			robot[i] = false;
		}
	}
}

void addr(){
	if(belt[0]) {
		robot[0] = true;
		belt[0]--;
	}
}

int check(){
	int ans = 0;
	for(int i = 0; i < 2 * N; i++) if(!belt[i]) ans++;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) cin >> belt[i];

	int phase = 1;
	while(true){
		rotate();
		move();
		addr();
		if(check() >= K) break;
		phase++;
	}
	cout << phase;

	return 0;
}