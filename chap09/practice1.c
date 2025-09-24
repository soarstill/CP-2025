#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// forward declarations
void printHelloWorld();
int test_student_records();

int main()
{
    printHelloWorld();
    test_student_records();

    return 0;
}

void printHelloWorld()
{
    printf("Hello, World!\n");
}

/*
    문제: 키보드로부터 반복적으로 다음 형식의 레코드를 한 줄 입력받아 필드를 구분하여 구조체 배열에 저장한 후 전체를 출력하는 프로그램을 작성하시오.
    레코드 형식: 이름 | 학번 | 학과 | 학년(정수)
    입력 종료 조건: "exit" 입력


*/
struct Student {
    char name[24];
    char id[16];
    char major[32];
    int year;
};
typedef struct Student Student;

// 함수 원형 선언
void inputStudents(Student* students, int* count);
void printStudents(const Student* students, int count);
Student * parseStudent(const char* buffer, Student* student);
const Student* findStudentByName(const Student* students, int count, const char* name);

int test_student_records()
{
    /*
    Student students[100] = {{"", "", "", 0}};
    int count = 0;

    inputStudents(students, &count);
    printStudents(students, count);
    */

    return 0;
}

// 학생 레코드 입력
// 입력: 학생 레코드 배열, 학생 수 포인터 (추가할   배열의 인덱스)
// 출력: 없음
void inputStudents(Student* students, int* count)
{
    char line[256];
    int i = *count;
    while (1) {
        printf("이름 | 학번 | 학과 | 학년(정수)(끝내려면 '종료' 입력 ): ");
        
        // == gets(line, sizeof(line), stdin);
        gets_s(line, sizeof(line));
        if (strlen(line) == 0) continue;

        // 라인에서 학생 레코드 파싱
        parseStudent(line, &students[i]);

        if (strstr(line, "exit") != NULL) {
            break;
        }
        i++;
    }
    *count = i;
}

 // 입력 버퍼에서 토큰을 추출하는 함수
Student * parseStudent(const char* buffer, Student* student)
{
    if (student == NULL || buffer == NULL) return;

    char* token = NULL;
    char* context = NULL;

    // 이름 | 학번 | 학과 | 학년(정수) -> 이름
    token = strtok_s(buffer, "|", &context);
    if (token != NULL) strncpy(student->name, token, sizeof(student->name) - 1);

    // 학번 | 학과 | 학년(정수) -> 학번
    token = strtok_s(NULL, "|", &context);
    if (token != NULL) strncpy(student->id, token, sizeof(student->id) - 1);

    // 학과 | 학년(정수) -> 학과
    token = strtok_s(NULL, "|", &context);
    if (token != NULL) strncpy(student->major, token, sizeof(student->major) - 1);

    // 학년(정수) -> 학년(정수)
    token = strtok_s(NULL, "|", &context);
    if (token != NULL) student->year -= atoi(token);

    return student;
}

void printStudentTitle();
void printStudent(const Student* student);

// 모든 학생 레코드 출력
// 입력: 학생 레코드 배열(읽기 전용 포인터), 학생 수
// 출력: 없음
void printStudents(const Student* students, int count)
{
    int i = 0;
    if (students == NULL || count <= 0) return;

    printStudentTitle();

    for (i = 0; i < count; i++) {
        printStudent(&students[i]);
    }
}

void printStudentTitle()
{
    printf("\n------- 학생 명단 -------\n");
    printf("| %23s | ", "이름");
    printf("%10s | ", "학번");
    printf("%23s | ", "전공");
    printf("%4s |\n", "학년");
}

void printStudent(const Student* student)
{
    if (student == NULL) return;

    printf("| %23s | ", student->name);
    printf("%10s | ", student->id);
    printf("%23s | ", student->major);
    printf("%4d |\n", student->year);
}

// 학생 이름으로 레코드 검색
// 입력: 학생 레코드 배열(읽기 전용 포인터), 학생 수, 검색할 이름
// 출력: 해당 이름의 학생 레코드 포인터(없으면 NULL)
const Student* findStudentByName(const Student* students, int count, const char* name)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return &students[i];
        }
    }
    return NULL;
}