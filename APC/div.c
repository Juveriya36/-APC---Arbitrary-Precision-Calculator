#include "apc.h"

/* Subtract second list from first list.
   Assumes first >= second */
static void subtract_temp(node *head1, node *head2,
                          node **headR, node **tailR)
{
    node *tail1 = NULL;
    node *tail2 = NULL;
    node *temp;

    temp = head1;
    while (temp)
    {
        tail1 = temp;
        temp = temp->next;
    }

    temp = head2;
    while (temp)
    {
        tail2 = temp;
        temp = temp->next;
    }

    int borrow = 0;
    int diff;

    while (tail1)
    {
        diff = tail1->data - borrow;

        if (tail2)
        {
            diff -= tail2->data;
            tail2 = tail2->prev;
        }

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, diff);

        tail1 = tail1->prev;
    }

    remove_pre_zeros(headR);
}

void division(node *head1, node *head2,
              node **headR, node **tailR)
{
    node *currentHead = NULL;
    node *currentTail = NULL;
    node *tempHead = NULL;
    node *tempTail = NULL;

    int quotient_digit;


    if (head2 == NULL)
    {
        printf("Error: Division by zero\n");
        return;
    }

    /* Check divisor == 0 */
    node *temp = head2;

    while (temp)
    {
        if (temp->data != 0)
            break;

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Error: Division by zero\n");
        return;
    }

    /* If dividend < divisor */
    if (compare_list(head1, head2) == OPERAND2)
    {
        insert_last(headR, tailR, 0);
        return;
    }

    temp = head1;

    while (temp)
    {
        /* Append current digit */
        insert_last(&currentHead, &currentTail, temp->data);
        remove_pre_zeros(&currentHead);

        quotient_digit = 0;

        /* Determine quotient digit */
        while (compare_list(currentHead, head2) != OPERAND2)
        {
            delete_list(&tempHead, &tempTail);

            subtract_temp(currentHead, head2,
                          &tempHead, &tempTail);

            delete_list(&currentHead, &currentTail);

            currentHead = tempHead;
            currentTail = tempTail;

            tempHead = NULL;
            tempTail = NULL;

            quotient_digit++;
        }

        insert_last(headR, tailR, quotient_digit);

        temp = temp->next;
    }

    remove_pre_zeros(headR);

    delete_list(&currentHead, &currentTail);
}