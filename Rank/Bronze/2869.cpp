#include <iostream>

using namespace std;

int main()
{
    int a, b ,v;
    cin >> a >> b >> v;

    cout << ((v-b)%(a-b)==0 ? (v-b)/(a-b) : (v-b)/(a-b)+1);

    return 0;
}