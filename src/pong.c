// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>
#include <stdlib.h>

const int fieldH = 25;
const int fieldW = 80;
const char fieldHr = '|';
const char fieldGr = '-';

const int racketFirstH = 3;
const int racketSecondH = 3;

const int ballH = 1;
const char ballC = 'o';

const int winScore = 21;

void makeField(int racketFirstY, int racketSecondY, int ballX, int ballY, int scoreFirst, int scoreSecond) {
    printf("Field\n");
    printf("%d\n", racketFirstY);
    printf("%d\n", racketSecondY);
    printf("%d\n", ballX);
    printf("%d\n", ballY);
    printf("%d\n", scoreFirst);
    printf("%d\n", scoreSecond);
    for (int h = 0; h <= fieldH; h++) {
        for (int w = 0; w <= fieldW; w++) {
            if (h == 0 || h == fieldH) {
                printf("%c", fieldGr);
                continue;
            }

            if (w == fieldW) {
                printf("%c", fieldHr);
                continue;
            }

            if (w == fieldW / 2) {
                printf("%c", fieldHr);
                continue;
            }

            if (w == ballX && h == ballY) {
                printf("%c", ballC);
            }
        }
        printf("\n");
    }
}

int main() {
    int scoreFirst;
    int scoreSecond;
    char controlChar;

    printf("Start\n");

    // initial field
    scoreFirst = 0;
    scoreSecond = 0;
    controlChar = ' ';

    makeField(12, 12, 3, 12, 0, 0);

    // game
    while (1) {
        scanf("%c\n", &controlChar);

        // break game
        if (controlChar == 'q') {
            printf("Break\n");
            return 1;
        }

         if (controlChar == 'A') {
            printf("A\n");
        }
        if (controlChar == 'Z') {
            printf("Z\n");
        }
        if (controlChar == 'K') {
            printf("K\n");
        }
        if (controlChar == 'M') {
            printf("M\n");
        }

        // next turn
        if (controlChar == ' ') {
            printf("Space\n");
        }

       // move ball
        printf("Ball move\n");

        // move racket
        printf("Racket move\n");

        // calc score - if win
        printf("Score calc\n");

        // print field
        makeField(12, 12, 3, 12, scoreFirst, scoreSecond);
        // clear screen
        printf("\e[1;1H\e[2J");
        //system("clear");
    }

    // win intro
    printf("Win!\n");

    return 0;
}
