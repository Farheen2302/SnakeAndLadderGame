#include "sulluhead.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/shm.h>

#define DELAY 3
struct shared_st *shared_board;

void snake1();
void snake2();
void snake3();
void snake4();
void snake5();
void snake6();
void snake7();
void snake8();
void ladder1();
void ladder2();
void ladder3();
void ladder4();
void ladder5();
void ladder6();

void extra_taste();
void playerpos();
void banner();
void main(int argc,char *argv[]){

	int i=0,k=0,l=0,m=0,n=0,r=1,flag=0,r1=0,s=0;
       	int x = 0, y = 0;
	char *p;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	int direction = 1;
	int shmid; //to hold the shared memory identifier
	void *shared_mem=(void*)0;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	start_color();
	
	shmid=shmget((key_t)1234,sizeof(struct shared_st),0666| IPC_CREAT);// creat shared memory
        shared_mem=shmat(shmid,(void*)0,0);// attach shared memory to the process
        shared_board=(struct shared_st*)shared_mem;

	init_pair(1, COLOR_RED, COLOR_GREEN); 
//attron(COLOR_PAIR(1)); 
	init_pair(2,COLOR_GREEN,COLOR_BLUE);
	getmaxyx(stdscr, max_y, max_x);
while(1) {

	clear();
	for(i=0;i<5;i++){
		for(s=0;s<4;s++){
			for(k=0;k<5;k++){
				attron(COLOR_PAIR(1));
					printw("        ");
				attron(COLOR_PAIR(2));
				printw("        ");
				}
			printw("\n");
			}
		for(s=0;s<4;s++){
			for(k=0;k<5;k++){
				attron(COLOR_PAIR(2));
				printw("        ");
				attron(COLOR_PAIR(1));
				printw("        ");
			}
			printw("\n");
			}
		}
		curs_set(FALSE);
	
	refresh();
	n=2;
	m=3;
	init_pair(3,COLOR_WHITE,COLOR_GREEN);
	for(i=100;i>0;i--){
	//j=itoa(i);
	
	
		move(n,m);
			
		attron(A_BOLD | A_BLINK | A_DIM | COLOR_PAIR(3));
		printw("%d",i);
		if((i-1)%10==0){
		flag=1;
		r1=r;
                r=0;
		n=n+4;
		}
		m=m+8*(r);
		if(flag==1){
			r=r1;
			r=(-1)*r;
			flag=0;
		}
	
  	
	
	}
refresh();
//making snakes
	snake1();
	snake2();
	snake3();
	snake4();
	snake5();
	snake6();
	snake7();
	snake8();
	refresh();
	ladder1();
	ladder2();
	ladder3();	
	ladder4();	
	ladder5();
	ladder6();
	
	extra_taste();
	playerpos();
	refresh();
	banner();
	refresh();
	attroff(COLOR_PAIR(1));
//halfdelay(5);
	refresh();
	sleep(DELAY);
	}
}

void snake1(){
	int i,j,k=0;
	i=1;
	j=10;
	
	attron(A_NORMAL);
	init_pair(4, COLOR_RED, COLOR_BLUE);
   	attron(COLOR_PAIR(4)); 
	mvprintw(i++,j++,"o");//1
	mvprintw(i++,j++,"o");//2
	mvprintw(i++,j,"o");//3
	mvprintw(i,j++," ");//4
	mvprintw(i++,j,"o");//5
	mvprintw(i++,j--,"o");//6
	mvprintw(i++,j--,"o ");//7
	for(k=0;k<3;k++)
		mvprintw(i++,j++," o");//8
	mvprintw(i,j++," o");//11
	mvprintw(i++,j++," o");//12
	mvprintw(i,j++," o");//13
	
	mvprintw(i++,j++," o");//14
	mvprintw(i,j++," o");//15
	mvprintw(i++,j++," o");//16
	mvprintw(i,j++," o");//17
	mvprintw(i++,j++," o");//18
	
	mvprintw(i++,j++," o");//19
	mvprintw(i,j++," o");//20
	mvprintw(i++,j++," o");//21
	mvprintw(i,j++," o");//22
	
	mvprintw(i++,j++," o");//23
	mvprintw(i++,j++," o");//24
	for(k=0;k<16;k++)
		mvprintw(i++,j++,"o");
	for(k=0;k<5;k++)
		mvprintw(i++,j++," o");
}
void snake2(){
	int i,j,k=0;
	i=2;
	j=41;
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"o");
	for(k=0;k<3;k++)
		mvprintw(i++,j,"o");
	for(k=0;k<3;k++)
		mvprintw(i++,j++,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j--,"o");	
}
	
