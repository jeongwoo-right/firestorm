# 🧙‍♂️ 파이어스톰 (C 프로젝트)

---

## 📄 프로젝트 개요

> **파이어스톰**은 백준 20058번 **마법사 상어와 파이어스톰** 문제를 기반으로 만든  
> 텍스트 기반 **C 콘솔 게임**입니다.  
> 플레이어는 마법사 상어가 되어 빙판 맵의 일부를 회전시키고 얼음을 녹여가며  
> **남은 얼음의 총합**과 **가장 큰 얼음 덩어리의 크기**를 최대화해야 합니다.  
> 목표는 최고의 점수를 기록해 **명예의 전당**에 이름을 올리는 것입니다!

---

## 📊 상세 기능 소개

✅ **맵 생성**
- 원하는 사이즈(4x4, 8x8, 16x16)로 랜덤 빙판 생성

✅ **파이어스톰 시전**
- 맵의 일부를 시계 방향으로 회전
- 인접 조건에 따라 얼음이 녹아 맵이 변화

✅ **점수 계산**
- 남아있는 얼음 총합 계산
- BFS/DFS로 가장 큰 얼음 덩어리 탐색

✅ **명예의 전당**
- 최고 점수를 기록한 플레이어의 이름, 점수, 날짜를 저장 (`hall_of_fame.txt`)
- 상위 기록 출력

✅ **콘솔 UI**
- 게임 설명, 메뉴 선택, 맵 출력 등 직관적인 사용자 경험 제공

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
│   ├── main.c         # 메인 진입점
│   ├── map.c          # 맵 생성, 출력, 회전, 얼음 녹이기
│   ├── game.c         # 게임 로직 (마법사 상어 이동, 파이어스톰 시전 등)
│   ├── io.c           # 입력/출력 처리 (파일 저장/로드, 명예의 전당 출력 등)
│   ├── player.c       # 플레이어 점수 관리, 기록
│   └── util.c         # 기타 유틸리티 함수들
│
├── data/              # 📂 게임 데이터 (예: 저장 파일, 기록)
│   ├── hall_of_fame.txt   # 명예의 전당 기록
│   └── config.txt         # (옵션) 게임 설정
│
├── build/             # 📂 빌드된 실행 파일 저장 (컴파일 후)
│   └── Firestorm.exe  # (Windows라면) 실행 파일 예시
│
├── Makefile           # ⚙️ 빌드 자동화 파일 (Linux/Unix)
└── README.md          # 📝 게임 설명 & 실행 방법

```

---

## 💡 실행 방법

**프로젝트 클론 / 다운로드**
```
$ git clone https://github.com/jeongwoo-right/firestorm
$ cd firestorm
$ code .
```


---

## 📅 개발 기간

- **2025년 7월**  
- **C/C++ 통합 프로젝트 (2일)**

---

## ✅ 개선 방향

- 다양한 파이어스톰 레벨별 스테이지 추가
- 플레이어 이름 입력/점수 자동 저장 로직 고도화
- BFS/DFS 덩어리 탐색 알고리즘 최적화
- 콘솔 UI에 ASCII 아트 추가
- 코드 리팩토링: 모듈화, 메모리 누수 방지

---

## 🔗 기타

- 원문 문제: [백준 20058 - 마법사 상어와 파이어스톰](https://www.acmicpc.net/problem/20058)  
- 문의 및 피드백: 프로젝트 담당자에게 연락 부탁드립니다! 🚀
