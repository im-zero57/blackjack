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
		CardTray[i]=1+rand(%(N_MAX_CARDNUM));
	}
	return 0;
}

int bet Dollar(void){
	
	int i;
	for(i=1;i<max_user;i++){
		dollar[i] = 1+rand()%(now_money);
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
	printf("딜러의 카드 : %d ",cardhold[n_user][0]);
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
	int bet_money;
	int now_money;
	int answer;
	int now_cardsum = 0;
	int round_try = 0;
	int input=0;
	
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
			round_try++
			printUserCardStatus(0,round_try);
			cardSum[0]=calcStepResult(0,round_try);
			if(cardSum[0]==21)
				printf("축하합니다! 블랙잭이네요:P 당신이 얻는 급액은 %d원 입니다",2*bet_money);
				dollar[0]+=2*bet_money;
				break;
			if else(cardSum[0]>21)
				printf("사망하셨습니다:( 당신의 카드의 합은 %d 입니다. 당신이 잃은 금액은 %d 원입니다",cardSum[0],bet_money);
				dollar[0]-=bet_money;	
			else
				input = getAction();
				if(input==0)
				{
					offerCardsplus(0,round_try)
				}
				
		if(cardSum[0]==21)
		{
			dollar[0]+=bet_money;
		} 
		if else(cardSum[0]>21)
			dollar[0]-=bet_money;
		else	
			answer=getAction();
			if(answer=='Y')
				cardSum[0]+=pullCard()
				if(cardSum[0]==21)
				{
					dollar[0]+=bet_money;
				}
				if else(cardSum[0]>21)
				{
					dollar[0]-=bet_money;
				}
				else
					dollar[0]=dollar[0];
					
			if else(answer!='Y')				
				for(i=0;i<n_user;i++)
				{
					while((cardSum[i]<21&&cardSum[i]<17){
						printf("i번째 player 순서 입니다")
						printUserCardStatus(i,roundIndex)
						calStepResult(i,roundIndex)
						
						cardSum[i]=cardhold[i][0]+cardhold[i][1];
						
						
					if (cardSum[i]==21)
						{
						dollar[i]+=bet_money;
						break;
						}
					if else(cardSum[i]>21)
						dollar[i]-=bet_money;
						break;
						
					if else(cardSum[i]<17)
						printf("i번째 플레이어가 go를 하셨습니다.",i );
						cardSum[i]+=pullcard()
						if(cardSum[i]==21)
								dollar[i]+=bet_money;
								break;
						if else(cardSum[i]>21)
								dollar[i]-=bet_money;
								break;
						else
								break;
					if else(cardSum[i]>=17)
						cardSum[i]=cardSum[i];
											
					}
				
				
			
			printUserCardStatus
			
			if((cardhold[i][0]+cardhold[i][1])=21)
				printf("축하합니다! 블랙잭입니다! 당신이 얻는 급액은 %d 달러 입니다",dollar[i]+dollar[i]);
				now_money = 2*dollar[i];
			if else(cardhold[i][0]+cardhold[i][1]<21)
				printf("go or stop? : ");
				scanf("%a",answer);
				{
					if(answer=='go')
						
				}
				 
		}
	}
	return 0;
}
