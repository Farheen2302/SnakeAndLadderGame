 struct shared_st 
      { 
	char player1[15];
	char player2[15];
	char c;
	int num;
        int ply1,ply2;// to store position
        int flag1,flag2;// to check one has 6 on dice to start playing
        int turn1,turn2; // to see who is playing
        };

int ener(int p)
{
        switch (p)
        {
		case 4:return check_pos(9);
		case 35:return check_pos(40);
		case 86:return check_pos(68);
		default:return p;
        }
}

int stud(int pos,int pos1)
{
     // if a stud is present in the path then the player will stop at stud and continue from that postion in next turn.
     if(40<pos&&40>pos1)
          return 40;
     else if(80<pos&&80>pos1)
	return 80;
       else 
           return pos;
}


int halu(int pos)
{
       // under affect of some magic food the player gets dizzi and can move one location all the eight directions.
	int r1[]={45,46,47,54,56,65,66,67};
	int r2[]={22,23,24,37,39,42,43,44};
	int r=rand()%8;
	if(pos==55)
		return r1[r];
	else if (pos==38)
	  	{	
			if(r2[r]==37)
			  return 77;
			else 
			  return r2[r];
           	}
        else 
               return pos;
}

int check_pos(int p)
{        // to check the final postion of the player after encountering a snake or ladder
	switch(p)
	{
		case 20:return 22;
		case 6:return  25;
		case 37:return 77;
		case 61:return 79;
		case 46:return 92;
		case 65:return 97;
		case 99:return 7;
		case 95:return 56;
		case 72:return 31;
		case 74:return 17;
		case 63:return 22;
		case 34:return 9;
		case 18:return 2;
		case 89:return 48;
        	default:return p;	
  }

}

int move(int r,int curpos)
{	int curpos2=0;
	curpos2=r+curpos;// to add the dice value
    	curpos2=stud(curpos2,curpos);// to check for stud
    	curpos2=check_pos(curpos2);// to check for ladder or snake
    	curpos2=halu(curpos2);// if the player hallucinates
	curpos2=ener(curpos2);// if player consumes the energy drink
	if(curpos2>100)
		curpos=curpos;
	else if(curpos2<100)
		curpos=curpos2;
	else
		curpos=100;	 
     return curpos;
}
