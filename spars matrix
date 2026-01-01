#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

int main() {
    int rows, cols, nonZero;
    Element elements[MAX];

    printf("Matris boyutunu giriniz (satir sutun): ");
    scanf("%d %d", &rows, &cols);

    printf("Sifir olmayan eleman sayisi: ");
    scanf("%d", &nonZero);

    for(int i = 0; i < nonZero; i++) {
        printf("Eleman %d - satir, sutun, deger: ", i+1);
        scanf("%d %d %d", &elements[i].row, &elements[i].col, &elements[i].value);
    }

    printf("\nSimple Matrix:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int found = 0;
            for(int k = 0; k < nonZero; k++) {
                if(elements[k].row == i && elements[k].col == j) {
                    printf("%d ", elements[k].value);
                    found = 1;
                    break;
                }
            }
            if(!found)
                printf("0 ");
        }
        printf("\n");
    }

    printf("\n Sparse Matrix:(0lar olmayan form)\n");

     for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int found = 0;
            for(int k = 0; k < nonZero; k++) {
                if(elements[k].row == i && elements[k].col == j) {
                    printf("%d ", elements[k].value);
                    found = 1;
                    break;
                }
            }
            if(!found)
                printf(" - ");
        }
        printf("\n");
    }


    return 0;
}
