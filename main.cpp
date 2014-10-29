#include "initialize.h"
#include<iomanip>
Base *chessboard[8][8];
blacksoldier b[8];
whitesoldier w[8];
blackking bk;
whiteking wk;
blackqueen bqueen;
whitequeen wqueen;
blackelephant belephant[2];
whiteelephant welephant[2];
blackuut buut[2];
whiteuut wuut[2];
blackhorse bhorse[2];
whitehorse whorse[2];
void display()
{
    cout<<"\n...............................................................................\n";
    for(int i=0;i<8;i++)
    {

        for(int j=0;j<8;j++)
        {
            if(chessboard[i][j]==NULL)
            cout<<left<<setw(10)<<"Null";
            else if(chessboard[i][j]->givemetheplayer()==100)
            cout<<left<<setw(10)<<"Blsoldier";
            else if(chessboard[i][j]->givemetheplayer()==200)
            cout<<left<<setw(10)<<"whsoldier";
            else if(chessboard[i][j]->givemetheplayer()==101)
            cout<<left<<setw(10)<<"Blking";
            else if(chessboard[i][j]->givemetheplayer()==102)
            cout<<left<<setw(10)<<"Blqueen";
            else if(chessboard[i][j]->givemetheplayer()==201)
            cout<<left<<setw(10)<<"whking";
            else if(chessboard[i][j]->givemetheplayer()==202)
            cout<<left<<setw(10)<<"whqueen";
             else if(chessboard[i][j]->givemetheplayer()==103)
            cout<<left<<setw(10)<<"blHanthi";
            else if(chessboard[i][j]->givemetheplayer()==203)
            cout<<left<<setw(10)<<"whHanthi";
            else if(chessboard[i][j]->givemetheplayer()==104)
            cout<<left<<setw(10)<<"buut";
            else if(chessboard[i][j]->givemetheplayer()==204)
            cout<<left<<setw(10)<<"wuut";
            else if(chessboard[i][j]->givemetheplayer()==105)
            cout<<left<<setw(10)<<"bhorse";
             else if(chessboard[i][j]->givemetheplayer()==205)
            cout<<left<<setw(10)<<"whorse";

        }
        cout<<"\n";
    }
        cout<<"\n............................................................................\n";
}
int main()
{//intializing the chessboard
    /**********************************************************************/

     for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            chessboard[i][j]=NULL;
        }
    }
    //initializing white horse
    whorse[0].setposition(0,1);
    chessboard[0][1]=&whorse[0];
    whorse[1].setposition(0,6);
    chessboard[0][6]=&whorse[1];
    //initializing black horse
    bhorse[0].setposition(7,1);
    chessboard[7][1]=&bhorse[0];
    bhorse[1].setposition(7,6);
    chessboard[7][6]=&bhorse[1];
    //initializing white uut
    wuut[0].setposition(0,2);
    chessboard[0][2]=&wuut[0];
    wuut[1].setposition(0,5);
    chessboard[0][5]=&wuut[1];
    //intializing white uut
    buut[0].setposition(7,2);
    chessboard[7][2]=&buut[0];
    buut[1].setposition(7,5);
    chessboard[7][5]=&buut[1];

    welephant[0].setposition(0,0);//initializing white elephant
    chessboard[0][0]=&welephant[0];

    welephant[1].setposition(0,7);
    chessboard[0][7]=&welephant[1];

 belephant[0].setposition(7,0);//initializing black elephant1
    chessboard[7][0]=&belephant[0];
    //chessboard[7][0]->setposition(7,0);

    belephant[1].setposition(7,7);//initializing black elephant1
    chessboard[7][7]=&belephant[1];
    //chessboard[7][7]->setposition(7,7);
    for(int j=0;j<8;j++)             //initializing blacksoldier
    {
        b[j].setposition(6,j);
        chessboard[6][j]=&b[j];

    }
          bk.setposition(7,3);
      chessboard[7][3]=&bk;//initializing black king

            wk.setposition(0,3);
      chessboard[0][3]=&wk;//initializing white king
    for(int j=0;j<8;j++)//initializing whitesoldier
    {
        w[j].setposition(1,j);
        chessboard[1][j]=&w[j];

    }
     bqueen.setposition(7,4);
    chessboard[7][4]=&bqueen;//initializing black queen

    wqueen.setposition(0,4);//initiliazing white queen
    chessboard[0][4]=&wqueen;
