#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/map.h"
#include "../include/util.h"

int rotated[MAX_N][MAX_N] = {0}; // 회전된 칸 표시


int map[MAX_N][MAX_N];
int N;

void generate_map(int size) {
    N = size;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = rand() % 6;
}

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
    int size = 1 << L;
    for (int y = 0; y < N; y += size)
        for (int x = 0; x < N; x += size)
            rotate_subgrid(y, x, size);
}

void melt_ice() {
    int temp[MAX_N][MAX_N];
    memcpy(temp, map, sizeof(map));
    int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};

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
    memcpy(map, temp, sizeof(map));
}

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

