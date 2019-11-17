#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDSET		1
#define N_CARD			52
#define N_DOLLAR		50


#define	N_MAX_CARDNUM	13
#define N_MAX_USER		6
#define N_MAX_CARDHOLD	10
#define N_MAX_GO		17
#define N_MAX_BET		6

#define N_MIN_ENDCARD	3O

//카드 트레이를 배영을 이용해서  정의
int CARDTRAY[N_CARDSET*N_CARD];
int cardIndex = 0;

//플레이어와 관련된 사항의 정의 
int dollar[N_MAX_USER];		//각각의 플레이어가 배팅할 돈을 입력받을 배열 
int now_money[N_MAX_USER];	//당시의 금액을 알려줌 
int bet_money;				//배팅받을 금액을 말함 
int with_player; 			//함께 플레이할 플레이어를 입력받는 값   

//플레이 판 정의 
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//플레이 판 위에 있는 플레이어가 가지는 카드를 배열을 이용하여 정의 
int cardSum[N_MAX_USER+1];							//각 플레이어가 가지는 카드의 합 
int gameend = 0; 									//게임이 끝나는 것을 의미
int cardNumber[N_MAX_USER+1];						//각 플레이어와 딜러가 가지는 카드의 개수 
int Number[N_CARD];									//임의로 할당받을 값을 저장하는 배열. 단순한 숫자를 배열받으려고 함으로 큰 의미는 없음. 

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
	
	printf("함께 할 플레이어의 수를 입력해주세요(최대 다섯명까지 할 수 있습니다): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

//카드를 중복 없이 섞는 함수 
int mixCardTray(void){
	
	int i;
	int player_i;
	
	srand((unsigned)time(NULL));
	
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
	
}

//플레이어들에게 제공되는 초기의 두개 카드  
void offerCards(void){
	int i;
	int number;
	
	for (i=0;i<=with_player;i++);
	{
		cardhold[i][0] = pullCard(i);				//플레이어 모두에게 제공되는 두가지 카드 중 첫번째 카드. 
		cardhold[i][1] = pullCard(i+5);				//플레이어 모두에게 제공되는 두가지 카드 중 두번째 카드. 
	}
	cardhold[N_MAX_USER][0] = pullCard(N_MAX_USER-1);	//딜러에게 제공하는 두가지 카드 중 첫번째 카드. 
	cardhold[N_MAX_USER][1] = pullCard(N_MAX_USER);		//딜러에게 제공하는 두가지 카드 중 두번째 카드. 
	
	return;
}

//플레이어가 'go'를 선택할 경우 제공되는 추가의 카드 
void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)							 
		cardhold[player][i] = pullCard(i+10);		//플레이어에게 제공되는 셋,넷,,, 그 이상의 카드. 이 모든 카드는 pullCard 함수로 받는다. 
}

//카드를 나눠줌 
int pullCard(int number){
	int i, check_number, return_number, card;
	
	do{												//플레이어에게 제공되는 카드를 의미함. 
		Number[number]=rand()%N_CARD;				//CARDTRAY에 임의로 값을 할당하고 pullcard함수에서는 그 CARDTRAY의 배열이름을 임의로 할당해서 가져옴. 
		for(i=0;i<number;i++)						//이 경우 중복을 피하고자 임시로 Number배열에 임의로 할당된 숫자를 저장하고 만약 임의로 할당된 
		{											 
			if(Number[number]=Number[i])
			{
				check_number=1;						//숫자가 같을 경우 다시 할당받도록 함.  
			}
			else
			{
				check_number=2;
			}
		}
	}while(check_number==1);

	card = CARDTRAY[Number[number]];				//최종적으로 숫자가 다를 경우에만 CARDTRAY에 들어갈 수 있음. 
	return card;
}

