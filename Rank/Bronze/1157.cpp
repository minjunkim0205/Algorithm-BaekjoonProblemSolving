//
// Created by mjk on 2023-07-08.
//
#include <iostream>

using namespace std;

int main() {
    /*Input*/
    char s[1000001];
    cin >> s;
    /*Solve*/
    int a_to_z['Z' - 'A' + 1]; // A~Z(65~90), a~z(97~122)
    for (char c : s) {
        if (c == '\0') {
            break;
        }
        if (('A' <= c) && (c <= 'Z')) {
            a_to_z[int(c) - 'A']++;
        } else {
            a_to_z[int(c) - 'a']++;
        }
    }
    bool check_non_max_number = true;
    for (int i = 0; i < ; ++i) {
        if () {
            // 여기까지 하자
        }
    }
    /*Output*/
    return 0;
}