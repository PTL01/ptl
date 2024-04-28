#include <stdio.h>
#include <ctype.h>

int main()
{
    char expression[15], character;
    int index = 0;

    printf("Enter Expression terminated by $: ");
    while ((character = getchar()) != '$')
    {
        if (isalpha(character) || strchr("+-/*%", character))
        {
            expression[index++] = character;
            printf("%c \t %p \t %s \n", character, &expression[index - 1], isalpha(character) ? "identifier" : "operator");
        }
    }
    return 0;
}
