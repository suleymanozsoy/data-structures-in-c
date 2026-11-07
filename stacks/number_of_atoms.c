#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEPTH 100

typedef struct
{

    int count[26];

} AtomCounts;

typedef struct
{

    AtomCounts items[MAX_DEPTH];
    int top;

} Stack;

int push(Stack *s, AtomCounts value)
{

    if (s->top >= MAX_DEPTH - 1)
        return 0;

    s->top++;

    s->items[s->top] = value;

    return 1;
}

int pop(Stack *s, AtomCounts *value)
{

    if (s->top == -1)
        return 0;

    *value = s->items[s->top];

    s->top--;

    return 1;
}

int parseFormula(char *formula, AtomCounts *result)
{

    Stack s = {.top = -1};

    AtomCounts current = {0};

    int i = 0;

    while (formula[i] != '\0')
    {

        char ch = formula[i];

        if (ch >= 'A' && ch <= 'Z')
        {

            i++;

            int multiplier = 1;

            if (isdigit((unsigned char)formula[i]))
            {

                multiplier = formula[i] - '0';
                i++;
            }

            current.count[ch - 'A'] += multiplier;
        }
        else if (ch == '(')
        {

            if (!push(&s, current))
                return 0;

            current = (AtomCounts){0};
            i++;
        }
        else if (ch == ')')
        {

            i++;

            int multiplier = 1;

            if (isdigit((unsigned char)formula[i]))
            {
                multiplier = formula[i] - '0';
                i++;
            }

            for (int i = 0; i < 26; i++)
                current.count[i] *= multiplier;

            AtomCounts outer;

            if (!pop(&s, &outer))
                return 0;

            for (int i = 0; i < 26; i++)
                outer.count[i] += current.count[i];

            current = outer;
        }
        else
        {
            return 0;
        }
    }

    if (s.top != -1)
        return 0;

    *result = current;

    return 1;
}

int main(void)
{
    char formula[] = "K4(ON(SO3)2)2";

    AtomCounts result = {0};

    if (!parseFormula(formula, &result))
    {
        printf("Invalid formula!\n");
        return 1;
    }

    printf("Result: ");

    for (int i = 0; i < 26; i++)
    {
        if (result.count[i] > 0)
        {
            printf("%c", 'A' + i);

            if (result.count[i] != 1)
                printf("%d", result.count[i]);
        }
    }

    printf("\n");

    return 0;
}
