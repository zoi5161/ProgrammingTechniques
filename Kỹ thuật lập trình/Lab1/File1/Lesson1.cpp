#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    float a, b;
    char k;

    ifstream fin;
    ofstream fout;

    fin.open("input1.txt");
    fout.open("output1.txt");

    fin >> n;
    for(int i=1; i<=n; i++)
    {
        fin >> a >> k >> b;
        if(k == '+')
            fout << a+b << endl;
        else if(k == '*')
            fout << a*b << endl;
        else if(k == '-')
            fout << a-b << endl;
        else
        {
            if(b==0)
                fout << "Can't solve" << endl;
            else 
                fout << a/b;
        }
    }

    fin.close();
    fout.close();
    return 0;
}