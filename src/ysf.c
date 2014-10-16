//约瑟夫问题
#include <stdio.h>
#include <stdlib.h>
#define TOTLE 41
struct node
{
    struct node *next;
    int i;
};
typedef struct node Node;
Node *init_linked_node(int n);
void print_linked_node(Node *first_node);
Node *self_kill(Node *first_node);

int ysf(void)
{
    Node *linked_node = init_linked_node(TOTLE);
    print_linked_node (linked_node);
    printf("\nstart self-kill:\n");
    linked_node = self_kill(linked_node);
    printf("\nend of self-kill:\n");
    print_linked_node(linked_node);
    return 0;
}

Node *init_linked_node(int n)
{
    Node *p, *first_node;
    int i;
    for (i = 0; i < n; ++i)
    {
        Node *anode = malloc(sizeof(Node));
        anode->i = i + 1;
        if (i == 0)
        {
            first_node = anode;
            p = first_node;
        }
        else
        {
            p->next = anode;
            p = anode;
        }
    }
    p->next = first_node;
    return first_node;
}

void print_linked_node(Node *first_node)
{
    printf("%d  ", first_node->i);
    Node *p = first_node->next;
    for (;p != first_node; p = p->next )
    {
        printf("%d  ", p->i);
    }
}

Node *self_kill(Node *first_node)
{
    Node *p1 = first_node;
    Node *p2;
    int current_num = TOTLE;
    int i = 0;
    //printf("curr:%d\n",current_num);
    for (; current_num != 2;)
    {
        //printf("curr:%d\n",current_num);
        ++i;
        if (i == 3)
        {
            //自杀
            p2 ->next = p1->next;
            printf("%d self-killed\n", p1->i);
            free(p1);
            p1 = p2->next;
            --current_num;
            i = 0;
        }
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }
    return p1;

}
