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
int bet_dollar[N_MAX_USER];
int n_user; 
int now_money[N_MAX_USER];
	
now_money[0]=50;
now_money[1]=50;
now_moeny[2]=50;
now_money[3]=50;
now_money[4]=50;

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
		CardTray[i]=1+rand(%(N_MAX_CARDNUM));
	}
	return 0;
}

void bet Dollar(void){
	
	int bet_money
	printf("얼마를 배팅하시겠습니까? : ");
	scnaf("%d",bet_money);
	dollar[0]=bet_money;
	 
	int i;
	for(i=1;i<max_user;i++){
		dollar[i] = 1+rand()%(N_DOLLAR);
		printf("플레이어 i의 배팅 금액은 %d 입니다", i, dollar[i]);
	} 
	
}

void offerCards(void){
	int i;
	for (i=0;i<n_user;i++);
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)
		cardhold[player][i] = pullCard();
}

int pullCard(void){
	int card
	card = cardTray[rand()%(N_CARD)];
	return card;
}

void printCardInitialStatus(void){
	int i;
	printf("본인의 카드 : %d , %d",cardhold[0][0],cardhold[0][1]);
	for (i=1;i<(n_user-1);i++)
	{
		printf("i 플레이어의 카드: %d , %d",i,cardhold[i][0],cardhold[i][0])
	}
	printf("딜러의 카드 : <비밀> , %d ",cardhold[n_user][0]);
}

void printUserCardStatus(int user, int cardcnt){
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
	{
		printCard(cardhold[user][i]);
	}
	printf("\t:::");
}

int calcStepResult(int user,int turn){
	
	int step_result;
	int i;
	for(i=0;i<turn;i++)
		step_result += cardhold[user][i];
	return step_result;
}

int getAction(void){
	
	int input;
	printf("go하시겠습니까? stop 하시겠습니까? (Y-0 / N-others) :  ");
	input=getIntegerInput();
	return input;
}

int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
        

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	int now_money;
	int answer;
	int now_cardsum = 0;
	int round_try_for_me = 0;
	int round_try_for_player = 0;
	int round_try_for_dealer = 0;
	int input=0;
	int bet
	
	srand((unsigned)time(NULL));
	
	max_user = configUser();
	n_user = configUser()+2;
	//돈 
	printf("모든 플레이어의 초기 자본금은 %d 달러 입니다.",N_DOLLAR);
	
	//카드 트레이
	mixCardTray();
	
	do{
		bet dollar();
		printf("얼마를 배팅하시겠습니까? : ");
		scnaf("%d",&bet_money);
		offerCards(); 
		
		printCardInitialStatus();
		printf("\n------------------------게임을 시작하겠습니다-------------------------\n");
		roundIndex++;
		
		printf(">>>나의 순서입니다---------------------------------------------------\n")		
		while(cardSum[0]<21&&input==0)
			round_try_for_me++
			printUserCardStatus(0,round_try_for_me);
			cardSum[0]=calcStepResult(0,round_try_for_me);
			if(cardSum[0]==21)
				printf("축하합니다! 블랙잭이네요:P 당신이 얻는 급액은 %d원 입니다",2*dollar[0]);
				now_money[0]+=2*dollar[0];
			else if(cardSum[0]>21)
				printf("사망하셨습니다:( 당신의 카드의 합은 %d 입니다. 당신이 잃은 금액은 %d 원입니다",cardSum[0],dollar[0]);
				now_money-=dollar[0];	
			else
				input = getAction();
				if(input==0)
				{
					offerCardsplus(0,round_try_for_me)
				}
				
	
		for(i=1;i<n_user;i++)
		{	printf(">>>플레이어i의 순서입니다---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17){
				round_try_for_player++
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("축하합니다! 블랙잭이네요:P 플레이어 i가 얻는 급액은 %d원 입니다",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("사망하셨습니다:( 플레이어 i의 카드의  합은 %d 입니다. 플레이어 i가 잃은 금액은 %d 원입니다",i,i,cardSum[0],);
					now_money[i]-=dollar[i];
				}
				else if(cardSum[i]<17)
				{
					printf("플레이어i가 go를 선택했습니다.");
					offerCardsplus(i,round_try_for_player);
				}
				else if(cardSum[i]>=17)
				{
					printf("플레이어i가 stop을 선택했습니다.");
				}
				
			}
		}
		printf("딜러의 순서 입니다!") 
		while(cardSum[n_user]<17)
		{
			round_try_for_dealer++
			printUserCardStatus(n_user,round_try_for_dealer);
			cardSum[n_user]=calcStepResult(n_user,round_try_for_dealer);
			if(cardSum[n_user]==21)
				break;
			else if(cardSum[n_user]>21)
				break;	
			else if(cardSum[n_user]<17)
			{
				printf("딜러가 go를  선택했습니다.");
				offerCardsplus(n_user,round_try_for_dealer);
			}
			else if(cardSum[n_user]>17&&cardSum[n_user]<21)
			{
				printf("딜러가 stop을 선택했습니다.")
			}
		}
		printf("딜러의 값은 %d 입니다",cardSum[n_user]);
		if(cardSum[n_user]>21)
		{
			printf("딜러의 카드 합이 21을 초과하므로 모든 플레이어들에게 배팅금액이 다시 돌아갑니다(본인 카드의 합이 21을 넘는 플레이어는 배팅금액을 다시 얻을 수 없습니다.)");
			for(i=0;i<n_user;i++)
			{
				if(cardSum[i]<21)
				{
					now_money[i]+=dollar[i];
				}
			 } 
		}
		else if(cardSum[n_user]==21)
		{
			printf("딜러의 카드 합이 21이므로 모든 플레이어들이 배팅금액을 잃습니다.(블랙잭이 된 플레이어는 배팅금액을 잃지 않습니다.)");
			for(i=0;i<n_user;i++)
			{
				if(cardSum[i]<21)
				{
				now_money[i]-=dollar[i];
				}
			}
		}
		else if(cardSum[n_user]<21)
		{
			for(i=0;i<n_user;i++)
			{
				if(cardSum[i]<cardSum[n_user])
				{
					now_money[i]+=dollar[i];
				}
				else if(cardSum[i]>cardSum[n_user]&&cardSum[i<21])
				{
					now_money[i]-=dollar[i];
				}
			}
		}
		printf("결과는 다음과 같습니다.");
		
	}
	return 0;
}
