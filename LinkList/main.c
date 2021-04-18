#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N_MAX 10
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

int Count(struct Node *p){
    int l;
    while(p != NULL)
    {
        l = l + 1;
        p = p->next;
    }
    return l;
}
void Create(int data[], int N)
{
    struct Node *tmp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = data[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < N; i++)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = data[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node* LSearch(struct Node *p, int key)
{
    while(p->next != NULL)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node* RSearch(struct Node *p, int key)
{
    if(p->next == NULL)
        return NULL;
    if(p->data == key)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x){
    struct Node * t;
    int i;
    if(index < 0 || index > Count(p))
    {
        printf("pos is invalid \n");
        return;
    }
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = first->next;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1 ; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void SortInsert(struct Node *p, int x)
{
    struct Node *t, *q;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
        return;
    }

    while(p && p->data < x)
    {
        q = p;
        p = p->next;
    }

    if(p == first)
    {
        t->next = p;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if(index < 1 || index > Count(first))
        return -1;

    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
       for(int i = 0; i < index -1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

}

int IsSorted(struct Node *p)
{
    int x = - 749324;
    while(p)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = NULL;
    q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

//struct Node* Reversing(struct Node *head)
//{
//    int A[N_MAX];
//    int i = 0;
//    struct Node *p;
//    p = head;
//    while(p != NULL)
//    {
//         A[i] = p->data;
//         p = p->next;
//         i++;
//    }
//    p = first; i--;
//    while(p != NULL)
//    {
//         p->data = A[i];
//         p = p->next;
//         i--;
//    }
//    return head;
//}


// Approach #1 (Iterative)

struct Node* Reversing1(struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;

    while(curr != NULL)
    {
        struct Node *nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
    }
    return prev;
}

struct Node* reverseList(struct Node* head){
    int A[5000];
    int  j = 0;
    struct Node *p;
    p = head;
    while(!p)
    {
        A[j] = p->data;
        p = p->next;
        j++;
    }
    p = head;
    j--;
    while(!p)
    {
        p->data = A[j];
        p = p->next;
        j--;
    }
    return head;
}
int main()
{
    int data[] = {10, 20, 20, 40, 50};
    Create(data, 5);
    Display(first);
    struct Node *q;
    q = Reversing1(first);
    Display(q);
    return 0;
}
