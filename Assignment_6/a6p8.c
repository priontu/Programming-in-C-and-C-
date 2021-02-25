/*
CH-230-A
a6 p8.[c or cpp or h]
Priontu Chowdhury
p.chowdhury@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//Initialization:
struct list
{
    int info;
    struct list *next;
};

//Declaring all necessary functions:
//Pushing at the back of list:
void push_back(struct list **new_list, int n)
{
    struct list *newlist = (struct list *)malloc(sizeof(newlist));
    if (newlist == NULL)
    {
        printf(" Error allocating memory \n");
        exit(1);
    }
    newlist->info = n;
    newlist->next = (*new_list);
    (*new_list) = newlist;
}
//Pushing in front of list:
void push_front(struct list **my_list_ref, int new_info)
{
    struct list *new_list = (struct list *)malloc(sizeof(struct list));
    if (new_list == NULL)
    {
        printf(" Error allocating memory \n");
        exit(1);
    }
    struct list *last = *my_list_ref;
    new_list->info = new_info;
    new_list->next = NULL;
    if (*my_list_ref == NULL)
    {
        *my_list_ref = new_list;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_list;
    return;
}
//Printing the values:
void print(struct list *n)
{
    while (n != NULL)
    {
        printf("%d ", n->info);
        n = n->next;
    }
    printf("\n");
}
//Removing the first element:
struct list *remove_front(struct list *my_list)
{
    struct list *newlist = NULL;
    if (my_list != NULL)
    {
        newlist = my_list->next;
        free(my_list);
        return newlist;
    }
    else
    {
        return my_list;
    }
}
//Disposing of the structure:
void dispose_list(struct list *n)
{
    struct list *nextelem;
    while (n != NULL)
    {
        nextelem = n->next;
        free(n);
        n = nextelem;
    }
}
int main()
{
    char quit = 'a';
    char inp;
    int n;
    struct list *my_list = NULL;
    while (quit != 'q')
    {   //Separating inputs into cases:
        scanf("%c", &inp);
        switch (inp)
        {
        case 'a':
            scanf("%d", &n);
            push_front(&my_list, n);
            break;
        case 'b':
            scanf("%d", &n);
            push_back(&my_list, n);
            break;
        case 'p':
            print(my_list);
            break;
        case 'r':
            my_list = remove_front(my_list);
            break;
        case 'q':
            quit = 'q';
            dispose_list(my_list);
        }
    }
    
    return 0;
}
