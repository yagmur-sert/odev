#include <stdio.h>
#include <stdlib.h>

long long int hanoi(int n, char from, char to, char aux, int depth) {



    if(n == 1) {
        for(int i = 0; i < depth + 1; i++) printf("  ");
        printf("Move disk 1 from %c to %c\n", from, to);
        return 1;
    }

    long long int moves1 = hanoi(n-1, from, aux, to, depth+1);

    for(int i = 0; i < depth + 1; i++) printf("  ");
    printf("Move disk %d from %c to %c\n", n, from, to);

    long long int moves2 = hanoi(n-1, aux, to, from, depth+1);

    return moves1 + moves2 + 1;
}

int main() {
    int n;
    long long int toplam;

    printf("3 farkli disk sayisi giriniz:\n");
    for(int i = 1; i <= 3; i++) {
        printf("%d. n = ", i);
        scanf("%d", &n);
        printf("\n=== n = %d icin Call Tree ===\n", n);
        toplam = hanoi(n, 'A', 'C', 'B', 0);
        printf("\nToplam adim sayisi: %lld\n\n", toplam);
    }

    printf("Bu verilere gore Big-O: O(2^n-1)=O(2^n)\n");

    return 0;
}
