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

priority_queue<pair<int, int>> pq;


int main() {
    int x, y, N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        pq.push(make_pair(-x, -y));
    }

    while (!pq.empty()) {
        printf("%d %d\n", -pq.top().first, -pq.top().second);
        pq.pop();
    }
    return 0;
}

