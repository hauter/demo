/*
 * 输入一个链表的头节点，从尾到头反过来打印出每个结点的值。
 * 链表结点定义如下:
 * struct ListNode
 * {
 *      int m_nKey;
 *      ListNode* m_pNext;
 * };
 */

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
     int m_nKey;
     ListNode* m_pNext;
};
typedef struct ListNode ListNode, *LinkList;
void CreateList(LinkList &L)
{
    int temp;
    ListNode *s;
    L = new ListNode;
    L->m_pNext = NULL;
    s = L;
    cout << "input:" << endl;

    while (cin >> temp)
    {
        ListNode *node = new ListNode;
        node->m_nKey = temp;
        node->m_pNext = NULL;
        s->m_pNext = node;
        s = s->m_pNext;
    }
}

void PrintList(LinkList l)
{
    if (l == NULL) return;
    while (l->m_pNext != NULL)
    {
        l = l->m_pNext;
        cout << l->m_nKey << "  ";
    }
    cout << endl;
}

void PrintListReversingly(LinkList l)
{
    stack<ListNode*> nodes;
    while ((l = l->m_pNext) != NULL)
    {
        nodes.push(l);
    }
    ListNode *node;
    while (!nodes.empty())
    {
        node = nodes.top();
        cout << node->m_nKey << "  ";
        nodes.pop();
    }
    cout << endl;

}
int mainQ5 (void)
{
    LinkList l;
    CreateList(l);
    PrintList(l);
    PrintListReversingly(l);
    return 0;
}



