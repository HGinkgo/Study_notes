#include <ctype.h>
#include <stdio.h>

void encrypt(char *data, const char *key) {
    for (int ch; (ch = *data) != '\0'; ++data) {
        if (islower(ch))
            *data = key[ch - 'a'];
        else if (isupper(ch))
            *data = toupper(key[ch - 'A']);
    }
}

int main(void) {
    char msg[] = "Hello, WORLD!";
    const char *key = "qwertyuiopasdfghjklzxcvbnm";  // 26 字母表重排
    encrypt(msg, key);
    puts(msg);   // 输出: Itssg, VGKSR!
    return 0;
}