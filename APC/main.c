/*
Name : Juveriya Bepari
Institute : Emertxe, 26005B
Date of submission : 20/08/2026

Description :-

* This project is an "Arbitrary Precision Calculator (APC)" developed using C language.
* It performs arithmetic operations on large multi-digit numbers.
* It supports operations like "addition, subtraction, multiplication and division".
* The project uses a "Doubly Linked List" to store and process each digit of the number.
* It can handle numbers larger than the normal integer data type limit.
* The user can perform calculations by providing two operands and an operator.
* The program performs calculations digit by digit using linked-list operations.
* It handles carry and borrow during addition and subtraction.
* It provides accurate results for large number calculations without integer overflow.
* The project uses functions to make the code simple, modular and organized.
* It uses "dynamic memory allocation" for creating and managing linked-list nodes.
* The project helps in understanding "Doubly Linked Lists, pointers, structures and dynamic memory allocation".
* It improves problem-solving skills and provides practical understanding of data structures in C.

*/






#include "apc.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    node *head1 = NULL;
    node *tail1 = NULL;

    node *head2 = NULL;
    node *tail2 = NULL;

    node *headR = NULL;
    node *tailR = NULL;

    char operator;

    if (argc != 4)
    {
        printf("Usage: %s <operand1> <operator> <operand2>\n", argv[0]);
        return FAILURE;
    }

    operator = argv[2][0];

    /* Create operand 1 list */
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("Invalid operand\n");
            return FAILURE;
        }

        insert_last(&head1, &tail1, argv[1][i] - '0');
    }

    /* Create operand 2 list */
    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)argv[3][i]))
        {
            printf("Invalid operand\n");
            return FAILURE;
        }

        insert_last(&head2, &tail2, argv[3][i] - '0');
    }

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    /* Perform operation */
    switch (operator)
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            break;

        case '-':
        {
            int cmp = compare_list(head1, head2);

            if (cmp == SAME)
            {
                insert_last(&headR, &tailR, 0);
            }
            else if (cmp == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);
            }
            else
            {
                printf("Result: %s - %s = -", argv[1], argv[3]);

                subtraction(tail2, tail1, &headR, &tailR);
                print_list(headR);

                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
                delete_list(&headR, &tailR);

                return SUCCESS;
            }

            break;
        }

        case 'x':
        case 'X':
        case '*':
            multiplication(tail1, tail2, &headR, &tailR);
            break;

        case '/':
            division(head1, head2, &headR, &tailR);
            break;

        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    /* Simple output */
    printf("Result: %s %c %s = ", argv[1], operator, argv[3]);
    print_list(headR);
    printf("\n");

    /* Free memory */
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}