//
// Created by mjk on 2023-09-07.
//
#include <iostream>
#include <ctime>

using namespace std;

/*Function*/
void customFormat(const int &size) {
    cout.width(size);
    cout.fill('0');
}

/*Main*/
int main() {
    /*Solve*/
    time_t timer = time(nullptr);
    struct tm *t = localtime(&timer);
    /*Output*/
    customFormat(4);
    cout << (t->tm_year + 1900) << "-";
    customFormat(2);
    cout << (t->tm_mon + 1) << "-";
    customFormat(2);
    cout << (t->tm_mday);
    return 0;
}