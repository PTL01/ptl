#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywordList[] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return", "union", "const", "float", "short", "unsigned", "continue", "for", "signed", "void", "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"};
char *operatorList[] = {"+", ">", "~", "%=", "-", "<", "&", "<<=", "*", ">=", "^", ">>=", "/", "<=", "|", "&=", "%", "&&", "=", "^=", "++", "||", "+=", "|=", "--", "!", "-=", "==", "<<", "*=", "!=", ">>", "/="};
char *specialSymbolList[] = {"[", "]", "{", "}", ",", ";", ":", "(", ")"};

int isInArray(char *word, char **array, int size)
{
    for (int i = 0; i < size; i++)
        if (!strcmp(word, array[i]))
            return 1;
    return 0;
}

int isConstant(char *word)
{
    int dotCount = 0;
    for (int i = 0; word[i]; i++)
    {
        if (!isdigit(word[i]) && word[i] != '.')
            return 0;
        if (word[i] == '.')
            dotCount++;
    }
    return dotCount <= 1;
}

int isLiteral(char *word)
{
    int length = strlen(word);
    return length > 1 && ((word[0] == '"') && (word[length - 1] == '"'));
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if (!fp)
    {
        printf("Can't open input.txt for reading.\n");
        return 1;
    }
    char currentWord[100];
    while (fscanf(fp, "%s", currentWord) != EOF)
    {
        if (isInArray(currentWord, keywordList, sizeof(keywordList) / sizeof(char *)))
            printf("%s is a keyword\n", currentWord);
        else if (isInArray(currentWord, operatorList, sizeof(operatorList) / sizeof(char *)))
            printf("%s is an operator\n", currentWord);
        else if (isConstant(currentWord))
            printf("%s is a constant\n", currentWord);
        else if (isInArray(currentWord, specialSymbolList, sizeof(specialSymbolList) / sizeof(char *)))
            printf("%s is a special symbol\n", currentWord);
        else if (isLiteral(currentWord))
            printf("%s is a literal\n", currentWord);
        else
            printf("%s is an identifier\n", currentWord);
    }
    fclose(fp);
    return 0;
}
