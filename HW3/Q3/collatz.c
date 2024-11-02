#include <stdio.h>
#include <stdlib.h>

void print_collatz_sequence(int num) {
    while (num != 1) {
        printf("%d, ", num);
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
    }
    printf("1\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./collatz <positive integer>\n");
        return 1;
    }
    
    int num = atoi(argv[1]);
    if (num <= 0) {
        printf("Please provide a positive integer.\n");
        return 1;
    }

    print_collatz_sequence(num);
    return 0;
}
