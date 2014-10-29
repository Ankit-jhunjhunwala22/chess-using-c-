#include "whiteuut.h"
#include "blackking.h"
#include <stdlib.h>
extern blackking bk;
extern Base *chessboard[8][8];
whiteuut::whiteuut()
{
   oneownsmovement=0;
northeastcountertomove=0;
southeastcountertomove=0;
southwestcountertomove=0;
northwestcountertomove=0;
northeastcountertoattack=0;
southeastcountertoattack=0;
southwestcountertoattack=0;
northwestcountertoattack=0;
}
int whiteuut::givemetheplayer()
{
return 204;
}
void whiteuut::findpossiblelocationtomoveorattack()
{
int i,j;
i=j=0;
int curx;
int cury;
curx=posx-1;
cury=posy;

northeastcountertomove=0;
northeastcountertoattack=0;
//for north-east direction
curx=posx-1;
cury=posy+1;
while(curx >=0 && cury <=7)
    {
        if(chessboard[curx][cury]==NULL)
        {
            possiblemove[i].x=curx;
            possiblemove[i++].y=cury;
            northeastcountertomove++;
            curx=curx-1;
            cury=cury+1;
            if(curx <0 || cury >7) break;
        }
     else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                possibleattack[j].x=curx;
                possibleattack[j++].y=cury;
                northeastcountertoattack++;
                break;
            }
        else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
            {
                break;
            }
    }
southeastcountertomove=0;
southeastcountertoattack=0;
//for south-east diagnal
curx=posx+1;
cury=posy+1;
while(curx<=7 && cury <=7)
{
    if(chessboard[curx][cury]==NULL)
    {
        possiblemove[i].x=curx;
        possiblemove[i++].y=cury;
        southeastcountertomove++;
        curx=curx+1;
        cury=cury+1;
        if(curx >7 || cury >7)break;
    }
   else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        southeastcountertoattack++;
        break;
    }
    else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        break;
    }

}

//for south-west diagnal
southwestcountertomove=0;
southwestcountertoattack=0;
curx=posx+1;
cury=posy-1;
while(curx<=7 && cury>=0)
{
if(chessboard[curx][cury]==NULL){
    possiblemove[i].x=curx;
    possiblemove[i++].y=cury;
    southwestcountertomove++;
    curx++;
    cury--;
    if(curx>7 || cury<0)break;          }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        southwestcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        break;
    }
}//for nort-west disgnal
northwestcountertomove=0;
northwestcountertoattack=0;
curx=posx-1;
cury=posy-1;
while(cury>=0 && curx>=0)
{
if(chessboard[curx][cury]==NULL){
    possiblemove[i].x=curx;
    possiblemove[i++].y=cury;
    northwestcountertomove++;
    cury--;
    curx--;
    if(cury<0 || curx<0)break;          }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        northwestcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        break;
    }
}
noofattackpos=j;
noofmovepos=i;
if(noofmovepos)
    {
        int i=0;
        int j=0;
        int tem;
        cout<<"possible location to move from the whiteuut at("<<posx<<","<<posy<<")\n";

        if(northeastcountertomove){
        cout<<"\nnorth-east::";
        for(j=i,tem=j;j<tem+northeastcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
                                 }

        if(southeastcountertomove){
        cout<<"\nsouth-east::";
        for(j=(i==0?j:i),tem=j;j<tem+southeastcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }

        if(southwestcountertomove){
        cout<<"\nsouth-west::";
        for(j=(i==0?j:i),tem=j;j<tem+southwestcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }

        if(northwestcountertomove)
        {
            cout<<"\nnorth-west::";
             for(j=(i==0?j:i),tem=j;j<tem+northwestcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }
    }
else
    cout<<"No location to move from the whiteuut at ("<<posx<<","<<posy<<")\n";
if(noofattackpos)
    {

        int i=0;int j=0;
        i=noofattackpos;
        cout<<"\npossible location to attack\n";

        if(northeastcountertoattack){
        cout<<"north-east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;}

        if(southeastcountertoattack)
        {
        cout<<"south-east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;

        if(southwestcountertoattack)
        {
        cout<<"south-west:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;


        if(northwestcountertoattack)
        {
        cout<<"north-west:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;

    }
else
   cout<<"\nNo location to attack from the whiteuut at ("<<posx<<","<<posy<<")\n";
}
void whiteuut::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"\nenter positions to move from the whiteuut at ("<<posx<<","<<posy<<")\n";
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
void whiteuut::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"\nenter positions to attack from whiteuut at ("<<posx<<","<<posy<<")\n";
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
