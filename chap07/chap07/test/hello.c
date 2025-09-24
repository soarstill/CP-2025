#include <stdio.h>

void* swapDouble(double* pa, double* pb); //���漱��
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
		printf("1���� �߸��Ǿ���!!\n");
	}
	else
	{
		printf("a = %f, b = %f\n", a, b);
	}

	presult = (double*)swapDouble((double*)NULL, &b);
	if (presult == NULL)
	{
		printf("2���� �߸��Ǿ���!!\n");
	}
	else
	{
		printf("a = %f, b = %f\n", a, b);
	}
}

void * swapDouble(double* pa, double* pb)
{
	// 1. �Է� �� �������� üũ : NULL�� �ƴϾ�� ��!!
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

// ���: 1���� �Ǽ� �迭�� �Է� �޾� �ֿܼ� ����Ѵ�
// �Լ��� : print_array_double
// �Է�: double Ÿ�� 1���� �迭 �ּ�
// ���: �͹̳ο� �迭�� ������ ���ڰ� ���
// ��ȯ: ����

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



// ���� ���� ��� ��ȯ
// �Է�: �� �Ǽ�
// ���: ���� ��
double add(double a, double b)
{
	return a + b;
}

// ���: ���� ����
//�Է� : �� ����
// ���: �� ��
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