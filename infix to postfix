#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct Stack{

char data[MAX];
int top;

};

void baslat(struct Stack *s)
{
    s->top=-1;
}

int isempty(struct Stack *s)
{

    return s->top==-1;
}

int isfull(struct Stack *s)
{

    return s->top==MAX-1;
}


void push(struct Stack *s,char ch)
{
    if(isfull(s))
    {
        printf("liste dolu!");
        return;
    }
    s->data[++(s->top)]=ch;
}

char pop(struct Stack *s)
{
    if(isempty(s))
    {
        printf("liste bos!");
        return '\0';
    }
    return s->data[(s->top)--];
}

char peek(struct Stack *s){

    if(isempty(s))
    {
        return '\0';
    }
    return s->data[s->top];


}

int oncelik(char op){

if(op=='^') return 3;
else if(op=='*'||op=='/') return 2;
else if(op=='+'||op=='-') return 1;
else return 0;


}


void infixtopostfix(char *infix,char *postfix){

    struct Stack s;
    baslat(&s);
    int j=0;

    for(int i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];

        if(ch==' ')
        {
            continue;
        }

        if(isalpha(ch)||isdigit(ch))
        {
            postfix[j++]=ch;
        }

        else if(ch=='('){

            push(&s,ch);

        }
        else if(ch==')')
        {
            while(!isempty(&s)&&peek(&s)!='(')
            {
                postfix[j++]=pop(&s);

            }

            pop(&s);
        }
        else
        {
            while(!isempty(&s)&&oncelik(peek(&s))>=oncelik(ch))
            {
                postfix[j++]=pop(&s);
            }
            push(&s,ch);
        }



    }
     while (!isempty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';


}


int main()
{
    char infix[MAX],postfix[MAX];

    printf("infix ifadeyi giriniz:\n");

    fgets(infix,sizeof(infix),stdin);
    infix[strcspn(infix,"\n")]='\0';
    infixtopostfix(infix,postfix);

    printf("\n postfix ifade: %s\n",postfix);

    return 0;
}
