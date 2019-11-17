#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int calcStepResult(int user,int turn){				//�� �ܰ��� ������� �˷���. 
	int i;
	int step_result;
	int plus=0;
	for(i=0;i<=turn;i++)
		plus+=getCardNum(cardhold[0][i]);		
		if(plus>=8000)								//ACE�� ��� 1�� 11 �ΰ����� �ǹ��� �� �ֱ� ������ �ʱ⿡ ACE ī���� ��� 8000���� �ް� 
		{											//���� ī�忡 ACE�� �ִ� ��츣 Ȯ����. 
			if((plus-8000)>10)						//ī���� �տ��� 8000�� ���� �� 10 ���� Ŭ ��� ACE�� 1�� �ǹ��ϵ��� ��.  
			{
				step_result=plus-8000+1;			
			}
			else if((plus-8000)<=10)				//ī���� �տ��� 8000�� ���� ��, 10���� ���� ��� ACE�� 11�� �ǹ��ϵ��� ��. 
			{
				step_result=plus-8000+11;
			}
		}
		else if(plus<8000)
			step_result = plus;
	
	return step_result;
}

int CheckResult(int player){
	if(cardSum[N_MAX_USER]>21&&cardSum[player]<21)		//������ ī�� ���� �������� �ٸ� �÷��̾���� �¸� Ȥ�� �й踦 �����ϱ� ���ؼ� �����ϴ� �Լ�. 
	{													//������ ���� 21�� �Ѱ� �÷��̾��� ���� 21 ������ ��쿡�� ����. 21 �ʰ��̸� ���ӿ��� �й�/21�̸� �����̹Ƿ� �� �����ְų� ���ִ� ���� �ǹ� ���� 
		printf("������ ī�� ���� 21�� �ʰ��ϹǷ� �÷��̾�%i���� ���ñݾ��� �ٽ� ���ư��ϴ�.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[N_MAX_USER]==21&&cardSum[player]<21)	//�հ� ���������� 21�� �� ��� ������ �¸���. �� ��쿡�� �÷��̾��� ���� 
	{														//21�� ���� 21���� Ŭ ���� �ǹ̰� ����. 
		printf("������ ī�� ���� 21�̹Ƿ� �÷��̾�%i�� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[N_MAX_USER]<21)						//�� ��� ������ �÷��̾� ������ �� �񱳰� �¸��� �����ϴµ� ������ ��. 
	{
		if(cardSum[player]<cardSum[N_MAX_USER])			//������ �պ��� �÷��̾��� ���� �������. 
		{												//���ʿ� ������ �պ��� �����Ƿ� �÷��̾ 21�̻��� ���� ����� �ʿ䰡 ����. 
			printf("�÷��̾�%i�� ���� ī���� ���� ������ ���� ī���� �պ��� �����Ƿ� ���ñݾ��� �ҽ��ϴ�.",player); 
			now_money[player]-=dollar[player];
		}
	}
	else if(cardSum[player]>cardSum[N_MAX_USER]&&cardSum[player]<21)		//������ �պ��� �÷��̾��� ���� ū ���. 
	{																		//�� ��� �÷��̾��� ���� 21�̻��� ���ɼ��� �����Ƿ� �� ��츦 ������. 
		printf("�÷��̾�%i�� ���� ī���� ���� ������ ���� ī���� �պ��� ũ���Ƿ� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]+=dollar[player];
	}
}        


int main(int argc, char *argv[]) {
	return 0;
}
