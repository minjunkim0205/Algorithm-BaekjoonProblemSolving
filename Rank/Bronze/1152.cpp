//
// Created by mjk on 2023-07-08.
//
#include <iostream>

using namespace std;

int main() {
    /*Input*/
    char s[1000001];
    cin.getline(s, 1000001);
    /*Solve*/
    int count_word = 1;
    for (int i = 0; i < 1000001 - 1; ++i) {
        if (s[i] == '\0') {
            if (s[i-1] == ' ') {
                count_word--;
            }
            break;
        }
        if ((s[i]!=' ')&&(s[i+1]==' ')) {
            count_word++;
        }
    }
    /*Output*/
    cout << count_word;
    return 0;
}