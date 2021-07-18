#include <iostream>
#include <stack>
using namespace std;

int N;
int num[1000001];
int cnt[1000001] = { 0 }; // i의 개수가
stack<int> s; // first : num, second : cnt
stack<int> ans;
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int now;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        cnt[num[i]]++;
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && cnt[s.top()] <= cnt[num[i]]) s.pop();
        now = num[i];
        if (s.empty()) num[i] = -1;
        else num[i] = s.top();
        s.push(now);
    }
    for (int i = 0; i < N; i++) cout << num[i] << ' ';
    return 0;
}