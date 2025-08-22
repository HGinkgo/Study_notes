#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read(void) {
    int size, n, val;
    scanf("%d", &n);
    int* array = (int*)malloc((n + 1) * size);
    if (array == NULL) {
        return NULL;
    }

    int cnt = 0;
    while(scanf("%d", &val) == 1){
        cnt++;
        if (cnt > n) {
            array = realloc(array, (n + 1) * sizeof(int));
            if (array == NULL) {
                return NULL;
            }
            array[cnt] = val;
        }
    }

    if (cnt < size) {
        array = realloc(array, (cnt + 1) * sizeof(int));
        if (array == NULL) {
            return NULL;
        }
    }
    array[0] = cnt;
    return array;
}