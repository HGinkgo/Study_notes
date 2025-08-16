#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    const char token[] = " \n\r\f\t\v";
    int count = 0;

    char buff[101];
    while (fgets(buff, sizeof buff, stdin)) {
        for (char *word = strtok(buff, token);
             word != NULL;
             word = strtok(NULL, token)) {
            if (strcmp(word, "the") == 0)
                count++;
        }
    }
    return count;   // shell 里 echo $? 可查看
}