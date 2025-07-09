#include <stdio.h>
#include <stdlib.h>
#include "../include/map.h"
#include "../include/game.h"
#include "../include/io.h"
#include "../include/player.h"


#include <stdio.h>
#include <stdlib.h>
#include "../include/map.h"
#include "../include/game.h"
#include "../include/io.h"
#include "../include/player.h"

int main() {
    show_main_menu();

    int choice;
    printf("선택: ");
    scanf("%d", &choice);

    if (choice == 1) {
        N = input_map_size();
        generate_map(N);
        print_map();

        while (1) {
            int L = input_firestorm_level();
            if (L < 0) break;

            int max_L = 0, tmp = N;
            while (tmp > 1) { tmp /= 2; max_L++; }
            if ((1 << L) > N) {
                printf("⚠️ L이 너무 큽니다! 현재 맵에서는 2^L ≤ %d 이어야 합니다.\n", N);
                continue;
            }

            perform_firestorm(L);
            print_map();
        }

        int total = get_total_ice();
        int largest = get_largest_ice_group();
        print_result(total, largest);
        save_hall_of_fame(total);
    }
    else if (choice == 2) {
        show_hall_of_fame();
        exit(0); // 바로 종료
    }
    else {
        printf("⚠️ 잘못된 입력입니다.\n");
    }

    return 0;
}

