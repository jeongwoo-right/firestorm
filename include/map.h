#ifndef MAP_H
#define MAP_H

#define MAX_N 64

// 맵과 관련된 로직(맵 생성, 얼음 녹이기, 맵 출력)

extern int map[MAX_N][MAX_N];
extern int N;

void generate_map(int size); // 0 ~ 5 사이의 숫자로 맵 랜덤 생성
void rotate_subgrids(int L); // 좌표로 직접 R 90도 회전
void melt_ice(); // 얼음 녹이기 delta 탐색(인접한 곳에 얼음이 2개 이하인 경우)
void print_map(); // 맵의 상태 출력(2x2 기준으로 경계 생성)

#endif
