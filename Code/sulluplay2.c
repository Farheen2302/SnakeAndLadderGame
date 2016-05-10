#include "sulluhead.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/shm.h>
 // to include from current directory

struct shared_st *shared_board;

int throw()
{    
    int r,count=0; int flag=0;
        // count the number of 6 received
	while(1)
	{         
                r=rand()%6+1; 
                shared_board->num=r;
                shared_board->ply2=move(r,shared_board->ply2);
                 if((shared_board->ply2==100)||(shared_board->ply1==100))
		{
			flag=1;
			break;
		}
		if(r!=6)
			break;
                count++;
                if(count==2)
			break;	
	        
       
	}
	 count=0;
      	if(flag==1)
		return 1;
	else
		return 0;
}

int main()
{
	int r; int val;
	int shmid; //to hold the shared memory identifier
	srand((unsigned int)getpid());
        void *shared_mem=(void*)0;
	shmid=shmget((key_t)1234,sizeof(struct shared_st),0666| IPC_CREAT);// creat shared memory
        shared_mem=shmat(shmid,(void*)0,0);// attach shared memory to the process
        shared_board=(struct shared_st *)shared_mem;
        shared_board->ply1=0;
	shared_board->ply2=0;
        shared_board->flag2=0;
        shared_board->turn2=1;
        shared_board->turn1=0;
	shared_board->c='\0';
        printf("enter your name\n");
	scanf("%s",shared_board->player2);
        while(1)
        {       if((shared_board->ply2==100)||(shared_board->ply1==100))
                        break;
              if(shared_board->turn1==1)
			sleep(7);
		if(shared_board->c=='\0')
			sleep(1);
              if(shared_board->flag2!=1)
		{
			r=rand()%6+1;
			shared_board->num=r;
                        if(r==6)//until get 6 we cannot start playing
        	        { 
                        	shared_board->ply2=1;
				shared_board->flag2=1;
			}
		}
            	else
            	{
                        if((shared_board->ply2==100)||(shared_board->ply1==100))
                                    break;
			val=throw();
			  if(val==1)
			 	break;
		}
		shared_board->c='\0';
                shared_board->turn1=1;
		shared_board->turn2=0;
            }
        shmdt(shared_mem);
        shmctl(shmid,IPC_RMID,0); 
        exit(1);
   
}
