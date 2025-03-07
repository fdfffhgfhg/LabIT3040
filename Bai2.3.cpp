#include <stdio.h>
#include<math.h>
// Ta Quoc Tuan 20225110
//# Vi?t hàm get_value
/*****************
# YOUR CODE HERE #
*****************/
int get_value(int x){
    return 2*pow(x,2) + x ;
}
int get_value(int x,int a){
    return a*pow(x,2) + x;
}
int get_value(int x,int a ,int b){
    return a*pow(x,2) + b*x;
}
int get_value(int x,int a,int b,int c){
    return a*pow(x,2) + b*x+ c;
}


int main(){
    int x;
    scanf("%d", &x);
    
    int a = 2; //# giá tr? m?c d?nh c?a a
    int b = 1; //# giá tr? m?c d?nh c?a b
    int c = 0; //# giá tr? m?c d?nh c?a c
    
    //# Nh?p 3 s? nguyên a, b, c t? bàn phím
    /*****************
    # YOUR CODE HERE #
    *****************/
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
