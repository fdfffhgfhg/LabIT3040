#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}
int luuvet[10000][10000];
void khoitao(int luuvet[10000][10000]){
	for(int i = 1;i<10000;i++){
		luuvet[0][i] = 1;
		luuvet[1][i] = i;
		luuvet[i][i] = 1;
	}
	for(int n = 2;n<10000;n++){
		for(int j = 2;j<n;j++){
			luuvet[j][n] = luuvet[j-1][n-1] + luuvet[j][n-1];
		}
	}
}
// Ta Quoc Tuan 20225110
int binom2(int n, int k){
    
    //# Kh? d? quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    return luuvet[k][n];
}

int main() {
    int m;
    cin >> m;
    khoitao(luuvet);
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
