#include<stdio.h>
int Player=1,choice,status=-1;
char symbol;
char position[10]={'0','1','2','3','4','5','6','7','8','9'};
void board();
void board(){
printf("    |    |    \n");
printf(" %c  |  %c |  %c \n",position[1],position[2],position[3]);
printf("____|____|____\n");
printf("    |    |    \n");
printf(" %c  |  %c |  %c \n",position[4],position[5],position[6]);
printf("____|____|____\n");
printf("    |    |    \n");
printf(" %c  |  %c |  %c \n",position[7],position[8],position[9]);
printf("    |    |    \n");
}
int win();
int win(){
  int j;
  if(position[1]==position[2]&&position[2]==position[3]){
    return 1;
  }
  if(position[4]==position[5]&&position[5]==position[6]){
    return 1;
  }
  if(position[7]==position[8]&&position[8]==position[9]){
    return 1;
  }
  if(position[1]==position[5]&&position[5]==position[9]){
    return 1;
  }
  if(position[3]==position[5]&&position[5]==position[7]){
    return 1;
  }
  if(position[1]==position[4]&&position[4]==position[7]){
    return 1;
  }
  if(position[2]==position[5]&&position[5]==position[8]){
    return 1;
  }
  if(position[3]==position[6]&&position[6]==position[9]){
    return 1;
  }
  for(j=1;j<=9;j++){
    if(position[j]=='0'+j){
      return -1;
    }
  }
  return 0;

}

void main(){
  board();

  while(status==-1){
    Player=(Player%2!=0)?1:2;
    symbol=(Player==1)?'X':'O';
    printf("Player %d, enter your position choice:");
    scanf("%d",&choice);
    if(choice<1 || choice>9){
      printf("INVALID INPUT!! ENTER CHOICE AGAIN.\n");
      continue;
    }
    else if(position[choice]!=('0'+choice)){
      printf("SORRY THIS POSITION IS OCCUPIED. TRY ANOTHER.\n");
      continue;
    }
      position[choice]=symbol;
  board();
  status=win();
    if (status==1){
    printf("Player %d WON!!\n",Player);
  }
  else if (status==0){
    printf("GAME DRAW!!\n");
  }


  Player++;
  }

}
