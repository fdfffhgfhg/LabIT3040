// Ta Quoc Tuan 20225110
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Luu t?a d? c�c bu?c di chuy?n c?a qu�n m�
int mark[100][100]; //# ��nh d?u v? tr� c�c � m� qu�n m� d� di chuy?n qua

//# M?ng hx, hy m� t? 8 v? tr� qu�n m� c� th? di chuy?n k? t? v? tr� hi?n t?i
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra d�y c�c di chuy?n t�m du?c
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}
// Ham kiem tra mot o co thoa man hay khong
bool checkok(int xx , int yy){
	if(mark[xx][yy] == 1) return false;
	if(xx < 1 || xx > n || yy < 1 || yy > n) return false;
	return true;
}
//# Thu?t to�n quay lui
void TRY(int k){
	// Neu da di du roi thi ta se in ra ket qua
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        /*****************
        # YOUR CODE HERE #
        *****************/
        // neu o dang xet thoa man
        if(checkok(xx,yy)){
        	// Gan gia tri cho x[k]
                mark[xx][yy] = 1; 
        	     X[k] = xx;
        	     Y[k] = yy;
        	    if(k == n*n) print_sol();
        	    else{
        	    	TRY(k+1);
				}
        	     mark[xx][yy] = 0;   // tra lai gia tri quay lui		 
		}
    }
    
      
}

int main(){
	cin>>n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
