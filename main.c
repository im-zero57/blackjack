#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET		1
#define N_CARD			52
#define N_DOLLAR		50


#define	N_MAX_CARDNUM	13
#define N_MAX_USER		5
#define N_MAX_CARDHOLD	10
#define N_MAX_GO		17
#define N_MAX_BET		5

#define N_MIN_ENDCARD	3O

//카드 트레이를 배영을 이용해서  정의
int CARDTRAY[N_CARDSET*N_CARD];
int cardIndex = 0;

//플레이어와 관련된 사항의 정의 
int dollar[N_MAX_USER];		//각각의 플레이어가 가질 수 있는 돈을 배열을 이용하여 정의 
int n_user; 

//플레이 판 정의
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//플레이 판 위에 있는 플레이어가 가지는 카드의 수를 배열을 이용하여 정의 
int cardSum[N_MAX_USER];							//플레이 판 위에 있는 카드의 총 합  
int bet[N_MAX_USER];								//컴퓨터 플레이어가 배팅할 수 있는 배팅금액  
int gameend = 0; 									//게임이 끝나는 것을 의미


//카드 함수 정의----------
int getCardNum(int cardnum) {
	
	int real_number;
	if(cardnum = 'K'){
		real_number = 10;
	}
	if else(cardnum = 'Q'){
		real_number = 10;
	} 
	if else(cardnum = 'J'){
		real_number = 10; 
	}
	if else(cardnum = 'A'){
		if (cardnum)
	}
	else
		real_number = cardnum;
	
	return real_number;
} 

//할당된 카드를 보여줌
void printCard(int cardnum) {
	
} 
//플레이어의 구성
int configUser(void){
	
	int with_player;
	printf("함께 할 플레이어의 수를 입력해주세요(최대 다섯명까지 할 수 있습니다): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

int mixCardTray(void){
	int i;
	for(i=0;i<N_CARD;i++)
	{
		CardTray[i]=1+rand(%(N_CARD));
	}
	return 0;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	max_user = configUsre();
	//돈
	for(i=0;i<max_user;i++){
		dollar[i] = 1+rand()%(N_DOLLAR);
		printf("플레이어 i의 배팅 금액은 %d 입니다", i+1, d0llar[i]);
	} 
	//카드 트레이
	mixCardTray();
	 
	return 0;
}
