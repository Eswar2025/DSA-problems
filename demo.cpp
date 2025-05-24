#include <iostream>

using namespace std;

int main()
{
    int x, y, n, number;
    cin >> n;
    cin >> number;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> y;
        if (x / 2 > y / 3)
        {
            cout << 2 * y << "\n";
        }
        else
            cout << 3 * x << "\n";
    }
    
    while (n--)
    {
        /*Code here  */
    }
    return 0;
}