/*
    CH-230-A
    a6_p9.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

struct list *insert_item(struct list *my_list, int pos, int val)
{
	struct list *newel, *cursor;
	cursor = my_list;
	newel = (struct list *)malloc(sizeof(struct list));
	if (newel == NULL)
	{
		printf(" Error allocating memory \n");
		return my_list;
	}

	if (pos == 0)
	{
		push_back(&my_list, val);
	}
	else if (pos > 0)
	{
		newel->info = val;
		for (int i = 1; i < pos; i++)
		{
			cursor = cursor->next;
			if (cursor == NULL)
			{
				return my_list;
			}
		}
		newel->next = cursor->next;
		cursor->next = newel;
	}
	else
	{
		printf("Invalid position!\n");
	}
	return my_list;
}
struct list *reverse_list(struct list *my_list)
{
	struct list *prev_El, *current_El;

	if (my_list != NULL)
	{
		prev_El = my_list;
		current_El = my_list->next;
		my_list = my_list->next;

		prev_El->next = NULL;

		//Loop to go to the end of the linked list
		while (my_list != NULL)
		{
			my_list = my_list->next;
			current_El->next = prev_El;

			prev_El = current_El;
			current_El = my_list;
		}

		my_list = prev_El;
	}
	return my_list;
}

int main()
{
	char quit = 'a';
	char inp;
	int n;
	int value;
	int position;
	int count = 0;
	struct list *my_list = NULL;
	while (quit != 'q')
	{ //Separating inputs into cases:
		scanf("%c", &inp);
		switch (inp)
		{
		case 'a':
			count++;
			scanf("%d", &n);
			push_front(&my_list, n);
			break;
		case 'b':
			count++;
			scanf("%d", &n);
			push_back(&my_list, n);
			break;
		case 'i':
			scanf("%d", &position);
			scanf("%d", &value);
			if (position < 0 || position > count)
			{
				printf("Invalid position!\n");
				continue;
			}
			count++;
			my_list = insert_item(my_list, position, value);
			break;
		case 'R':
			my_list = reverse_list(my_list);
			break;
		case 'p':
			print(my_list);
			break;
		case 'r':
			count--;
			my_list = remove_front(my_list);
			break;
		case 'q':
			quit = 'q';
			dispose_list(my_list);
			break;
		}
	}

	return 0;
}
