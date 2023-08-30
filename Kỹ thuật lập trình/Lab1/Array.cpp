#include <iostream>

using namespace std;

//Data for all lesson
const int maxN = 1e6 + 9;
float a[maxN];
int n, b[maxN];

void inputArrayInt(int A[], int n)
{
    for(int i=1; i<=n; i++)
        cin >> A[i];
}

//Data from precious lesson (Function)

//1.3
bool isPrime(int a)
{
    if(a <= 3)
        return a > 1;
    if(a%2 == 0 || a%3 == 0)
        return false;
    
    int i = 5;
    while(i*i <= a)
    {
        if(a%i == 0 || a%(i+2) == 0)
            return false;

        i += 6;
    }

    return true;
}

//1.4
int countPrime(int A[], int x)
{
    int cnt = 0;

    for(int i=1; i<=x; i++)
        if(isPrime(A[i]))
            cnt++;

    return cnt;
}

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

//2.1.1
void inputArray(float A[], int n)
{
    for(int i=1; i<=n; i++)
        cin >> A[i];
}

//2.1.2
void printArray(float A[], int n)
{
    cout << endl << "They are: ";

    for(int i=1; i<=n; i++)
        cout << A[i] << ' ';
}

//2.1.3
int countArrayPrime(int A[], int n)
{
    return countPrime(A, n);
}

//2.1.4
float sumArray(float A[], int n)
{
    float sum = 0;

    for(int i=1; i<=n; i++)
        sum += A[i];

    return sum;
}

//2.1.5
bool isIncreasing(float A[], int n)
{
    for(int i=2; i<=n; i++)
    {
        if(A[i-1] >= A[i])
            return false;
    }
    return true;
}

bool isDecreasing(float A[], int n)
{
    for(int i=2; i<=n; i++)
    {
        if(A[i-1] <= A[i])
            return false;
    }
    return true;
}

int main()
{
    //2.1.1
    cout << "Lesson 2.1.1" << endl;
    cout << "Input an array with size n" << endl;
    cout << "Please enter n: ";

    cin >> n;

    cout << "Enter the element of the array: ";
    inputArray(a, n);

    if(!check())
        return 0;
    
    //2.1.2
    cout << "Lesson 2.1.2" << endl;
    cout << "Output a given array with size n (From lesson 2.1.1)" << endl;
    
    printArray(a, n);
    if(!check())
        return 0;

    //2.1.3
    cout << "Lesson 2.1.3" << endl;
    cout << "Count the number of prime in a given array" << endl;

    cout << "Enter the size n: ";
    cin >> n;

    cout << "Enter the element of the array: ";
    inputArrayInt(b, n);

    cout << "The number of prime in a given array is: " << countArrayPrime(b, n);
    if(!check())
        return 0;

    //2.1.4
    cout << "Lesson 2.1.4" << endl;
    cout << "Calculate the summary of all elements from a given array" << endl;
    cout << "Input an array with size n" << endl;
    cout << "Please enter n: ";

    cin >> n;

    cout << "Enter the element of the array: ";
    inputArray(a, n);

    cout << endl << "The answer is: " << sumArray(a, n);

    if(!check())
        return 0;

    //2.1.5
    cout << "Lesson 2.1.5" << endl;
    cout << "Determine if a given array is increasing/decreasing" << endl;
    cout << "Input an array with size n" << endl;
    cout << "Please enter n: ";

    cin >> n;

    cout << "Enter the element of the array: ";
    inputArray(a, n);

    if(isIncreasing(a, n))
        cout << endl << "This array is increasing";
    else 
        cout << endl << "This array isn't increasing";

    cout << endl;

    if(isDecreasing(a, n))
        cout << endl << "This array is decreasing";
    else 
        cout << endl << "This array isn't decreasing";

    if(!check())
        return 0;

    return 0;
}