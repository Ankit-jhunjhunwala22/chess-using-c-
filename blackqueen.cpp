#include "blackqueen.h"
extern Base *chessboard[8][8];
blackqueen::blackqueen()
{
oneownsmovement=0;
northcountertomove=0;
northeastcountertomove=0;
eastcountertomove=0;
southeastcountertomove=0;
southcountertomove=0;
southwestcountertomove=0;
westcountertomove=0;
northwestcountertomove=0;
northcountertoattack=0;
northeastcountertoattack=0;
eastcountertoattack=0;
southeastcountertoattack=0;
southcountertoattack=0;
southwestcountertoattack=0;
westcountertoattack=0;
northwestcountertoattack=0;
}
int blackqueen::givemetheplayer()
{
return 102;
}
void blackqueen::findpossiblelocationtomoveorattack()
{
int i,j;
i=j=0;
int curx;
int cury;
curx=posx-1;
cury=posy;
//for north direction
northcountertomove=0;
northcountertoattack=0;
while(curx>=0)
{
if(chessboard[curx][cury]==NULL){
    possiblemove[i].x=curx;
    possiblemove[i++].y=cury;
    northcountertomove++;
    curx--;
    if(curx<0)break;          }
else if((chessboard[curx][cury]!=NULL) && (chessboard[curx][cury]->givetypeofplayer()==1))
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        northcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}
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
     else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
            {
                possibleattack[j].x=curx;
                possibleattack[j++].y=cury;
                northeastcountertoattack++;
                break;
            }
        else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
    }
    eastcountertomove=0;
    eastcountertoattack=0;
//for east direction
cury=posy+1;
curx=posx;
while(cury <=7 )
{
    if(chessboard[curx][cury]==NULL)
    {
        possiblemove[i].x=curx;
        possiblemove[i++].y=cury;
        eastcountertomove++;
        cury=cury+1;
        if(cury >7)break;
    }
    else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        eastcountertoattack++;
        break;
    }
    else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
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
   else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        southeastcountertoattack++;
        break;
    }
    else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }

}
//for south direction
southcountertoattack=0;
southcountertomove=0;
curx=posx+1;
cury=posy;

while(curx<=7)
{
if(chessboard[curx][cury]==NULL){
    possiblemove[i].x=curx;
    possiblemove[i++].y=cury;
    southcountertomove++;
    curx++;
    if(curx>7)break;          }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        southcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
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
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        southwestcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}
//for west
westcountertomove=0;
westcountertoattack=0;
curx=posx;
cury=posy-1;

while(cury>=0)
{
if(chessboard[curx][cury]==NULL){
    possiblemove[i].x=curx;
    possiblemove[i++].y=cury;
    westcountertomove++;
    cury--;
    if(cury<0)break;          }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        westcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}
//for nort-west disgnal
northwestcountertoattack=0;
northwestcountertomove=0;
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
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==1)
    {
        possibleattack[j].x=curx;
        possibleattack[j++].y=cury;
        northwestcountertoattack++;
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
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
        cout<<"possible location to move from the blackqueen\n";
        if(northcountertomove){
        cout<<"north::";
        for(i=0;i<northcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
                              }
        if(northeastcountertomove){
        cout<<"\nnorth-east::";
        for(j=i,tem=j;j<tem+northeastcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
                                 }
        if(eastcountertomove){
        cout<<"\neast:: ";
        cout<<eastcountertomove;
        for(i=(j==0?i:j),tem=i;i<tem+eastcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";}
        if(southeastcountertomove){
        cout<<"\nsouth-east::";
        for(j=(i==0?j:i),tem=j;j<tem+southeastcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }
        if(southcountertomove){
        cout<<"\nsouth::";
        for(i=(j==0?i:j),tem=i;i<tem+southcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
        if(southwestcountertomove){
        cout<<"\nsouth-west::";
        for(j=(i==0?j:i),tem=j;j<tem+southwestcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }
        if(westcountertomove){
        cout<<"\nwest::";
        for(i=(j==0?i:j),tem=i;i<tem+westcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
        if(northwestcountertomove)
        {
            cout<<"\nnorth-west::";
             for(j=(i==0?j:i),tem=j;j<tem+northwestcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }
    }
else
    cout<<"No location to move from the blackqueen at ("<<posx<<","<<posy<<")\n";
if(noofattackpos)
    {

        int i=0;int j=0;
        i=noofattackpos;
        cout<<"\npossible location to attack\n";
       if(northcountertoattack){
        cout<<"north:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
       }
        if(northeastcountertoattack)
        {
        cout<<"north-east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;
        if(eastcountertoattack)
        {
        cout<<"east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;
        if(southeastcountertoattack)
        {
        cout<<"south-east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;
        if(southcountertoattack)
        {
        cout<<"south:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
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
        if(westcountertoattack)
        {
        cout<<"west:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
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
   cout<<"\nNo location to attack from the blackqueen at ("<<posx<<","<<posy<<")\n";
}
void blackqueen::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"\nenter positions to move from the blackqueen\n";
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
void blackqueen::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"\nenter positions to attack from blackqueen\n";
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
