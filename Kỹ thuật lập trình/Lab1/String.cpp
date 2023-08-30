#include <iostream>
#include <cstring>

using namespace std;

//Data for all lesson
char c[101], k;

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

//2.3.1
void inputString(char C[100])
{
    cin.getline(C, 100);
    cout << "The string is: " << C;
    C[strlen(C)] = '\0';
}

//2.3.2
void printString(char C[100])
{
    char B[100];

    for(int i=strlen(C); i>=1; i--)
        B[strlen(C)-i] = C[i-1];
    B[strlen(C)] = '\0';

    if(strcmp(C, B) == 0)
        cout << "Palindrome";
    else 
        cout << "not Palindrome";
}

//2.3.3
int countCapital(char C[100])
{
    int cnt = 0;
    for(int i=0; i<strlen(C); i++)
        if(C[i] >= 'A' && C[i] <= 'Z')
            cnt++;
    return cnt;
}

//2.3.4
int countAppearance(char C[100], char c)
{
    int cnt = 0;
    for(int i=0; i<strlen(C); i++)
        if(C[i] == c)
            cnt++;
    return cnt;
}

//2.3.5
int countWord(char C[100])
{
    int cnt = 0;
    C[strlen(C)] = ' ';
    for(int i=0; i<strlen(C); i++)
    {
        if(C[i] != ' ' && C[i+1] == ' ')
            cnt++;
    }
    C[strlen(C)] = '\0';
    return cnt;
}

int main()
{
    //2.3.1
    cout << "Lesson 2.3.1" << endl;
    cout << "Input a string and print it out on the screen" << endl;
    cout << "Please enter string: ";

    inputString(c);

    if(!check())
        return 0;
    
    // //2.3.2
    // cout << "Lesson 2.3.2" << endl;
    // cout << "Determine if a given string is a palindrome" << endl;
    // cout << "It is ";
    
    // printString(c);

    // if(!check())
    //     return 0;

    // //2.3.3
    // cout << "Lesson 2.3.3" << endl;
    // cout << "Count the number of capital characters from a given string" << endl;
    // cout << "The number of capital characters from a given string is: ";
    // cout << countCapital(c);

    // if(!check())
    //     return 0;

    // //2.3.4
    // cout << "Lesson 2.3.4" << endl;
    // cout << "Count the number of appearances of an input character from a given string" << endl;
    // cout << "Enter the charater: ";

    // cin >> k;

    // cout << "The number of appearances of an input character: ";
    // cout << countAppearance(c, k);
    // if(!check())
    //     return 0;

    //2.3.5
    cout << "Lesson 2.3.4" << endl;
    cout << "Count the number of words from a given string" << endl;
    cout << "The number of words from a given string: ";

    cout << countWord(c);

    return 0;
}