#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int Compare(const void* v1, const void* v2) {
    char m1m2[5], m2m1[5];
    sprintf(m1m2, "%d%d", *(int*)v1, *(int*)v2);
    sprintf(m2m1, "%d%d", *(int*)v2, *(int*)v1);
    return strcmp(m2m1, m1m2);
}

char* func_01(int numbers[], size_t numbers_len) {
    char* answer = (char*)malloc(numbers_len + 1);
    char num[3];
    strcpy(answer, "");

    qsort(numbers, numbers_len, sizeof(int), Compare); // 퀵정렬
    
    for (int i=0; i < (int) numbers_len; i++) {
        sprintf(num, "%d", numbers[i]);
        strcat(answer, num);
    }
    
    return answer;
}
    
int main(void) {
    int Numbers[] = { 4, 40, 49, 7, 8 };

    printf("입력: "); 
    for (int i = 0; i < sizeof(Numbers) / sizeof(Numbers[0]); i++) printf("%2d", Numbers[i]);
    
    printf("%s\n", func_01(Numbers, sizeof(Numbers) / sizeof(Numbers[0])));
 
    return 0;
}