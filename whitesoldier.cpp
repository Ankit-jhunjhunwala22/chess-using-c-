#include "whitesoldier.h"
#include "blackking.h"
#include <stdlib.h>
extern blackking bk;
extern whitesoldier w[8];
extern Base *chessboard[8][8];
 int whitesoldier::givemetheplayer()
 {
     return 200;
 }
whitesoldier::whitesoldier()
{
    oneownsmovement=0;
    noofattackpos=0;
    noofmovepos=0;
}
void whitesoldier::findpossiblelocationtomoveorattack()
{
    int j=0;
    int i=0;
    if(posx+1<=7){
if(chessboard[posx+1][posy] == NULL)
    {
    possiblemove[j].x=posx+1;
    possiblemove[j].y=posy;
    j++;
   if(chessboard[posx+2][posy] == NULL && oneownsmovement==0)
    {
    possiblemove[j].x=posx+2;
    possiblemove[j].y=posy;
    j++;
    }
    }
    }
    noofmovepos=j;
    if(noofmovepos>0)
    {
        cout<<"possible location to move from the whitesoldier at ("<<posx<<","<<posy<<")\n";
        for(int k=0;k<noofmovepos;k++)
        {
            cout<<"( "<<possiblemove[k].x<<","<<possiblemove[k].y<<" )\n";
        }
    }
    else
    cout<<"No location to move from the whitesoldier at ("<<posx<<","<<posy<<")\n";
    if((posx+1<=7&&posy-1>=0)&&chessboard[posx+1][posy-1]!=NULL)
    {
        if(chessboard[posx+1][posy-1]->givetypeofplayer()!=chessboard[posx][posy]->givetypeofplayer())
        {
            possibleattack[i].x=posx+1;
            possibleattack[i].y=posy-1;
            i++;
        }

    }
    if((posx+1<=7&&posy+1<=7)&&chessboard[posx+1][posy+1]!=NULL)
    {
        if(chessboard[posx+1][posy+1]->givetypeofplayer()!=chessboard[posx][posy]->givetypeofplayer())
        {
            possibleattack[i].x=posx+1;
            possibleattack[i].y=posy+1;
            i++;
        }
    }
    noofattackpos=i;
     if(noofattackpos>0)
    {
        cout<<"\npossible location to attack from the whitesoldier at ("<<posx<<","<<posy<<")\n";
        for(int k=0;k<noofattackpos;k++)
        {
            cout<<"( "<<possibleattack[k].x<<","<<possibleattack[k].y<<" )\n";
        }
    }
    else
    cout<<"No location to attack from the whitesoldier at ("<<posx<<","<<posy<<")\n";
}
void whitesoldier::attack(){
            if(noofattackpos)
            {
                int usrx,usry;
                cout<<"enter one of the above cordinates to attack from the whitesoldier at ("<<posx<<","<<posy<<")\n";
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
                cout<<"no possible location to attack from the current position\n";
            }

        }
void whitesoldier::move(){
            if(noofmovepos)
            {
                int usrx,usry;
                cout<<"enter one of the above cordinates to move from the whitesoldier at ("<<posx<<","<<posy<<")\n";
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
                cout<<"no possible location to move from the current position\n";
            }

        }

