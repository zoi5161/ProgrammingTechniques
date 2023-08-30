#include <iostream>

using namespace std;

struct fract
{
    int nume, deno;
};

//Function for this lesson
void print(fract x)
{
    cout << endl << "The fraction after simplify is: ";
    if(x.deno == 1 || x.nume == 0)
        cout << x.nume << endl;
    else
        cout << x.nume << '/' << x.deno << endl << endl;
}

void printCal(fract x)
{
    cout << endl << "The fraction after calculate is: ";
    if(x.deno == 1 || x.nume == 0)
        cout << x.nume << endl;
    else
        cout << x.nume << '/' << x.deno << endl << endl;
}

//3.2.1
void enter(fract &x)
{
    string s;
    int i=0;
    x.nume = 0;
    x.deno = 0;

    cout << endl << "Enter a numerator and a denominator: ";
    cin >> s;

    while(s[i]!='/' && i<s.length())
    {
        x.nume = x.nume*10 + (s[i] - '0');
        i++;
    }

    if(i==s.length())
        x.deno = 1;
    else
    {
        i++;
        while(i<s.length())
        {
            x.deno = x.deno*10 + (s[i]-'0');
            i++;
        }
    }
    cout << endl;
}

int check(fract x)
{
    if(x.deno == 0)
    {
        cout << "It isn't a fraction" << endl;
        return 0;
    }
    cout << "It's a fraction" << endl;
    return 1;
}

//3.2.2
void simplify(fract &x)
{
    int mn, GCD=1;

    if(x.deno < x.nume)
        mn = x.deno;
    else 
        mn = x.nume;

    for(int i=1; i<=mn; i++)
        if(x.deno%i==0 && x.nume%i==0)
            GCD = i;

    x.deno /= GCD;
    x.nume /= GCD;
}

//3.2.3
void total(fract a, fract b, fract &c)
{
    c.nume = a.nume*b.deno + b.nume*a.deno;
    c.deno = a.deno*b.deno;
    simplify(c);
}

//3.2.4
void cmp(fract a, fract b)
{
    float aa = a.nume*1.0/a.deno;
    float bb = b.nume*1.0/b.deno;

    if(aa>bb)
        cout << "The first fraction is greater than the second one" << endl;
    else if(aa<bb)
        cout << "The second fraction is greater than the first one" << endl;
    else 
        cout << "They're equally" << endl;
}

int main()
{
    fract a, b, c;

    //3.2.1
    enter(a);
    while(!check(a))
        enter(a);

    //3.2.2
    simplify(a);
    print(a);
    
    //3.2.3
    enter(b);
    while(!check(b))
        enter(b);

    simplify(b);
    print(b);

    total(a, b, c);
    printCal(c);

    //3.2.4
    cmp(a, b);
    return 0;
}