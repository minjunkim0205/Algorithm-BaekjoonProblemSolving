#include <iostream>

using namespace std;

int check(int a, int b, int c)
{
    return(a*a+b*b==c*c);
}

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b+c == 0){ break; }
        if(check(a,b,c)||check(a,c,b)||check(b,c,a))
        {
            cout << "right" << '\n';
        }
        else
        {
            cout << "wrong" << '\n';
        }
    }
    return 0;
}