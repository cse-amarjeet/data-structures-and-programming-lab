#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
void postfix_ev();
int stackTop(struct stack* sp);
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack* ptr, char val);
char pop(struct stack* ptr);
int precedence(char ch);
int isOperator(char ch);
char* infixToPostfix(char* infix);

int main()
{
	
    char * infix = "a+b/c-d*e";
    
    printf("Infix Expression is: %s \n",infix);
    printf("postfix is:  %s", infixToPostfix(infix));
    postfix_ev();
    return 0;
}
//Main function End And Fuction Initialzation Starts

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
void postfix_ev()
{
	struct stack *s=(struct stack *) malloc(sizeof(struct stack));
	s->size=20;
	s->top=-1;
	s->arr=(char *) malloc(s->size * sizeof(char));
	char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("\nEnter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(s,num);
        }
        else
        {
            n1 = pop(s);
            n2 = pop(s);
            if(*e=='+')
            {
                n3 = n1 + n2;
            }
            if(*e=='-')
            {
                n3 = n2 - n1;
            }
            if(*e=='*')
            {
                n3 = n1 * n2;
            }
            if(*e=='/')
            {
                n3 = n2 / n1;
            }
            push(s,n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop(s));
}