void printCardInitialStatus(void){					//초기의 카드를 알려주는 함수. 
	int i;											//'나'의 카드를 알려줌. 
	printf("본인의 카드 : ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("------------------------------------------");
	for (i=1;i<with_player;i++)						//함께 할 플레이어 카드를 알려줌. 
	{
		printf("i 플레이어의 카드: ");
		printCard(cardhold[i][0]);
		printCard(cardhold[i][1]);
		printf("---------------------------------------");
	}
	printf("딜러의 카드 : ");						//딜러의 카드를 알려줌. 
	printf("알 수 없음");							//딜러의 카드는 한가지만 알려줄 수 있음. 
	printCard(cardhold[N_MAX_USER][0]);
}

void printUserCardStatus(int user, int cardcnt){
	int i;											//각 단계에서 새로 뽑은 카드를 추가해서 알려줌. 
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
	{
		printCard(cardhold[user][i]);
	}
	printf("\t:::");
}

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

int getAction(void){							//'GO'할지 'STOP'할 지 결정해야함. 
	
	char input;
	printf("go하시겠습니까? stop 하시겠습니까? (Y / N) :  ");
	scanf("%c",input);							//교수님이 주신 함수가 자꾸 오류가 나서... 그냥 scanf로 받아서 했습니다. 
	return input;
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	now_money[0]=50;		//초기 모든 플레이어가 가질 수 있는 돈을 저장한 배열. 
	now_money[1]=50;
	now_money[2]=50;
	now_money[3]=50;
	now_money[4]=50;
	now_money[5]=50;
	
	int roundIndex = 0;			//몇번 라운드를 했는지를 알려줄 값. 
	int n_user;					//함께 진행하는 플레이어의 수. 
	int i;						//for 문에 사용할 임시 값. 
	
	int input=0;				//go 할것인지 stop할 것인지를 받을 값. 
	int until_cardnum=0;		//현재까지의 카드 값의 합을 의미함. 
	int round_try_for_me = 0;	//내가 이때까지 뽑은 카드수를 계산할 때 사용할 값. 
	int round_try_for_player = 0;//플레이어가 이때까지 뽑은 카드수를 계산할 때, 사용할 값. 
	int round_try_for_dealer = 0;//딜러가 이때까지 뽑은 카드수를 계산할 떼 사용할 값. 
	
	srand((unsigned)time(NULL));

	n_user = configUser()+1;	//함께 할 플레이어의 수와 딜러의 수를 더한 값. 
	//돈 
	printf("모든 플레이어의 초기 자본금은 %d 달러 입니다.",N_DOLLAR); //초기 자본금을 알려줌. 
	
	//카드 트레이
	mixCardTray();					//카드를 섞음. 
	
	do{
		betDollar();			//배팅받을 카드를 입력함. 
		
		offerCards();			//카드를 제공함. 
		
		printCardInitialStatus();	//초기 카드값을 알려줌 
		
		printf("\n------------------------게임을 시작하겠습니다-------------------------\n");
		roundIndex++;				//기본으로 한 라운드를 시작하므로 
		
		printf("현재는 %d라운드 입니다.",roundIndex);	//라운드를 알려줌 
		
		printf("현재 자산 결과는 다음과 같습니다.");	//초기값과 각 라운드 시작할때마다의 값을 알려주려고함. 
		for(i=0;i<n_user;i++)
		{
			printf("플레이어i의 현재 자산은 %d 입니다",i,now_money[i]);
		}
		
		printf("\n---------------------------------------------------------\n");
		 
		printf(">>>나의 순서입니다---------------------------------------------------\n");		
		while(cardSum[0]<21&&input=='Y')//카드의 합이 21 미만이거나 내 대답이 Y일때는 계속함 
			
			
			round_try_for_me++;//일단 1을 더하고 시작함 
			printUserCardStatus(0,round_try_for_me);//내 현재의 카드 를 알려줌 
			
			cardSum[0]=calcStepResult(0,round_try_for_me);		//현재의 카드 값의 합을 의미함. 
			if(cardSum[0]==21)					//카드의 합이 21일 경우 나올 멘트와 값의 합. 
				{
					printf("축하합니다! 블랙잭이네요:P 당신이 얻는 급액은 %d원 입니다",2*dollar[0]);
					now_money[0]+=2*dollar[0];
				}
			else if(cardSum[0]>21)		//만약 21보다 클 경우 나올 멘트와 배팅한 금액을 잃음.... 
				{
					printf("지셨습니다:( 당신의 카드의 합은 %d 입니다. 당신이 잃은 금액은 %d 원입니다",cardSum[0],dollar[0]);
					now_money[0]-=dollar[0];	
				}
			else			//둘다의 경우가 아닐 경우 '나'에게 GO할 것인지 STOP 할 것인지를 물어봄. 
				{
					input = getAction();
					if(input=='Y')			//만약 Y를 입력받을 경우 새로운 카드를 제공함. 
					{
						offerCardsplus(0,round_try_for_me);
					}
					cardNumber[0]=round_try_for_me+1;	//한 번 돌 경우 플레이어가 가진 카드가 총 2장이므로 라운드의 값에서 일단 한장 더 더해줌. 
				}
		for(i=1;i<n_user;i++)					//'나'가 할 경우와 똑같이 진행되며 다른 점은 GO를 할지 STOP을 할지를 플레이어가 스스로 17을 기준으로 결정한 다는 것 밖에 없음. 
		{	printf(">>>플레이어i의 순서입니다---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17)){
				
				round_try_for_player++;
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("축하합니다! 블랙잭이네요:P 플레이어 %i가 얻는 급액은 %d원 입니다",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("지셨습니다:( 플레이어 %i의 카드의  합은 %d 입니다. 플레이어 %i가 잃은 금액은 %d 원입니다",i,cardSum[i],i,dollar[i]);
					now_money[i]-=dollar[i];
				}
				else if(cardSum[i]<17)//값이 17 미만일 경우 한장 더 뽑음. 
				{
					printf("플레이어%i가 카드를 한장 더 뽑았습니다.");
					offerCardsplus(i,round_try_for_player);
				}
				else if(cardSum[i]>=17)//값이 17 이상일 경우 그만 뽑음 
				{
					printf("플레이어%i가 카드를 그만 뽑기를 선탰했습니다.");
				}
				cardNumber[i]=round_try_for_player+1;//이 경우에도 위와 마찬가지로 한번 돌았을 때는 카드의 값이 두장이고 어차피 한장 더 뽑았으면
													//한번 더 돌것이므로 그때 더해짐 
			}
		}
		printf("딜러의 순서 입니다!"); 				//앞의 모든 플레이어와 똑같음. 
		while(cardSum[n_user]<17)
		{
			
			round_try_for_dealer++;
			printUserCardStatus(n_user,round_try_for_dealer);		//여기서 딜러의 숨겨왔던 카드를 보여줌 
			cardSum[n_user]=calcStepResult(n_user,round_try_for_dealer);
			if(cardSum[n_user]==21)
				break;
			else if(cardSum[n_user]>21)
				break;	
			else if(cardSum[n_user]<17)//딜러도 카드를 뽑을 수 있음. 
			{
				printf("딜러가 한장을 더 뽑았습니다.");
				offerCardsplus(n_user,round_try_for_dealer);
			}
			else if(cardSum[n_user]>17&&cardSum[n_user]<21)
			{
				printf("딜러가 그만 뽑기를 선택했습니다.");
			}
			cardNumber[n_user]=round_try_for_dealer+1;
		}
		printf("딜러의 값은 %d 입니다",cardSum[n_user]);
		for (i=0;i<n_user;i++)
		{
			CheckResult(i);			//결과 값을 비교함. 플레이어가 이겼는지 안 이겼는지를 확인함. 
		}
		
		printf("현재까지의 자산 결과는 다음과 같습니다.");
		for(i=0;i<n_user;i++)
		{
			printf("플레이어%i의 현재 자산은 %d 입니다",i,now_money[i]);		//자산 결과를 알려줌. 
		}
		
		for(i=0;i<=n_user+1;i++)			//현재까지의 모든 플레이어의 카드개수의 합을 구함. 
		{
			until_cardnum+=cardNumber[i];
		}
		
		if(until_cardnum>=52)				//만약 카드의 개수가 52개를 넘었을 경우 카드 트레이의 카드가 모두 소진된 것을 의미하므로  
		{									//게임을 끝내게 됨. 
			gameend = 1;
		}
		for(i=0;i<n_user;i++)
		{
			if(now_money[i]<=0)		//만약 플레이어 한명이라도 돈이 없다면 게임은 끝나게 됨.  
			{						// 이 두 모든 경우 gameend 값을 1로 받아서 do-while 의 조건인 gameend=0인 것을 만족하지 못하므로 반복이 끝남. 
				gameend = 1;
			}
		}
		
	}while(gameend == 0); //게임이 끝났을 것을 의미함. 
	
	int winner_money;
	winner_money = checkWinner(n_user);			//승자를 확인함. 저 checkWinnter함수는 승자의 돈을 확인하는 함수이므로 
	for(i=0;i<n_user;i++)						//승자의 돈을 먼저 확인하고 그 돈을 가진 승자를 확인함. 
	{
		if(winner_money==now_money[i])
		{
			printf("승자는 플레이어%i입니다.",i);
			break;								//승자를 확인했으면 그 이후는 볼 필요가 없으므로 나감... 
		}
	}	
		
	return 0;
}
