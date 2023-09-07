//
// Created by mjk on 2023-07-17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Struct*/
struct Flower {
    int sm, sd, em, ed;
};

/*Function*/
bool compare(Flower &a, Flower &b) {
    if (a.sm == b.sm) {
        return a.sd < b.sd;
    }
    return a.sm < b.sm;
}

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    vector<Flower> data(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> data[i].sm >> data[i].sd >> data[i].em >> data[i].ed;
    }
    /*Solve*/
    data[n] = {12, 1, 12, 31};
    sort(data.begin(), data.end(), compare);
    vector<Flower> stack(n + 2);
    stack[0] = {1, 1, 3, 1};
    int top = 0;
    for (auto &i: data) {
        for (int j = top; j >= 0; j--) {
            if (((i.sm * 100 + i.sd) <= (stack[j].em * 100 + stack[j].ed)) &&
                ((i.em * 100 + i.ed) >= (stack[j].em * 100 + stack[j].ed))) {
                stack[j + 1] = i;
                top = j + 1;
            } else {
                break;
            }
        }
    }
    /*Output*/
    if (stack[top].em == 12 && stack[top].ed == 31) {
        cout << top - 1;
    } else {
        cout << "0";
    }
    return 0;
}