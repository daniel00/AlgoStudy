//Git
//Git test 2
//Git test 3
//Git test 4
//Git test 5 from GitHub

#include <iostream>
#include <string>
#include "time.h"

using namespace std;

int* arrChkPrime;
void GetPrimeNums(int nNum);
bool IsPrimeNum(int nNum);
bool IsFlipNum(int nNum);

int main()
{

	int nNum;
	int nResultCnt = 0;

	cout << "type number : ";
	cin >> nNum;
	cout << "\n";

	clock_t StartTime = clock();

	arrChkPrime = new int[nNum + 1];	//"0" + 1~nNum
	GetPrimeNums(nNum);

	for (int i = 2; i <= nNum; i++)
	{
		if (IsPrimeNum(i))
		{
			if (IsFlipNum(i))
			{
				//printf("%d ", i);
				nResultCnt++;
			}
		}
		
	}

	printf("Result count : %d\n", nResultCnt);
	printf("\nElapsed time : %.3f sec\n\n", (float)(clock()-StartTime)/1000);

	system("pause");
	return 0;
}



void GetPrimeNums(int nNum)
{
	
	arrChkPrime[0] = 0;	//mark to not prime
	arrChkPrime[1] = 0;	//mark to not prime

	//?Όλ¨ λͺ¨λ  ?«μλ₯??μλ‘?λ§ν¬?λ€
	for (int i = 2; i <= nNum; i++) //skip 0,1
	{
		arrChkPrime[i] = 1;	
	}

	//2λΆ??root(nNum)κΉμ????«μ????΄μ κ·??μ λ°°μ?€μ ?μκ° ?λ?Όλ‘ ?μ?λ€. ?λ???¨μ΄μ§λ―λ‘??μκ° ?λμ§
	double dblEndRef = sqrt(nNum);
	
	for (int i = 2; i <= dblEndRef; i++)	//λ£¨νΈnNum κΉμ?λ§??κ??λ©΄ ?λ¨?? ?ν?λ€??κ²μ¦ν?€κ³  ?λ€.
	{
		for (int j = i*i; j <= nNum; j+=i)	//iλ₯??μΈ??i??λ°°μ(2λ°?i+i), 3λ°?i+i+i) ...)?€μ ?κ??λ€
		{
			if (arrChkPrime[i] == 0)
				continue;
			else
				arrChkPrime[j] = 0;
		}
	}

	/*for (int i = 0; i <= nNum; i++)
	{
		if (arrChkPrime[i] == 1)
			printf("%d ", i);
	}*/

	//printf("finish\n");
}


bool IsPrimeNum(int nNum)
{
	return arrChkPrime[nNum];
}

bool IsFlipNum(int nNum)
{
	bool bIsFiipNum = true;
	
	string str = to_string(nNum);
	int nlen = str.length();

	for (int i = 0; i < nlen/2; i++)
	{
		if (str.at(i) != str.at(nlen - 1 - i))
		{
			bIsFiipNum = false;
			break;
		}
	}

	return bIsFiipNum;
}
