//
// Created by mjk on 2023-12-27.
//
#include <iostream>

using namespace std;
/*Main*/
int main() {
    /*Input,Solve,Output*/
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int h, w, n; cin >> h >> w >> n;
        int result;
        if (n % h == 0) {
            result = (h * 100)+(n/h);
        } else {
            result = ((n % h)*100)+(n/h)+1;
        }
        cout << result << "\n";
    }
}