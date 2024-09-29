#include <iostream>

using namespace std;

int dec_sum_cal(int n)
{
    int sum = n;
    while(n > 0)
    {
        sum += n%10;
        n = n/10;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if(n == dec_sum_cal(i)) 
        {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}