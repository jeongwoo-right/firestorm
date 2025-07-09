#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/map.h"
#include "../include/game.h"
#include "../include/io.h"
#include "../include/player.h"


int main() {
    SetConsoleOutputCP(65001);

    int choice;

    while (1) {
        show_main_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            play_game();
        } else if (choice == 2) {
            show_hall_of_fame();
        }else if (choice == 3) {
            printf("게임을 종료합니다. 감사합니다!\n");
            break;
        } else {
            printf("⚠️ 잘못된 입력입니다! 다시 선택해주세요.\n");
        }
    }

    return 0;
}

