#include <iostream>

using namespace std;

struct Node{
       int key;
       Node* p_next;
};

struct List{
    Node* p_head;
    Node* p_tail;
};

Node* createNode(int data)
{
    Node* p = new Node;
    p -> key = data;
    p -> p_next = NULL;
    return p;
}

//1.14
int sizeList(List* L)
{
    int cnt = 0;
    Node* p = L -> p_head;
    while(p != NULL)
    {
        cnt++;
        p = p -> p_next;
    }
    return cnt;
}

//1.1
List* createList(Node* p_node)
{
    List* p = new List;

    p -> p_head = p_node;
    p -> p_tail = p_node;

    return p;
}

//1.2
bool addHead(List* &L, int data)
{
    Node* p = new Node;
    p -> key = data;
    p -> p_next = L -> p_head;
    L -> p_head = p;
    return true;
}

//1.3
bool addTail(List* &L, int data)
{
    Node* p = new Node;

    p -> key = data;
    p -> p_next = NULL;

    if(L -> p_head == NULL)
    {
        L -> p_head = p;
        L -> p_tail = p;
    }
    else
    {
        L -> p_tail -> p_next = p;
        L -> p_tail = p;
    }
    return true;
}

//1.4
void removeHead(List* &L)
{
    if(L -> p_head == NULL) 
        return;
    Node* p = L -> p_head;
    L -> p_head = L -> p_head -> p_next;
    delete p;
}

//1.5
void removeTail(List* &L)
{
    if(L -> p_head == NULL)
        return;

    if(L -> p_head -> p_next == NULL)
    {
        Node* tmp = L -> p_head;
        delete tmp;
        L -> p_head = NULL;
        L -> p_tail = NULL;
        return;
    }

    Node* p_prev = NULL;
    Node* p_cur = L -> p_head;    
    while(p_cur -> p_next != NULL)
    {
        p_prev = p_cur;
        p_cur = p_cur -> p_next;
    }
    L -> p_tail = p_prev;
    p_prev -> p_next = NULL;
    delete p_cur;
}

//1.6
void removeAll(List* &L)
{
    if(L -> p_head == NULL)
        return;

    Node* p = L -> p_head;
    while(L -> p_head -> p_next != NULL)
    {
        L -> p_head = L -> p_head -> p_next;
        delete p;
        p = L -> p_head;
    }
    delete p;
    L -> p_head = NULL;
    L -> p_tail = NULL;
}

//1.7
void removeBefore(List* &L, int val)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return;

    if(L -> p_head -> p_next -> key == val)
    {
        Node* p = L -> p_head;
        L -> p_head = L -> p_head -> p_next;
        delete p;
        return;
    }

    Node* p_front = NULL;
    Node* p_behind = L -> p_head -> p_next;

    while(p_behind -> p_next != NULL)
    {
        if(p_behind -> key == val)
        {
            Node* p = p_behind;
            p_front -> p_next = p_behind -> p_next;
            p_behind = p_behind -> p_next;
            delete p;
        }
        p_front = p_behind;
        p_behind = p_behind -> p_next;
    }
}

//1.8
void removeAfter(List* &L, int val)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return;
    
    Node* p_front = L -> p_head;

    while(p_front -> p_next != NULL)
    {
        if(p_front == L -> p_tail)
            break;

        if(p_front -> key == val)
        {
            Node* p = p_front -> p_next;
            p_front -> p_next = p_front -> p_next -> p_next;
            delete p;
        }
        p_front = p_front -> p_next;
    }
}

//1.9
bool addPos(List* &L, int data, int pos)
{
    if(L -> p_head == NULL)
        return addHead(L, data);

    int n = sizeList(L);
    if(pos < 1 || pos > n + 1)
        return false;
    if(pos == 1)
        return addHead(L, data);
    else if(pos == n + 1)
        return addTail(L, data);
    else
    {
        Node* p = L -> p_head;

        for(int i = 1; i < pos - 1; i++)
            p = p -> p_next;
            
        Node* tmp = new Node;
        tmp -> key = data;
        tmp -> p_next = p -> p_next;

        p -> p_next = tmp;
        return true;
    }
}

//1.10
void RemovePos(List* &L, int pos)
{
    if(L -> p_head == NULL)
        return;
    
    int n = sizeList(L);
    if(pos < 1 || pos > n)
        return;
    if(pos == 1)
        removeHead(L);
    else if(pos == n)
        removeTail(L);
    else
    {
        Node* p_front = NULL;
        Node* p_behind = L -> p_head;

        for(int i = 1; i < pos; i++)
        {
            p_front = p_behind;
            p_behind = p_behind -> p_next;
        }

        p_front -> p_next = p_behind -> p_next;
        delete p_behind;
    }
}

