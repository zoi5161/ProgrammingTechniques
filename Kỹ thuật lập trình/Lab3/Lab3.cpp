#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

//3.1
void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

//3.2
int* sum(int *a, int *b)
{
    int tmp = *a + *b, *k = &tmp;
    return k;
}

//3.3
void inputArray(int *&a, int &n)
{
    cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++)
        cin >> a[i];
}

//3.4
void printArray(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
}

//3.5
int* findMax(int* arr, int n)
{   
    int tmp = *arr, *mx = &tmp;
    for(int i=1; i<n; i++)
        if(*(arr+i) > *mx)
            *mx = *(arr+i);
    return mx;
}

//3.6
int* copyArray(int* &arr, int n)
{
    return arr;
}

//3.7
int* countEvens(int* arr, int n, int* evens)
{
    int tmp = 0;
    for(int i=0; i<n; i++)
        if(arr[i] % 2 == 0)
            tmp++;
    *evens = tmp;
    return evens;
}

int* genEvenSubarray(int* arr, int n, int* count)
{
    int cnt = -1;
    for(int i=0; i<n; i++)
        if(arr[i] % 2 == 0)
        {
            cnt++;
            count[cnt] = arr[i];
        }
    return count;
}

//3.8
int* findLargestTotalSubarray(int* a, int n, int &total, int &length)
{
    int mn, *find, index = 0;

    for(int i=1; i<n; i++)
        *(a+i) += *(a+i-1);

    mn = *a;
    total = *(a+1) - mn;

    for(int i=1; i<n; i++)
    {
        if(*(a+i) < mn)
            index = i + 1;

        mn = min(mn, *(a+i));
        
        if(*(a+i) - mn > total)
            total = max(total, *(a+i) - mn);
        length = i - index + 1;
    }

    for(int i=n-1; i>0; i--)
        *(a+i) -= *(a+i-1);
    find = (a + index);
    return find;
}

//3.9
int* findLongestAscendingSubarray(int* a, int n, int &length)
{
    int index = 0, cnt = 1, *p = a;
    length = 0;
    for(int i=1; i<n; i++)
    {
        if(*(a+i) > *(a+i-1))
            cnt++;
        else
        {
            if(cnt > length)
            {
                length = cnt;
                index = i;
            }
            cnt = 1;
        }
    }
    if(cnt > length)
    {
        length = cnt;
        index = n;
    }
    p = a + index - length;
    return p;
}

//3.10
void swapArrays(int* a, int* b, int &na, int &nb)
{
    int *p, tmp = na;
    p = new int[na];


    for(int i=0; i<na; i++)
        *(p+i) = *(a+i);
    
    for(int i=0; i<nb; i++)
        *(a+i) = *(b+i);

    for(int i=0; i<na; i++)
        *(b+i) = *(p+i);

    na = nb;
    nb = tmp;

    delete []p;
}

//3.11
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
    int *p;
    p = new int[na+nb];

    for(int i=0; i<na+nb; i++)
    {
        if(i<na)
            *(p+i) = *(a+i);
        else
            *(p+i) = *(b+i-na);
    }
    return p;
}

//3.12
int* merge2Arrays(int* a, int* b, int na, int nb, int&nc)
{
    int *p;
    int i=0, j=0;

    nc = na + nb;
    p = new int [nc];
    while(i+j < na+nb)
    {
        if(a[i] < b[j] && i < na)
        {
            p[i+j] = a[i];
            i++;
        }
        else
        {
            p[i+j] = b[j];
            j++;
        }
    }

    return p;
}

//3.13
void generateMatrix1(int** &A, int &length, int &width)
{
    srand(time(0));
    cin >> length >> width;

    A = new int *[length];
    for(int i=0; i<length; i++)
        A[i] = new int [width];

    for(int i=0; i<length; i++)
        for(int j=0; j<width; j++)
            (*(A+i))[j] = rand()%101;

}

