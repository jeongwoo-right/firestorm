#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/io.h"
#include "../include/player.h"
#include <math.h>  
#include "../include/map.h"
#include "../include/game.h"

// 게임을 처음 시작하면 나오는 화면
void show_main_menu() {
    printf("\n");
    printf("=========================================\n");
    printf("🔥  파이어스톰: 마법사 상어의 얼음 도전  🔥\n");
    printf("=========================================\n");
    printf(" [1] 게임 시작 (파이어스톰 시전)\n");
    printf(" [2] 명예의 전당 보기\n");
    printf(" [3] 게임 종료\n");
    printf("-----------------------------------------\n");
    printf("메뉴를 선택하세요 (1-3): ");
}

int input_map_size() {
    int N;
    while (1) {
        printf("\n가능한 맵 크기: 4, 8, 16\n");
        printf("맵 크기를 선택하세요: ");
        scanf("%d", &N);

        if (N == 4 || N == 8 || N == 16) {
            printf("✅ %dx%d 맵이 선택되었습니다!\n", N, N);
            break;
        } else {
            printf("⚠️ 잘못된 크기입니다! 4, 8, 16 중 하나만 선택하세요.\n");
        }
    }
    return N;
}


int input_firestorm_level(int N) {
    int L, max_L = 0, tmp = N;
    while (tmp > 1) { tmp /= 2; max_L++; }

    printf("시전할 L 입력 (0 ~ %d, 종료:-1): ", max_L);
    scanf("%d", &L);
    return L;
}


void play_game() {
    int N = input_map_size();   // 맵 크기 선택

    generate_map(N);            // 맵 생성
    printf("\n*** 랜덤 빙판 맵 생성 완료! ***\n");
    print_map();                // 초기 맵 출력

    int turn = 1;               // 턴 번호 관리

    while (1) {
        printf("\n-------------------------------\n");
        printf("🌀 [턴 %d] 파이어스톰 시전 단계\n", turn);

        int max_L = 0, tmp = N;
        while (tmp > 1) { tmp /= 2; max_L++; }

        printf("가능한 L: 0 ~ %d (종료하려면 음수 입력)\n", max_L);
        printf("시전할 L을 입력하세요: ");
        int L;
        scanf("%d", &L);

        if (L < 0) {
            printf("\n🛑 파이어스톰 시전을 종료합니다!\n");
            break;
        }

        if ((1 << L) > N) {
            printf("⚠️ L이 너무 큽니다! 2^L ≤ %d 이어야 합니다.\n", N);
            continue;
        }

        printf("\n🌪️ L=%d 파이어스톰을 시전합니다!\n", L);

        perform_firestorm(L);   // 핵심 로직
        printf("\n빙판 상태 업데이트:\n");
        print_map();

        // 중간 피드백
        int total = get_total_ice();
        int largest = get_largest_ice_group();
        printf("현재 총 얼음 양: %d, 가장 큰 덩어리: %d\n", total, largest);

        turn++;
    }

    // 3️⃣ 최종 결과 출력 및 저장
    int total = get_total_ice();
    int largest = get_largest_ice_group();

    printf("\n💯 === 최종 결과 ===\n");
    print_result(total, largest);

    save_hall_of_fame(total, N);
}


void print_result(int total, int largest) {
    printf("🌨️ 총 얼음 양: %d\n", total);
    printf("❄️ 가장 큰 덩어리 크기: %d\n", largest);
}

void save_hall_of_fame(int total, int map_size) {
    char name[50];
    input_player_name(name);
    save_score(name, total, map_size);
}

typedef struct {
    char name[50];
    int score;
    int year, mon, day;
} Record;

int compare(const void* a, const void* b) {
    Record* r1 = (Record*)a;
    Record* r2 = (Record*)b;
    return r2->score - r1->score;  // 내림차순
}

void show_hall_of_fame() {
    int sizes[] = {4, 8, 16};

    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        char filename[64];
        sprintf(filename, "data/hall_of_fame_%d.txt", size);

        printf("\n🏆 %dx%d 명예의 전당 (상위 5명) 🏆\n", size, size);

        FILE* fp = fopen(filename, "r");
        if (!fp) {
            printf("기록 없음\n");
            continue;
        }

        Record records[100];  // 최대 100개 가정
        int count = 0;

        while (fscanf(fp, "%49s %d점 (%4d-%2d-%2d)\n",
                      records[count].name,
                      &records[count].score,
                      &records[count].year,
                      &records[count].mon,
                      &records[count].day) == 5) {
            count++;
        }
        fclose(fp);

        if (count == 0) {
            printf("기록 없음\n");
            continue;
        }

        // 내림차순 정렬
        qsort(records, count, sizeof(Record), compare);

        printf(" Rank | Name                | Score   | Date\n");
        printf("------+---------------------+---------+------------\n");

        int rank = 1;
        for (int j = 0; j < count && j < 5; j++) {
            printf(" %4d | %-20s | %3d점  | %04d-%02d-%02d\n",
                   rank,
                   records[j].name,
                   records[j].score,
                   records[j].year,
                   records[j].mon,
                   records[j].day);
            rank++;
        }
    }

    printf("\n엔터를 누르면 메뉴로 돌아갑니다...");
    getchar(); getchar();
}