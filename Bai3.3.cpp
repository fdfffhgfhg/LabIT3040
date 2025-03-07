#include <bits/stdc++.h>
using namespace std;
#define MAX 100  
// Ta Quoc Tuan 20225110
int n, c[MAX][MAX]; //# s? thành ph? và ma tr?n chi phí
int cmin = INT_MAX; //# chi phí di l?i nh? nh?t gi?a hai thành ph? khác nhau
int best = INT_MAX; //# t?ng chi phí nh? nh?t c?n tìm, ban d?u d?t b?ng giá tr? vô cùng l?n INT_MAX = 2^31-1
int curr[MAX]; //# t?ng chi phí t?i th?i di?m hi?n t?i
int mark[MAX]; //# dánh d?u nh?ng thành ph? dã di
int x[MAX]; //# luu gi? các thành ph? dã di

//# Ð?c d? li?u vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    for(int i = 0;i < MAX ; i++){
    	curr[i] = 0;
    	x[i] = 0;
    	mark[i] = 0;
	}    
}

//# Thu?t toán quay lui
void TRY(int k){
	if(k == n+1){
		curr[k] = curr[k-1]+c[x[k-1]][1];
		if(curr[k] < best){
			best = curr[k];
		}
		return;
	}
    for(int i = 2; i <= n; i++){
        /*****************
        # YOUR CODE HERE #
        *****************/
        // neu thanh pho chua duoc tham
        if(mark[i] == 0){
        	// neu chi phi cong vao < mincost thi cap nhat
        	if(curr[k-1] + c[x[k-1]][i] < best){
        		// cap nhat
        		x[k] = i;
        		curr[k] = curr[k-1] + c[x[k-1]][i];
        		mark[i] = 1;
        		// Quay lui tiep
        		TRY(k+1);
        		// Tra lai gia tri
        		mark[i] = 0;
			}
		}
        
    }
}

int main() {
    input();
    x[1] = 1;
    mark[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
