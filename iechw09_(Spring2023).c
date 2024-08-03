#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 1000
#define MAX_HOBBIES 10
#define MAX_SKILLS 10
#define MAX_INTRODUCTION 30
#define MAX_ID_LENGTH 10
#define MAX_NAME_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH]; // 이름
    char birthdate[9]; // 생년월일
    char school[21]; // 학교
    char student_id[MAX_ID_LENGTH]; // 학번
    char admission_date[9]; // 입학날짜
    char email[51]; // 이메일
    char hobbies[MAX_HOBBIES][MAX_NAME_LENGTH]; // 취미
    char skills[MAX_SKILLS][MAX_NAME_LENGTH]; // 특기
    char introduction[MAX_INTRODUCTION + 1]; // 한 줄 자기소개
} Member;

Member members[MAX_MEMBERS]; // 회원들의 배열
int memberCount = 0; // 현재 회원 수

void registerMember(); // 회원 등록 함수
void printMemberInfo(Member member); // 회원 정보 출력 함수
void printAllMembers(); // 모든 회원 정보 출력 함수
int findMemberIndex(char student_id[]); // 회원 인덱스 찾기 함수
void modifyMemberInfo(); // 회원 정보 수정 함수
void deleteMember(); // 회원 정보 삭제 함수

int main() {
    int choice;

    while (1) {
        printf("===== 회원 관리 시스템 =====\n");
        printf("1. 회원 등록\n");
        printf("2. 회원 정보 출력\n");
        printf("3. 전체 회원 정보 출력\n");
        printf("4. 회원 정보 수정\n");
        printf("5. 회원 정보 삭제\n");
        printf("6. 메뉴 종료\n");
        printf("===========================\n");
        printf("원하는 작업을 선택하세요: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerMember(); // 회원 등록 실행
        }
        else if (choice == 2) {
            if (memberCount == 0) {
                printf("등록된 회원이 없습니다.\n");
            }
            else {
                printf("회원 정보를 출력할 회원의 학번을 입력하세요: ");
                char studentId[MAX_ID_LENGTH];
                scanf("%s", studentId);
                int index = findMemberIndex(studentId);
                if (index == -1) {
                    printf("해당 학번의 회원이 없습니다.\n");
                }
                else {
                    printMemberInfo(members[index]); // 회원 정보 출력
                }
            }
        }
        else if (choice == 3) {
            printAllMembers(); // 전체 회원 정보 출력
        }
        else if (choice == 4) {
            modifyMemberInfo(); // 회원 정보 수정
        }
        else if (choice == 5) {
            deleteMember(); // 회원 정보 삭제
        }
        else if (choice == 6) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        printf("\n");
    }

    return 0;
}

void registerMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("더 이상 멤버를 등록할 수 없습니다.\n");
        return;
    }

    Member newMember;

    printf("이름을 입력하세요: ");
    scanf("%s", newMember.name);

    printf("생년월일을 입력하세요 (yyyymmdd): ");
    scanf("%s", newMember.birthdate);

    printf("학교를 입력하세요: ");
    scanf("%s", newMember.school);

    printf("학번을 입력하세요: ");
    scanf("%s", newMember.student_id);

    printf("입학날짜를 입력하세요 (yyyymmdd): ");
    scanf("%s", newMember.admission_date);

    printf("이메일을 입력하세요: ");
    scanf("%s", newMember.email);

    printf("취미를 입력하세요 (10개까지 가능, 입력을 마치려면 0을 입력하세요): ");
    int hobbyCount = 0;
    while (1) {
        scanf("%s", newMember.hobbies[hobbyCount]);
        if (strcmp(newMember.hobbies[hobbyCount], "0") == 0 || hobbyCount >= MAX_HOBBIES) {
            break;
        }
        hobbyCount++;
        //만약 입력한 취미가 "0"과 같거나, 혹은 hobbyCount가 MAX_HOBBIES보다 크거나 같으면 반복문을 종료하고, 그렇지 않으면 hobbyCount를 증가
    }

    printf("특기를 입력하세요 (10개까지 가능, 입력을 마치려면 0을 입력하세요): ");
    int skillCount = 0;
    while (1) {
        scanf("%s", newMember.skills[skillCount]);
        if (strcmp(newMember.skills[skillCount], "0") == 0 || skillCount >= MAX_SKILLS) {
            break;
        }
        skillCount++;
    }

    printf("한 줄 자기소개를 입력하세요 (최대 30자): ");
    scanf(" %[^\n]s", newMember.introduction);

    members[memberCount] = newMember;
    memberCount++;

    printf("회원 등록이 완료되었습니다.\n");
}

