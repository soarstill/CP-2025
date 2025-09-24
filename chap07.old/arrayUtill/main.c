#include <stdio.h>
#include <stdlib.h>

void test_pointers();

int main()
{
	printf("Hello, Array! I love you!!\n");

	test_pointers();

	return 0;
}
int getInt(int* pa);

void test_pointers()
{
	int x = 0;

	getInt(&x);
	
	printf("random number = %d\n", x);

}

int getInt(int* pa)
{
	*pa = rand() % 100 + 1;
}