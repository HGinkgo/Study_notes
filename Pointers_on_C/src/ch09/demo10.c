#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *string) {
    char *start = string;
    char *end = string + strlen(string) - 1;

    while (start < end) {
        if (!isalpha((unsigned char)*start)) {
            start++;
            continue;
        }
        if (!isalpha((unsigned char)*end)) {
            end--;
            continue;
        }
        if (tolower((unsigned char)*start) != tolower((unsigned char)*end))
            return 0;
        start++;
        end--;
    }
    return 1;
}