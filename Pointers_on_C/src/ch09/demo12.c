#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 返回最终密钥表长度（26），出错返回 0 */
int prepara_key(char *key)
{
    unsigned char *p = (unsigned char *)key;
    unsigned char *dst, *src;
    int ch;

    /* 1. 全部转小写并检查非法字符 */
    for ( ; (ch = *p) != '\0'; ++p) {
        if (isupper(ch))
            ch = tolower(ch);
        if (!islower(ch))
            return 0;                   /* 出现非字母字符 */
        *p = (unsigned char)ch;
    }

    /* 2. 去重：O(n²) 但密钥通常很短，可接受 */
    p = (unsigned char *)key;
    while ((ch = *p) != '\0') {
        unsigned char *q = p + 1;
        while ((q = (unsigned char *)strchr((char *)q, ch)) != NULL) {
            /* memmove 允许重叠 */
            memmove(q, q + 1, strlen((char *)q + 1) + 1);
        }
        ++p;
    }

    /* 3. 追加缺失字母 */
    p = (unsigned char *)key + strlen(key);
    for (ch = 'a'; ch <= 'z'; ++ch) {
        if (!strchr(key, ch))
            *p++ = (unsigned char)ch;
    }
    *p = '\0';

    return 26;  /* 成功 */
}

/* 简单测试 */
int main(void)
{
    char k[64] = "SecretKey";
    if (prepara_key(k))
        printf("result: %s\n", k);  /* 期望 26 字母表 */
    else
        puts("bad key");
    return 0;
}