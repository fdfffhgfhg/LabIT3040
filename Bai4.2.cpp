#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;
// Ta Quoc Tuan 20225110
double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    double x = sqrt(pow(a.first - b.first , 2) + pow(a.second-b.second,2));
    double y = sqrt(pow(a.first - c.first , 2) + pow(a.second-c.second,2));
    double z = sqrt(pow(b.first - c.first , 2) + pow(b.second-c.second,2));
    double p = (x + y + z)/2;
    double square = p * (p - x) * (p - y) * (p - z);
    square = sqrt(square);
    return square;  
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl; 
	return 0;
 }
