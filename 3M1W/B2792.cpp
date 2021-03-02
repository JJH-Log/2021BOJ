#include<iostream>
#include<queue>
#include<vector>
#include <cmath>
using namespace std;

vector<int> jewel;


int main()
{
    long long N, M, result;
    long long i, left, right, temp, mid;

    cin >> N >> M;
    jewel.resize(M);
    
    for (i = 0; i < M; i++) {
        cin >> jewel[i];
    }

    left = 1;
    right = 1e9;
    result = 1e9;

    while (left <= right) {
        mid = (left + right) / 2;
        temp = 0;
        for (i = 0; i < M; i++) {
            temp += jewel[i] / mid;
            if (jewel[i] % mid != 0) {
                temp ++;
            }
        }
        if (temp > N) {
            left = mid + 1;
        }
        else {
            if (result > mid) {
                result = mid;
            }
            right = mid - 1;
        }
    }
    
    cout << result;

    return 0;
}

//내가 놓친 것
//[1] : jewel[i] % mid != 0 의 경우를 놓쳤다.
//[2] : left = 1 을 넣지 않았다.
//[3] : right = 1e9 가 아닌 N 을 넣어버렸다.
