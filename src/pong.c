#include <stdio.h>

const int field_h = 25;
const int field_w = 80;
const char field_hr = '|';
const char field_gr = '-';
const int racket_first_h = 3;
const int racket_second_h = 3;
const char racket_first = ']';
const char racket_second = '[';
const int ball_h = 1;
const char ball_c = 'o';
const int win_score = 21;

void make_initial_field();
void make_field(int racket_first_y, int racket_second_y, int ball_x, int ball_y,
                int score_first, int score_second);
void make_first_win_field();
void make_second_win_field();
void make_score_field();
void make_game_over_field();

int main() {
    int score_first;
    int score_second;
    char control_char;
    int ball_x;
    int ball_y;
    int racket_first_y;
    int racket_second_y;
    int mode_game;
    int flag_change_score;

    // initial field
    mode_game = 1;
    score_first = 0;
    score_second = 0;
    control_char = ' ';

    racket_first_y = 12;
    racket_second_y = 12;

    ball_x = field_w / 2;
    ball_y = 0;

    int flag = 0;  // flag == 1 - game doesn't begin
    int flag_side;  // flag shows, who starts
    int dir_y = 0;  // flag show the change of direction of fly ball y - direction
    char direct;  // signal for start
    int dir_x = 0;  // flag show the change of direction of fly ball x - direction

    printf("\033[H\033[J");  // устанавливаем курсор в верхний левый угол и стираем все что ниже
    make_initial_field();
    // game
    while (mode_game) {
        if (flag_change_score) {
            if (scanf("%c", &direct) == 1) {
                printf("\033[H\033[J");  // устанавливаем курсор в верхний левый угол и стираем все что ниже
                make_field(racket_first_y, racket_second_y, ball_x, ball_y, score_first, score_second);
                flag_change_score = 0;
                continue;
            }
        }

        scanf("%c", &control_char);

        if (flag == 0) {
                if (flag_side == 0) {
                    dir_y = 1;
                    dir_x = 1;
                    ball_x = field_w / 2;
                    ball_y = 0;
                }
                if (flag_side == 1) {
                    dir_y = 1;
                    dir_x = 0;
                    ball_x = field_w / 2;
                    ball_y = 0;
                }
            flag = 1;
            }

        if (flag) {
        // fly ball move right
            if (dir_x % 2 == 0) {
                // switch control x - direction
                if (ball_x != 77) {
                    ball_x++;
                } else {
                    if (ball_y == racket_second_y
                        || ball_y + 1 == racket_second_y || ball_y - 1 == racket_second_y) {
                        dir_x++;
                        ball_x--;
                    } else {
                        score_first++;
                        flag_side = 1;
                        flag = 0;
                        flag_change_score = 1;
                    }
                }
            } else {  // fly ball move left
                // switch control x - direction
                if (ball_x !=3) {
                    ball_x--;
                } else {
                    if (ball_y == racket_first_y || ball_y + 1 == racket_first_y
                        || ball_y - 1 == racket_first_y) {
                        dir_x++;
                        ball_x++;
                    } else {
                        score_second++;
                        flag_side = 0;
                        flag = 0;
                        flag_change_score = 1;
                    }
                }
            }

            // switch control y - direction
            if (dir_y % 2 == 0) {
                if (ball_y != 1) {
                    ball_y--;
                } else {
                    dir_y++;
                    ball_y++;
                }
            } else {
                if (ball_y != 24) {
                    ball_y++;
                } else {
                    dir_y++;
                    ball_y--;
                }
            }
        }

        if (control_char == 'q' || control_char == 'Q') {
            printf("\033[H\033[J");
            make_game_over_field();
            return 1;
        }

        // move racket first
        if (control_char == 'a' || control_char == 'A') {
            if (racket_first_y > 2) {
                racket_first_y--;
            }
        }
        if (control_char == 'z' || control_char == 'Z') {
            if (racket_first_y < 23) {
                racket_first_y++;
            }
        }

        // move racket second
        if (control_char == 'k' || control_char == 'K') {
            if (racket_second_y > 2) {
                racket_second_y--;
            }
        }
        if (control_char == 'm' || control_char == 'M') {
            if (racket_second_y < 23) {
                racket_second_y++;
            }
        }

        if (flag == 0) {
            if (flag_side == 0) {
                ball_x = field_w / 2;
                ball_y = 0;
            } else {
                ball_x = field_w / 2;
                ball_y = 0;
            }
        }

        if (flag_change_score) {
            make_score_field();
            continue;
        }

        // calc score - if win*/
        printf("\033[H\033[J");  // устанавливаем курсор в верхний левый угол и стираем все что ниже
        make_field(racket_first_y, racket_second_y, ball_x, ball_y, score_first, score_second);

        if (score_first == win_score) {
            printf("\033[H\033[J");
            make_first_win_field();
            mode_game = 0;
        } else if (score_second == win_score) {
            printf("\033[H\033[J");
            make_second_win_field();
            mode_game = 0;
        }
    }


    return 0;
}

