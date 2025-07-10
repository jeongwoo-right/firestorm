
# 🧙‍♂️ 파이어스톰 (C 프로젝트)

---

## 👥 팀원 소개

| <img alt="김예랑 프로필" src="https://github.com/01tilinfinity.png" width="150px"> | <img alt="김정우 프로필" src="https://github.com/jeongwoo-right.png" width="150px"> |
| :----------------------------------------------------------------------------------: | :-------------------------------------------------------------------------: |
| **김예랑**                                                                          | **김정우**                                                                  |
|             [01tilinfinity](https://github.com/01tilinfinity)                   | [jeongwoo-right](https://github.com/jeongwoo-right)                                          |


---

## 📄 프로젝트 개요

> **파이어스톰**은 백준 20058번 **마법사 상어와 파이어스톰** 문제를 기반으로 만든  
> 텍스트 기반 **C 콘솔 게임**입니다.  
> 플레이어는 마법사 상어가 되어 빙판 맵의 일부를 회전시키고 얼음을 녹여가며  
> **남은 얼음의 총합**을 최대화해야 합니다.  
> 목표는 최고의 점수를 기록해 **명예의 전당**에 이름을 올리는 것입니다!

---

## 📊 상세 기능 소개

✅ **맵 생성**  
- 원하는 사이즈(4x4, 8x8, 16x16)로 랜덤 빙판 생성  
- 4, 8, 16 중 선택하지 않으면 랜덤으로 맵 사이즈 선택  
- 매 턴마다 맵이 어떻게 바뀌었는지 실시간 출력

✅ **파이어스톰 시전**  
- 맵의 일부를 시계 방향으로 회전  
- 인접 조건에 따라 얼음이 녹아 맵이 변화

✅ **점수 계산**  
- 남아있는 얼음 총합 계산  
- DFS로 가장 큰 얼음 덩어리 탐색

✅ **명예의 전당 (Hall of Fame)**  
- 최고 점수를 기록한 플레이어의 이름, 점수, 날짜를 저장 (`hall_of_fame_4.txt`, `hall_of_fame_8.txt`, `hall_of_fame_16.txt`)  
- 3개 파일로 나누어 난이도별 관리  
- 순위는 점수 기준 내림차순 정렬(qsort)
- UI 개선: 상위 기록을 표로 출력하고 최신 기록 즉시 반영

✅ **콘솔 UI**    
- 메인 메뉴, 게임 맵, 명예의 전당 UI 제작 
- 게임 설명, 난이도 선택, 잘못된 입력 시 유효성 검사  
- 매 턴 진행 시 맵 상태 출력으로 직관적인 사용자 경험 제공

---

## 🛠️ 기술 스택 (MySkills)

<p align="left">
  <img src="https://img.shields.io/badge/Language-C%20(C99)-blue?style=flat-square"/>
  <img src="https://img.shields.io/badge/Compiler-gcc-informational?style=flat-square"/>
  <img src="https://img.shields.io/badge/Build-Makefile-critical?style=flat-square"/>
  <img src="https://img.shields.io/badge/IO-Console%20%2F%20TXT%20File-success?style=flat-square"/>
  <img src="https://img.shields.io/badge/DataStructure-2D%20Array%2C%20BFS%2FDFS-yellow?style=flat-square"/>
  <img src="https://img.shields.io/badge/Library-time.h-lightgrey?style=flat-square"/>
</p>

---

## 🔧 프로젝트 폴더 구조

```
FirestormGame/         # 최상위 프로젝트 폴더
├── include/           # 📂 헤더 파일 모음
│   ├── map.h
│   ├── game.h
│   ├── io.h
│   ├── player.h
│   └── util.h
│
├── src/               # 📂 C 소스 파일 모음
│   ├── main.c         # 메인
│   ├── map.c          # 맵과 관련된 로직(맵 생성, 얼음 녹이기, 맵 출력)
│   ├── game.c         # 알고리즘과 관련된 로직
│   ├── io.c           # 입출력 처리 (+파일 저장/로드, 명예의 전당)
│   ├── player.c       # 플레이어 기록 저장
│   └── util.c         # 수식 계산에 활용하기 위한 util (max, min)
│
├── data/              # 📂 게임 데이터
│   ├── hall_of_fame_4.txt
│   ├── hall_of_fame_8.txt
│   ├── hall_of_fame_16.txt
│
├── build/             # 📂 빌드된 실행 파일
│   └── Firestorm.exe
│
├── Makefile           # ⚙️ 빌드 자동화(not use)
└── README.md          # 📝 게임 설명 & 실행 방법
```

---

## 💡 실행 방법

### ✅ Git 클론

```bash
git clone https://github.com/jeongwoo-right/firestorm
cd firestorm
code .
```

### ✅ 빌드 & 실행 (Windows 기준)

```bash
gcc -Iinclude -Wall -o build/Firestorm.exe src/main.c src/map.c src/game.c src/io.c src/player.c src/util.c
cd build
Firestorm
```

---

## 📅 개발 기간

- **2025년 7월**
- **SCSA C/C++ 통합 프로젝트 (2일)**

---

## ✅ 개선 방향

- 난이도별 다양한 스테이지 추가
- GUI 기반 게임으로 UI 개선

---

## 🔗 참고

- 원문 문제: [백준 20058 - 마법사 상어와 파이어스톰](https://www.acmicpc.net/problem/20058)
- 프로젝트 저장소: [jeongwoo-right/firestorm](https://github.com/jeongwoo-right/firestorm)

---
<br>

**🔥 최고의 빙판 마법사 상어가 되어 기록을 깨보세요!**
