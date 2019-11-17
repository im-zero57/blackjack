#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int calcStepResult(int user,int turn){				//각 단계의 결과값을 알려줌. 
	int i;
	int step_result;
	int plus=0;
	for(i=0;i<=turn;i++)
		plus+=getCardNum(cardhold[0][i]);		
		if(plus>=8000)								//ACE의 경우 1과 11 두가지로 의미할 수 있기 때문에 초기에 ACE 카드의 경우 8000으로 받고 
		{											//먼저 카드에 ACE가 있는 경우르 확인함. 
			if((plus-8000)>10)						//카드의 합에서 8000을 뺐을 때 10 보다 클 경우 ACE는 1을 의미하도록 함.  
			{
				step_result=plus-8000+1;			
			}
			else if((plus-8000)<=10)				//카드의 합에서 8000을 뺐을 때, 10보다 작을 경우 ACE는 11을 의미하도록 함. 
			{
				step_result=plus-8000+11;
			}
		}
		else if(plus<8000)
			step_result = plus;
	
	return step_result;
}

int CheckResult(int player){
	if(cardSum[N_MAX_USER]>21&&cardSum[player]<21)		//딜러의 카드 값을 기준으로 다른 플레이어들의 승리 혹은 패배를 결정하기 위해서 진행하는 함수. 
	{													//딜러의 합이 21을 넘고 플레이어의 합이 21 이하인 경우에만 가능. 21 초과이면 게임에서 패배/21이면 블랙잭이므로 더 더해주거나 빼주는 것이 의미 없음 
		printf("딜러의 카드 합이 21을 초과하므로 플레이어%i에게 배팅금액이 다시 돌아갑니다.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[N_MAX_USER]==21&&cardSum[player]<21)	//앞과 마찬기지로 21이 될 경우 딜러가 승리함. 이 경우에도 플레이어의 값이 
	{														//21인 경우와 21보다 클 경우는 의미가 없음. 
		printf("딜러의 카드 합이 21이므로 플레이어%i는 배팅금액을 잃습니다.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[N_MAX_USER]<21)						//이 경우 딜러와 플레이어 사이의 값 비교가 승리를 결정하는데 요인이 됨. 
	{
		if(cardSum[player]<cardSum[N_MAX_USER])			//딜러의 합보다 플레이어의 합이 작은경우. 
		{												//애초에 딜러의 합보다 작으므로 플레이어가 21이상인 경우는 고려할 필요가 없음. 
			printf("플레이어%i가 가진 카드의 합이 딜러가 가진 카드의 합보다 작으므로 배팅금액을 잃습니다.",player); 
			now_money[player]-=dollar[player];
		}
	}
	else if(cardSum[player]>cardSum[N_MAX_USER]&&cardSum[player]<21)		//딜러의 합보다 플레이어의 합이 큰 경우. 
	{																		//이 경우 플레이어의 값이 21이상일 가능성이 있으므로 이 경우를 제외함. 
		printf("플레이어%i가 가진 카드의 합이 딜러가 가진 카드의 합보다 크으므로 배팅금액을 잃습니다.",player);
		now_money[player]+=dollar[player];
	}
}        


int main(int argc, char *argv[]) {
	return 0;
}
