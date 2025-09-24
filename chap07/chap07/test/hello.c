#include <stdio.h>

void* swapDouble(double* pa, double* pb); //전방선언
int test_print_array();
int test_swapDouble();
int test_function_pointer();

int main()
{

//	test_swapDouble();
	//test_print_array();
	test_function_pointer();

	return 0;
}

int test_swapDouble()
{
	double a = 3.14;
	double b = 5.12;

	double * presult = (double *)swapDouble(&a, &b);
	if (presult == NULL)
	{
		printf("1뭔가 잘못되었어!!\n");
	}
	else
	{
		printf("a = %f, b = %f\n", a, b);
	}

	presult = (double*)swapDouble((double*)NULL, &b);
	if (presult == NULL)
	{
		printf("2뭔가 잘못되었어!!\n");
	}
	else
	{
		printf("a = %f, b = %f\n", a, b);
	}
}

void * swapDouble(double* pa, double* pb)
{
	// 1. 입력 값 정상인지 체크 : NULL이 아니어야 함!!
	if (pa == NULL || pb == NULL)
	{
		return NULL;
	}

	//2.swap two values
	double tmp = *pa;
	*pa = *pb;
	*pb = tmp;

	return pa;

}

void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

int test_print_array()
{
	double da[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

	int size = sizeof(da) / sizeof(da[0]);

	print_array_double(da, size);

	printArrayDouble(&da[0], size);

	return 0;
}

// 기능: 1차원 실수 배열을 입력 받아 콘솔에 출력한다
// 함수명 : print_array_double
// 입력: double 타입 1차원 배열 주소
// 출력: 터미널에 배열의 내용을 예쁘게 출력
// 반환: 없음

void print_array_double(double arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%lf ", arr[i]);
	}
	printf("\n");
}
void printArrayDouble(double* arr, int sz)
{
	for (int i = 0; i < sz; i++, arr++)
	{
		printf("%lf ", *arr);
	}
	printf("\n");
}



// 정수 덧셈 결과 반환
// 입력: 두 실수
// 출력: 더한 값
double add(double a, double b)
{
	return a + b;
}

// 기능: 정수 뺄셈
//입력 : 두 정수
// 출력: 뺀 값
double sub(double a, double b)
{
	return a - b;
}

double mul(double a, double b)
{
	return a * b;
}


int test_function_pointer()
{
	double (*pfunc)(double a, double b) = NULL;
	double result = 0.0;


	pfunc = add;

	printf("add(3,4)= %f\n", add(3.0, 4.0));

	result = (*pfunc) (3.0, 4.0);  // 7.0?
	printf("(*pfunc)(3,4)= %f\n", (*pfunc)(3.0, 4.0));

	pfunc = mul;
	printf("(*pfunc)(3,4)= %f\n", (*pfunc)(3.0, 4.0));



}