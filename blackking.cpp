#include "blackking.h"
extern Base *chessboard[8][8];
void blackking::getposition(int &a,int &b)
{
    a=posx;
    b=posy;
}
blackking::blackking()
{
oneownsmovement=0;
}
int blackking::givemetheplayer()
{
    return 101;
}

void blackking::findpossiblelocationtomoveorattack()
{
    int j=0,i=0;
    if(posx-1 >= 0)
    {
        if(chessboard[posx-1][posy]==NULL)
        {
            possiblemove[j].x=posx-1;
            possiblemove[j].y=posy;
            j++;
        }
        else if(chessboard[posx-1][posy]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx-1;
              possibleattack[i].y=posy;
              i++;


        }
    }
    if(posx-1 >=0 && posy-1>=0)
    {
        if(chessboard[posx-1][posy-1]==NULL)
        {
            possiblemove[j].x=posx-1;
            possiblemove[j].y=posy-1;
            j++;
        }
         else if(chessboard[posx-1][posy-1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx-1;
              possibleattack[i].y=posy-1;
              i++;


        }
    }
    if(posy-1 >=0 )
    {
        if(chessboard[posx][posy-1] == NULL)
        {
            possiblemove[j].x=posx;
            possiblemove[j].y=posy-1;
            j++;
        }
         else if(chessboard[posx][posy-1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx;
              possibleattack[i].y=posy-1;
              i++;


        }
    }
    if(posx+1 <=7 && posy-1 >=0)
    {
        if(chessboard[posx+1][posy-1]==NULL)
        {
            possiblemove[j].x=posx+1;
            possiblemove[j].y=posy-1;
            j++;
        }
        else if(chessboard[posx+1][posy-1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx+1;
              possibleattack[i].y=posy-1;
              i++;
        }
    }
    if(posx+1 <=7)
    {
        if(chessboard[posx+1][posy]==NULL)
        {
            possiblemove[j].x=posx+1;
            possiblemove[j].y=posy;
            j++;
        }
        else if(chessboard[posx+1][posy]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx+1;
              possibleattack[i].y=posy;
              i++;
        }
    }
    if(posx+1 <=7 && posy+1 <=7)
    {
        if(chessboard[posx+1][posy+1]==NULL)
        {
            possiblemove[j].x=posx+1;
            possiblemove[j].y=posy+1;
            j++;
        }
        else if(chessboard[posx+1][posy+1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx+1;
              possibleattack[i].y=posy+1;
              i++;
        }
    }
     if( posy+1 <=7)
    {
        if(chessboard[posx][posy+1]==NULL)
        {
            possiblemove[j].x=posx;
            possiblemove[j].y=posy+1;
            j++;
        }
        else if(chessboard[posx][posy+1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx;
              possibleattack[i].y=posy+1;
              i++;
        }
    }
     if(posx-1 >=0 && posy+1 <=7)
    {
        if(chessboard[posx-1][posy+1]==NULL)
        {
            possiblemove[j].x=posx-1;
            possiblemove[j].y=posy+1;
            j++;
        }
        else if(chessboard[posx-1][posy+1]->givetypeofplayer()==1)
        {

              possibleattack[i].x=posx-1;
              possibleattack[i].y=posy+1;
              i++;


        }
    }
    noofmovepos=j;
    if(noofmovepos>0)
    {
        cout<<"possible location to move\n";
        for(int k=0;k<noofmovepos;k++)
        {
            cout<<"( "<<possiblemove[k].x<<","<<possiblemove[k].y<<" )\n";
        }
    }
    else
cout<<"No location to move from the blackking at ("<<posx<<","<<posy<<")\n";

    noofattackpos=i;
     if(noofattackpos>0)
    {
        cout<<"\npossible location to attack\n";
        for(int k=0;k<noofattackpos;k++)
        {
            cout<<"( "<<possibleattack[k].x<<","<<possibleattack[k].y<<" )\n";
        }
    }
    else
    cout<<"No location to attack from the blackking at ("<<posx<<","<<posy<<")\n";
}
void blackking::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"\nenter positions to move from the blackking\n";
    while(2){
                cin>>usrx;
                cin>>usry;
                if(isuserinputtomoveisvalid(usrx,usry))
                    {

                    chessboard[usrx][usry]=chessboard[posx][posy];
                    chessboard[posx][posy]=NULL;
                    posx=usrx;
                    posy=usry;
                    oneownsmovement++;
                    break;
                    }
                else
                    {
                    cout<<"please enter valid input\n";
                    }
                }
    }
else
    {
        cout<<"no positions to move\n";
    }
}
void blackking::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"\n enter positions to attack from the blackking\n";
    while(2){
                cin>>usrx;
                cin>>usry;
                if(isuserinputtoattackisvalid(usrx,usry))
                    {
                    chessboard [usrx][usry]=chessboard[posx][posy];
                    chessboard[posx][posy]=NULL;
                    posx=usrx;
                    posy=usry;
                    oneownsmovement++;
                    decrementwhitecount();
                    break;
                    }
                else
                    {
                    cout<<"please enter valid input\n";
                    }
                }
        }
    else
        {
            cout<<"no positions to attack\n";
        }


}
