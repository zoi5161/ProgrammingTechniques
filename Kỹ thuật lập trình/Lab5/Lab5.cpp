#include <iostream>
#include <cmath>

using namespace std;

//1.1
long long sum(int x)
{
    if(x < 1)
        return 0;

    if(x == 1)
        return 1;

    return x + sum(x-1);
}

//1.2
long long factorial(int x)
{
    if(x <= 1)
        return 1;

    return x * factorial(x-1);
}

//1.3
long long xFacn(int n)
{
    if(n < 1)
        return 1;

    return n * xFacn(n - 1);
}

//1.4
int cntDigits(int x)
{
    if(x < 1)
        return 0;

    return x % 10 + cntDigits(x/10);
}

//1.5
int cntOddDigits(int x)
{
    if(x < 1)
        return 0;

    return ((x%10) % 2 != 0) ? x%10 + cntOddDigits(x/10) : cntOddDigits(x/10);
}

//1.6
bool verifyEven(int x)
{
    if(x < 1)
        return true;

    return ((x%10) % 2 == 0) ? verifyEven(x/10) : false;
}

//1.7
int cntCommonDivisors(int a, int b, int i)
{
    if(i > min(a, b))
        return 0;
    else if(a % i == 0 and b % i == 0)
        return 1 + cntCommonDivisors(a, b, i+1);
    else
        return cntCommonDivisors(a, b, i+1);
}

//1.8
int greaterDivisor(int a, int b)
{
    for(int i = min(a, b); i >= 1; i--)
        if(a % i == 0 && b % i == 0)
            return i;
    return 1;
}

int leastDivisor(int a, int b)
{
    int k = max(a, b);
    while(1)
    {
        k++;
        if(k % a == 0 && k % b == 0)
        {
            return k;
            break;
        }
    }
}

//1.9
int reverseDigit(int x)
{
    if(x < 10)
        return x;
    return (x%10)*pow(10, (int)log10(x/10) + 1) + reverseDigit(x/10); 
}

//1.10
int binaryDigit(int x)
{
    if(x < 1)
        return 0;
    return (!(x%2 == 0)) + binaryDigit(x/2)*10;
}

void binaryDigit2(int x)
{
    if(x > 1)
        binaryDigit2(x/2);
    cout << x%2;
}

//1.11
int Fibo(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return Fibo(n-1) + Fibo(n-2);
}

//1.12
void permutations(string s, int left, int right)
{
    if(left == right)
        cout << s << endl; 
    else
    {
        for(int i = left; i <= right; i++)
        {
            swap(s[left], s[i]);
            permutations(s, left + 1, right);
            swap(s[left], s[i]);
        }
    }
}

//1.13
struct Node
{
    int key;
    Node* p_next;
};

Node* createNode(int data)
{
    Node* p = new Node;
    p -> key = data;
    p -> p_next = NULL;
    return p;
}

int sizeList(Node* p)
{
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        p = p -> p_next;
    }
    return cnt;
}

Node* createList(int a[], int i, int n)
{
    if(i > n)
        return NULL;
    else
    {
        Node* p = createNode(a[i]);
        p -> p_next = createList(a, i+1, n);
        return p;
    }
}

void printList(Node* p)
{
    cout << endl;
    while(p != NULL)
    {
        cout << p -> key << endl;
        p = p -> p_next;
    }
    cout << endl;
}

//
void backtrack(int sum, int index, int A[], int n, int k) 
{
    if (sum == k) 
    {
        for (int i = 0; i < index; i++)
            cout << A[i] << " ";
        cout << endl;
        return;
    }

    if (sum > k || index == n)
        return;

    A[index] = 1;
    backtrack(sum + 1, index + 1, A, n, k);
    A[index] = 0;
    backtrack(sum, index + 1, A, n, k);
}


int main()
{
    long long n;
    int k, f, a, b;
    /*
    cin >> n;

    //1.1
    cout << sum(n) << endl;

    //1.2
    cout << factorial(n) << endl;

    //1.3
    cout << xFacn(n, n) << endl;

    //1.4
    cin >> k;
    cout << cntDigits(k) << endl;

    //1.5
    cout << cntOddDigits(k) << endl;

    //1.6
    cin >> f;
    if(verifyEven(f) && f != 0)
        cout << "Yé" << endl;
    else
        cout << "Nope" << endl;

    //1.7
    cin >> a >> b;
    cout << cntCommonDivisors(a, b, 1);
    
    //1.8
    cout << greaterDivisor(a, b) << endl;
    cout << leastDivisor(a, b) << endl;
    

    //1.9
    cout << reverseDigit(4321);

    //1.10
    for(int i = 0; i <= 20; i++)
    {
        cout << i << ' ';
        //cout << binaryDigit(i) << endl;
        binaryDigit2(i);
        cout << endl;
    }

    //1.11
    for(int i = 0; i <= 20; i++)
        cout << i << ' ' << Fibo(i) << endl;

    //1.12
    string s = "ABCD";
    permutations(s, 0, s.length()-1);

    //1.13
    int arr[10];
    for(int i = 1; i <= 5; i++)
        cin >> arr[i];
    
    Node* p = createNode((int)NULL);

    p = createList(arr, 1, 5); 
    printList(p);
    */

    //1.14

    //
    int A[] = {1, 2, 3, 4};
    int m = 4;
    k = 5;
    backtrack(0, 0, A, m, k);

    return 0;
}