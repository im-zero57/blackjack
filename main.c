#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int dollar[N_MAX_USER];		//각각의 플레이어가 배팅할 돈을 입력받을 배열 
int now_money[N_MAX_USER];	//당시의 금액을 알려줌 
int bet_money;				//배팅받을 금액을 말함 

//플레이 판 정의 
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//플레이 판 위에 있는 플레이어가 가지는 카드를 배열을 이용하여 정의 
int cardSum[N_MAX_USER+1];							//각 플레이어가 가지는 카드의 합 
int gameend = 0; 									//게임이 끝나는 것을 의미
int cardNumber[N_MAX_USER+1];						//각 플레이어와 딜러가 가지는 카드의 개수 


//받은 숫자가 의미하는 카드의 진짜 숫자를 정의---------
int getCardNum(int card) {
	
	int real_number;
	
	if(card>1&&card<11){
		real_number=card;
	}
	else if(card&&card<14){
		real_number=10;
	} 
	else if(card&&card<24){
		real_number=card-13; 
	}
	else if(card>=24&&card<27)
		real_number=10;
	else if(card>27&&card<37)
		real_number=card-26;
	else if(card>=37&&card<40)
		real_number=10;
	else if(card>40&&card<50)
		real_number=card-39;	
	else if(card==1||card==14||card==27||card==40)
		real_number=8000;
	return real_number;
} 

//할당된 숫자가 의미하는 카드의 모양과 숫자를 알려줌 

void printCard(int card) {
	
	int ch_card;
	if(card==1)
	{
		printf("♠ACE"); 
	}
	else if(card>1&&card<11)
	{
		printf("♠%d",card-1);
	}
	else if(card==11)
	{
		printf("♠king");	
	}
	else if(card==12)
	{
		printf("♠Queen");
	} 
	else if(card==13)
	{
		printf("♠Jack");
	}
	else if(card==14)
	{
		printf("◇ACE");
	}
	else if(card>14&&card<24)
	{
		printf("◇%d",card-13);
	}
	else if(card==24)
	{
		printf("◇King");
	}
	else if(card==25)
	{
		printf("◇Queen");
	}
	else if(card==26)
	{
		printf("◇Jack");
	}
	else if(card==27)
	{
		printf("♡ACE");
	}
	else if(card>27&&card<37)
	{
		printf("♡%d",card-28);
	}
	else if(card==37)
	{
		printf("♡King");
	}
	else if(card==38)
	{
		printf("♡Queen");
	}
	else if(card==39)
	{
		printf("♡Jack");
	}
	else if(card==40)
	{
		printf("♣ACE");
	}
	else if(card>40&&card<50)
	{
		printf("♣%d",card-39);
	}
	else if(card==50)
	{
		printf("♣King");
	}
	else if(card==51)
	{
		printf("♣Queen");
	}
	else if(card==52)
	{
		printf("♣Jack");												 
	} 	
}

//함께 할 플레이어의 수를 입력받는 프로그램 
int configUser(void){
	
	int with_player;
	printf("함께 할 플레이어의 수를 입력해주세요(최대 다섯명까지 할 수 있습니다): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

//카드를 중복 없이 섞는 함수 
int mixCardTray(void){
	
	int i;
	int player_i;
	
	
	for(i=0;i<N_CARD;i++)
	{	
		CARDTRAY[i]=1+rand()%(N_CARD);
		for(player_i=0;player_i<i;player_i++)
		{
			if(CARDTRAY[i]==CARDTRAY[player_i])
			{	
				i--;
				break;
			}	
		}
	}
	return 0;
}

//배팅할 금액을 입력받음 
void betDollar(void){
	
	int bet_money;
	
	printf("얼마를 배팅하시겠습니까? : ");
	scanf("%d",bet_money);
	dollar[0]=bet_money;
	 
	int i;
	for(i=1;i<N_MAX_USER;i++){
		dollar[i] = 1+rand()%(now_money[i]);
		printf("플레이어 i의 배팅 금액은 %d 입니다", i, dollar[i]);
	} 
	
}

//카드를 제공함 
void offerCards(void){
	int i;
	
	for (i=0;i<N_MAX_USER;i++);
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
		
	}
	cardhold[N_MAX_USER][0] = pullCard();
	cardhold[N_MAX_USER][1] = pullCard();
	
	return;
}

//추가로 나눠줄 카드를 알려줌 
void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)
		cardhold[player][i] = pullCard();
}

int pullCard(void){
	int card;
	card = CARDTRAY[rand()%N_CARD];
	return card;
}

