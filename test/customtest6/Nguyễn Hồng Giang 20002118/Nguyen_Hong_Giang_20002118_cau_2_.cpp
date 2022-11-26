#include <iostream>
using namespace std;

int main()
{
    int A[10][10], m, n, x, y;
    int a, b , i, j;
    cout << "Nhap so hang va so cot cua ma tran: ";
    cin >> n >> m;
    cout << "Nhap cac phan tu cua ma tran: ";
    for(x = 1; x < n+1; ++x)
     for(y = 1; y < m+1; ++y)
     {
        cout << "a[" << x << "]" << "[" << y << "] = ";
            cin >> A[x][y];;
     }
     cout << "Mang la: " << endl;
     for(x = 1; x < n+1; x++)
     {
     for(y = 1; y < m+1; y++)
     {
        cout << A[x][y] << " ";
     }
     cout << endl;
     }
    int min = A[1][1];
        for(x = 1; x < n+1; x++)
        for(y = 1; y < m+1; y++)
        {
            if(A[x][y] < min)
            {
                min = A[x][y];
                 a = x;
                 b = y;
            }
        }

  	cout << "Gia tri nho nhat trong mang la: ";
    cout << min << endl;
    cout << " Vi tri cua min la: " << "a[" << a << "]" << "[" << b << "]" << endl;
    
    int max = A[1][1];
        for(x = 1; x < n+1; x++)
        for(y = 1; y < m+1; y++)
        {
            if(A[x][y] > max)
            {
                max = A[x][y];
                 i = x;
                 j = y;
            }
        }
    cout << "Gia tri lon nhat trong mang la: ";
    cout << max << endl;
    cout << " Vi tri cua max la: " << "a[" << i << "]" << "[" << j << "]";
    
    return 0;
}
