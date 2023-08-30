#include <iostream>

using namespace std;

//Data for all lesson
const int maxN = 1e3 + 9; 
float a[maxN][maxN], b[maxN][maxN], c[maxN][maxN], d[maxN][maxN], res[maxN][maxN];
int n, m, p;

//Check your choice
bool check()
{
    int drt;

    cout << endl << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    cout << "Continue --> 1" << endl;
    cout << "Exit --> 0" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl << endl;
    cout << "Your choice is: ";

    cin >> drt;
    cout << endl;

    return drt;
}

//2.2.1
void input2DArray(float A[][maxN], int n, int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> A[i][j];
}

//2.2.2
void print2DArray(float A[][maxN], int n, int m)
{
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                cout << A[i][j] << ' ';
            cout << endl;
        }
}

//2.2.3
void rotate2DArray(float A[][maxN], int n, int m)
{ 
    for(int i=1; i<=m; i++)
    {
        for(int j=n; j>=1; j--) 
            cout << A[n-j+1][m-i+1] << ' ';
        cout << endl;
    }
}

//2.2.4
void sum2DArray(float A[][maxN], float B[][maxN], float result[][maxN], int n, int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            result[i][j] = A[i][j] + B[i][j];

    print2DArray(result, n, m);
}

//2.2.5
void multiple2DArray(float A[][maxN], float B[][maxN], float result[][maxN], int n, int m, int p)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=p; j++)
            result[i][j]=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=p; j++)
        {
            for(int u=1; u<=m; u++)
                result[i][j] += A[i][u]*B[u][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=p; j++)
            cout << result[i][j] << ' ';
        cout << endl;
    }
}
//2.2.6
bool isDiagonalMatrix(float A[][maxN], int m, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(i==j)
            {
                if(A[i][j]!=0)
                    return 0;
            }
    }
    return 1;
}

bool isUpperTriangleMatrix(float A[][maxN], int m, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j>i)
                if(A[i][j]!=0)
                    return 0;
        }
    }
    return 1;
}

bool isLowerTriangleMatrix(float A[][maxN], int m, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j<i)
                if(A[i][j]!=0)
                    return 0;
        }
    }
    return 1;
}

int main()
{
    //2.2.1
    cout << "Lesson 2.2.1" << endl;
    cout << "Input an 2D array with size n x m" << endl;
    cout << "Please enter n, m: ";

    cin >> n >> m;

    cout << endl << "Enter the elements of the array: ";
    input2DArray(a, n, m);

    if(!check())
        return 0;

    //2.2.2
    cout << "Lesson 2.2.1" << endl;
    cout << "Output a given 2D array with size n x m" << endl;
    
    cout << "Elements of array are: " << endl;
    print2DArray(a, n, m);

    if(!check())
        return 0;

    //2.2.3
    cout << "Lesson 2.2.3" << endl;
    cout << "Rotate a given 2D array 90 clockwise" << endl;
    cout << endl << "The array after rotating is: " << endl;
    rotate2DArray(a, n, m);

    if(!check())
        return 0;
    //2.2.4
    cout << "Lesson 2.2.4" << endl;
    cout << "Calculate the summary of 2 given 2D arrays." << endl;
    cout << "Enter the elements of the array B with size n x m: ";

    input2DArray(b, n, m);
    if(!check())
        return 0;
    //2.2.5
    cout << "Lesson 2.2.5" << endl;
    cout << "Calculate the multiplication of 2 given 2D array" << endl;

    cout << "Enter the first array n x m: ";
    cin >> n >> m;
    input2DArray(c, n, m);

    cout << "Enter the second array m x p: ";
    cin >> m >> p;
    input2DArray(d, m, p);

    cout << endl << "The array after multiplication is: " << endl;
    multiple2DArray(c, d, res, n, m, p);
    
    if(!check())
        return 0;
    //2.2.6
    cout << "Lesson 2.2.6" << endl;
    cout << "Determine if a given array is a diagonal matrix / upper triangle matrix / lower triangle matrix." << endl;

    if(isDiagonalMatrix(a, n, m))
        cout << "It's a Diagonal Matrix" << endl;
    else
        cout << "It isn't a Diagonal Maxtrix" << endl;
    
    if(isUpperTriangleMatrix(a, n, m))
        cout << "It's a Upper Triangle Matrix" << endl;
    else
        cout << "It isn't a Upper Triangle Maxtrix" << endl;

    if(isLowerTriangleMatrix(a, n, m))
        cout << "It's a Lower Triangle Matrix" << endl;
    else
        cout << "It isn't a Lower Triangle Maxtrix" << endl;
    return 0;
}