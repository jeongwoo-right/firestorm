#include <stdio.h>
#include <time.h>
#include "../include/player.h"


// 플레이어명 입력
void input_player_name(char* name) {
    printf("플레이어 이름: ");
    scanf("%s", name);
}

// 게임 종료 후 점수 저장
void save_score(const char* name, int score, int map_size) {
    char filename[64];
    sprintf(filename, "../data/hall_of_fame_%d.txt", map_size);


    FILE* fp = fopen(filename, "a");
    if (!fp) {
        printf("❌ 기록 파일을 열 수 없습니다!\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    fprintf(fp, "%s %d점 (%04d-%02d-%02d)\n",
            name, score,
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);

    fclose(fp);
}
