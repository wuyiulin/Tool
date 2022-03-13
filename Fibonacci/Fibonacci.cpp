#include "stdio.h"
#include <iostream>
#include <stdbool.h>
#include <vector>
#include <time.h>
using namespace std;



vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
    int M00, M01, M10, M11;
    M00 = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    M01 = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    M10 = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    M11 = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    A[0][0] = M00;
    A[0][1] = M01;
    A[1][0] = M10;
    A[1][1] = M11;
    //cout << "A[0][0]: " << A[0][0] << "\n";
    return A;
}

vector<vector<int>> Matrix_pow(vector<vector<int>> A, vector<vector<int>> B,int n)
{

    if (n==1)
    {
        return A;
    }

    else if (n%2==0)
    {
        vector<vector<int>> C = Matrix_pow( A, B, n/2);
        return multiply(C,C);
    }
    vector<vector<int>> C = Matrix_pow( A, B, (n-1)/2);
    return multiply(multiply(A, C), C);
}

int fibonacci_rec(int n)
{
    if( n==1 or n==2 )
        return 1;
    if( n >= 3 )
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
    return 0;
}

int fibonacci_matrix(int n)
{
    if (n<=0)
    {
        return 0;
    }
    else if (n==1 || n==2)
    {
        return 1;
    }
    
    int A[2][2] = {{1,1},{1,0}};
    int B[2][2] = {{1,1},{1,0}};
    int M00, M01, M10, M11;
    for (int i = 0; i < n-2;i++)
    {
        
        M00 = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        M01 = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        M10 = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        M11 = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        A[0][0] = M00;
        A[0][1] = M01;
        A[1][0] = M10;
        A[1][1] = M11;
        //cout << "A[0][0]: " << A[0][0] << "\n";
    }
    return A[0][0];
}

int fibonacci_pow_matrix(int n)
{
    if (n<=0)
    {
        return 0;
    }
    else if (n==1 || n==2)  
    {
        return 1;
    }


    vector<vector<int>> A = {{1,1},{1,0}};
    vector<vector<int>> B = {{1,1},{1,0}};
    return Matrix_pow(A, B, n-1)[0][0];
}

int main()
{
    clock_t start, end;
    string s = "111111111111111111111111111111111111111111111";
    int k = s.size();
    cout << "size of string s : " << k << "\n";
    start = clock();
    cout << "This is Rec sol: " << fibonacci_rec(k) << "\n";
    end = clock();
    double diff = end - start;
    cout << "Rec time: " << diff  << " ms\n";
    
    start = clock();
    cout << "This is Mat sol: " << fibonacci_matrix(k) << "\n";
    end = clock();
    diff = end - start;
    cout << "Mat time: " << diff << " ms\n";

    start = clock();
    cout << "This is Pow sol: " << fibonacci_pow_matrix(k) << "\n";
    end = clock();
    diff = end - start;
    cout << "Pow time: " << diff << " ms\n";
    
    system("pause");
    getchar();    
    return 0;
}