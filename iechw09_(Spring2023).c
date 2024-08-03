#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 1000
#define MAX_HOBBIES 10
#define MAX_SKILLS 10
#define MAX_INTRODUCTION 30
#define MAX_ID_LENGTH 10
#define MAX_NAME_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH]; // �̸�
    char birthdate[9]; // �������
    char school[21]; // �б�
    char student_id[MAX_ID_LENGTH]; // �й�
    char admission_date[9]; // ���г�¥
    char email[51]; // �̸���
    char hobbies[MAX_HOBBIES][MAX_NAME_LENGTH]; // ���
    char skills[MAX_SKILLS][MAX_NAME_LENGTH]; // Ư��
    char introduction[MAX_INTRODUCTION + 1]; // �� �� �ڱ�Ұ�
} Member;

Member members[MAX_MEMBERS]; // ȸ������ �迭
int memberCount = 0; // ���� ȸ�� ��

void registerMember(); // ȸ�� ��� �Լ�
void printMemberInfo(Member member); // ȸ�� ���� ��� �Լ�
void printAllMembers(); // ��� ȸ�� ���� ��� �Լ�
int findMemberIndex(char student_id[]); // ȸ�� �ε��� ã�� �Լ�
void modifyMemberInfo(); // ȸ�� ���� ���� �Լ�
void deleteMember(); // ȸ�� ���� ���� �Լ�

int main() {
    int choice;

    while (1) {
        printf("===== ȸ�� ���� �ý��� =====\n");
        printf("1. ȸ�� ���\n");
        printf("2. ȸ�� ���� ���\n");
        printf("3. ��ü ȸ�� ���� ���\n");
        printf("4. ȸ�� ���� ����\n");
        printf("5. ȸ�� ���� ����\n");
        printf("6. �޴� ����\n");
        printf("===========================\n");
        printf("���ϴ� �۾��� �����ϼ���: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerMember(); // ȸ�� ��� ����
        }
        else if (choice == 2) {
            if (memberCount == 0) {
                printf("��ϵ� ȸ���� �����ϴ�.\n");
            }
            else {
                printf("ȸ�� ������ ����� ȸ���� �й��� �Է��ϼ���: ");
                char studentId[MAX_ID_LENGTH];
                scanf("%s", studentId);
                int index = findMemberIndex(studentId);
                if (index == -1) {
                    printf("�ش� �й��� ȸ���� �����ϴ�.\n");
                }
                else {
                    printMemberInfo(members[index]); // ȸ�� ���� ���
                }
            }
        }
        else if (choice == 3) {
            printAllMembers(); // ��ü ȸ�� ���� ���
        }
        else if (choice == 4) {
            modifyMemberInfo(); // ȸ�� ���� ����
        }
        else if (choice == 5) {
            deleteMember(); // ȸ�� ���� ����
        }
        else if (choice == 6) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }

        printf("\n");
    }

    return 0;
}

void registerMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("�� �̻� ����� ����� �� �����ϴ�.\n");
        return;
    }

    Member newMember;

    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", newMember.name);

    printf("��������� �Է��ϼ��� (yyyymmdd): ");
    scanf("%s", newMember.birthdate);

    printf("�б��� �Է��ϼ���: ");
    scanf("%s", newMember.school);

    printf("�й��� �Է��ϼ���: ");
    scanf("%s", newMember.student_id);

    printf("���г�¥�� �Է��ϼ��� (yyyymmdd): ");
    scanf("%s", newMember.admission_date);

    printf("�̸����� �Է��ϼ���: ");
    scanf("%s", newMember.email);

    printf("��̸� �Է��ϼ��� (10������ ����, �Է��� ��ġ���� 0�� �Է��ϼ���): ");
    int hobbyCount = 0;
    while (1) {
        scanf("%s", newMember.hobbies[hobbyCount]);
        if (strcmp(newMember.hobbies[hobbyCount], "0") == 0 || hobbyCount >= MAX_HOBBIES) {
            break;
        }
        hobbyCount++;
        //���� �Է��� ��̰� "0"�� ���ų�, Ȥ�� hobbyCount�� MAX_HOBBIES���� ũ�ų� ������ �ݺ����� �����ϰ�, �׷��� ������ hobbyCount�� ����
    }

    printf("Ư�⸦ �Է��ϼ��� (10������ ����, �Է��� ��ġ���� 0�� �Է��ϼ���): ");
    int skillCount = 0;
    while (1) {
        scanf("%s", newMember.skills[skillCount]);
        if (strcmp(newMember.skills[skillCount], "0") == 0 || skillCount >= MAX_SKILLS) {
            break;
        }
        skillCount++;
    }

    printf("�� �� �ڱ�Ұ��� �Է��ϼ��� (�ִ� 30��): ");
    scanf(" %[^\n]s", newMember.introduction);

    members[memberCount] = newMember;
    memberCount++;

    printf("ȸ�� ����� �Ϸ�Ǿ����ϴ�.\n");
}

