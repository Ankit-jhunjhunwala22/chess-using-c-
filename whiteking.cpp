#include "whiteking.h"
#include "blackking.h"
#include <stdlib.h>
extern Base *chessboard[8][8];
extern blackking bk;
whiteking::whiteking()
{
    oneownsmovement=0;
}
void whiteking::getposition(int &a,int &b)
{
    a=posx;
    b=posy;
}
int whiteking::givemetheplayer()
{
    return 201;
}
void whiteking::findpossiblelocationtomoveorattack()
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
        else if(chessboard[posx-1][posy]->givetypeofplayer()==0)
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
         else if(chessboard[posx-1][posy-1]->givetypeofplayer()==0)
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
         else if(chessboard[posx][posy-1]->givetypeofplayer()==0)
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
        else if(chessboard[posx+1][posy-1]->givetypeofplayer()==0)
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
        else if(chessboard[posx+1][posy]->givetypeofplayer()==0)
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
        else if(chessboard[posx+1][posy+1]->givetypeofplayer()==0)
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
        else if(chessboard[posx][posy+1]->givetypeofplayer()==0)
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
        else if(chessboard[posx-1][posy+1]->givetypeofplayer()==0)
        {

              possibleattack[i].x=posx-1;
              possibleattack[i].y=posy+1;
              i++;


        }
    }
    noofmovepos=j;
    if(noofmovepos>0)
    {
        cout<<"possible location to move from the whiteking at ("<<posx<<","<<posy<<")\n";;
        for(int k=0;k<noofmovepos;k++)
        {
            cout<<"( "<<possiblemove[k].x<<","<<possiblemove[k].y<<" )\n";
        }
    }
    else
cout<<"No location to move from the whiteking at ("<<posx<<","<<posy<<")\n";

    noofattackpos=i;
     if(noofattackpos>0)
    {
        cout<<"\npossible location to attack from the whiteking at ("<<posx<<","<<posy<<")\n";
        for(int k=0;k<noofattackpos;k++)
        {
            cout<<"( "<<possibleattack[k].x<<","<<possibleattack[k].y<<" )\n";
        }
    }
    else
    cout<<"No location to attack from the whiteking at ("<<posx<<","<<posy<<")\n";
}
void whiteking::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"enter above coordinates to move\n";
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
void whiteking::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"enter above cordinates to attack";
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
                    decrementblackcount();
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
