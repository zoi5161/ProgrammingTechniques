#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Data for all lesson
int a, b, c;
float lss = 1.1;

//Check your choice
bool check()
{
    int drt;
    lss += 0.1;

    cout << endl << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    cout << "Continue --> 1" << endl;
    cout << "Exit --> 0" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl << endl;
    cout << "Your choice is: ";

    cin >> drt;
    cout << endl;

    if(drt != 0)
        cout << endl << "Lesson " << setprecision(1) << fixed << lss << endl;
    return drt;
}

//1.1
void LinearEquation(int a, int b)
{
    if(-b*1.0/a == -b/a)
        cout << endl << "x = " << -b/a;
    else
        cout << endl << "x = " << setprecision(2) << fixed << -b*1.0/a;
}

//1.2
void QuadraticEquation(int a, int b, int c)
{
    if(a==0 && b==0)
        cout << endl << "Infinity";
    else if(a==0 && c==0)
        cout << endl << "x = 0";
    else
    {
        int delta = b*b - 4*a*c;
        if(delta < 0)
            cout << endl << "No solution";
        else if(delta == 0)
            cout << endl << "x = x1 = x2 = " << -b*1.0/(2*a); 
        else
        {
            float x1 = (-b-sqrt(delta))/(2*a), x2 = (-b+sqrt(delta))/2*a;
            cout << endl << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        }
    }
}

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
int countPrime(int a, int b)
{
    int cnt = 0;

    for(int i=a; i<=b; i++)
        if(isPrime(i))
            cnt++;

    return cnt;
}

//1.5
int sumDigits(int n)
{
    int tmp = 0;
    while(n > 0)
    {
        tmp += n%10;
        n /= 10;
    }
    return tmp;
}

//1.6
int countInteger(int N, int k)
{
    return N/k;
}

//1.7
void Triangle(float a, float b, float c)
{
    if(a+b>c && a+c>b && b+c>a)
    {
        cout << endl << "They form a triangle" << endl;

        if(b == c && a == b)
            cout << endl << "That's Equilateral Triangle";
        else if(a == b || b == c || a == c)
        {
            if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
                cout << endl << "That's Right Isosceles Triangle";
            else
                cout << endl << "That's Isosceles Triangle";
        }
        else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            cout << endl << "That's Isosceles Triangle";
        else 
            cout << endl << "That's Normal Triangle";
    }
    else 
        cout << endl << "They don't form a triangle";
}

int main()
{
    //1.1
    cout << "Lesson 1.1" << endl;
    cout << "Solving the linear equation: ax + b = 0" << endl;
    cout << "Please enter a, b: ";

    cin >> a >> b;
    LinearEquation(a, b);
    
    if(!check())
        return 0;

    //1.2
    cout << "Solving the quadratic equation: ax^2 + bx + c = 0" << endl;
    cout << "Please enter a, b, c: ";

    cin >> a >> b >> c;
    QuadraticEquation(a, b, c);

    if(!check())
        return 0;

    //1.3
    cout << "Determine if a given integer is a prime" << endl;
    cout << "Please enter x: ";

    cin >> a;
    
    if(isPrime(a))
        cout << endl << "That's a Prime Number";
    else 
        cout << endl << "That isn't a Prime Number";

    if(!check())
        return 0;

    //1.4
    cout << "Count the number of prime between 2 input integer value a and b (a < b)" << endl;
    cout << "Please enter a, b: ";

    cin >> a >> b;
    
    c = countPrime(a, b);
    if(c == 0)
        cout << endl << "There isn't any Prime Number";
    else if(c == 1)
        cout << endl << "There is a Prime Number";
    else 
        cout << endl << "There are " << c << " Prime Number";

    if(!check())
        return 0;

    //1.5
    cout << "Calculate the total value of all digits of a given integer" << endl;
    cout << "Please enter n: ";

    cin >> a;
    cout << endl << "The total value of all digits of a given integer is: " << sumDigits(a);

    if(!check())
        return 0;

    //1.6
    cout << "Count the number of integers that is smaller than an input value N and divisible by k" << endl;
    cout << "Please enter n, k: ";

    cin >> a >> b;
    cout << endl << "The answer is: " << countInteger(a, b);

    if(!check())
        return 0;
    
    //1.7
    cout << "Given a, b, and c are 3 real numbers. Determine if a, b, and c form a triangle. Which type of triangle is that? (normal triangle, right triangle, isosceles triangle, right isosceles triangle, equilateral triangle)" << endl;
    cout << "Please enter a, b, c: ";

    cin >> a >> b >> c;
    Triangle(a, b, c);

    return 0;
}