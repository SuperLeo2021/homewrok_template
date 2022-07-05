#include <iostream>

using namespace std;

int counter1 = 0;
int counter2 = 0;


int main()
{
    while (1)
    {
        counter1 = 0;
        counter2 = 0;
        int n = 0;
        cout << endl << "enter n;";
        cin >> n;
        DAC_f(n);
        DP_f(n);
        cout << "The number of additions using the split-and-conquer algorithm is:" << counter1 << endl << "The number of additions made using the dynamic programming algorithm is:" << counter2;

    }

    return 0;
}
//分治法
int DAC_f(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        counter1 += 1;
        return DAC_f(n - 1) + DAC_f(n - 2);
    }
}
//动态规划
int DP_f(int n)
{
    int f [n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            f[i] = 1;
        }
        else
        {
            counter2 += 1;
            f[i] = f[i - 1] + f[i - 2];
        }
    }
}
