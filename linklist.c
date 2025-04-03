#include <stdio.h>
#include <stdlib.h>

struct linklist // self ref. structure
{
    int data;       // data       
    struct linklist *next;
};
struct linklist *start;

void insert();
void display();
void del();
void count();
void sort();
void reverse();
void edit();
void exit_program();
void atbeg();
void atend();
void before();
void after();
void atpos();
void delete_at_pos();

int main()
{
    int ch1;
    char choice1 = 'y';
    start = NULL;

    system("cls");  // clrscr(); // Clears the screen on Windows
    do
    {
        printf("\n LINKED LIST PROJECT \n");
        printf("\n 1. INSERT     ");
        printf("\n 2. DISPLAY     ");
        printf("\n 3. DELETE      ");
        printf("\n 4. COUNT NODES ");
        printf("\n 5. SORTING     ");
        printf("\n 6. REVERSE     ");
        printf("\n 7. EDIT        ");
        printf("\n 8. EXIT        ");
        printf("\n\n Enter Your Choice = ");
        scanf("%d", &ch1);

        switch (ch1)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            del();
            break;
        case 4:
            count();
            break;
        case 5:
            sort();
            break;
        case 6:
            reverse();
            break;
        case 7:
            edit();
            break;
        case 8:
            choice1 = 'n';
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice1 == 'y');

    return 0;
} // end of main //

void insert()
{
    int ch2;
    char choice2 = 'y';
    do
    {
        printf("\n 1. ATBEG ");
        printf("\n 2. ATEND ");
        printf("\n 3. BEFORE ");
        printf("\n 4. AFTER ");
        printf("\n 5. ATPOSI ");
        printf("\n 6. EXIT ");
        printf("\n\n Enter Your Choice = ");
        scanf("%d", &ch2);

        switch (ch2)
        {
        case 1:
            atbeg();
            break;
        case 2:
            atend();
            break;
        case 3:
            before();
            break;
        case 4:
            after();
            break;
        case 5:
            atpos();
            break;
        case 6:
            choice2 = 'n';
            break;
        default:
            printf("INVALID CHOICE");
        }
    } while (choice2 == 'y');
}

void atbeg()
{
    struct linklist *newnode = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n Enter a number to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = start;
    start = newnode;
}

void atend()
{
    struct linklist *newnode = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *temp;
    printf("\n Enter a number to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    
    
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void before()
{
    int value;
    printf("\n Enter the value before which you want to insert: ");
    scanf("%d", &value);

    struct linklist *newnode = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n Enter the number to insert: ");
    scanf("%d", &newnode->data);

    struct linklist *temp = start, *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n Value not found in the list.");
    }
    else
    {
        newnode->next = temp;
        if (prev == NULL)
        {
            start = newnode;
        }
        else
        {
            prev->next = newnode;
        }
    }
}

void after()
{
    int value;
    printf("\n Enter the value after which you want to insert: ");
    scanf("%d", &value);

    struct linklist *newnode = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n Enter the number to insert: ");
    scanf("%d", &newnode->data);

    struct linklist *temp = start;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n Value not found in the list.");
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void atpos()
{
    int pos, i;
    printf("\n Enter the position at which you want to insert: ");
    scanf("%d", &pos);

    struct linklist *newnode = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n Enter the number to insert: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        struct linklist *temp = start;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\n Position exceeds the length of the list.");
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void display()
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    struct linklist *temp = start;
    printf("\n The linked list is: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void del()
{
    int value;
    printf("\n Enter the value to delete: ");
    scanf("%d", &value);

    struct linklist *temp = start, *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        start = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n Value not found in the list.");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void count()
{
    struct linklist *temp = start;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\n The total number of nodes: %d\n", count);
}

void sort()
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    struct linklist *i, *j;
    int temp;

    for (i = start; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\n The list has been sorted.\n");
}

void reverse()
{
    struct linklist *prev = NULL, *current = start, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    start = prev;
    printf("\n The list has been reversed.\n");
}

void edit()
{
    int old, new;
    printf("\n Enter the value to edit: ");
    scanf("%d", &old);
    printf("\n Enter the new value: ");
    scanf("%d", &new);

    struct linklist *temp = start;

    while (temp != NULL && temp->data != old)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n Value not found in the list.");
    }
    else
    {
        temp->data = new;
        printf("\n Value updated successfully.");
    }
}

void exit_program()
{
    printf("\n Exiting program.\n");
}