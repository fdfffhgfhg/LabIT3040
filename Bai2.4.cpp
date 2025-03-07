#include <stdio.h>
#include<math.h>
// Ta Quoc Tuan 20225110
int cube(int x) {
    //# tr? v? l?p phuong c?a x
    /*****************
    # YOUR CODE HERE #
    *****************/
    return x*x*x;
}

//# vi?t hàm tính l?p phuong c?a m?t s? ki?u double
double cube(double x){
    return pow(x,3);
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
