#include<stdio.h>
int main()
{
	/*
	以下程序的执行结果为_02_________25_______00 00_____
       #pragma pack(4)
		int main()
	{
		unsigned char puc[4];
		struct tagPIM
		{
			unsigned char ucPim1;//1
			unsigned char ucData0 : 1;//2
			unsigned char ucData1 : 2;//2
			unsigned char ucData2 : 3;//2
		}*pstPimData;

		pstPimData = (struct tagPIM*)puc;

		memset(puc, 0, 4);
		pstPimData->ucPim1 = 2;
		pstPimData->ucData0 = 3;
		pstPimData->ucData1 = 4;
		pstPimData->ucData2 = 5;

		printf(“ % 02x % 02x % 02x % 02x\n”, puc[0], puc[1], puc[2], puc[3]);
		return 0;
	}


	unsigned long FUNC_C(unsigned long ulAction)
	{
		unsigned long ulResult = 0;
		switch (ulAction)
		{
		case ACTION_A:
		{
			ulResult += 1;
			break;
		}
		case ACTION_B:
		{
			ulResult += 1;
		}
		default:
		{
			ulResult += 1;
		}
		}
		printf(“ulResult = % u”, ulResult);
		return ulResult;
	}
	当输入为ACTION_B 时，结果为：ulResult = _____2__________

	
	union tagAAAA
	{
		struct
		{
			char ucFirst;//0-3
			short usSecond;//4-5
			char ucThird;//6-7
		}half;
		short kk;//8-9
   }number;
	struct tagBBBB
	{
		char ucFirst;//0-1
		short usSecond;//2-3
		char ucThird;//4-5
		short usForth;//6-7
	}half;
	struct tagCCCC
	{
		struct
		{
			char ucFirst;//0-1
			short usSecond;//2-3
			char ucThird;//4-7
		}half;
		long kk;//8-11
	};
	在1字节对齐时：sizeof(union tagAAAA) = ____4_____
		sizeof(struct tagBBBB) = ______6____
		sizeof(struct tagCCCC) = ____8______
		在四字节对齐时：sizeof(union tagAAAA) = _12________
		sizeof(struct tagBBBB) = ___8_______
		sizeof(struct tagCCCC) = __12________

	
	double* c, p;
	p = 10.0;
	c = &p;
	printf("%d\n", sizeof(*c));
	
	char buf[] = "hello world";
	printf("%d\n", sizeof(buf));
	
	char c;
	unsigned char uc;
	unsigned short us;
	c = 128;
	uc = 128;
	us = c + uc;
	printf("0x % x", us);

	us = (unsigned char)c + uc;
	printf("0x % x", us);

	us = c + (char)uc;
	printf("0x % x", us);*/
	return 0;
}
