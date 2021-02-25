#include <stdio.h>

void printTriangle(int n, char ch){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i; j++){
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main() {
    int num;
    char ch;

    scanf("%d", &num);
    scanf(" %c", &ch);

    printTriangle(num, ch);
}