#include<iostream>
#include <stack>
using namespace std;
struct state {
	int i, j;
	state(int _i = 0, int _j = 0): i(_i), j(_j){}
};

int main() {
	int n, M;
	cin >> n >> M;
	int m[n+1];
	for (int i = 1; i <= n; i++) cin >> m[i];
	int* x = new int(n + 1);
	stack<state> s;
	//#sum of selected weights
	int sum = 0;
	s.push(state(1, -1));
	while (!s.empty()) {
		state& top = s.top();
		if (top.i > n) {
			sum = 0; 
			for (int i = 1; i <= n; i++) sum += x[i] * m[i];
			if (sum == M) {
				for (int i = 1; i <= n; i++) {
					if (x[i] == -1) cout << '-' << m[i];
					if (x[i] == 1) cout << '+' << m[i];
				}
				cout << "=" << M;
				exit(0);
			}
			s.pop();
			continue;
		}
		// Khử đệ quy
		//Code tại đây
		if (top.j > 1) {
			s.pop();
			continue;
		}
		if (top.j <= 1) {
			x[top.i] = top.j;
			s.push(state(top.i + 1, -1));
		}
		top.j++;
	}
	cout << -1;
	return 0;
}
