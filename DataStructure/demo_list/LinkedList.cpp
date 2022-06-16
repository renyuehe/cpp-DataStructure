#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}*LinkedList, LNode;


void CreatLinkedList(LinkedList& L, int n)   //尾插法创建单链表;
{
    L = (LinkedList)malloc(sizeof(LNode));  //初始化;
    L->next = NULL;
    L->data = 0;
    LinkedList Tail = L;    //尾指针;
    cout << "Enter " << n << " number(s)" << endl;
    for (int i = 0; i < n; i++)
    {
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        cin >> Temp->data;
        Tail->next = Temp;
        Tail = Temp;
        Temp = NULL;
        L->data++;  //计数;
    }
    Tail->next = NULL;
}

bool GetElem(int& e, int i, LinkedList L) //获取结点;
{
    while (L != NULL && i > 0)
    {
        i--;
        L = L->next;
    }
    if (i == 0 && L != NULL) //i=1时也有可能同时满足退出while的条件;
    {
        e = L->data;
        return true;
    }
    else return false;
}

bool InsertElem(int e, int i, LinkedList L)   //插入结点;
{
    if (i > L->data + 1 || i < 1)    return false;
    else
    {
        L->data++;
        while (i > 1)
        {
            i--;
            L = L->next;
        }
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        Temp->data = e;
        Temp->next = L->next;
        L->next = Temp;
        Temp = NULL;
        return true;
    }
}

bool DeleteElem(int i, LinkedList L) //删除结点;
{
    if (i > L->data || i < 1)    return false;
    else
    {
        L->data--;
        while (i > 1)
        {
            i--;
            L = L->next;
        }
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        Temp = L->next;
        L->next = Temp->next;
        free(Temp);
        Temp = NULL;
        return true;
    }
}

bool DestoryLinkedList(LinkedList& L)   //销毁单链表;
{
    if (L->next != NULL)
        DestoryLinkedList(L->next);
    free(L);
    L = NULL;
    return true;
}

bool ClearLinkedList(LinkedList& L) //清空单链表;
{
    DestoryLinkedList(L->next);
    L->next = NULL;
    L->data = 0;
    return true;
}

void GetLinkedList(LinkedList L)    //遍历单链表;
{
    LinkedList Head = L->next;
    while (Head != NULL)
    {
        cout << Head->data << endl;
        Head = Head->next;
    }
}

int main()
{
    int n, i, Elem;
    bool Flag;
    LinkedList L;
    cout << "How many Elem(s) do you want to creat?" << endl;
    cin >> n;
    CreatLinkedList(L, n);
    cout << "Here is what they look like:" << endl;
    GetLinkedList(L);
    cout << "Which position of Elem do you want?" << endl;
    cin >> i;
    Flag = GetElem(Elem, i, L);
    if (Flag == true)
        cout << Elem << endl;
    else
        cout << "No maching Elem" << endl;
    cout << "What Elem you wanna insert , and where?" << endl;
    cout << "Elem :";
    cin >> Elem;
    cout << "Position :";
    cin >> i;
    Flag = InsertElem(Elem, i, L);
    if (Flag == true)
    {
        cout << "Succeeded!" << endl;
        GetLinkedList(L);
    }
    else
        cout << "Failed!" << endl;
    cout << "Which position of Elem do you want to delete :" << endl;
    cin >> i;
    Flag = DeleteElem(i, L);
    if (Flag == true)
    {
        cout << "Succeeded!" << endl;
        GetLinkedList(L);
    }
    else
        cout << "Failed!" << endl;
    if (ClearLinkedList(L))   cout << "LinkedListed Cleared!" << endl;
    GetLinkedList(L);   //验证是否清空;
    if (DestoryLinkedList(L))    cout << "LinkedList Destoryed!" << endl;
    if (L == NULL) cout << "Check" << endl; //验证是否销毁;
    return 0;
}