//1.11
bool addBefore(List* &L, int data, int val)
{
    if(L -> p_head == NULL)
        return false;
    
    int n = sizeList(L);

    Node* p = L -> p_head;
    for(int i = 1; i <= n; i++)
    {
        if(p -> key == val)
        {
            addPos(L, data, i);
            i++;
            n++;
        }
        p = p -> p_next;
    }
    return true;
}

//1.12
bool addAfter(List* &L, int data, int val)
{
    if(L -> p_head == NULL)
        return false;
    
    int n = sizeList(L);
    Node* p = L -> p_head;
    for(int i = 1; i <= n; i++)
    {
        if(p -> key == val)
        {
            addPos(L, data, i + 1);
            i++;
            n++;
        }
        p = p -> p_next;
    }
    return true;
}

//1.13
void printList(List* L)
{
    cout << endl;
    Node* p = L -> p_head;
    while(p != NULL)
    {
        cout << p -> key << ' ';
        p = p -> p_next;
    }
    cout << endl;
}

//1.15
int countAppearance(List* L, int value)
{
    int cnt = 0;
    Node* p = L -> p_head;
    while(p != NULL)
    {
        if(p -> key == value)
            cnt++;
        p = p -> p_next;
    }
    return cnt;
}

//1.16
List* reverseList(List* &L)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return L;

    Node* prev = NULL;
    Node* cur = L -> p_head;
    Node* fut = NULL;
    Node* head = L -> p_head;

    while(cur != NULL)
    {
        fut = cur -> p_next;
        cur -> p_next = prev;
        prev = cur;
        cur = fut;
    }
    L -> p_head = prev;
    L -> p_tail = fut;

    return L;
}

//1.17
void removeDuplicate(List* &L)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return;
    Node* cur = L -> p_head;
    while(cur != NULL)
    {
        Node* run = cur;
        while(run -> p_next != NULL)
        {
            if(run -> p_next -> key == cur -> key)
            {
                Node* tmp = run -> p_next;
                run -> p_next = tmp -> p_next;
                delete tmp;
            }
            else
                run = run -> p_next;
        }
        cur = cur -> p_next;
    }
}

//1.18

//Swap
List* swapNode1(List* &L, int x, int y)
{
        if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return L;

    int n = sizeList(L);
    if(x < 1 || y < 1 || x == y || x > n || y > n)
        return L;
    
    Node* curX = L -> p_head;
    Node* prevX = NULL;
    int idxX = 1;
    while(curX != NULL && idxX < x)
    {
        idxX++;
        prevX = curX;
        curX = curX -> p_next;
    }

    Node* curY = L -> p_head;
    Node* prevY = NULL;
    int idxY = 1;
    while(curY != NULL && idxY < y)
    {
        idxY++;
        prevY = curY;
        curY = curY -> p_next;
    }

    if(curX == NULL || curY == NULL)
        return L;
    
    if(prevX == NULL)
        L -> p_head = curY;
    else 
        prevX -> p_next = curY;
    
    if(prevY == NULL)
        L -> p_head = curX;
    else
        prevY -> p_next = curX;
    
    Node* tmp = curY -> p_next;
    curY -> p_next = curX -> p_next;
    curX -> p_next = tmp;

    if(curX -> p_next == NULL)
        L -> p_tail = curX;

    if(curY -> p_next == NULL)
        L -> p_tail = curY;
    
    return L;
}

List* swapNode2(List* &L, int x, int y)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return L;

    int n = sizeList(L);
    if(x < 1 || y < 1 || x == y || x > n || y > n)
        return L;
    
    Node* curX = L -> p_head;
    int idxX = 1;
    while(curX != NULL && idxX < x)
    {
        idxX++;
        curX = curX -> p_next;
    }

    Node* curY = L -> p_head;
    int idxY = 1;
    while(curY != NULL && idxY < y)
    {
        idxY++;
        curY = curY -> p_next;
    }

    if(curX == NULL || curY == NULL)
        return L;

    int tmp = curY -> key;
    curY -> key = curX -> key;
    curX -> key = tmp;

    return L;
}

//Get Node
Node* getNode(List* L, int pos)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return NULL;
    
    Node* p = L -> p_head;
    int idx = 1;
    while(p != NULL && idx < pos)
    {
        idx++;
        p = p -> p_next;
    }
    return p;
}

//Sort
List* sortList(List* &L)
{
    if(L -> p_head == NULL || L -> p_head -> p_next == NULL)
        return L;
    
    int n = sizeList(L);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            Node* cur = getNode(L, i);
            Node* run = getNode(L, j);
            if(run -> key < cur -> key)
                swapNode1(L, i, j);
        }
    }
    return L;
}

int main()
{
    List* L = createList(NULL);

    //int x, n;
    //cin >> n;

    for(int i = 1; i <= 10; i++)
    {
        //cin >> x;
        addTail(L, i);
    }
    printList(L);

    reverseList(L);
    printList(L);

    // removeDuplicate(L);
    // printList(L);

    swapNode2(L, 4, 7);
    printList(L);

    sortList(L);
    printList(L);
    return 0;
}
