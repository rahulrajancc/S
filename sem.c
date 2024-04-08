#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int ch; // Declare ch as integer
    printf("\n1.PRODUCER\n 2.CONSUMER \n3.EXIT\n");
    while (1) {
        printf("\n Enter the choice \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("BUFFER IS FULL");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("BUFFER IS EMPTY");
                break;
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\n Producer produces an item %d", x); // Fixed typo 'p rintf'
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\n Consumer consumes an item %d", x);
    x--;
    mutex = signal(mutex);
}
