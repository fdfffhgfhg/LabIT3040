#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
// Ta Quoc Tuan 20225110
int gcd2(int a, int b){
    
    //# Kh? d? quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    if(b==0) return a;
    int max ;
    for(int i = (a>b)?a:b ; i >= 1 ; i--){
    	if((a%i == 0)&&(b%i == 0)){
    		max = i;
    		break;
		}
	}
	return max;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
