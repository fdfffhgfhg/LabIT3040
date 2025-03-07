#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
// Ta Quoc Tuan 20225110
int TEST_CASE;
int n[MAX] , h[MAX] ; 
int bin[MAX];

// Ham nhap input
void input(){
	cin>>TEST_CASE;
	for(int i = 1 ; i <= TEST_CASE ; i++ ){
		cin>>n[i]>>h[i];
	}
	memset(bin,0,sizeof(bin));
}
// Ham in ra ket qua
void printoutanswer(int n){
	for(int i = 1 ; i <= n ; i++){
		cout<<bin[i];
	}
	cout<<'\n';
}
// bool checkok
bool checkok(int n , int h){
	int sum = 0;
	for(int i = 1; i <= n ; i++ ){
		sum += bin[i];
	}
	if(sum == h) return true;
	else {
		return false;
	}
}
// Ham solution cho tung truong hop nho
void TRY(int n , int h , int k = 1){
	if( k>n ){
		if(checkok(n,h)){
			printoutanswer(n);
			return ;
		}
		else return;
	}
	else{
		bin[k] = 0;
		TRY(n,h,k+1);
		bin[k] = 1;
		TRY(n,h,k+1);
	}
}
// Ham giai bai toan lon
void solution(){
	for(int i = 1 ; i <= TEST_CASE ; i++){
		TRY(n[i],h[i]);
		cout<<'\n';
	}
}
int main(){
	input();
	solution();
	return 0;
}
