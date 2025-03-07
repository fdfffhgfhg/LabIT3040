#include <stdio.h>
// Ta Quoc Tuan 20225110
void rotate(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int x, y, z;
    
    //# Nh?p 3 s? nguyên
    /*****************
    # YOUR CODE HERE #
    *****************/
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
