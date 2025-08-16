#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t my_strlen(const char *string, int size) {
    size_t i = 0;
    for (i; i < size; i ++ ) 
        if (*string ++ == '\0')
            break;
    return i;
}

int main(void)
{
    char a[10] = "1234567";   /* 已占 8 字节 */
    char b[]   = "567";       /* 3 字符 + 1 '\0' */

    strncat(a, b, sizeof(a) - strlen(a) - 1);
    puts(a);                 

    printf("my_strlen(a, sizeof a) = %zu\n", my_strlen(a, sizeof a));
    return 0;
}