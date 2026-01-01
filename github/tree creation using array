#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


char agac[MAX];


int operator_mu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


int oncelik(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infix_to_postfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1, j = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (operator_mu(c)) {
            while (top != -1 && oncelik(stack[top]) >= oncelik(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}


int postfix_agac_array(char* postfix) {
    int stack[100];
    int top = -1;
    int next_free_index = 1;

    for (int i = 0; i < MAX; i++) agac[i] = 0;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {

            agac[next_free_index] = c;
            stack[++top] = next_free_index;
            next_free_index++;
        } else {

            int new_root_index = next_free_index;
            agac[new_root_index] = c;
            next_free_index++;

            int sag_indis = stack[top--];
            int sol_indis = stack[top--];



            agac[2 * new_root_index] = agac[sol_indis];


            agac[2 * new_root_index + 1] = agac[sag_indis];


            stack[++top] = new_root_index;
        }
    }

    return stack[top];
}

int hesapla_array(int index, int a, int b, int c) {
    if (index >= MAX || agac[index] == 0)
        return 0;

    char v = agac[index];


    if (!operator_mu(v)) {
        if (v == 'a') return a;
        if (v == 'b') return b;
        if (v == 'c') return c;

        return v - '0';
    }


    int sol = hesapla_array(index * 2, a, b, c);
    int sag = hesapla_array(index * 2 + 1, a, b, c);

    switch (v) {
        case '+': return sol + sag;
        case '-': return sol - sag;
        case '*': return sol * sag;
        case '/': return sol / sag;
    }
    return 0;
}


int main() {
    char ifade[] = "a-b+c*2";
    char postfix[100];

    infix_to_postfix(ifade, postfix);


    int kok = postfix_agac_array(postfix);

    int a = 10, b = 3, c = 4;

    int sonuc = hesapla_array(kok, a, b, c);

    printf("Ifade: %s\n", ifade);
    printf("Postfix: %s\n", postfix);
    printf("Hesaplanan Sonuc: %d\n", sonuc);

    printf("\nAgac:\n");

    for (int i = 1; i < 15; i++) {
        if (agac[i] != 0)
            printf("[%d] = %c\n", i, agac[i]);
    }

    return 0;
}
