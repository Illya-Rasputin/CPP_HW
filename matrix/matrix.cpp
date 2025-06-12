#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //ex1
    //int matrix[4][3];
    //int count = 0;
    //for (int i = 0; i < 4; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        matrix[i][j] = rand() % 100;
    //        //matrix[i][j] = rand() %90 + 10;//90-99
    //        //cout << left<<  setw(5) <<  matrix[i][j] ;
    //        cout << setw(5) << matrix[i][j];
    //        if (matrix[i][j] != 0)
    //        {
    //            count += 1;
    //        }
    //    }
    //    cout << endl;
    //}
    //cout << count;

    //ex2
    //int matrix[3][3];
    //int count = 0;
    //for (int i = 0; i < 3; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        matrix[i][j] = rand() % 100;
    //        //matrix[i][j] = rand() %90 + 10;//90-99
    //        //cout << left<<  setw(5) <<  matrix[i][j] ;
    //        cout << setw(5) << matrix[i][j];
    //        if (matrix[i][j] == 0)
    //        {
    //            count += 1;
    //        }
    //    }
    //    cout << endl;
    //}
    //cout << count;

    //ex3
    //const int row = 7;
    //const int col = 3;
    //int matrix[row][col];
    //int count = 0;
    //for (int i = 0; i < row; i++)
    //{
    //    for (int j = 0; j < col; j++)
    //    {
    //        matrix[i][j] = (-20 + rand() % 40);
    //        //matrix[i][j] = rand() %90 + 10;//90-99
    //        //cout << left<<  setw(5) <<  matrix[i][j] ;
    //        cout << setw(5) << matrix[i][j];
    //        if (matrix[i][j] < 12 && matrix[i][j] >= -12)
    //        {
    //            count += 1;
    //        }
    //    }
    //    cout << endl;
    //}
    //cout << count;

    //ex 4
    /*const int row = 4;
    const int col = 5;
    int matrix[row][col];
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            if (matrix[i][j] > 0)
            {
                count += 1;
            }
        }
        cout << endl;
    }
    cout << count;*/

    //ex5
    
    /*const int row = 5;
    const int col = 4;
    int matrix[row][col];
    int multi = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            if (matrix[i][j] > 0)
            {
                multi = multi * matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << multi;*/

    //ex 6
    /*const int row = 5;
    const int col = 4;
    int matrix[row][col];
    int multi = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            if (matrix[i][j] < 0)
            {
                multi = multi * matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << multi;*/

    //ex7
    /*const int row = 4;
    const int col = 4;
    int matrix[row][col];
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            if (matrix[i][j]%6 == 1)
            {
                count += 1;
            }
        }
        cout << endl;
    }
    cout << count;*/

    //ex8
    /*const int row = 5;
    const int col = 6;
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    int max = matrix[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    cout << max;*/

    //ex 9
    /*const int row = 5;
    const int col = 6;
    int matrix[row][col];
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            
        }
        cout << endl;
    }
    int min = matrix[0][0];
    for (int i = 0; i < row; i++)
    {
        
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }

        }
    }
    cout << min;*/
        
    //ex10
    const int row = 5;
    const int col = 4;
    int matrix[row][col];
    int count = 0;
    for (int i = 0; i < row; i++)
    {   
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (-20 + rand() % 40);
            cout << setw(5) << matrix[i][j];
            if (matrix[i][j] < 0)
            {
                count += matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << count;
}
