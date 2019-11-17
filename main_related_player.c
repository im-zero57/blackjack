#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int configUser(void){
	
	printf("함께 할 플레이어의 수를 입력해주세요(최대 다섯명까지 할 수 있습니다): ");
	scanf("%d",&with_player);
	return with_player;
	
void betDollar(void){
	
	int bet_money;									//배팅값을 입력 받을 변수 
	
	printf("얼마를 배팅하시겠습니까? : ");			//'나'에게 배팅할 값을 물어봄 
	scanf("%d",bet_money);							//물어본 배팅값을 저장할 변수 
	dollar[0]=bet_money;							//'나'의 배팅값을 저장한 배열값 
	
	srand((unsigned)time(NULL));
	 
	int i;
	for(i=1;i<=with_player;i++){					//나와 딜러를 제외한 플레이어 모두의 값을 임의로 입력받음, rand함수로 진행하며	
		dollar[i] = 1+rand()%now_money[i];		//이 받은 값을 각각의 플레이어의 배팅값을 저장할 배열에 저장함. 
		printf("플레이어 %d의 배팅 금액은 %d 입니다", i, dollar[i]);
	} 
	
int getAction(void){							//'GO'할지 'STOP'할 지 결정해야함. 
	
	char input;
	printf("go하시겠습니까? stop 하시겠습니까? (Y / N) :  ");
	scanf("%c",input);							//교수님이 주신 함수가 자꾸 오류가 나서... 그냥 scanf로 받아서 했습니다. 
	return input;
}	

int checkWinner(int player)			//최대값을 비교하는 경우. 
{
	int large[player];				//값을 임시로 저장하는 배열. 최대값을 찾아내는데 이용함, 
	int i;
	for(i=0;i<player;i++)
	{
		large[i]=now_money[i];		//각 배열값에 플레이어가 가진 돈의 값을 저장함. 
	}
	int most_large = large[0];		//기본적으로 첫째 플레이어의 값을 임시로 가장 큰 값으로 잡음. 
	for(i=0;i<player;i++)
	{
		if(large[i]>most_large)		//그 이후에 각 배열값을 비교하면서 가장 큰 값을 찾아감. 
		{
			most_large=large[i];
		}
	}
	return most_large;
}

int main(int argc, char *argv[]) {
	return 0;
}