//Print the array
void printArray2D(int** A, int length, int width)
{
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
            cout << A[i][j] << ' ';  
        cout << endl;
    }
    cout << endl;
}

//3.14
int** generateMatrix2(int* a, int* b, int na, int nb)
{
    int **p;

    p = new int *[na];
    for(int i=0; i<na; i++)
        p[i] = new int [nb];
    
    for(int i=0; i<na; i++)
        for(int j=0; j<nb; j++)
            p[i][j] = a[i] * b[j];
    
    return p;
}

//3.15
void swapRows(int** &a, int length, int width)
{
    int u, v, tmp[width];
    cin >> u >> v;

    for(int j=0; j<width; j++)
        tmp[j] = a[u][j];
        
    for(int j=0; j<width; j++)
        a[u][j] = a[v][j];

    for(int j=0; j<width; j++)
        a[v][j] = tmp[j];
}

void swapColumns(int** a, int length, int width)
{
    int u, v, tmp[length];
    cin >> u >> v;

    for(int j=0; j<length; j++)
        tmp[j] = a[j][u];
        
    for(int j=0; j<length; j++)
        a[j][u] = a[j][v];

    for(int j=0; j<length; j++)
        a[j][v] = tmp[j];
}

//3.16
int** transposeMatrix(int** &a, int &length, int &width)
{
    int tmp, **p, mx = max(length, width);

    p = new int *[width];
    for(int i=0; i<width; i++)
        p[i] = new int [length];

    **p = **a;
    for(int i=0; i<width; i++)
        for(int j=0; j<length; j++)
            p[i][j] = a[j][i];

    for(int i=0; i<mx; i++)
        for(int j=0; j<mx; j++)
            a[i][j] = 0;
    
    for(int i=0; i<width; i++)
        for(int j=0; j<length; j++)
            a[i][j] = p[i][j];

    tmp = length;
    length = width;
    width = tmp;
    
    cout << 1111;
    return a;
}


int main()
{
    int *a, *b, *c, k=3, v=4, n=1, m=1, mx, **d, total = 0, length = 0;
    a = &k;
    b = &v;
    // //3.1
    // swap(a, b);
    // cout << *a << ' ' << *b;

    // //3.2
    // cout << endl << *sum(a, b) << endl;

    //3.3
    // inputArray(a, n);
    
    // //3.4
    // printArray(a, n);
    // cout << endl;

    // //3.5
    // cout << *findMax(a, n);
    
    // //3.6
    // cout << endl;
    // b = copyArray(a, n);
    // printArray(b, n);

    //3.7
    // cout << *countEvens(a, n ,b) << endl;

    // v = *countEvens(a, n, b);
    // b = genEvenSubarray(a, n ,b);
    // printArray(b, v);
    // cout << endl;

    //3.8
    //  b = findLargestTotalSubarray(a, n, total, length);
    //  printArray(b, length);

    //3.9
    // b = findLongestAscendingSubarray(a, n, length);
    // printArray(b, length);

    //3.10
    // inputArray(b, m);

    // swapArrays(a, b, n, m);
    // printArray(a, n);
    // cout << endl;
    // printArray(b, m);

    //3.11
    // a = concatenate2Arrays(a, b, n, m);
    // printArray(a, n+m);

    //3.12
    // c = merge2Arrays(a, b, n, m, length);
    // printArray(c, length);

    //3.13
    generateMatrix1(d, n, m);
    printArray2D(d, n, m);

    //3.14
    //d = generateMatrix2(a, b, n, m);
    // printArray2D(d, n, m);

    //3.15
    // swapRows(d, n, m);
    // printArray2D(d, n, m);

    // swapColumns(d, n, m);
    // printArray2D(d, n, m);

    //3.16
    mx = max(n, m);
    d = transposeMatrix(d, n, m);
    printArray2D(d, n, m);

    for(int i=0; i<mx; i++)
        delete d[i];
    
    delete []d;
    delete []a;
    delete []b;
    return 0;
}