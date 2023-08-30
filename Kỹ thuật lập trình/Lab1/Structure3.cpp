#include <iostream>
#include <math.h>

using namespace std;

struct point
{
    float x, y;
};

//3.3.1
void enter(point &a)
{
    cout << endl << "Enter the position x and y: ";
    cin >> a.x >> a.y;
    cout << endl;
}

void check(point a)
{
    if(a.x == 0 && a.y == 0)
        cout << "This point is Origin" << endl;
    else if(a.x == 0)
        cout << "This point is on Ox" << endl;
    else if(a.y == 0)
        cout << "This point is on Oy" << endl;
    else if(a.x<0 && a.y<0)
        cout << "This point is on the down-left quadrant" << endl;
    else if(a.x<0 && a.y>0)
        cout << "This point is on the up-left quadrant" << endl;
    else if(a.x>0 && a.y<0)
        cout << "This point is on the down-right quadrant" << endl;
    else
        cout << "This point is on the up-right quadrant" << endl;
}

//3.3.2
float dist(point a, point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)*1.0 + (b.y-a.y)*(b.y-a.y)*1.0);
}

//3.3.3
void midPoint(point a, point b, point &c)
{
    c.x = (a.x + b.x)/2;
    c.y = (a.y + b.y)/2;
    cout << endl << "The position of Mid Point is (";
    cout << c.x << ';' << c.y << ')'<< endl;
}

//3.3.4
void collinear(point a, point b, point c)
{
    float u = (a.y - b.y)/(a.x - b.x), v = a.y - u*a.x;
    if(c.x*u + v == c.y)
        cout << "They're collinear";
    else
        cout << "They aren't collinear";
}

int main()
{
    point a, b, c;

    //3.3.1
    enter(a);
    check(a);

    //3.3.2
    enter(b);
    cout << "The distance between 2 point is " << dist(a, b) << endl;

    //3.3.3
    midPoint(a, b, c);

    //3.3.4
    enter(c);
    collinear(a, b, c);
    return 0;
}