#include "blackelephant.h"
extern Base *chessboard[8][8];
blackelephant::blackelephant()
{
oneownsmovement=0;
northcountertomove=0;
eastcountertomove=0;
southcountertomove=0;
westcountertomove=0;
}
int blackelephant::givemetheplayer()
{
return 103;
}
void blackelephant::findpossiblelocationtomoveorattack()
{
int i,j;
i=j=0;
int curx;
int cury;
curx=posx-1;
cury=posy;
//for north direction
northcountertomove=0;
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
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}

    eastcountertomove=0;
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
        break;
    }
    else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }

}

//for south direction
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
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}

//for west
westcountertomove=0;
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
        break;
    }
else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
    {
        break;
    }
}
noofattackpos=j;
noofmovepos=i;
cout<<noofattackpos<<"\n"<<noofmovepos<<"\n"<<westcountertomove<<"\n";
if(noofmovepos)
    {
        int i=0;
        int j=0;
        int tem;
        cout<<"possible location to move from the black elephant at("<<posx<<","<<posy<<")\n";

        if(northcountertomove){
        cout<<"north::";
        for(j=0;j<northcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";}

        if(eastcountertomove){
        cout<<"\neast:: ";
        for(i=(j==0?i:j),tem=i;i<tem+eastcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";}

        if(southcountertomove){
        cout<<"\nsouth::";
        for(j=(i==0?j:i),tem=j;j<tem+southcountertomove;j++)
                cout<<"("<<possiblemove[j].x<<","<<possiblemove[j].y<<") ";
        }

        if(westcountertomove){
        cout<<"\nwest::";
        for(i=(j==0?i:j),tem=i;i<tem+westcountertomove;i++)
                cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
    }
else
    cout<<"No location to move from the blackelephant at ("<<posx<<","<<posy<<")\n";
if(noofattackpos)
    {

        int i=0;int j=0;
        i=noofattackpos;
        cout<<"\npossible location to attack\n";
        cout<<"north:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;

        if(i)
        {
        cout<<"east:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;

        if(i)
        {
        cout<<"south:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;

        if(i)
        {
        cout<<"west:: "<<"("<<possibleattack[j].x<<","<<possibleattack[j].y<<")";
        j++;
        i--;
        }
        else
        return;


    }
else
   cout<<"\nNo location to attack from the blackelephant at ("<<posx<<","<<posy<<")\n";
}

void blackelephant::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"\nenter positions to move from the blackelephant ("<<posx<<","<<posy<<")\n";
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
void blackelephant::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"\nenter positions to attack from blackelephant at("<<posx<<","<<posy<<")\n";
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
