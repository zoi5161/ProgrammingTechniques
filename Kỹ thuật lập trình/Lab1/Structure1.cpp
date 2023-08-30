#include <iostream>
#include <iomanip>

using namespace std;

struct timee
{
    int hour, min, sec;
};

void enter(timee &x)
{
    cout << "Enter hour, minute, second: ";
    cin >> x.hour >> x.min >> x.sec;
}

void pass(timee x)
{
    cout << endl;
    cout << "The day that has passed " << x.hour*60 + x.min << " minutes" << endl;
    cout << "The day that has passed " << x.hour*3600 + x.min*60 + x.sec  << " seconds" << endl << endl;
}

void compare(timee a, timee b)
{
    cout << endl;
    if(a.hour < b.hour)
        cout << "The first time is earlier" << endl;
    else if(a.hour == b.hour && a.min < b.min)
        cout << "The first time is earlier" << endl;
    else if(a.hour == b.hour && a.min == b.min && a.sec < b.sec)
        cout << "The first time is earlier" << endl;
    else if(a.hour == b.hour && a.min == b.min && a.sec == b.sec)
        cout << "The first time and the second time are equally" << endl;
    else 
        cout << "The second time is earlier" << endl;
    cout << endl;
}

void nextTime(timee c, timee d)
{
    int h, m, s;
    if(c.sec + d.sec >= 60)
    {
        s = c.sec + d.sec - 59;
        if(c.min + d.min >= 59)
        {
            m = c.min + d.min - 60;
            if(c.hour + d.hour >= 23)
                h = c.hour + d.hour - 23;
            else 
                h = c.hour + d.hour + 1;
        }
        else 
        {
            m = c.min + d.min + 1;
            if(c.hour + d.hour >= 24)
                h = c.hour + d.hour - 24;
            else
                h = c.hour + d.hour;
        }
    }
    else
    {
        s = c.sec + d.sec;
        if(c.min + d.min >= 60)
        {
            m = c.min + d.min - 60;
            if(c.hour + d.hour >= 23)
                h = c.hour + d.hour - 23;
            else 
                h = c.hour + d.hour + 1;
        }
        else
        {
            m = c.min + d.min;
            if(c.hour + d.hour >= 24)
                h = c.hour + d.hour - 24;
            else
                h = c.hour + d.hour;
        }
    }
    cout << "The after time is: " << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m << ':' << setw(2) << setfill('0') << s << endl;  

}

int main()
{
    timee a, b, c, d;
//3.1.1
    enter(a);

//3.1.2
    pass(a);

//3.1.3
    enter(b);
    compare(a, b);

//3.1.4
    enter(c);
    cout << "Enter the time which adds to the previous time" << endl;
    enter(d);
    nextTime(c, d);
    return 0;
}