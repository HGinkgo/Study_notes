#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* 建立逆映射：cipher -> plain */
static void build_inv(const char *key, char inv[26])
{
    const char plain[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; ++i)
        inv[key[i] - 'a'] = plain[i];
}

void decrypt(char *data, const char *key)
{
    char inv[26];
    build_inv(key, inv);

    for (unsigned char *p = (unsigned char *)data; *p; ++p) {
        if (islower(*p))
            *p = inv[*p - 'a'];
        else if (isupper(*p))
            *p = toupper(inv[*p - 'A']);
    }
}

int main(void)
{
    char msg[] = "Itssg, VGKSR!";
    const char *key = "qwertyuiopasdfghjklzxcvbnm";
    decrypt(msg, key);
    puts(msg);          /* Hello, WORLD! */
    return 0;
}