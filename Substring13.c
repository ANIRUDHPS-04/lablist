#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], sub[50];
    int pos, i, len;

    printf("Enter the original string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the substring to insert: ");
    fgets(sub, sizeof(sub), stdin);

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    len = strlen(str);

    // Remove newline from strings
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(sub);
    if (sub[len - 1] == '\n')
        sub[len - 1] = '\0';

    // Shift original string to the right
    for (i = strlen(str); i >= pos; i--)
        str[i + strlen(sub)] = str[i];

    // Insert substring
    for (i = 0; sub[i] != '\0'; i++)
        str[pos + i] = sub[i];

    printf("Updated text: %s\n", str);

    return 0;
}
