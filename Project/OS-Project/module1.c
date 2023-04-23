#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 256

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    int DR = 0;
    char opcode[5];

    FILE *file = fopen("output.bl", "r");
    if (file == NULL) {
        printf("Error: Failed to open file\n");
        return 1;
    }

    while (fscanf(file, "%4s", opcode) == 1) {
        int num;
        unsigned int address;

        int op = strtol(opcode, NULL, 2);

        switch (op) {
            case 0: // 0000 LOAD Num
                fscanf(file, "%d", &num);
                DR = num;
                break;
            case 1: // 0001 LOAD [A]
                fscanf(file, "%u", &address);
                DR = stack[address];
                break;
            case 2: // 0010 STORE [A]
                fscanf(file, "%u", &address);
                stack[address] = DR;
                break;
            case 3: // 0011 PUSH Num
                fscanf(file, "%d", &num);
                push(num);
                break;
            case 4: // 0100 PUSH
                push(DR);
                break;
            case 5: // 0101 POP
                if (top >= 0) {
                    DR = pop();
                } else {
                    printf("Stack underflow!\n");
                    exit(1);
                }
                break;
            case 6: // 0110 ADD
                if (top >= 1) {
                    int temp = pop();
                    push(temp + DR);
                } else {
                    printf("Stack underflow!\n");
                    exit(1);
                }
                break;
            case 7: // 0111 SUB
                if (top >= 1) {
                    int temp = pop();
                    push(temp - DR);
                } else {
                    printf("Stack underflow!\n");
                    exit(1);
                }
                break;
            case 8: // 1000 WRITE [A]
                fscanf(file, "%u", &address);
                stack[address] = pop();
                break;
            case 9: // 1001 PRINT [A]
                fscanf(file, "%u", &address);
                printf("%04d\n", stack[address]);
                push(stack[address]); // 출력한 값을 다시 스택에 푸시
                break;
            default:
                printf("Error: Invalid opcode\n");
                exit(1);
        }
    }

    fclose(file);
    return 0;
}
