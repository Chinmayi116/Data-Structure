#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int main() {
    // PUSH operations
    printf("Pushing elements:\n");

    if(top < MAX - 1) stack[++top] = 10;
    if(top < MAX - 1) stack[++top] = 20;
    if(top < MAX - 1) stack[++top] = 30;

    // DISPLAY
    printf("\nStack elements:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    // PEEK
    if(top != -1) {
        printf("\nTop element: %d\n", stack[top]);
    }

    // POP operation
    if(top != -1) {
        printf("\nPopped element: %d\n", stack[top]);
        top--;
    }

    // DISPLAY after POP
    printf("\nStack after pop:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}
