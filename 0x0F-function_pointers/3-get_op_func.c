#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - selects the correct function to perform
 * the operation asked by the user
 * @s: the operator passed as argument
 *
 * Return: A pointer to the function crresponding
 * to the operator given as a parameter
 */
int (*get_op_func(char*s))(int, int)
{
        (void) s;
        op_t op[s] = {
                {"+", op_add},
                {"-", op_sub},
                {"*", op_mul},
                {"/", op_div},
                {"%", op_mod},
                {NULL, NULL},
        };
