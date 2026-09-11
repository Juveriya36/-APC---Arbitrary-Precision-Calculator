#include "apc.h"

void multiplication(node *tail1, node *tail2,
                    node **headR, node **tailR)
{
    int len1 = 0;
    int len2 = 0;

    node *temp;

    /* Find length of first number using tail */
    temp = tail1;
    while (temp)
    {
        len1++;
        temp = temp->prev;
    }

    /* Find length of second number using tail */
    temp = tail2;
    while (temp)
    {
        len2++;
        temp = temp->prev;
    }

    if (len1 == 0 || len2 == 0)
    {
        insert_last(headR, tailR, 0);
        return;
    }

    int *a = malloc(sizeof(int) * len1);
    int *b = malloc(sizeof(int) * len2);
    int *result = calloc(len1 + len2, sizeof(int));

    if (a == NULL || b == NULL || result == NULL)
    {
        free(a);
        free(b);
        free(result);
        return;
    }

    int i = 0;
    int j;

    /* Store first number in reverse array */
    temp = tail1;

    while (temp)
    {
        a[i++] = temp->data;
        temp = temp->prev;
    }

    /* Store second number in reverse array */
    i = 0;
    temp = tail2;

    while (temp)
    {
        b[i++] = temp->data;
        temp = temp->prev;
    }

    /* Multiplication */
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            result[i + j] += a[i] * b[j];
        }
    }

    /* Handle carry */
    for (i = 0; i < len1 + len2 - 1; i++)
    {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    /* Find most significant non-zero digit */
    i = len1 + len2 - 1;

    while (i > 0 && result[i] == 0)
    {
        i--;
    }

    /* Insert result from most significant digit */
    for (; i >= 0; i--)
    {
        insert_last(headR, tailR, result[i]);
    }

    free(a);
    free(b);
    free(result);
}