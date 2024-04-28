#include <stdio.h>
#include <ctype.h>

char look_ahead;

// E-> TE’
// E'-> +TE’ | epsilon
// T-> FT’
// T’-> *FT’ | epsilon
// F-> (E) | id

void E();
void Edash();
void T();
void Tdash();
void F();
void match(char);

int main()
{
    printf("Enter the string: ");
    look_ahead = getchar();
    E();
    if (look_ahead == '$')
    {
        printf("Parsing Successful");
    }
    else
        printf("Parsing Failed");
    return 0;
}

void match(char c)
{
    if (look_ahead == c)
    {
        look_ahead = getchar();
    }
    else
    {
        printf("Parsing Failed");
    }
}

// E-> TE’
void E()
{
    T();
    Edash();
}
// E'-> +TE’ | epsilon
void Edash()
{
    if (look_ahead == '+')
    {
        match('+');
        T();
        Edash();
    }
    else
    {
        return;
    }
}
// T-> FT’
void T()
{
    F();
    Tdash();
}
// T’-> *FT’ | epsilon
void Tdash()
{
    if (look_ahead == '*')
    {
        match('*');
        F();
        Tdash();
    }
    else
    {
        return;
    }
}
// F-> (E) | id
void F()
{
    if (look_ahead == '(')
    {
        match('(');
        E();
        match(')');
    }
    else if (look_ahead == 'i')
    {
        match('i');
        match('d');
    }
}