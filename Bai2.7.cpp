#include <iostream>
using namespace std;
// Ta Quoc Tuan 20225110
//# vi?t h�m arr_sum
/*****************
# YOUR CODE HERE #
*****************/
template<typename T> T arr_sum(T x[] , int size1 , T y[] , int size2){
    T sum = 0;
    for(int i = 0;i<size1;i++){
        sum+=x[i];
    }
    for(int i = 0;i<size2;i++){
        sum+=y[i];
    }
    return sum;
}

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
