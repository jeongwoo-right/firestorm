#include "../include/map.h"
#include "../include/game.h"
#include "../include/util.h"
#include <string.h>

int visited[MAX_N][MAX_N];
int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};

// 회전 + 얼음 녹이기
void perform_firestorm(int L) {
    rotate_subgrids(L);
    melt_ice();
}

// 얼음 총합 구하기
int get_total_ice() {
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += map[i][j];
    return sum;
}

// 인접 얼음 덩어리 크기 구하기
int dfs(int y, int x) {
    if (map[y][x] == 0 || visited[y][x]) return 0;
    visited[y][x] = 1;
    int cnt = 1;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

// 가장 큰 덩어리 구하기
int get_largest_ice_group() {
    int max_group = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] > 0 && !visited[i][j])
                max_group = max(max_group, dfs(i, j));
    return max_group;
}
