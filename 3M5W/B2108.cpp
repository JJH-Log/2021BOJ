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

vector<int> v;
int main() {
    int i, N, temp;
    int vmin = 0, vmax = 8000, vcount = 0, vcount2;
    double vsum = 0;
    cin >> N;
    v.resize(8001, 0);

    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        v[temp + 4000]++;
        vsum += temp;
    }

    //산술평균
    printf("%.0f\n", (vsum/N));

    //중앙값
    i = 0;
    while (vcount <= (N / 2)) {
        vcount += v[i];
        i++;
    }
    printf("%d\n", i - 4001);

    //최빈값
    vcount = 0; vcount2 = 0;
    for (i = 0; i < 8001; i++) {
        if (v[i] == vcount) vcount2++;
        if (v[i] > vcount) {
            vcount = v[i];
            vcount2 = 1;
        }
    }
    for (i = 0; i < 8001; i++) {
        if (vcount2 == 1) {
            if (v[i] == vcount) {
                printf("%d\n", i - 4000);
                i = 8001;
            }
        }
        else {
            if (v[i] == vcount) vcount2 = 1;
        }
    }

    //범위 : vmax-vmin
    while (v[vmax] == 0) vmax--;
    while (v[vmin] == 0) vmin++;
    printf("%d\n", vmax - vmin);
    

}

