#include <bits/stdc++.h>
using namespace std;
#define MAX 100  
// Ta Quoc Tuan 20225110
int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau
int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
int curr[MAX]; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

//# �?c d? li?u v�o
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

//# Thu?t to�n quay lui
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
