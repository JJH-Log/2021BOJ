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

vector<vector<int>> vMax;
vector<vector<int>> vMin;

int tmax(int a, int b, int c) {
    int result;
    result = max(a, b);
    result = max(result, c);
    return result;
}

int tmin(int a, int b, int c) {
    int result;
    result = min(a, b);
    result = min(result, c);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, N, x, y, z;
    cin >> N;
    vMax.resize(2, vector<int>(3, 0));
    vMin.resize(2, vector<int>(3, 0));
    for (i = 0; i < N; i++) {
        cin >> x >> y >> z;
        if (!i) {
            vMax[0][0] = x, vMax[0][1] = y, vMax[0][2] = z;
            vMin[0][0] = x, vMin[0][1] = y, vMin[0][2] = z;
        }
        else {
            vMax[1][0] = x + max(vMax[0][0], vMax[0][1]);
            vMax[1][1] = y + tmax(vMax[0][0], vMax[0][1], vMax[0][2]);
            vMax[1][2] = z + max(vMax[0][1], vMax[0][2]);

            vMin[1][0] = x + min(vMin[0][0], vMin[0][1]);
            vMin[1][1] = y + tmin(vMin[0][0], vMin[0][1], vMin[0][2]);
            vMin[1][2] = z + min(vMin[0][1], vMin[0][2]);

            swap(vMax[0], vMax[1]);
            swap(vMin[0], vMin[1]);
        }
    }
    cout << tmax(vMax[0][0], vMax[0][1], vMax[0][2]) << " ";
    cout << tmin(vMin[0][0], vMin[0][1], vMin[0][2]);
    return 0;
}