//
// Created by mjk on 2023-07-13.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*Struct*/
struct user{
    int number;
    int age;
    string name;
};
/*Function*/
bool compare(user &a, user &b) {
    if (a.age == b.age) {
        return a.number < b.number;
    }
    return a.age < b.age;
}
/*Main*/
int main() {
    /*Input*/
    int n; // 회원 수
    cin >> n;
    vector<user> data(n);
    for (int i = 0; i < n; ++i) {
        data[i].number = i;
        cin >> data[i].age >> data[i].name;
    }
    /*Solve*/
    sort(data.begin(), data.end(), compare);
    /*Output*/
    for (int i = 0; i < n; ++i) {
        cout << data[i].age << " " << data[i].name << "\n";
    }
    return 0;
}