#include <stdio.h>
#include <time.h>
#include "../include/player.h"

void input_player_name(char* name) {
    printf("플레이어 이름: ");
    scanf("%s", name);
}

void save_score(const char* name, int score) {
    FILE* fp = fopen("data/hall_of_fame.txt", "a");
    if (!fp) return;

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    fprintf(fp, "%s %d점 (%04d-%02d-%02d)\n", name, score,
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
    fclose(fp);
}