int blackcurposx,blackcurposy;
int whitecurposx,whitecurposy;
//getbothkingpos(wk,bk,blackcurposx,blackcurposy,whitecurposx,whitecurposy);
/*******************************************************************************/
string player1,player2;
int player1x,player1y;
int player2x,player2y;
int choice;
cout<<"player 1::white player\"WHITE BACKGROUND\"\n";
cout<<"player 2::black player\"BLACK BACKGROUND\"\n\n";
system("color 70");
cout<<"Player 1 name::";
cin>>player1;
system("color 07");
cout<<"Player 2 name::";
cin>>player2;
cout<<"\nlets start\n";
display();
while(2){
 cout<<player1<<"chance:\n";
while(2)
{
        system("color 70");
    cout<<"enter cordinates \n";
    while(2)
    {
        cin>>player1x;
        cin>>player1y;
        if(chessboard[player1x][player1y]==NULL)
        {
            cout<<"pls "<<player1<<",select players\n";
        }
        else if(chessboard[player1x][player1y]->givetypeofplayer()==0)
        {
            cout<<"pls "<<player1<<",select your own players\n";
        }
        else
        break;
    }
    chessboard[player1x][player1y]->findpossiblelocationtomoveorattack();
    if(chessboard[player1x][player1y]->noofattackpos!=0 && chessboard[player1x][player1y]->noofmovepos!=0)
    {
        if(chessboard[player1x][player1y]->givemetheplayer()==100 || chessboard[player1x][player1y]->givemetheplayer()==200)
            {
            while(2){
            cout<<"enter \n1:move  2:attack  3:enpass \n";
            cin>>choice;
            if(choice==1)
            {

                chessboard[player1x][player1y]->move();
                break;
            }
            else if(choice==2)
            {
                chessboard[player1x][player1y]->attack();
                break;
            }
                    }
            if(wk.getcheckbit()==1)
                {
                    int x;int y;
                    wk.getposition(x,y);
                    if(wk.ischeckisstillon(x,y))
                    {
                        cout<<"black wins\n";
                        exit(0);
                    }
                    else
                    {
                        wk.resetcheckbit();
                    }
                }
                    break;//to give another player chance
            }
        else
        {
             while(2){
            cout<<"enter \n1:move  2:attack \n";
            cin>>choice;
            if(choice==1)
            {
                chessboard[player1x][player1y]->move();
                break;
            }
            else if(choice==2)
            {
                chessboard[player1x][player1y]->attack();
                break;
            }
            else
            continue;
                    }

                if(wk.getcheckbit()==1)
                {
                    int x;int y;
                    wk.getposition(x,y);
                    if(wk.ischeckisstillon(x,y))
                    {
                        cout<<"black wins\n";
                        exit(0);
                    }
                    else
                    wk.resetcheckbit();
                }
                     break;//to give another player chance
        }

    }
    else if(chessboard[player1x][player1y]->noofattackpos)
    {
        while(2){
        cout<<"1:attack\n";
        cin>>choice;
        if(choice==1)
        {
            chessboard[player1x][player1y]->attack();
            break;
        }
        else
        continue;
        }
         if(wk.getcheckbit()==1)
                {
                    int x;int y;
                    wk.getposition(x,y);
                    if(wk.ischeckisstillon(x,y))
                    {
                        cout<<"black wins\n";
                        exit(0);
                    }
                    else
                    wk.resetcheckbit();
                }
         break;//to give another player chance
    }
    else if(chessboard[player1x][player1y]->noofmovepos)
    {
        while(2){
        cout<<"1:move\n";
        cin>>choice;
        if(choice==1)
        {
            chessboard[player1x][player1y]->move();
            break;
        }
        else
        continue;
        }
         if(wk.getcheckbit()==1)
                {
                    int x;int y;
                    wk.getposition(x,y);
                    if(wk.ischeckisstillon(x,y))
                    {
                        cout<<"black wins\n";
                        exit(0);
                    }
                    else
                    {
                        wk.resetcheckbit();
                    }
                }

         break;//to give another player chance
    }
    else
    {
        cout<<"No position to move\nNo position to attack\n";
    }


}
  display();
  bk.getposition(blackcurposx,blackcurposy);
  if(bk.ischeckisstillon(blackcurposx,blackcurposy))
  {
      bk.setcheckbit();
      cout<<player2<<" save your king\n";
  }
    wk.getposition(blackcurposx,blackcurposy);//for testing allowing own killing
  if(wk.ischeckisstillon(blackcurposx,blackcurposy))
  {
      wk.setcheckbit();
      cout<<player1<<",u ur self responsible\n";
      cout<<player2<<" wins\n";
      exit(0);
  }

cout<<"player 2:"<<player2<<" chance\n";
while(2)
{
        system("color 07");
    cout<<"enter cordinates \n";
    while(2)
    {
        cin>>player2x;
        cin>>player2y;
        if(chessboard[player2x][player2y]==NULL)
        {
            cout<<"pls "<<player2<<",select players\n";
        }
        else if(chessboard[player2x][player2y]->givetypeofplayer()==1)
        {
            cout<<"pls "<<player2<<",select your own players\n";
        }
        else
        break;
    }
    chessboard[player2x][player2y]->findpossiblelocationtomoveorattack();
    if(chessboard[player2x][player2y]->noofattackpos!=0 && chessboard[player2x][player2y]->noofmovepos!=0)
    {
        if(chessboard[player2x][player2y]->givemetheplayer()==100 || chessboard[player2x][player2y]->givemetheplayer()==200)
            {
            while(2){
            cout<<"1:move  2:attack  3:enpass \n";
            cin>>choice;
            if(choice==1)
            {

                chessboard[player2x][player2y]->move();
                break;
            }
            else if(choice==2)
            {
                chessboard[player2x][player2y]->attack();
                break;
            }
                    }
            if(bk.getcheckbit()==1)
                {
                    int x;int y;
                    bk.getposition(x,y);
                    if(bk.ischeckisstillon(x,y))
                    {
                        cout<<"white wins\n";
                        exit(0);
                    }
                    else
                    bk.resetcheckbit();
                }
                    break;//to give another player chance
            }
        else
        {
             while(2){
            cout<<"1:move  2:attack \n";
            cin>>choice;
            if(choice==1)
            {
                chessboard[player2x][player2y]->move();
                break;
            }
            else if(choice==2)
            {
                chessboard[player2x][player2y]->attack();
                break;
            }
            else
            continue;
                    }
                if(bk.getcheckbit()==1)
                {
                    int x;int y;
                    bk.getposition(x,y);
                    if(bk.ischeckisstillon(x,y))
                    {
                        cout<<"white wins\n";
                        exit(0);
                    }
                    else
                    bk.resetcheckbit();
                }
                     break;//to give another player chance
        }

    }
    else if(chessboard[player2x][player2y]->noofattackpos)
    {
        while(2){
        cout<<"1:attack\n";
        cin>>choice;
        if(choice==1)
        {
            chessboard[player2x][player2y]->attack();
            break;
        }
        else
        continue;
        }
         if(bk.getcheckbit()==1)
                {
                    int x;int y;
                    bk.getposition(x,y);
                    if(bk.ischeckisstillon(x,y))
                    {
                        cout<<"white wins\n";
                        exit(0);
                    }
                    else
                    bk.resetcheckbit();
                }
         break;//to give another player chance
    }
    else if(chessboard[player2x][player2y]->noofmovepos)
    {
        while(2){
        cout<<"1:move\n";
        cin>>choice;
        if(choice==1)
        {
            chessboard[player2x][player2y]->move();
            break;
        }
        else
        continue;
        }
         if(bk.getcheckbit()==1)
                {
                    int x;int y;
                    bk.getposition(x,y);
                    if(bk.ischeckisstillon(x,y))
                    {
                        cout<<"white wins\n";
                        exit(0);
                    }
                    else
                    bk.resetcheckbit();
                }
         break;//to give another player chance
    }
    else
    {
        cout<<"No position to move\nNo position to attack\n";
    }

}
display();
wk.getposition(whitecurposx,whitecurposy);
if(wk.ischeckisstillon(whitecurposx,whitecurposy))
{
    wk.setcheckbit();
    cout<<"white king "<<player1<<" save ur self,ur checked from "<<player2<<"\n";
}
 bk.getposition(blackcurposx,blackcurposy);//for testing allowing own killing
  if(bk.ischeckisstillon(blackcurposx,blackcurposy))
  {
      bk.setcheckbit();
      cout<<player2<<",u ur self responsible\n";
      cout<<player1<<" wins\n";
      exit(0);
  }
}
}
