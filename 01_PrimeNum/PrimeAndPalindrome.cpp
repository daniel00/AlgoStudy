//Git
//Git test 2
//Git test 3
//Git test 4

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

	return 0;
}



void GetPrimeNums(int nNum)
{
	
	arrChkPrime[0] = 0;	//mark to not prime
	arrChkPrime[1] = 0;	//mark to not prime

	//일단 모든 숫자를 소수로 마크한다
	for (int i = 2; i <= nNum; i++) //skip 0,1
	{
		arrChkPrime[i] = 1;	
	}

	//2부터 root(nNum)까지의 숫자에 대해서 그 수의 배수들을 소수가 아님으로 표시한다. 나누어 떨어지므로 소수가 아니지
	double dblEndRef = sqrt(nNum);
	
	for (int i = 2; i <= dblEndRef; i++)	//루트nNum 까지만 점검하면 된단다. 수학자들이 검증했다고 하네.
	{
		for (int j = i*i; j <= nNum; j+=i)	//i를 제외한 i의 배수(2배(i+i), 3배(i+i+i) ...)들을 점검한다
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