#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

int a[3][3];

 int checkwinner()
{
  if(a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][2] == a[0][0])
  {
     if(a[0][0] == 1 || a[0][0] == 2)
     {
	  return 1;
     }
  }
  else if(a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] == a[0][0])
  {
     if(a[0][0] == 1 || a[0][0] == 2)
     {
	  return 2;
     }
  }
  else if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[0][0])
  {
     if(a[0][0] == 1 || a[0][0] == 2)
     {
	 return 3;
     }
  }
  else if(a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] == a[0][1])
  {
     if(a[0][1] == 1 || a[0][1] == 2)
     {
	 return 4;
     }
  }
   else if(a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == a[0][2])
  {
     if(a[0][2] == 1 || a[0][2] == 2)
     {
	   return 5;
     }
  }
  else if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] == a[0][2])
  {
    if(a[0][2] == 1 || a[0][2] == 2)
     {
	return 6;
     }
  }
  else if(a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][2] == a[1][0])
  {
     if(a[1][0] == 1 || a[1][0] == 2)
     {
	return 7;
     }
  }
  else if(a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][2] == a[2][0])
  {
     if(a[2][0] == 1 || a[2][0] == 2)
     {
	return 8;
     }
  }

  return 0;
}

 void setzero()
{
  int i,j;
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
    a[0][0] = 0;
   }
  }
}

 void main()
{
  int flag = 0; //for tie handling
  int k,j;  //loop iterators
  char boxchar; //input box in char format
  int box;    //input box converted to int
  int i=1;    //turn no currently going on odd--> X even-->O i<=9 therefre 5 X and 4 O
  int fontsize = 3;
  char str1[2] = "X"; //to accomodate null char [2]
  char str2[2] = "O";
  setzero();  //sets all elements of a = 0
  int status;  //for checkwinner
  //declarations over

  cout<<"\n\n\tWelcome To  Tic Tac Toe";
  cout<<"\n\n Press Enter to see Graphically";
  getch();
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:/TC/BGI");

  setcolor(BLUE);
  //horizontal lines
  line( getmaxx()*0.33,50, getmaxx()*0.33, getmaxy()-50 );
  line( 2*getmaxx()*0.33,50, 2*getmaxx()*0.33 , getmaxy()-50);

  setcolor(RED);
  //vertical lines
  line( 50, getmaxy()*0.33 , getmaxx()-50 , getmaxy()*0.33 );
  line( 50, 2*getmaxy()*0.33, getmaxx()-50 , 2*getmaxy()*0.33 );

  cout<<"\n\tEnter box to input in and X/O:";
  settextstyle(DEFAULT_FONT , HORIZ_DIR , fontsize );

  while(i<=9)
 {
  boxchar = getche();
  box = boxchar - 48;

  //cout<<box;
  //delay(300);  //formatting tools
  //cout<<"\b";

  if(i%2 != 0)
  {
   switch(box)
   {
     case 1:
	    outtextxy( getmaxx()/3-50-50,     getmaxy()/3-50-50, str1);
	    a[0][0] = 1;
	    break;
     case 2:
	    outtextxy(2*getmaxx()/3-50-50 ,   getmaxy()/3-50-50  , str1);
	    a[0][1] = 1;
	    break;
     case 3:
	    outtextxy( (getmaxx()-50)-50-50 , getmaxy()/3-50-50 , str1);
	    a[0][2] = 1;
	    break;
     case 4:
	    outtextxy(getmaxx()/3-50-50 ,      2*getmaxy()/3-50-50 , str1);
	    a[1][0] = 1;
	    break;
     case 5:
	    outtextxy(2*getmaxx()/3-50-50 ,    2*getmaxy()/3-50-50 , str1);
	    a[1][1] = 1;
	    break;
     case 6:
	    outtextxy( (getmaxx()-50)-50-50 ,  2*getmaxy()/3-50-50 , str1);
	    a[1][2] = 1;
	    break;
     case 7:
	    outtextxy(getmaxx()/3-50-50 ,   (getmaxy()-50)-50-50  , str1);
	    a[2][0] = 1;
	    break;
     case 8:
	    outtextxy(2*getmaxx()/3-50-50 , (getmaxy()-50)-50-50 , str1);
	    a[2][1] = 1;
	    break;
     case 9:
	    outtextxy( (getmaxx()-50)-50-50 ,  (getmaxy()-50)-50-50 , str1);
	    a[2][2] = 1;
	    break;

     default: cout<<"\nWrong Box Enter again";
	      break;
   }

  }

  else if(i%2 == 0)
  {
      switch(box)
    {
      case 1:
	     outtextxy( getmaxx()/3-50-50,     getmaxy()/3-50-50, str2);
	     a[0][0] = 2;
	     break;
      case 2:
	     outtextxy(2*getmaxx()/3-50-50 ,   getmaxy()/3-50-50  , str2);
	     a[0][1] = 2;
	     break;
      case 3:
	     outtextxy( (getmaxx()-50)-50-50 , getmaxy()/3-50-50 , str2);
	     a[0][2] = 2;
	     break;
      case 4:
	     outtextxy(getmaxx()/3-50-50 ,      2*getmaxy()/3-50-50 , str2);
	     a[1][0] = 2;
	     break;
      case 5:
	     outtextxy(2*getmaxx()/3-50-50 ,    2*getmaxy()/3-50-50 , str2);
	     a[1][1] = 2;
	     break;
      case 6:
	     outtextxy( (getmaxx()-50)-50-50 ,  2*getmaxy()/3-50-50 , str2);
	     a[1][2] = 2;
	     break;
      case 7:
	     outtextxy(getmaxx()/3-50-50 ,   (getmaxy()-50)-50-50  , str2);
	     a[2][0] = 2;
	     break;
      case 8:
	     outtextxy(2*getmaxx()/3-50-50 , (getmaxy()-50)-50-50 , str2);
	     a[2][1] = 2;
	     break;
      case 9:
	     outtextxy( (getmaxx()-50)-50-50 ,  (getmaxy()-50)-50-50 , str2);
	     a[2][2] = 2;
	     break;

      default:
	     break;
    }
  }
   //Out of Both ifs

    status = checkwinner();
    if(status!=0)
    {
     // cout<<"\n\n\t:"<<status;
      flag = 1;
      if(i%2 != 0)
      {
	cout<<"\n\n\tPlayer 1 (X) Wins";
      }

      else if(i%2 == 0)
      {
	cout<<"\n\n\tPlayer 2 (O) Wins";
      }
       //display matrix
      getch();
      delay(500);
/*      for(k=0;k<3;k++)
      {
       cout<<"\n";
       for(j=0;j<3;j++)
       {
	 cout<<" "<<a[k][j];
       }
      }
    */
      getch();
      exit(0);
    }

   i++; //turn increment--> i.e. value formed here is for next turn no
 }
  delay(300);
  if(!flag)
  {
   cout<<"\n\n\tPlayers Tie";
   getch();
  }
  getch();
  closegraph();

}
