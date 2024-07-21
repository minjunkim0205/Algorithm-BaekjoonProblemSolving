#include <iostream>

using namespace std;
/*Main*/
int main()
{
    // Input
    int m, n;
    cin >> m >> n; // 1 <= M <= N <= 1,000,000
    // Solve[sieve of Eratosthenes(에라토스테네스의 체)]
    bool flag[1000000 + 1] = {false,};
    flag[1] = true;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; i * j <= n; j++)
        {
            flag[i * j] = true;
        }
    }
    // Ouput
    for (int i = m; i <= n; i++)
    {
        if (!flag[i])
        {
            cout << i << '\n';
        }
    }
    return 0;
}