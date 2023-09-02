#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;

    for (count = 5; count >= 1; count = count - 1) {
        printf("%d\n", count);
    }
    printf("Blast off to the moon!\n");

    return 0;
}
