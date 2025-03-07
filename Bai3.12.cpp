#include<bits/stdc++.h>
#define MAX 100
using namespace std;
// Ta Quoc Tuan 20225110
int n,k,m;
int a[MAX][MAX];
bool visited[MAX];
int cnt = 0;
int x[MAX];

// Ham nhap input
void input(){
	cin>>n>>k>>m;
	memset(a,0,sizeof(a));
	for(int i = 1 ; i <= m ; i++ ){
		int x,y;
		cin>>x>>y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	memset(visited,false,sizeof(visited));
}
// Ham thu
void TRY(int index = 2){
	if(index > k+1){
		cnt++;
		return;
	}
	else{
	for(int i = 1 ; i != x[index-1] , i <= n ; i++){
		if((!visited[i])&&(a[x[index-1]][i]!=0)){
			// Gan gia tri
			x[index] = i;
			visited[i] = true;
			TRY(index+1);
			visited[i] = false;
		}
	}
}
}
// Ham giai
void solution(){
	for(int i = 1 ; i <= n ;i++){
		x[1] = i;
		visited[i] = true;
		TRY();
		visited[i] = false;
	}
	cout<<cnt/2;
}
int main(){
		
	input();
	solution();
	return 0;
}

