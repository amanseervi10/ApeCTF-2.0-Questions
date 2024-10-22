#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void kill_on_timeout(int sig) {
    if (sig == SIGALRM) {
        printf("[!] Anti DoS Signal. Patch me out for testing.\n");
        fflush(stdout); 
        _exit(0);
    }
}

void init_signal() {
    signal(SIGALRM, kill_on_timeout);
    alarm(120);
}

// --------------------------------------------------- The vulnerable function

void guess_the_number() {
    int ans = 79583762;
    int k = 10;

    while (k--) {
        int num;
        printf("Guess the number: ");
        fflush(stdout);
        scanf("%d", &num);

        if (num < ans) {
            printf("Too less\n");
        } else if (num > ans) {
            printf("Too much\n");
        } else {
            printf("CaptureTheHeadsCTF{divid3d_my_h34r7_4nd_c0nqu3r3d_n07hin6}\n");
            fflush(stdout);
            break;
        }
    }

    if (k < 0) {
        printf("You've had enough tries!! Are you sure you weren't guessing the numbers in a bingo game?\n");
    }
     fflush(stdout); 
}

// --------------------------------------------------- MAIN

int main(int argc, char* argv[]) {
    init_signal();
    guess_the_number();
    return 0;
}

