#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bfs(int n, int m) {
    vector<int> steppingNumbers;
    queue<int> q;
    for (int i = 0; i <= 9; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int stepNum = q.front();
        q.pop();
        if (stepNum >= n && stepNum <= m) {
            steppingNumbers.push_back(stepNum);
        }
        if (stepNum == 0 || stepNum > m) {
            continue;
        }
        int lastDigit = stepNum % 10;
        if (lastDigit > 0) {
            int nextStepNum = stepNum * 10 + (lastDigit - 1);
            if (nextStepNum <= m) {
                q.push(nextStepNum);
            }
        }
        if (lastDigit < 9) {
            int nextStepNum = stepNum * 10 + (lastDigit + 1);
            if (nextStepNum <= m) {
                q.push(nextStepNum);
            }
        }
    }
     return steppingNumbers;
}
int main() {
    int n, m;
    cout << "Enter range [n, m]: ";
    cin >> n >> m;
    vector<int> result = bfs(n, m);
    sort(result.begin(), result.end());
    cout << "Stepping Numbers: ";
    for (int num : result)  cout << num << " ";
    cout << endl;
    return 0;
}
