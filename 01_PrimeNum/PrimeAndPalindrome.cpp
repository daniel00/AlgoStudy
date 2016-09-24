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

	//?¼ë‹¨ ëª¨ë“  ?«ìžë¥??Œìˆ˜ë¡?ë§ˆí¬?œë‹¤
	for (int i = 2; i <= nNum; i++) //skip 0,1
	{
		arrChkPrime[i] = 1;	
	}

	//2ë¶€??root(nNum)ê¹Œì????«ìž???€?´ì„œ ê·??˜ì˜ ë°°ìˆ˜?¤ì„ ?Œìˆ˜ê°€ ?„ë‹˜?¼ë¡œ ?œì‹œ?œë‹¤. ?˜ëˆ„???¨ì–´ì§€ë¯€ë¡??Œìˆ˜ê°€ ?„ë‹ˆì§€
	double dblEndRef = sqrt(nNum);
	
	for (int i = 2; i <= dblEndRef; i++)	//ë£¨íŠ¸nNum ê¹Œì?ë§??ê??˜ë©´ ?œë‹¨?? ?˜í•™?ë“¤??ê²€ì¦í–ˆ?¤ê³  ?˜ë„¤.
	{
		for (int j = i*i; j <= nNum; j+=i)	//ië¥??œì™¸??i??ë°°ìˆ˜(2ë°?i+i), 3ë°?i+i+i) ...)?¤ì„ ?ê??œë‹¤
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
