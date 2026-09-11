#include "apc.h"

/* Insert node at beginning */
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}

/* Insert node at end */
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}

/* Delete entire list */
int delete_list(node **head, node **tail)
{
    node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}

/* Print list */
void print_list(node *head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

/* Find length */
int list_len(node *head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

/* Compare two positive numbers */
int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if (len1 > len2)
        return OPERAND1;

    if (len2 > len1)
        return OPERAND2;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return OPERAND1;

        if (head1->data < head2->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}

/* Remove leading zeros */
void remove_pre_zeros(node **head)
{
    node *temp;

    while (*head != NULL &&
           (*head)->data == 0 &&
           (*head)->next != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

/* Free list */
void free_list(node **head, node **tail)
{
    delete_list(head, tail);
}

/* Copy list */
void copy_list(node *src, node **head, node **tail)
{
    while (src)
    {
        insert_last(head, tail, src->data);
        src = src->next;
    }
}