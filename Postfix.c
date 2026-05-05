#include<stdio.h>
#include<ctype.h>

int stack[100];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void main()
{
    int res;
    int ch;
    char postfix[100];
    int final_result;
    int a, b;

    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);

    for(int i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            a = pop();
            b = pop();

            switch(ch)
            {
                case '+': res = b + a;
                break;
                case '-': res = b - a;
                break;
                case '*': res = b * a;
                break;
                case '/': res = b / a;
                break;
            }
            push(res);
        }
    }

    final_result = pop();
    printf("value of postfix expression is %d", final_result);
}
