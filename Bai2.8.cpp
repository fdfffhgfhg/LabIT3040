#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// Ta Quoc Tuan 20225110
using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# s?p x?p các vector trong a theo t?ng các ph?n t? gi?m d?n
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(),a.end(), [](vector<int> vt1 , vector<int> vt2) -> bool {
        return accumulate(vt1.begin(),vt1.end(),0)>accumulate(vt2.begin(),vt2.end(),0);
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Ta Quoc Tuan 20225110
