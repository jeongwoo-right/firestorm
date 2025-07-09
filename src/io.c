#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/io.h"
#include "../include/player.h"
#include <math.h>  
#include "../include/map.h"

void show_main_menu() {
    printf("🔥 파이어스톰 게임 🔥\n");
    printf("1. 파이어스톰 시전\n");
    printf("2. 명예의 전당 보기\n");
    printf("레벨 입력시 시전 시작 / 음수 입력시 종료\n");
}

int input_map_size() {
    printf("맵 크기 선택 (4, 8, 16): ");
    int size;
    scanf("%d", &size);
    return size;
}

int input_firestorm_level() {
  int max_L = 0;
  int temp = N;
  while (temp > 1) {
      temp /= 2;
      max_L++;
  }

  printf("시전할 L 입력 (0 ~ %d, 음수 입력시 종료): ", max_L);
  int L;
  scanf("%d", &L);
  return L;
}

void print_result(int total, int largest) {
    printf("🌨️ 총 얼음 양: %d\n", total);
    printf("❄️ 가장 큰 덩어리 크기: %d\n", largest);
}

void save_hall_of_fame(int total) {
    char name[50];
    input_player_name(name);
    save_score(name, total);
}

void show_hall_of_fame() {
    FILE* fp = fopen("data/hall_of_fame.txt", "r");
    if (!fp) {
        printf("기록 없음\n");
        return;
    }
    char line[128];
    printf("🏆 명예의 전당 🏆\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}
