#include<stdio.h>
void initialize(int[][16]);	//二维数组做函数形参
int tmain(void)
{
	int sbox[16][16] = { 0 };
	initialize(sbox);
	for (size_t i = 0; i != 16; i++)	//数组的下标，vector的下标都是size_t类型的
	{
		for (size_t j = 0; j != 16; j++)
			printf("s[%d][%d]=%d", i, j, sbox[i][j]);
		printf("\n");
	}
	return 0;
}
void initialize(int s[][16])
{
	size_t i, j;
	for ( i = 0; i != 16; i++)
		for (j = 0; j != 16; j++)
			s[i][j] = i + j;

}