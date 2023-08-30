#include <iostream>

using namespace std;

struct Node
{
       int key;
       Node* next;
};

bool empty(Node* pHead)
{
    return pHead == NULL;
}

//1.13
int sizeList(Node* pHead)
{
    int cnt = 0;
    while(pHead != NULL)
    {
        cnt++;
        pHead = pHead -> next;
    }
    return cnt;
}

//1.1
Node* createNode(int data)
{
    Node* tmp = new Node;
    tmp -> key = data;
    tmp -> next = NULL;
    return tmp;
}

//1.2
void addHead(Node* &pHead, int data)
{
    if(pHead == NULL)
        pHead = createNode(data);
    else
    {
        Node* tmp = createNode(data);
        tmp -> next = pHead;
        pHead = tmp;
    }
}

//1.3
void addTail(Node* &pHead, int data)
{
    if(pHead == NULL)
        pHead = createNode(data);
    else
    {
        Node* p = pHead;
        while(p -> next != NULL)
            p = p -> next;
        Node* tmp = createNode(data);
        p -> next = tmp;
    }
}

//1.4
void removeHead(Node* &pHead)
{
    if(pHead == NULL)
        return;
    Node* p = pHead;
    pHead = pHead -> next;
    delete p;
}

//1.5
void removeTail(Node* &pHead)
{
    if(pHead == NULL)
        return;

    int n = sizeList(pHead);

    if(n == 1)
    {
        delete pHead;
        pHead = NULL;
        return;
    }

    Node* p = pHead;

    for(int i = 1; i < n - 1; i++)
        p = p -> next;
    
    Node* tmp = p -> next;
    p -> next = NULL;
    delete tmp;
}

//1.6
void removeAll(Node* &pHead)
{
    Node* p = pHead;
    while(pHead -> next != NULL)
    {
        p = pHead;
        pHead = pHead -> next;
        delete p;
    }
    delete pHead;
    pHead = NULL;
}

//1.10
void RemovePos(Node* &pHead, int pos)
{
    if(pHead == NULL)
        return;

    int n = sizeList(pHead);

    if(pos < 1 || pos > n)
        cout << "Error" << endl;
    else if(pos == 1)
        removeHead(pHead);
    else if(pos == n)
        removeTail(pHead);
    else
    {
        Node* pFront = NULL;
        Node* pBehind = pHead;

        for(int i = 1; i < pos; i++)
        {
            pFront = pBehind;
            pBehind = pBehind -> next;
        }
        
        pFront -> next = pBehind -> next;
        delete pBehind;
    }
}

//1.7
void removeBefore(Node* &pHead, int val)
{
    if(pHead == NULL)
        return;
    
    int n = sizeList(pHead);

    if(n == 1)
        return;
    
    Node* p = pHead;

    for(int i = 1; i < n; i++)
    {
        if(p -> next -> key == val)
        {
            RemovePos(pHead, i);
            i--;
            n--;
        }
        p = p -> next;
    }
}

//1.8
void removeAfter(Node* &pHead, int val)
{
    if(pHead == NULL)
        return;
    
    int n = sizeList(pHead);
    
    if(n == 1)
        return;

    Node* pFront = pHead;
    for(int i = 1; i < n; i++)
    {
        if(pFront -> key == val)
        {
            RemovePos(pHead, i+1);
            i--;
            n--;
        }
        pFront = pFront -> next;
    }
}

//1.9
bool addPos(Node* &pHead, int data, int pos)
{
    if(pHead == NULL)
    {
        pHead = createNode(data);
        return false;
    }
    else
    {
        int n = sizeList(pHead);

        if(pos < 1 || pos > n + 1)
            cout << "Error" << endl;
        else if(pos == 1)
            addHead(pHead, data);
        else if(pos == n + 1)
            addTail(pHead, data);
        else
        {
            Node* p = pHead;
            for(int i = 1; i < pos - 1; i++)
                p = p -> next;
            Node* tmp = createNode(data);
            tmp -> next = p -> next;
            p -> next = tmp;
        }
        return true;
    }
}

//1.13
void printList(Node* &pHead)
{
    Node* p = pHead;
    cout << endl;
    while(p != NULL)
    {
        cout << p -> key << ' ';
        p = p -> next;
    }
    cout << endl;
}

