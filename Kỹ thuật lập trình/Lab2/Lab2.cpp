#include <iostream>
#include <fstream>

using namespace std;

struct Player
{
    string po, name, team, club;
    int bth;
};

//1.1
bool SequentialSearch(int a[], int n, int x)
{
    int i=1;
    while(i<=n && a[i]!=x)
        i++;
    return i<=n;
}

//1.2
bool BinarySearch(int a[], int n, int x)
{
    int l=1, r=n, m;
    while(l<=r)
    {
        m = (l+r)/2;
        if(a[m]==x)
            return true;
        else if(a[m]>x)
            r=m-1;
        else
            l=m+1;
    }
    return false;
}

//1.3
bool SequentialSearchWithSentinel(int a[], int n, int x)
{
    a[n+1]=x+1;
    int i=1;
    while(a[i]<x)
        i++;
    return (a[i]==x); //*
}

//1.4
bool RecursiveBinarySearch(int a[], int n, int x, int l, int r)
{
    if(l<=r)
    {
        int m = (l+r)/2;
        if(a[m]==x)
            return true;
        else if(a[m]>x)
            return RecursiveBinarySearch(a, n, x, l, m-1);
        else
            return RecursiveBinarySearch(a, n, x, m+1, r);
    }
    return false;
}

//1.5
bool InterpolationSearch(int a[], int n, int x)
{
    int l=1, r=n, m;
    while(l<=r && x>=a[l] && x<=a[r]) //*
    {
        if(l==r)
        {
            if(a[l]==x)
                return true;
            return false;
        }
        m = l + (((double)(r-l)/(a[r]-a[l]))*(x-a[l])); //*
        if(a[m]==x)
            return true;
        else if(a[m]<x)
            l=m+1;
        else 
            r=m-1;
    }
    return false;
}

//2.1
void SelectionSort(int a[], int n) //*
{
    int Idx, Val;
    for(int i=1; i<n; i++)
    {
        Idx = i;
        Val = a[i];
        for(int j=i+1; j<=n; j++)
        {
            if(a[j] < Val)
            {
                Idx = j;
                Val = a[j];
            }
        }
        a[Idx] = a[i];
        a[i] = Val; 
    }

}

//2.2
void InsertionSort(int a[], int n) //*
{
    int Val, j;
    for(int i=2; i<=n; i++)
    {
        Val = a[i];
        j = i-1;
        while(j>=1 && a[j]>Val)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = Val;
    }
}

//2.3
void BubbleSort(int a[], int n)
{
    for(int i=2; i<=n; i++)
        for(int j=n; j>=i; j--)
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
}

//2.4
void InterchargeSort(int a[], int n)
{
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i]>a[j])
                swap(a[i], a[j]);
}

//2.5
void InsertionSortWithSentinel(int a[], int n)
{
    int Val, j;
    a[0] = -99999;
    for(int i=2; i<=n; i++)
    {
        Val = a[i];
        j = i-1;
        while(a[j] > Val)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = Val;
    }
}

//2.6
int LowerBound(int a[], int x, int l, int r)
{
    while(l<=r)
    {
        int m = (l+r)/2;
        if(a[m] >= x)
            r = m - 1;
        else 
            l = m + 1;
    }
    return r;
}

void BinaryInsertionSort(int a[], int n)
{
    int Val, j, Locate;
    for(int i=2; i<=n; i++)
    {
        Val = a[i];
        j = i - 1;
        Locate = LowerBound(a, Val, 1, i - 1);
        while(j > Locate)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = Val;
    }
}

//2.7
void ImprovedBubbleSort(int a[], int n)
{
    int flag = 0;
    for(int i=2; i<=n; i++)
    {
        flag = 0;
        for(int j=n; j>=i; j--)
        {
            if(a[j] < a[j-1]) //*
            {
                swap(a[j], a[j-1]);
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
}

//2.8
void ShakerSort(int a[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<n; j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        n--;
        for(int j=n; j>i; j--)
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        i++;
    }
}

//3
void InterchargeSortYear(Player a[], int n)
{
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i].bth > a[j].bth)
                swap(a[i], a[j]);
}

void InterchargeSortLastName(Player a[], int n)
{
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i].name > a[j].name)
                swap(a[i], a[j]);
}