void snake3(){
	int i,j,k=0;
	i=2;
	j=66;
	init_pair(5, COLOR_CYAN, COLOR_BLUE);
   	attron(COLOR_PAIR(5) | A_BOLD); 
	for(k=0;k<4;k++)
		mvprintw(i++,j++,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j,"o");
	for(k=0;k<6;k++)
		mvprintw(i++,j--,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j++,"o");
 	mvprintw(i++,j++,"o");
	mvprintw(i++,j,"o");
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"o");
	mvprintw(i++,j,"o");
}

void snake4(){
	int i,j,k=0;

 	i=10;
	j=70;
	init_pair(6, COLOR_RED, COLOR_GREEN);
   	attron(COLOR_PAIR(6) | A_BOLD); 
	for(k=0;k<4;k++)
		mvprintw(i++,j++,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j--,"o");
	mvprintw(i++,j--,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j++,"o");
	mvprintw(i++,j,"o");
 	mvprintw(i++,j--,"o");
}
void snake5(){
		int i,j,k;
	i=9;
	j=50;
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j++,"o");
	for(k=0;k<3;k++)
	mvprintw(i++,j,"o");
	mvprintw(i++,j--,"o");
	for(k=0;k<6;k++)
 		mvprintw(i++,j--,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j--,"o");
	i++;
	j--;
	mvprintw(i++,j--,"o");
	//i++;
        j-=2;
     	mvprintw(i++,j--,"o");
	j-=2;
	mvprintw(i++,j--,"o");
	j-=3;
 	mvprintw(i++,j--,"o");
}

void snake6(){
	int i,j,k=0;
	i=14;
	j=18;
	init_pair(7, COLOR_YELLOW, COLOR_BLUE);
   	attron(COLOR_PAIR(7) | A_BOLD | A_BLINK);
	for(k=0;k<7;k++)
		mvprintw(i++,j--,"o");
	mvprintw(i++,j,"o");
	mvprintw(i++,j,"o");
	for(k=0;k<4;k++)
		mvprintw(i++,j++,"o");
	mvprintw(i++,j,"o");
 	mvprintw(i++,j--,"o");
	mvprintw(i++,j--,"o");
	}



void snake7(){
	int i,j,k=0;
	i=26;
	j=50;
	init_pair(7, COLOR_YELLOW, COLOR_BLUE);
   	attron(COLOR_PAIR(7) | A_BOLD | A_BLINK);
	mvprintw(i++,j++,"o");
	j++;
	mvprintw(i++,j++,"o");
	j++;
	mvprintw(i++,j++,"o");
	j++;
	mvprintw(i++,j++,"o");
	mvprintw(i++,j++,"o");
	j++;
	for(k=0;k<7;k++)
		mvprintw(i++,j++,"o");
	j++;
	j++;
	j++;
	mvprintw(i,j++,"o");
	}

void snake8(){
	int i,j,k=0;
	i=34;
	j=18;
	init_pair(8, COLOR_RED, COLOR_BLUE);
   	attron(COLOR_PAIR(8) | A_BOLD | A_BLINK);
	mvprintw(i++,j,"o");
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"o");
	j--;	
	mvprintw(i++,j--,"o");
}
void ladder1(){
	int i;
	init_pair(9, COLOR_YELLOW
, COLOR_BLUE);
   	attron(COLOR_PAIR(9) | A_BOLD | A_BLINK);
	for(i=10;i<26;i++){
		mvprintw(i,26,"|-|");
		
	}
}
		
