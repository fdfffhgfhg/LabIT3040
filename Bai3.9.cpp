#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
// Ta Quoc Tuan 20225110
int n , k1 , k2 ;
int bin[MAX];
int cnt[MAX];
 
// Ham nhap input
void input(){
	cin>>n>>k1>>k2;
	memset(bin,0,sizeof(bin));
	memset(cnt,0,sizeof(cnt));
}
// Ham in ra ket qua
void printoutanswer(){
	for(int i = 1 ; i <= n ; i++){
		cout<<bin[i];
    }
    cout<<'\n';
}
// bool kiem tra xem mot chuoi nhi phan co ok khong
bool checkok(){
	int max = INT_MIN;
	for(int i = 1 ; i <= n ; i++){
		if(bin[i] == 0){
			if((bin[i+1] == 0) && (i<n)) return false;
			 else{
			        cnt[i] = 0;
		     }
		}
		else if (bin[i] == 1){
			cnt[i] = cnt[i-1] + 1;
			if(cnt[i] > max){
				max = cnt[i];
			}
		}
	}
	if ((max < k1) || (max > k2)){
		return false;
	}
	else{
		return true;
	}
}
// Ham giai bai toan
void TRY(int k = 1){
	if( k > n ){
	     if(checkok()){
	     	printoutanswer();
	     	return;
		 }		
		 else return;	
	}
	else{
		// Gan bin[k] = 0
		bin[k] = 0;
		TRY(k+1);
		// Gan bin[k] = 1
		bin[k] = 1;
		TRY(k+1);
	}
}
int main(){
	input();
	TRY();
	return 0;
}