//1.11
void addBefore(Node* &pHead, int data, int val)
{
    if(pHead == NULL)
        return;
    
    int n = sizeList(pHead);
    Node* p = pHead;

    for(int i = 1; i <= n; i++)
    {
        if(p -> key == val)
        {
            addPos(pHead, data, i);
            i++;
            n++;
        }
        p = p -> next;
    }
}

//1.12
void addAfter(Node* &pHead, int data, int val)
{
    if(pHead == NULL)
        return;
    
    int n = sizeList(pHead);
    Node* p = pHead;

    for(int i = 1; i <= n; i++)
    {
        if(p -> key == val)
        {
            addPos(pHead, data, i+1);
            i++;
            n++;
        }
        p = p -> next;
    }
}

//1.15
int countAppearance(Node* &pHead, int value)
{
    Node* p = pHead;
    int cnt = 0;
    while(p != NULL)
    {
        if(p -> key == value)
            cnt++;
        p = p -> next;
    }  
    return cnt;
}

//1.16
Node* reverseList(Node* &pHead)
{
    Node* prev = NULL;
    Node* cur = pHead;
    Node* fut = NULL;

    while(cur != NULL)
    {
        fut = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = fut;
    }

    pHead = prev;
    return pHead;
}

Node* reverseList2(Node* &pHead)
{
    Node* tmp = NULL;
    Node* p = pHead;

    while(p != NULL)
    {
        addHead(tmp, p -> key);
        p = p -> next;
    }

    pHead = tmp;
    return pHead;
}

//1.17
void removeDuplicate(Node* &pHead)
{
    if(pHead == NULL || pHead -> next == NULL)
        return;
    
    Node* cur = pHead;
    while(cur != NULL)
    {
        Node* run = cur;
        while(run -> next != NULL)
        {
            if(run -> next -> key == cur -> key)
            {
                Node* tmp = run -> next;
                run -> next = run -> next -> next;
                delete tmp;
            }
            else
                run = run -> next;
        }
        cur = cur -> next;
    }
}

//1.18

//Swap
void swapNode(Node* &pHead, int posX, int posY) 
{
    if(pHead == NULL || pHead -> next == NULL)
        return;

    int n = sizeList(pHead);
    if(posX == posY || posX < 1 || posY < 1 || posX > n || posY > n)
        return;

    if(posX > posY)
        swap(posX, posY);
    
    Node* prevX = NULL;
    Node* curX = pHead;
    int curx = 1;
    while(curX != NULL && curx < posX)
    {
        prevX = curX;
        curX = curX -> next;
        curx++;
    }

    Node* prevY = NULL;
    Node* curY = pHead;
    int cury = 1;
    while(curY != NULL && cury < posY)
    {
        prevY = curY;
        curY = curY -> next;
        cury++;
    }

    if(curX == NULL || curY == NULL)
        return;
    
    if(prevX == NULL)
        pHead = curY;
    else
        prevX -> next = curY;
    
    if(prevY == NULL)
        pHead = curX;
    else
        prevY -> next = curX;
    
    Node* tmp = curY -> next;
    curY -> next = curX -> next;
    curX -> next = tmp;
}


int main()
{
    Node* pHead = NULL;

    //1.3
    for(int i = 1; i <= 10; i++)
        addTail(pHead, i);
    printList(pHead);

    //1.2
    addHead(pHead, 99);
    printList(pHead);

    //1.4
    removeHead(pHead);
    printList(pHead);

    //1.5
    removeTail(pHead);
    printList(pHead);

    //1.6
    removeAll(pHead);
    if(empty(pHead))
    {
        cout << endl << "Empty" << endl;
        for(int i = 1; i <= 10; i++)
            addTail(pHead, i);
    }
    else
        printList(pHead);


    //1.7
    removeBefore(pHead, 8);
    printList(pHead);

    //1.8
    removeAfter(pHead, 4);
    printList(pHead);

    //1.9
    addPos(pHead, 100, 5);
    printList(pHead);

    //1.10
    RemovePos(pHead, 7);
    printList(pHead);

    //1.11
    addBefore(pHead, 666, 1);
    printList(pHead);

    //1.12
    addAfter(pHead, 9, 666);
    printList(pHead);

    //1.14
    cout << endl << sizeList(pHead) << endl;

    //1.15
    cout << endl << countAppearance(pHead, 9) << endl;
    
    //1.16
    reverseList(pHead);
    printList(pHead);

    //1.17
    removeDuplicate(pHead);
    printList(pHead);

    swapNode(pHead, 2, 3);
    printList(pHead);
    return 0;
}