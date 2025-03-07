#include <stdio.h>
#include <math.h>
// Ta Quoc Tuan 20225110
float get_hypotenuse(float x, float y) {
    float sumsqrt;                         // z^2 = x^2 + y^2
    sumsqrt = pow(x,2) + pow(y,2);       // =>z = sqrt(x^2+y^2)
    float z = sqrt(sumsqrt);
    return z;
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}
