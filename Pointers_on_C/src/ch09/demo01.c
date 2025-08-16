#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int n_cntrl = 0;
int n_space = 0;
int n_digit = 0;
int n_lower = 0;
int n_upper = 0;
int n_punct = 0;
int n_nprint = 0;
int total   = 0;

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        total++;

        if (!isprint(ch)) {
            n_nprint++;
            n_cntrl++;
        } else if (isspace(ch)) {
            n_space++;
        } else if (isdigit(ch)) {
            n_digit++;
        } else if (islower(ch)) {
            n_lower++;
        } else if (isupper(ch)) {
            n_upper++;
        } else if (ispunct(ch)) {
            n_punct++;
        }
    }

    if (total == 0) {
        puts("No characters in the input!");
        return EXIT_SUCCESS;
    }

    printf("%3.0f%% control characters\n",   n_cntrl * 100.0 / total);
    printf("%3.0f%% whitespace characters\n", n_space * 100.0 / total);
    printf("%3.0f%% digit characters\n",     n_digit * 100.0 / total);
    printf("%3.0f%% lower case characters\n", n_lower * 100.0 / total);
    printf("%3.0f%% upper case characters\n", n_upper * 100.0 / total);
    printf("%3.0f%% punctuation characters\n", n_punct * 100.0 / total);
    printf("%3.0f%% non-printable characters\n", n_nprint * 100.0 / total);

    return EXIT_SUCCESS;
}