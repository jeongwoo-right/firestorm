#ifndef IO_H
#define IO_H

void show_main_menu(); // 메인 메뉴 console
int input_map_size(); // 맵 사이즈 설정
int input_firestorm_level(int N); // 파이어스톰 크기 입력
void print_result(int total, int largest);  // 결과 출력
void save_hall_of_fame(int total, int map_size); // 명예의 전당에 저장
void show_hall_of_fame(); // 명예의 전당 상위 5위까지 출력
void play_game(); // *****게임 진행 함수*****

#endif
