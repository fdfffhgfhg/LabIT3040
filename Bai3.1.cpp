#include<bits/stdc++.h>
// Ta Quoc Tuan 20225110
using namespace std;
int lucas(int n){
	if(n<0) return 0;
	else if(n == 0) return 2;
	else if( n == 1 ) return 1;
	else {
		return lucas(n-1) + lucas(n-2);
	}
}
int main(){
	int n;
	cin>>n;
	cout<<lucas(n)<<"\n";
	return 0;	
}
