#include <stdio.h>
#include <string.h>

typedef struct {
   int n[100];
   int top;
} wakata;

wakata iyabang;

void init() {
    iyabang.top = -1;
}

int isFull() {
    return (iyabang.top == 100 - 1);
}

int isEmpty() {
    return (iyabang.top == -1);
}

void push(int datamasuk) {
    if (isFull()) {
        return;
    }
    iyabang.n[++iyabang.top] = datamasuk;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return iyabang.n[iyabang.top--];
}

int main() {
    init();
    char temp[100];
    int operator1, operator2;

    scanf("%[^\n]%*c", temp);

    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] >= '0' && temp[i] <= '9') {
            push(temp[i] - '0');
        } else if (temp[i] == ' ') {
            continue;
        } else {
            operator2 = pop();
            operator1 = pop();

            switch (temp[i]) {
                case '+':
                    push(operator1 + operator2);
                    break;
                case '-':
                    push(operator1 - operator2);
                    break;
                case '*':
                    push(operator1 * operator2);
                    break;
                default:
                    return 1;
            }
        }
    }

    printf("%d", pop());

    return 0;
}