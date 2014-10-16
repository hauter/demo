//ħ��ʦ��������
#include <stdio.h>
#include <stdlib.h>
struct card
{
    int i;
    struct card *next;
};
typedef struct card Card;

Card *initCards()
{
    Card *first, *p;
    int i;
    for (i = 0; i < 13; ++i)
    {
        Card *acard = malloc(sizeof(Card));
        acard->i = i;
        if (!i)
        {
            first = acard;
            p = acard;
        }
        else
        {
            p->next = acard;
            p = acard;
        }
    }
    p->next = first;
    return first;
}

void printCards(Card *first)
{
    Card *p;
    printf("%d\n", first->i);
    for (p = first->next; p != first; p = p->next )
    {
        printf("%d\n", p->i);
    }
}

void magicCal(Card *first)
{
    int cards[13];
    Card *p1, *p2;
    //p1ָ���һ���ڵ�
    p1 = first;
    //ʹp2ָ�����һ���ڵ�
    for (p2 = first; p2->next != first; p2 = p2->next)
        ;

    int i = 1;
    int j;
    for (;i <= 13; ++i)
    {
        j = 0;
        //����
        while (j < i - 1)
        {
            p1 = p1->next;
            p2 = p2->next;
            ++j;
        }
        //ȡ��
        cards[p1->i] = i;
        p2->next = p1->next;
        free(p1);
        p1 = p2->next;

    }

    printf("�����");
    for (i = 0; i < 13; ++i)
    {
        printf("%d  ", cards[i]);
    }
}



int magic(void)
{
    Card *cards = initCards();
    printCards(cards);
    magicCal(cards);
    return 0;
}

