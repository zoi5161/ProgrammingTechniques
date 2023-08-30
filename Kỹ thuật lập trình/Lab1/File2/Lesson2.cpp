#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string s;
    int cnt=0;

    ifstream fin;
    ofstream fout;

    fin.open("input2.txt");
    fout.open("output2.txt");

    fin >> s;
    for(int i=0; i<s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z'))
            cnt ++;
    }
    fout << cnt;

    fin.close();
    fout.close();
    return 0;
}