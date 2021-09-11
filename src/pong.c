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
const char racketFirst = ']';
const char racketSecond = '[';

const int ballH = 1;
const char ballC = 'O';

const int winScore = 21;

void makeField(int racketFirstY, int racketSecondY, int ballX, int ballY, int scoreFirst, int scoreSecond) {
    printf("Field\n");
    printf("%d\n", scoreFirst);
    printf("%d\n", scoreSecond);
    for (int h = 0; h <= fieldH; h++) {
        for (int w = 0; w <= fieldW; w++) {
            if (h == 0 || h == fieldH) {
                if (h == 0 && w == fieldW / 3) {
					printf("%d", scoreFirst);
					continue;
				}
				if (h == 0 && w == fieldW / 3 * 2) {
					printf("%d", scoreSecond);
					continue;
				}
                printf("%c", fieldGr);
                continue;
            }

            if (w == 0 || w == fieldW) {
				
                printf("%c", fieldHr);
                continue;
            }

            if (w == fieldW / 2) {
                printf("%c", fieldHr);
                continue;
            }

            if (w == ballX && h == ballY) {
                printf("%c", ballC);
				continue;
            }

            if (w == 2 && (h == racketFirstY - 1 || h == racketFirstY || h == racketFirstY + 1)) {
                printf("%c", racketFirst);
				continue;
            }

            if (w == 78 && (h == racketSecondY || h == racketSecondY - 1 || h == racketSecondY + 1)) {
				printf("%c", racketSecond);
				continue;
			}
			printf(" ");

        }
        printf("\n");
    }
}

int main() {
    int scoreFirst;
    int scoreSecond;
    char controlChar;
	int ballX;
	int ballY;
	int racketFirstY;
	int racketSecondY;

    printf("Start\n");

    // initial field
    scoreFirst = 0;
    scoreSecond = 0;
    controlChar = ' ';

	racketFirstY = 12;
	racketSecondY = 12;

	ballX = 3;
	ballY = 12;


    makeField(racketFirstY, racketSecondY, ballX, ballY, 0, 0);
    // game
    while (1) {
        scanf("%c", &controlChar);

        // break game
        if (controlChar == 'q') {
            printf("Break\n");
            return 1;
        }

        if (controlChar == 'a') {
			if (racketFirstY > 2 && racketFirstY < 22) {
			    racketFirstY--;
			}
        }

        if (controlChar == 'z') {
            if (racketFirstY > 2 && racketFirstY < 22) {
			    racketFirstY++;
			}
        }

        if (controlChar == 'k') {
            if (racketSecondY > 2 && racketSecondY < 22) {
				racketSecondY--;
			}
        }
        if (controlChar == 'm') {
            if (racketSecondY > 2 && racketSecondY < 22) {
				racketSecondY++;
			}
        }

        // next turn
        if (controlChar == ' ') {
            // printf("Space\n");
        }

       // move ball

        // move racket

        // calc score - if win

        // print field
        makeField(racketFirstY, racketSecondY, ballX, ballY, 0, 0);
        // clear screen
        //printf("\e[1;1H\e[2J");
        //system("cls");
    }

    // win intro
    printf("Win!\n");

    return 0;
}