void printCardInitialStatus(void){
	int i;
	printf("본인의 카드 : ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("------------------------------------------");
	for (i=1;i<N_MAX_USER;i++)
	{
		printf("i 플레이어의 카드: ");
		printCard(cardhold[i][0]);
		printCard(cardhold[i][1]);
		printf("---------------------------------------");
	}
	printf("딜러의 카드 : ");
	printf("알 수 없음");
	printCard(cardhold[N_MAX_USER][0]);
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
	int i;
	int step_result;
	int plus=0;
	for(i=0;i<=turn;i++)
		plus+=getCardNum(cardhold[0][i]);
		if(plus>=8000)
		{
			if((plus-8000)>10)
			{
				step_result=plus-8000+1;			
			}
			else if((plus-8000)<=10)
			{
				step_result=plus-8000+11;
			}
		}
		else if(plus<8000)
			step_result = plus;
	
	return step_result;
}

int getAction(void){
	
	char input;
	printf("go하시겠습니까? stop 하시겠습니까? (Y / N) :  ");
	scanf("%c",input);
	return input;
}

int CheckResult(int player){
	if(cardSum[N_MAX_USER]>21&&cardSum[player]<21)
	{
		printf("딜러의 카드 합이 21을 초과하므로 플레이어i에게 배팅금액이 다시 돌아갑니다.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[N_MAX_USER]==21&&cardSum[player]<21)
	{
		printf("딜러의 카드 합이 21이므로 플레이어i는 배팅금액을 잃습니다.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[N_MAX_USER]<21)
	{
		if(cardSum[player]<cardSum[N_MAX_USER])
		{
			printf("플레이어i가 가진 카드의 합이 딜러가 가진 카드의 합보다 크므로 배팅금액을 다시 돌려받습니다.",player); 
			now_money[player]+=dollar[player];
		}
	}
	else if(cardSum[player]>cardSum[N_MAX_USER]&&cardSum[player]<21)
	{
		printf("플레이어i가 가진 카드의 합이 딜러가 가진 카드의 합보다 작으므로 배팅금액을 잃습니다.",player);
		now_money[player]-=dollar[player];
	}
}        

int checkWinner(int player)
{
	int large[player];
	int i;
	for(i=0;i<player;i++)
	{
		large[i]=now_money[i];
	}
	int most_large = large[0];
	for(i=0;i<player;i++)
	{
		if(large[i]>most_large)
		{
			most_large=large[i];
		}
	}
	return most_large;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	now_money[0]=50;
	now_money[1]=50;
	now_money[2]=50;
	now_money[3]=50;
	now_money[4]=50;
	
	int roundIndex = 0;
	int n_user;
	int i;

	int answer;
	
	int input=0;
	int until_cardnum=0;
	int round_try_for_me = 0;
	int round_try_for_player = 0;
	int round_try_for_dealer = 0;
	
	srand((unsigned)time(NULL));

	n_user = configUser()+1;
	//돈 
	printf("모든 플레이어의 초기 자본금은 %d 달러 입니다.",N_DOLLAR);
	
	//카드 트레이
	mixCardTray();
	
	do{
		betDollar();
		
		offerCards(); 
		
		printCardInitialStatus();
		
		printf("\n------------------------게임을 시작하겠습니다-------------------------\n");
		roundIndex++;
		
		printf("현재는 %d라운드 입니다.",roundIndex);
		
		printf("현재 자산 결과는 다음과 같습니다.");
		for(i=0;i<n_user;i++)
		{
			printf("플레이어i의 현재 자산은 %d 입니다",i,now_money[i]);
		}
		
		printf("\n---------------------------------------------------------\n");
		 
		printf(">>>나의 순서입니다---------------------------------------------------\n");		
		while(cardSum[0]<21&&input=='Y')
			
			
			round_try_for_me++;
			printUserCardStatus(0,round_try_for_me);
			
			cardSum[0]=calcStepResult(0,round_try_for_me);
			if(cardSum[0]==21)
				{
					printf("축하합니다! 블랙잭이네요:P 당신이 얻는 급액은 %d원 입니다",2*dollar[0]);
					now_money[0]+=2*dollar[0];
				}
			else if(cardSum[0]>21)
				{
					printf("지셨습니다:( 당신의 카드의 합은 %d 입니다. 당신이 잃은 금액은 %d 원입니다",cardSum[0],dollar[0]);
					now_money[0]-=dollar[0];	
				}
			else
				{
					input = getAction();
					if(input=='Y')
					{
						offerCardsplus(0,round_try_for_me);
					}
					cardNumber[0]=round_try_for_me+1;	
				}
		for(i=1;i<n_user;i++)
		{	printf(">>>플레이어i의 순서입니다---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17)){
				
				round_try_for_player++;
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("축하합니다! 블랙잭이네요:P 플레이어 i가 얻는 급액은 %d원 입니다",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("지셨습니다:( 플레이어 i의 카드의  합은 %d 입니다. 플레이어 i가 잃은 금액은 %d 원입니다",i,cardSum[i],i,dollar[i]);
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
				cardNumber[i]=round_try_for_player+1;
			}
		}
		printf("딜러의 순서 입니다!"); 
		while(cardSum[n_user]<17)
		{
			
			round_try_for_dealer++;
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
				printf("딜러가 stop을 선택했습니다.");
			}
			cardNumber[n_user]=round_try_for_dealer+1;
		}
		printf("딜러의 값은 %d 입니다",cardSum[n_user]);
		for (i=0;i<n_user;i++)
		{
			CheckResult(i);
		}
		
		printf("현재까지의 자산 결과는 다음과 같습니다.");
		for(i=0;i<n_user;i++)
		{
			printf("플레이어i의 현재 자산은 %d 입니다",i,now_money[i]);
		}
		
		for(i=0;i<=n_user+1;i++)
		{
			until_cardnum+=cardNumber[i];
		}
		
		if(until_cardnum>=52)
		{
			gameend = 1;
		}
		else if(now_money[i]<=0)
		{
			gameend = 1;
		}
	}while(gameend == 0);
	
	int winner_money;
	winner_money = checkWinner(n_user);
	for(i=0;i<n_user;i++)
	{
		if(winner_money==now_money[i])
		{
			printf("승자는 플레이어i입니다.",i);
			break;
		}
	}	
		
	return 0;
}
