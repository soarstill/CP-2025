#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 문자열 앞쪽 공백 제거 (Left Trim)
char* ltrim(char* str) {
    if (str == NULL) return NULL;
    
    // 앞쪽 공백 문자들을 건너뛰기
    while (*str && isspace(*str)) {
        str++;
    }
    return str;
}

// 문자열 뒤쪽 공백 제거 (Right Trim)
char* rtrim(char* str) {
    if (str == NULL) return NULL;
    
    int len = strlen(str);
    if (len == 0) return str;
    
    // 뒤에서부터 공백 문자를 NULL로 변경
    char* end = str + len - 1;
    while (end >= str && isspace(*end)) {
        *end = '\0';
        end--;
    }
    return str;
}

// 문자열 앞뒤 공백 제거 (Trim)
char* trim(char* str) {
    if (str == NULL) return NULL;
    
    // 먼저 오른쪽 trim, 그다음 왼쪽 trim
    rtrim(str);
    return ltrim(str);
}

// trim 함수들의 사용 예제
void demonstrate_trim_functions() {
    printf("=== TRIM 함수 예제 ===\n");
    
    // 테스트 문자열들
    char test1[] = "   hello world   ";
    char test2[] = "\t\n  C Programming  \r\n ";
    char test3[] = "NoSpaces";
    char test4[] = "   ";
    char test5[] = "";
    
    printf("원본 문자열들:\n");
    printf("1: '%s'\n", test1);
    printf("2: '%s'\n", test2);
    printf("3: '%s'\n", test3);
    printf("4: '%s'\n", test4);
    printf("5: '%s'\n", test5);
    printf("\n");
    
    // ltrim 테스트
    printf("ltrim (왼쪽 공백 제거) 결과:\n");
    char temp1[100]; strcpy(temp1, test1);
    char temp2[100]; strcpy(temp2, test2);
    char temp3[100]; strcpy(temp3, test3);
    char temp4[100]; strcpy(temp4, test4);
    char temp5[100]; strcpy(temp5, test5);
    
    printf("1: '%s'\n", ltrim(temp1));
    printf("2: '%s'\n", ltrim(temp2));
    printf("3: '%s'\n", ltrim(temp3));
    printf("4: '%s'\n", ltrim(temp4));
    printf("5: '%s'\n", ltrim(temp5));
    printf("\n");
    
    // rtrim 테스트
    printf("rtrim (오른쪽 공백 제거) 결과:\n");
    strcpy(temp1, test1); strcpy(temp2, test2); strcpy(temp3, test3);
    strcpy(temp4, test4); strcpy(temp5, test5);
    
    printf("1: '%s'\n", rtrim(temp1));
    printf("2: '%s'\n", rtrim(temp2));
    printf("3: '%s'\n", rtrim(temp3));
    printf("4: '%s'\n", rtrim(temp4));
    printf("5: '%s'\n", rtrim(temp5));
    printf("\n");
    
    // trim 테스트
    printf("trim (양쪽 공백 제거) 결과:\n");
    strcpy(temp1, test1); strcpy(temp2, test2); strcpy(temp3, test3);
    strcpy(temp4, test4); strcpy(temp5, test5);
    
    printf("1: '%s'\n", trim(temp1));
    printf("2: '%s'\n", trim(temp2));
    printf("3: '%s'\n", trim(temp3));
    printf("4: '%s'\n", trim(temp4));
    printf("5: '%s'\n", trim(temp5));
    printf("\n");
}

// strtok_s와 trim을 함께 사용하는 예제
void strtok_with_trim_example() {
    printf("=== strtok_s + trim 조합 예제 ===\n");
    
    char data[] = " apple , banana , cherry , date ";
    char *token;
    char *context = NULL;
    
    printf("원본 문자열: '%s'\n", data);
    printf("구분자: ','\n\n");
    
    token = strtok_s(data, ",", &context);
    int count = 1;
    
    while (token != NULL) {
        printf("토큰 %d (trim 전): '%s'\n", count, token);
        printf("토큰 %d (trim 후): '%s'\n", count, trim(token));
        printf("\n");
        
        token = strtok_s(NULL, ",", &context);
        count++;
    }
}

int main() {
    printf("문자열 처리 함수 예제\n");
    printf("===================\n\n");
    
    // trim 함수 시연
    demonstrate_trim_functions();
    
    // strtok_s와 trim 조합 사용
    strtok_with_trim_example();
    
    printf("=== 기본 strtok_s 예제 ===\n");
    char str[] = "apple,banana,cherry,date";
    char *token;
    char *context = NULL;  // 컨텍스트 포인터
    
    printf("원본 문자열: %s\n", str);
    printf("토큰들:\n");
    
    // 첫 번째 토큰
    token = strtok_s(str, ",", &context);
    
    // 모든 토큰 출력
    while (token != NULL) {
        printf("토큰: %s\n", token);
        token = strtok_s(NULL, ",", &context);  // 다음 토큰
    }
    
    printf("\n=== trim 함수 특징 ===\n");
    printf("• ltrim(): 문자열 왼쪽(앞쪽) 공백 제거\n");
    printf("• rtrim(): 문자열 오른쪽(뒤쪽) 공백 제거\n");
    printf("• trim():  문자열 양쪽 공백 제거\n");
    printf("• isspace() 함수로 모든 종류의 공백 문자 처리\n");
    printf("  (스페이스, 탭, 줄바꿈, 캐리지 리턴 등)\n");
    
    return 0;
}