void make_initial_field() {
    printf("--------------------------------------------------------------------------------\n");  // 1
    printf("|                                                                              |\n");  // 2
    printf("|                                                                              |\n");  // 3
    printf("|                                                                              |\n");  // 4
    printf("|                                                                              |\n");  // 5
    printf("|                                                                              |\n");  // 6
    printf("|             _____                _       _____  _____  _____  __             |\n");  // 7
    printf("|            |_   _|              (_)     / __  \\|  _  |/ __  \\/  |            |\n");  // 8
    printf("|              | | ___ _ __  _ __  _ ___  `' / /'| |/' |`' / /'`| |            |\n");  // 9
    printf("|              | |/ _ \\ '_ \\| '_ \\| / __|   / /  |  /| |  / /   | |            |\n");  // 10
    printf("|              | |  __/ | | | | | | \\__ \\ ./ /___\\ |_/ /./ /____| |_           |\n");  // 11
    printf("|              \\_/\\___|_| |_|_| |_|_|___/ \\_____/ \\___/ \\_____/\\___/           |\n");  // 12
    printf("|                                                                              |\n");  // 13
    printf("|                                                                              |\n");  // 14
    printf("|                 Firsst player - key A - move UP, key Z - move down           |\n");  // 15
    printf("|                 Second player - key K - move UP, key M - move down           |\n");  // 16
    printf("|                                                                              |\n");  // 17
    printf("|                 Press space to start                                         |\n");  // 18
    printf("|                 Press q to exit                                              |\n");  // 19
    printf("|                                                                              |\n");  // 20
    printf("|                                                                              |\n");  // 21
    printf("|                                                                              |\n");  // 22
    printf("|                                                                              |\n");  // 23
    printf("|                                                                              |\n");  // 24
    printf("--------------------------------------------------------------------------------\n");  // 25
}

