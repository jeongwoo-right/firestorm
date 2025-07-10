#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/map.h"

int rotated[MAX_N][MAX_N] = {0}; // 회전된 칸 표시


int map[MAX_N][MAX_N];
int N;

// 0 ~ 5 사이의 숫자로 맵 랜덤 생성
void generate_map(int size) {
    N = size;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = rand() % 6;
}

// 좌표로 직접 R 90도 회전
void rotate_subgrid(int sy, int sx, int size) {
    int tmp[MAX_N][MAX_N];
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            tmp[x][size - 1 - y] = map[sy + y][sx + x];
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            map[sy + y][sx + x] = tmp[y][x];
}


void rotate_subgrids(int L) {
    int size = 1 << L; // 비트마스킹으로 2^L 값(회전할 한 변의 길이)
    for (int y = 0; y < N; y += size)
        for (int x = 0; x < N; x += size)
            rotate_subgrid(y, x, size);
}

// 얼음 녹이기 delta 탐색(인접한 곳에 얼음이 2개 이하인 경우)
void melt_ice() {
    int temp[MAX_N][MAX_N];
    memcpy(temp, map, sizeof(map));
    int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1}; // 상 하 좌 우

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 0) continue;
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (map[ny][nx] > 0) cnt++;
            }
            if (cnt < 3) temp[y][x]--;
        }
    }

    // 배열 복사
    memcpy(map, temp, sizeof(map));
}


// 맵의 상태 출력(2x2 기준으로 경계 생성)
void print_map() {
  int block = 2;

  printf("┌");
  for (int j = 0; j < N; j++) {
      printf("──");
      if ((j + 1) % block == 0 && j != N - 1) printf("┬");
      else if (j != N - 1) printf("─");
  }
  printf("┐\n");

  for (int i = 0; i < N; i++) {
      printf("│");
      for (int j = 0; j < N; j++) {
          printf("%2d", map[i][j]);
          if ((j + 1) % block == 0 && j != N - 1) printf("│");
          else printf(" ");
      }
      printf("│\n");

      if ((i + 1) % block == 0 && i != N - 1) {
          printf("├");
          for (int j = 0; j < N; j++) {
              printf("──");
              if ((j + 1) % block == 0 && j != N - 1) printf("┼");
              else if (j != N - 1) printf("─");
          }
          printf("┤\n");
      }
  }

  printf("└");
  for (int j = 0; j < N; j++) {
      printf("──");
      if ((j + 1) % block == 0 && j != N - 1) printf("┴");
      else if (j != N - 1) printf("─");
  }
  printf("┘\n");
}

