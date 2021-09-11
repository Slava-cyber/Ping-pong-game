#include <stdio.h>
const int fieldH = 25;
const int fieldW = 80;
const char fieldHr = '|';
const char fieldGr = '-';
const int racketFirstH = 3;
const int racketSecondH = 3;
const char racketFirst = ']';
const char racketSecond = '[';
const int ballH = 1;
const char ballC = 'o';
const int winScore = 21;
void makeField(int racketFirstY, int racketSecondY, int ballX, int ballY, int scoreFirst, int scoreSecond) {
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

            if (w == ballX && h == ballY) {
                printf("%c", ballC);
                continue;
            }

            if (w == fieldW / 2) {
                printf("%c", fieldHr);
                continue;
            }

            /* if (w == ballX && h == ballY) {
                printf("%c", ballC);
                continue;
            } */

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

    // initial field
scoreFirst = 0;
scoreSecond = 0;
controlChar = ' ';

racketFirstY = 12;
racketSecondY = 12;

ballX = 3;
ballY = 12;

    int flag = 0;  // flag == 1 - game doesn't begin
    int flag_side;  // flag shows, who starts
    char start, direct;  // signal for start
    int dir_y = 0;  // flag show the change of direction of fly ball y - direction
    int dir_x = 0;  // flag show the change of direction of fly ball x - direction

printf("\033[H\033[J");  // устанавливаем курсор в верхний левый угол и стираем все что ниже 1
    makeField(racketFirstY, racketSecondY, ballX, ballY, 0, 0);
    // printf("\033[r");
    // game
    while (1) {
        scanf("%c", &controlChar);

        if (controlChar == 's' && flag == 0) {
            if (scanf("%c", &direct) == 1) {
                // indeficate direction of fly after start down or up
                // up - % == 0
                // down - % == 1ßs
                if (flag_side == 0 && direct == '<') {
                    dir_y = 0;
                    dir_x = 0;
                    ballX = 3;
                    ballY = racketFirstY; }
                if (flag_side == 0 && direct == '>') {
                    dir_y = 1;
                    dir_x = 0;
                    ballX = 3;
                    ballY = racketFirstY; }
                if (flag_side == 1 && direct == '<') {
                    dir_y = 1;
                    dir_x = 1;
                    ballX = 77;
                    ballY = racketSecondY; }
                if (flag_side == 1 && direct == '>') {
                    dir_y = 0;
                    dir_x = 1;
                    ballX = 77;
                    ballY = racketSecondY;  }
                flag = 1;
            }
        }

        if (flag) {
            // fly ball move right
            if (dir_x % 2 == 0) {
                // switch control x - direction
                if (ballX != 77) {
                    ballX++;
                } else {
                    if (ballY == racketSecondY || ballY+ 1 == racketSecondY || ballY - 1 == racketSecondY) {
                    dir_x++;
                    ballX--;
                    } else {
                    scoreFirst++;
                    flag_side = 1;
                    flag = 0;
                    }
                }
            } else {  // fly ball move left
                // switch control x - direction
                if (ballX !=3) {
                    ballX--;
                } else {
                    if (ballY == racketFirstY || ballY + 1 == racketFirstY || ballY - 1 == racketFirstY) {
                        dir_x++;
                        ballX++;
                    } else {
                    scoreSecond++;
                    flag_side = 0;
                    flag = 0;
                    }
                }
            }
            // switch control y - direction
            if (dir_y % 2 == 0) {
                if (ballY != 1) {
                    ballY--;
                } else {
                    dir_y++;
                    ballY++;
                }
            } else {
                if (ballY != 24) {
                    ballY++;
            } else {
                dir_y++;
                ballY--;
            }
        }
    }

        // break game
        if (controlChar == 'q') {
        printf("Break\n");
        return 1;
        }
        if (controlChar == 'a') {
        if (racketFirstY > 2) {
            racketFirstY--;
        }
        }

        if (controlChar == 'z') {
            if (racketFirstY < 23) {
            racketFirstY++;
        }
        }

        if (controlChar == 'k') {
            if (racketSecondY > 2) {
            racketSecondY--;
            }
        }
        if (controlChar == 'm') {
            if (racketSecondY < 23) {
            racketSecondY++;
            }
        }

        if (flag == 0) {
            if (flag_side == 0) {
                ballX = 3;
                ballY = racketFirstY;
            } else {
                ballX = 77;
                ballY = racketSecondY;
            }
        }

        /* next turn
        if (controlChar == ' ') {
        makeField(racketFirstY, racketSecondY, ballX, ballY, 0, 0);
		system("clear");
		continue;
        }

       // move ball

        // calc score - if win*/

        printf("\033[H\033[J");  // устанавливаем курсор в верхний левый угол и стираем все что ниже
        makeField(racketFirstY, racketSecondY, ballX, ballY, scoreFirst, scoreSecond);

        if (scoreFirst == winScore) {
            printf("\033[H\033[JWIN\nP1\n");
            break;
        } else if (scoreSecond == winScore) {
            printf("\033[H\033[JWIN\nP2\n");
            break;
        }
        }
            return 0;}