void make_field(int racket_first_y, int racket_second_y, int ball_x, int ball_y,
                int score_first, int score_second) {
    for (int h = 0; h <= field_h; h++) {
        for (int w = 0; w <= field_w; w++) {
            if (h == 0 || h == field_h) {
                printf("%c", field_gr);
                continue;
            }

            if (h == 4 && w == field_w / 9 * 4) {
                printf("%d", score_first);
                continue;
            }
            if (h == 4 && w == field_w / 9 * 6) {
                printf("%d", score_second);
                continue;
            }

            if (w == 0) {
                printf("%c", field_hr);
                continue;
            }
            if (w == field_w && h != 4) {
                printf("%c", field_hr);
                continue;
            }
            if ((score_second >= 10 && score_first < 10) && w == field_w - 1 && h == 4) {
                printf("%c", field_hr);
                continue;
            }
            if ((score_second < 10 && score_first >= 10) && w == field_w - 1 && h == 4) {
                printf("%c", field_hr);
                continue;
            }
            if ((score_second >= 10 && score_first >= 10) && w == field_w - 2 && h == 4) {
                printf("%c", field_hr);
                continue;
            }
            if ((score_second >= 10 || score_first >= 10) && w == field_w && h == 4) {
                continue;
            }
            if (score_second < 10 && w == field_w && h == 4) {
                printf("%c", field_hr);
                continue;
            }

            if (w == ball_x && h == ball_y) {
                printf("%c", ball_c);
                continue;
            }

            // print middle line
            if (w == field_w / 2 && h != 4) {
                printf("%c", field_hr);
                continue;
            }
            if (score_first < 10 && w == field_w / 2 && h == 4) {
                printf("%c", field_hr);
                continue;
            }
            if (score_first >= 10 && w == (field_w / 2) - 1 && h == 4) {
                printf("%c", field_hr);
                continue;
            }

            // first racket
            if (w == 2 && (h == racket_first_y - 1 || h == racket_first_y || h == racket_first_y + 1)) {
                printf("%c", racket_first);
            continue;
            }

            // second racket
            if (w == 78 && (h == racket_second_y || h == racket_second_y - 1 || h == racket_second_y + 1)) {
            printf("%c", racket_second);
            continue;
            }
            printf(" ");
        }
        printf("\n");
    }
}



void make_first_win_field() {
    printf("--------------------------------------------------------------------------------\n");  // 1
    printf("|                                                                              |\n");  // 2
    printf("|                                                                              |\n");  // 3
    printf("|                  _____  _                                                    |\n");  // 4
    printf("|                 |  __ \\| |                                                   |\n");  // 5
    printf("|                 | |__) | | __ _ _   _  ___ _ __                              |\n");  // 6
    printf("|                 |  ___/| |/ _` | | | |/ _ \\ '__|                             |\n");  // 7
    printf("|                 | |    | | (_| | |_| |  __/ |                                |\n");  // 8
    printf("|                 |_|    |_|\\__,_|\\__, |\\___|_|                                |\n");  // 9
    printf("|                                  __/ |                                       |\n");  // 10
    printf("|                  ______ _       |___/                                        |\n");  // 11
    printf("|                 |  ____(_)        | |                                        |\n");  // 12
    printf("|                 | |__   _ _ __ ___| |_                                       |\n");  // 13
    printf("|                 |  __| | | '__/ __| __|                                      |\n");  // 14
    printf("|                 | |    | | |  \\__ \\ |_                                       |\n");  // 15
    printf("|                 |_|    |_|_|__|___/\\__|                                      |\n");  // 16
    printf("|                 \\ \\        / (_)                                             |\n");  // 17
    printf("|                  \\ \\  /\\  / / _ _ __                                         |\n");  // 18
    printf("|                   \\ \\/  \\/ / | | '_ \\                                        |\n");  // 19
    printf("|                    \\  /\\  /  | | | | |                                       |\n");  // 20
    printf("|                     \\/  \\/   |_|_| |_|                                       |\n");  // 21
    printf("|                                                                              |\n");  // 22
    printf("|                                                                              |\n");  // 23
    printf("|                                                                              |\n");  // 24
    printf("--------------------------------------------------------------------------------\n");  // 25
}

