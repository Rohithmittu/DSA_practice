#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;

        int temp = i;
        while (temp != 0)
        {

            int r = temp % 2;

            if (r == 0)
            {
                cnt++;
            }
            temp = temp / 2;
        }

        if (cnt % 2 == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}