void printMemberInfo(Member member) {
    printf("===== 회원 정보 =====\n");
    printf("이름: %s\n", member.name);
    printf("생년월일: %s\n", member.birthdate);
    printf("학교: %s\n", member.school);
    printf("학번: %s\n", member.student_id);
    printf("입학날짜: %s\n", member.admission_date);
    printf("이메일: %s\n", member.email);
    printf("취미: ");
    for (int i = 0; i < MAX_HOBBIES; i++) {
        if (strcmp(member.hobbies[i], "") != 0) {
            printf("%s ", member.hobbies[i]);
        }
    }
    printf("\n");
    printf("특기: ");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strcmp(member.skills[i], "") != 0) {
            printf("%s ", member.skills[i]);
        }
    }
    printf("\n");
    printf("한 줄 자기소개: %s\n", member.introduction);
    printf("=====================\n");
}

void printAllMembers() {
    if (memberCount == 0) {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("===== 전체 회원 정보 =====\n");
    for (int i = 0; i < memberCount; i++) {
        printf("회원 번호: %d\n", i + 1);
        printMemberInfo(members[i]);
    }
    printf("=========================\n");
}

int findMemberIndex(char student_id[]) {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].student_id, student_id) == 0) {
            return i;
        }
    }
    return -1;
}

void modifyMemberInfo() {
    if (memberCount == 0) {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("수정할 회원의 학번을 입력하세요: ");
    char studentId[MAX_ID_LENGTH];
    scanf("%s", studentId);

    int index = findMemberIndex(studentId);
    if (index == -1) {
        printf("해당 학번의 회원이 없습니다.\n");
        return;
    }

    Member modifiedMember = members[index];

    printf("이름을 입력하세요 (수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.name);

    printf("생년월일을 입력하세요 (yyyymmdd, 수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.birthdate);

    printf("학교를 입력하세요 (수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.school);

    printf("학번을 입력하세요 (수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.student_id);

    printf("입학날짜를 입력하세요 (yyyymmdd, 수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.admission_date);

    printf("이메일을 입력하세요 (수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.email);

    printf("취미를 입력하세요 (10개까지 가능, 입력을 마치려면 0을 입력하세요, 수정하지 않으려면 그대로 엔터): ");
    int hobbyCount = 0;
    while (1) {
        scanf("%s", modifiedMember.hobbies[hobbyCount]);
        if (strcmp(modifiedMember.hobbies[hobbyCount], "0") == 0 || hobbyCount >= MAX_HOBBIES) {
            break;
        }
        hobbyCount++;
    }

    printf("특기를 입력하세요 (10개까지 가능, 입력을 마치려면 0을 입력하세요, 수정하지 않으려면 그대로 엔터): ");
    int skillCount = 0;
    while (1) {
        scanf("%s", modifiedMember.skills[skillCount]);
        if (strcmp(modifiedMember.skills[skillCount], "0") == 0 || skillCount >= MAX_SKILLS) {
            break;
        }
        skillCount++;
    }

    printf("한 줄 자기소개를 입력하세요 (최대 30자, 수정하지 않으려면 그대로 엔터): ");
    scanf(" %[^\n]s", modifiedMember.introduction);

    members[index] = modifiedMember;

    printf("회원 정보 수정이 완료되었습니다.\n");
}

void deleteMember() {
    if (memberCount == 0) {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("삭제할 회원의 학번을 입력하세요: ");
    char studentId[MAX_ID_LENGTH];
    scanf("%s", studentId);

    int index = findMemberIndex(studentId);
    if (index == -1) {
        printf("해당 학번의 회원이 없습니다.\n");
        return;
    }

    for (int i = index; i < memberCount - 1; i++) {
        members[i] = members[i + 1];
    }

    memberCount--;

    printf("회원 정보 삭제가 완료되었습니다.\n");
}