void ladder2(){
	int i,j,k;
	i=30;
	j=8;
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"/-/");
}	
void ladder3(){
	int i,j,k;
	i=10;
	j=8;
	for(k=0;k<4;k++)
		mvprintw(i++,j--,"/-/");
	
}
		
void ladder4(){
	int i,j,k=0;
	i=0;
	j=30;
	for(k=0;k<11;k++)
		mvprintw(i++,j++,"\\-\\");
   	}

void ladder5(){
	int i,j,k=0;
	i=2;
	j=65;
	for(k=0;k<20;k++)
		mvprintw(i++,j--,"/-/");
}

void ladder6(){
	int i,j,k=0;
	i=30;
	j=34;
	for(k=0;k<8;k++)
		mvprintw(i++,j++,"\\-\\");
}
void banner(){
	int i,j;
	//attroff();
	
	init_pair(10, COLOR_WHITE, COLOR_BLACK); 
	attron(COLOR_PAIR(10) | A_BOLD);
	mvaddstr(4,83," --");
	mvaddstr(5,83,"|    |  |   /\\   | /  --");
	mvaddstr(6,83," --  |\\ |  /  \\  |/  |");
	mvaddstr(7,83,"   | | \\| /    \\ |\\  |--");
	mvaddstr(8,83," --  |  |        | \\  --");
	mvaddstr(10,113,"|");
	mvaddstr(11,113,"|     /\\   -   -    --  -");
	mvaddstr(12,113,"|    /  \\  | | | | |   |  )");
	mvaddstr(13,113,"|   /    \\ | | | | |-  | \\");
	mvaddstr(14,113," ---       -   -    -- |  \\");
	mvaddstr(16,83,"PLAYER1:");
	mvaddstr(16,92,shared_board->player1);
	
	
	mvaddstr(17,83,"PLAYER2:");
	mvaddstr(17,92,shared_board->player2);
	refresh();
	mvaddstr(18,83,"TURN:");
	if(shared_board->turn1==1)
		mvaddstr(18,92,shared_board->player1);
	else
		mvaddstr(18,92,shared_board->player2);
	if(shared_board->c=='\0'){
		mvaddstr(34,84,"Enter to throw   ");
		shared_board->c=getch();
		
		refresh();	
	}
	//sleep(1);
	mvaddstr(19,83,"NUMBER ON DICE:");
	mvprintw(19,100,"%d",shared_board->num);
	//mvaddstr(22,90,"MAGIC:");
	refresh();
	mvaddstr(24,83,"WINNER:");
	if(shared_board->ply1==100){
		init_pair(11, COLOR_RED, COLOR_BLACK); 
		attron(COLOR_PAIR(11));
		mvaddstr(3,3,"A");
		mvaddstr(24,92,shared_board->player1);
		attroff(COLOR_PAIR(11));
		}
	if(shared_board->ply2==100){
		init_pair(11, COLOR_RED, COLOR_BLACK); 
		attron(COLOR_PAIR(11));
		mvaddstr(3,2,"B");
		mvaddstr(24,92,shared_board->player1);
		attroff(COLOR_PAIR(11));
		}
	 
        mvaddstr(25,83,"A=");
	mvaddstr(25,86,shared_board->player1);
	mvaddstr(26,83,"pos=");
	mvprintw(26,88,"%d",shared_board->ply1);
	 mvaddstr(27,83,"B=");
	mvaddstr(27,86,shared_board->player2);
	mvaddstr(28,83,"pos=");
	mvprintw(28,88,"%d",shared_board->ply2);
	refresh();

	if(shared_board->ply1==4||shared_board->ply1==35||shared_board->ply1==86||shared_board->ply2==4||shared_board->ply2==35||shared_board->ply2==86)
	mvaddstr(30,82,"ENERGY DRINK      ");
	refresh();
	if(shared_board->ply1==40||shared_board->ply2==40){
		mvaddstr(30,82,"CAUGHT UP BY STUD ");refresh();}
	
	if(shared_board->ply1==38||shared_board->ply2==5){
		mvaddstr(30,82,"UNDER HALUCINATION");refresh();}
	switch(shared_board->ply1)
	{
		case 20:mvaddstr(30,82,"u got ladder      ");
		case 7:mvaddstr(30,82,"u got ladder      ");
		case 37:mvaddstr(30,82,"u got ladder      ");
		case 61:mvaddstr(30,82,"u got ladder      ");
		case 46:mvaddstr(30,82,"u got ladder      ");
		case 75:mvaddstr(30,82,"u got ladder      ");	
	}
	refresh();
	switch(shared_board->ply2)
	{
		case 20:mvaddstr(30,82,"u got ladder      ");
		case 7:mvaddstr(30,82,"u got ladder     ");
		case 37:mvaddstr(30,82,"u got ladder     ");
		case 61:mvaddstr(30,82,"u got ladder     ");
		case 46:mvaddstr(30,82,"u got ladder      ");
		case 75:mvaddstr(30,82,"u got ladder      ");	
	}
	refresh();
	switch(shared_board->ply1)
	{
		case 99:mvaddstr(30,82,"u bit by snake    ");
		case 94:mvaddstr(30,82,"u bit by snake    ");
		case 88:mvaddstr(30,82,"u bit by snake    ");
		case 74:mvaddstr(30,82,"u bit by snake    ");
		case 63:mvaddstr(30,82,"u bit by snake    ");
		case 34:mvaddstr(30,82,"u bit by snake    ");	
		case 18:mvaddstr(30,82,"u bit by snake    ");	
	}	
		refresh();
	switch(shared_board->ply2)
	{
		case 99:mvaddstr(30,82,"u bit by snake    ");
		case 94:mvaddstr(30,82,"u bit by snake    ");
		case 88:mvaddstr(30,82,"u bit by snake    ");
		case 74:mvaddstr(30,82,"u bit by snake    ");
		case 63:mvaddstr(30,82,"u bit by snake    ");
		case 34:mvaddstr(30,82,"u bit by snake    ");	
		case 18:mvaddstr(30,82,"u bit by snake    ");	
	}	

refresh();





}



	
void extra_taste(){
	int i,j;
	init_pair(10, COLOR_WHITE, COLOR_BLACK); 
	attron(COLOR_PAIR(10) | A_BOLD);
	mvaddstr(25,18,"H");
	mvaddstr(17,41,"H");
	mvaddstr(9,1,"$");
	mvaddstr(25,1,"$");
	mvaddstr(37,25,"E");
	mvaddstr(25,41,"E");
	mvaddstr(5,41,"E");
	mvaddstr(30,113,"TASTE:");
	mvaddstr(31,113,"E-EneryDrink +5steps");
	mvaddstr(32,113,"$-STOPS you");
	mvaddstr(34,113,"H-Halucination");
	
	refresh();
	
}	
void playerpos(){

	init_pair(11, COLOR_RED, COLOR_BLACK); 
	attron(COLOR_PAIR(11) | A_BOLD);
	int i,j,s=100,flag=0,x,y;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(shared_board->ply1==s)
				{
					flag=1;
					break;
			
				}
			s--;
			}			
		if(flag==1)
			break;
	}			
	
	x=i;
	if(i%2==0){
		if(s%10==0)
			y=3;
		else
			y=10-(s%10);
		}
	else{
		if(s<=10){
			y=s-1;
			}
		else
			y=s%10-1;
	}
	mvaddstr((x*4+3),(y*8+3),"A");



	i=0;j=0;x=0;y=0;flag=0;s=100;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(shared_board->ply2==s)
				{
					flag=1;
					break;
			
				}
			s--;
			}			
		if(flag==1)
			break;
	}			
	
	x=i;
	if(i%2==0){
		if(s%10==0)
			y=2;
		else
			y=10-(s%10);
		}
	else{
		if(s<=10){
			y=s-1;
			}
		else
		   y=s%10-1;
	}
	mvaddstr((x*4+3),(y*8+2),"B");
	attroff(COLOR_PAIR(11));
	init_pair(10, COLOR_WHITE, COLOR_BLACK); 
	attron(COLOR_PAIR(10) | A_BOLD);
}
