#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void demonstrate_strtok_s() {
    printf("=== strtok_s() 기본 사용법 ===\n");
    
    // 예제 1: 기본적인 토큰화
    char str1[] = "Hello,World,C,Programming";
    char *token1;
    char *context1 = NULL;
    
    printf("문자열: %s\n", str1);
    printf("구분자: ','\n");
    printf("토큰들:\n");
    
    token1 = strtok_s(str1, ",", &context1);
    int count = 1;
    while (token1 != NULL) {
        printf("%d번째 토큰: %s\n", count++, token1);
        token1 = strtok_s(NULL, ",", &context1);
    }
    
    printf("\n");
}

void demonstrate_multiple_delimiters() {
    printf("=== 여러 구분자 사용 ===\n");
    
    char str2[] = "apple;banana,cherry:date grape";
    char *token2;
    char *context2 = NULL;
    
    printf("문자열: %s\n", str2);
    printf("구분자: ';,: '\n");
    printf("토큰들:\n");
    
    token2 = strtok_s(str2, ";,: ", &context2);
    int count = 1;
    while (token2 != NULL) {
        printf("%d번째 토큰: %s\n", count++, token2);
        token2 = strtok_s(NULL, ";,: ", &context2);
    }
    
    printf("\n");
}

void demonstrate_thread_safety() {
    printf("=== 스레드 안전성 비교 ===\n");
    
    // 두 개의 독립적인 문자열 토큰화
    char str_a[] = "1-2-3-4-5";
    char str_b[] = "A|B|C|D|E";
    
    char *token_a, *token_b;
    char *context_a = NULL, *context_b = NULL;
    
    printf("문자열 A: %s (구분자: '-')\n", str_a);
    printf("문자열 B: %s (구분자: '|')\n", str_b);
    printf("번갈아가며 토큰 추출:\n");
    
    // 첫 번째 토큰들
    token_a = strtok_s(str_a, "-", &context_a);
    token_b = strtok_s(str_b, "|", &context_b);
    
    int i = 1;
    while (token_a != NULL && token_b != NULL) {
        printf("%d회차 - A: %s, B: %s\n", i++, token_a, token_b);
        token_a = strtok_s(NULL, "-", &context_a);
        token_b = strtok_s(NULL, "|", &context_b);
    }
    
    printf("\n");
}

void demonstrate_edge_cases() {
    printf("=== 특수 상황들 ===\n");
    
    // 빈 토큰들이 있는 경우
    char str3[] = "a,,b,c,";
    char *token3;
    char *context3 = NULL;
    
    printf("연속된 구분자가 있는 문자열: %s\n", str3);
    printf("토큰들 (빈 토큰은 건너뜀):\n");
    
    token3 = strtok_s(str3, ",", &context3);
    int count = 1;
    while (token3 != NULL) {
        printf("%d번째 토큰: '%s'\n", count++, token3);
        token3 = strtok_s(NULL, ",", &context3);
    }
    
    printf("\n");
}

int main() {
    printf("strtok_s() 함수 완전 가이드\n");
    printf("==========================\n\n");
    
    demonstrate_strtok_s();
    demonstrate_multiple_delimiters();
    demonstrate_thread_safety();
    demonstrate_edge_cases();
    
    printf("=== 주요 특징 요약 ===\n");
    printf("1. 스레드 안전 (재진입 가능)\n");
    printf("2. context 매개변수로 상태 관리\n");
    printf("3. 원본 문자열을 수정함 (주의!)\n");
    printf("4. NULL 포인터 반환시 토큰화 완료\n");
    printf("5. 연속된 구분자는 하나로 처리\n");
    
    return 0;
}