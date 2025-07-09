#ifndef MAP_H
#define MAP_H

#define MAX_N 64

extern int map[MAX_N][MAX_N];
extern int N;

void generate_map(int size);
void rotate_subgrids(int L);
void melt_ice();
void print_map();

#endif