void InterchargeSortLastNameVer2(Player a[], int n)
{
    string s1, s2;
    int u;
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
        {
            s1 = "";
            s2 = "";
            u = 0;
            while(a[i].name[u] != ' ' &&  u <a[i].name.length())
            {
                s1 += a[i].name[u];
                u++;
            }
            u = 0;
            while(a[j].name[u] != ' ' &&  u <a[j].name.length())
            {
                s2 += a[j].name[u];
                u++;
            }
            if(s1 > s2)
                swap(a[i], a[j]);
        }
}

void enter(Player a[], int &u)
{
    ifstream fin;
    string s, s1;

    fin.open("Players.txt");
    while(!fin.eof()) 
    {
        u++;
        getline(fin, a[u].po, '/');
        getline(fin, a[u].name, '/');

        getline(fin, s, '/');
        a[u].bth = 0;
        for(int i=0; i<4; i++)
            a[u].bth = a[u].bth*10 + (s[i]-'0');
        
        getline(fin, a[u].team, '/');
        getline(fin, s1, '\n');

        a[u].club = "";

        for(int i=0; i<s1.length()-1; i++)
            a[u].club += s1[i];
    }
    fin.close();
}

void print(Player a[], int n)
{
    ofstream fout;
    int i=1;

    fout.open("Output.txt");
    fout << "Players born in 1994: " << endl;
    while(i<=n)
    {
        if(a[i].bth == 1994)
        {
            fout << endl;
            fout << "Position: " << a[i].po << endl;
            fout << "Name: " << a[i].name << endl;
            fout << "Year of birth: " << a[i].bth << endl;
            fout << "National team: " << a[i].team << endl;
            fout << "Club: " << a[i].club << endl;
        }
        i++;
    }

    fout << endl << "================================================" << endl;
    fout << endl << "Players play for Manchester United club: " << endl;
    i=1;
    while(i<=n)
    {
        if(a[i].club == "Manchester United")
        {
            fout << endl;
            fout << "Position: " << a[i].po << endl;
            fout << "Name: " << a[i].name << endl;
            fout << "Year of birth: " << a[i].bth << endl;
            fout << "National team: " << a[i].team << endl;
            fout << "Club: " << a[i].club << endl;
        }
        i++;
    }

    fout << endl << "================================================" << endl;
    fout << endl << "Players at position FW for Manchester City: " << endl;
    i=1;
    while(i<=n)
    {
        if(a[i].po == "FW" && a[i].club == "Manchester City")
        {
            fout << endl;
            fout << "Position: " << a[i].po << endl;
            fout << "Name: " << a[i].name << endl;
            fout << "Year of birth: " << a[i].bth << endl;
            fout << "National team: " << a[i].team << endl;
            fout << "Club: " << a[i].club << endl;
        }
        i++;
    }

    fout << endl << "================================================" << endl;
    fout << "The players ascendingly by their year of birth: " << endl;
    InterchargeSortYear(a, n);
    i = 1;
    while(i<=n)
    {
        fout << endl;
        fout << "Position: " << a[i].po << endl;
        fout << "Name: " << a[i].name << endl;
        fout << "Year of birth: " << a[i].bth << endl;
        fout << "National team: " << a[i].team << endl;
        fout << "Club: " << a[i].club << endl;
        i++;
    }

    fout << endl << "================================================" << endl;
    fout << "The players ascendingly by their last name: " << endl;
    InterchargeSortLastName(a, n);
    i = 1;
    while(i<=n)
    {
        fout << endl;
        fout << "Position: " << a[i].po << endl;
        fout << "Name: " << a[i].name << endl;
        fout << "Year of birth: " << a[i].bth << endl;
        fout << "National team: " << a[i].team << endl;
        fout << "Club: " << a[i].club << endl;
        i++;
    }

    fout.close();
}

int main()
{
    int n = 0;
    // Player a[100];
    // enter(a, n);
    // print(a, n);
    int a[100];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ShakerSort(a, n);
    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}