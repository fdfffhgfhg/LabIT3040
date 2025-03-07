// Ta Quoc Tuan 20225110
#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int n, r;
int prices[MAX + 1][MAX + 1],
trace[MAX + 1], 
visited[MAX + 1], 
selection[MAX + 1], 
result[MAX + 1]; 

int start, 
des, 
best, 
sum, 
length; 

void input() {
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> prices[i][j];
        }
    }
}

bool check(int i, int j) {
    if (visited[selection[j]]) return false;
    if (prices[trace[i - 1]][selection[j]] == 0) return false;
    return true;
}

void solution(){
    if (prices[trace[length - 2]][des] != 0) best = min(best, sum + prices[trace[length - 2]][des]);
}

void TRY(int i) {
    if (sum > best) return; 
    for (int j = 1; j <= length - 2; ++j) {
        if (check(i, j)) {
            visited[selection[j]] = true;
            sum += prices[trace[i - 1]][selection[j]];
            trace[i] = selection[j];

            if (i == length - 2) solution();
            else TRY(i + 1);

            visited[selection[j]] = false;
            sum -= prices[trace[i - 1]][selection[j]];
        }
    }
}

int main() {
	// Ta Quoc Tuan 20225110
    input();
    string str;
    stringstream ss;
    getline(cin, str);
    int t = 0;
    while (t < r) {
        getline(cin, str);
        length = 0;
        best = INT_MAX;
        sum = 0;
        memset(visited, 0, sizeof(visited));
        stringstream ss(str);
        while (ss >> selection[length++]);
        length--;
        start = selection[0];
        des = selection[length - 1];
        trace[0] = start;
        TRY(1);
        result[t++] = (best == INT_MAX ? 0 : best);
    }
    for (t = 0; t < r; ++t) {
        cout << result[t] << endl;
    }
    return 0;
}
