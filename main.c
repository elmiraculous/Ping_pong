#include <stdio.h>

// Функция для отображения игрового поля
void draw_game(int ballX, int ballY, int count1, int count2, int rocket1,
               int rocket2);

int main() {
    int rocket1 = 12;
    int rocket2 = 12;
    int ballX = 40;
    int ballY = 12;
    int count1 = 0;
    int count2 = 0;
    int ballVectorX = 1;
    int ballVectorY = 1;
    char a;
    printf("\e[H\e[2J\e[3J");
    draw_game(ballX, ballY, count1, count2, rocket1, rocket2);

    while (count1 != 21 && count2 != 21) {
        a = getchar();
        if (a == ' ' ||  a == 'A'||  a == 'Z' ||  a == 'K' || a == 'M') {
            if (a != ' ') {
                //движение ракетки
                if (a == 'A' && rocket1 > 2) {
                    rocket1--;
                } else if (a == 'Z' && rocket1 < 21) {
                    rocket1++;
                }
                if (a == 'K' && rocket2 > 2) {
                    rocket2--;
                } else if (a == 'M' && rocket2 < 21) {
                    rocket2++;
                }
            }
            //движение мяча
            if (ballX == 3) {
                if (ballY - 1 <= rocket1 && ballY + 1 >= rocket1) {
                    if (ballVectorY == -1) {
                        ballVectorX = 1;
                        ballVectorY = 1;
                    }
                    if (ballVectorY == 1) {
                        ballVectorX = 1;
                        ballVectorY = -1;
                    }
                } else {
                    ballX = 40;
                    ballY = 12;
                    count2++;
                }
            } else if (ballX == 77) {
                if (ballY - 1 <= rocket2 && ballY + 1 >= rocket2) {
                    if (ballVectorY == -1) {
                        ballVectorX = -1;
                        ballVectorY = -1;
                    }
                    if (ballVectorY == 1) {
                        ballVectorX = -1;
                        ballVectorY = 1;
                    }
                } else {
                    ballX = 40;
                    ballY = 12;
                    count1++;
                }
            } else if (ballY == 1) {
                ballVectorY = 1;

            } else if (ballY == 23) {
                if (ballVectorX == 1 && ballVectorY == 1) {
                    ballVectorY = -1;
                } else if (ballVectorX == -1 && ballVectorY == 1) {
                    ballVectorY = -1;
                }
            }
            ballX = ballX + ballVectorX;
            ballY = ballY + ballVectorY;
            printf("\e[H\e[2J\e[3J");
            draw_game(ballX, ballY, count1, count2, rocket1, rocket2);
        }
    }
    printf("\e[H\e[2J\e[3J");

    if (count1 == 21) {
        printf("Ура! Игрок 2 выиграл!\n");
    } else {
        printf("Ура! Игрок 1 выиграл!\n");
    }
    return 0;
}

void draw_game(int ballX, int ballY, int count1, int count2, int rocket1,
               int rocket2) {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if ((x == 1) && (y - 1 <= rocket1 && y + 1 >= rocket1)) {
                printf("▌");
            } else if (x == 78 && (y - 1 <= rocket2 && y + 1 >= rocket2)) {
                printf("▐");
            } else if (x == ballX && y == ballY) {
                printf("●");
            } else if ((y == 0)) {
                printf("▁");
            }
            else if (y==24) {
                printf("▔");
            }else if (x == 0) {
                printf("▏");
            }
            else if(x==79){
                printf("▕");
            }
            else if ((y != 0 || y != 80) && (x == 40)) {
                printf("╏");
            } else if (y == 2 && (x == 34 || x == 44)) {
                if (x == 34) {
                    if (count1 > 9) {
                        printf("%d", count1);
                        x++;
                    } else {
                        printf(" %d", count1);
                        x++;
                    }
                }
                if (x == 44) {
                    if (count2 > 9) {
                        printf("%d", count2);
                        x++;
                    } else {
                        printf(" %d", count2);
                        x++;
                    }
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