void printMemberInfo(Member member) {
    printf("===== ȸ�� ���� =====\n");
    printf("�̸�: %s\n", member.name);
    printf("�������: %s\n", member.birthdate);
    printf("�б�: %s\n", member.school);
    printf("�й�: %s\n", member.student_id);
    printf("���г�¥: %s\n", member.admission_date);
    printf("�̸���: %s\n", member.email);
    printf("���: ");
    for (int i = 0; i < MAX_HOBBIES; i++) {
        if (strcmp(member.hobbies[i], "") != 0) {
            printf("%s ", member.hobbies[i]);
        }
    }
    printf("\n");
    printf("Ư��: ");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strcmp(member.skills[i], "") != 0) {
            printf("%s ", member.skills[i]);
        }
    }
    printf("\n");
    printf("�� �� �ڱ�Ұ�: %s\n", member.introduction);
    printf("=====================\n");
}

void printAllMembers() {
    if (memberCount == 0) {
        printf("��ϵ� ȸ���� �����ϴ�.\n");
        return;
    }

    printf("===== ��ü ȸ�� ���� =====\n");
    for (int i = 0; i < memberCount; i++) {
        printf("ȸ�� ��ȣ: %d\n", i + 1);
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
        printf("��ϵ� ȸ���� �����ϴ�.\n");
        return;
    }

    printf("������ ȸ���� �й��� �Է��ϼ���: ");
    char studentId[MAX_ID_LENGTH];
    scanf("%s", studentId);

    int index = findMemberIndex(studentId);
    if (index == -1) {
        printf("�ش� �й��� ȸ���� �����ϴ�.\n");
        return;
    }

    Member modifiedMember = members[index];

    printf("�̸��� �Է��ϼ��� (�������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.name);

    printf("��������� �Է��ϼ��� (yyyymmdd, �������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.birthdate);

    printf("�б��� �Է��ϼ��� (�������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.school);

    printf("�й��� �Է��ϼ��� (�������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.student_id);

    printf("���г�¥�� �Է��ϼ��� (yyyymmdd, �������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.admission_date);

    printf("�̸����� �Է��ϼ��� (�������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.email);

    printf("��̸� �Է��ϼ��� (10������ ����, �Է��� ��ġ���� 0�� �Է��ϼ���, �������� �������� �״�� ����): ");
    int hobbyCount = 0;
    while (1) {
        scanf("%s", modifiedMember.hobbies[hobbyCount]);
        if (strcmp(modifiedMember.hobbies[hobbyCount], "0") == 0 || hobbyCount >= MAX_HOBBIES) {
            break;
        }
        hobbyCount++;
    }

    printf("Ư�⸦ �Է��ϼ��� (10������ ����, �Է��� ��ġ���� 0�� �Է��ϼ���, �������� �������� �״�� ����): ");
    int skillCount = 0;
    while (1) {
        scanf("%s", modifiedMember.skills[skillCount]);
        if (strcmp(modifiedMember.skills[skillCount], "0") == 0 || skillCount >= MAX_SKILLS) {
            break;
        }
        skillCount++;
    }

    printf("�� �� �ڱ�Ұ��� �Է��ϼ��� (�ִ� 30��, �������� �������� �״�� ����): ");
    scanf(" %[^\n]s", modifiedMember.introduction);

    members[index] = modifiedMember;

    printf("ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.\n");
}

void deleteMember() {
    if (memberCount == 0) {
        printf("��ϵ� ȸ���� �����ϴ�.\n");
        return;
    }

    printf("������ ȸ���� �й��� �Է��ϼ���: ");
    char studentId[MAX_ID_LENGTH];
    scanf("%s", studentId);

    int index = findMemberIndex(studentId);
    if (index == -1) {
        printf("�ش� �й��� ȸ���� �����ϴ�.\n");
        return;
    }

    for (int i = index; i < memberCount - 1; i++) {
        members[i] = members[i + 1];
    }

    memberCount--;

    printf("ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.\n");
}