void make_second_win_field() {
    printf("--------------------------------------------------------------------------------\n");  // 1
    printf("|                                                                              |\n");  // 2
    printf("|                                                                              |\n");  // 3
    printf("|                  _____  _                                                    |\n");  // 4
    printf("|                 |  __ \\| |                                                   |\n");  // 5
    printf("|                 | |__) | | __ _ _   _  ___ _ __                              |\n");  // 6
    printf("|                 |  ___/| |/ _` | | | |/ _ \\ '__|                             |\n");  // 7
    printf("|                 | |    | | (_| | |_| |  __/ |                                |\n");  // 8
    printf("|                 |_|____|_|\\__,_|\\__, |\\___|_|                                |\n");  // 9
    printf("|                   _____          __/ |           _                           |\n");  // 10
    printf("|                  / ____|        |___/           | |                          |\n");  // 11
    printf("|                 | (___   ___  _______  _ __   __| |                          |\n");  // 12
    printf("|                  \\___ \\ / _ \\/ __/ _ \\| '_ \\ / _` |                          |\n");  // 13
    printf("|                  ____) |  __/ (_| (_) | | | | (_| |                          |\n");  // 14
    printf("|                 |_____/ \\___|\\___\\___/|_| |_|\\__,_|                          |\n");  // 15
    printf("|                 \\ \\        / (_)                                             |\n");  // 16
    printf("|                  \\ \\  /\\  / / _ _ __                                         |\n");  // 17
    printf("|                   \\ \\/  \\/ / | | '_ \\                                        |\n");  // 18
    printf("|                    \\  /\\  /  | | | | |                                       |\n");  // 19
    printf("|                     \\/  \\/   |_|_| |_|                                       |\n");  // 20
    printf("|                                                                              |\n");  // 21
    printf("|                                                                              |\n");  // 22
    printf("|                                                                              |\n");  // 23
    printf("|                                                                              |\n");  // 24
    printf("--------------------------------------------------------------------------------\n");  // 25
}

void make_score_field() {
    printf("\033[H\033[J");
    printf("--------------------------------------------------------------------------------\n");  // 1
    printf("|                                                                              |\n");  // 2
    printf("|                                                                              |\n");  // 3
    printf("|                                                                              |\n");  // 4
    printf("|                                                                              |\n");  // 5
    printf("|                                                                              |\n");  // 6
    printf("|                                                                              |\n");  // 7
    printf("|                         _____                                                |\n");  // 8
    printf("|                        / ____|                                               |\n");  // 9
    printf("|                       | (___   ___ ___  _ __ ___                             |\n");  // 10
    printf("|                        \\___ \\ / __/ _ \\| '__/ _ \\                            |\n");  // 11
    printf("|                        ____) | (_| (_) | | |  __/                            |\n");  // 12
    printf("|                       |_____/ \\___\\___/|_|  \\___|                            |\n");  // 13
    printf("|                                                                              |\n");  // 14
    printf("|                                                                              |\n");  // 15
    printf("|                                                                              |\n");  // 16
    printf("|                                                                              |\n");  // 17
    printf("|                                                                              |\n");  // 18
    printf("|                                                                              |\n");  // 19
    printf("|                                                                              |\n");  // 20
    printf("|                                                                              |\n");  // 24
    printf("--------------------------------------------------------------------------------\n");  // 25
}

void make_game_over_field() {
    printf("--------------------------------------------------------------------------------\n");  // 1
    printf("|                                                                              |\n");  // 2
    printf("|                                                                              |\n");  // 3
    printf("|                                                                              |\n");  // 4
    printf("|                                                                              |\n");  // 5
    printf("|                                                                              |\n");  // 6
    printf("|                                                                              |\n");  // 7
    printf("|               ______                       _____                             |\n");  // 8
    printf("|              / _____)                     / ___ \\                            |\n");  // 9
    printf("|             | /  ___  ____ ____   ____   | |   | |_   _ ____  ____           |\n");  // 10
    printf("|             | | (___)/ _  |    \\ / _  )  | |   | | | | / _  )/ ___)          |\n");  // 11
    printf("|             | \\____/( ( | | | | ( (/ /   | |___| |\\ V ( (/ /| |              |\n");  // 12
    printf("|              \\_____/ \\_||_|_|_|_|\\____)   \\_____/  \\_/ \\____)_|              |\n");  // 13
    printf("|                                                                              |\n");  // 14
    printf("|                                                                              |\n");  // 15
    printf("|                                                                              |\n");  // 16
    printf("|                                                                              |\n");  // 17
    printf("|                                                                              |\n");  // 18
    printf("|                                                                              |\n");  // 19
    printf("|                                                                              |\n");  // 20
    printf("|                                                                              |\n");  // 24
    printf("--------------------------------------------------------------------------------\n");  // 25
}
