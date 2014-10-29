#include "blackhorse.h"
extern Base *chessboard[8][8];
blackhorse::blackhorse()
{
    oneownsmovement=0;
    northcountertomove=0;
    eastcountertomove=0;
    southcountertomove=0;
    westcountertomove=0;
   northcountertoattack=0;
   eastcountertoattack=0;
  southcountertoattack=0;
   westcountertoattack=0;
}
int blackhorse::givemetheplayer(){
    return 105;
}
void blackhorse::findpossiblelocationtomoveorattack()
{
    int i,j;
    i=0;
    j=0;
    //for north
    northcountertomove=0;
    northcountertoattack=0;
    if((posx-2>=0 && posy+1<=7) && chessboard[posx-2][posy+1]==NULL)
    {
        northcountertomove++;
        possiblemove[i].x=posx-2;
        possiblemove[i++].y=posy+1;
    }
    else if((posx-2>=0 && posy+1<=7) && chessboard[posx-2][posy+1]->givetypeofplayer()==1)
    {
        northcountertoattack++;
        possibleattack[j].x=posx-2;
        possibleattack[j++].y=posy+1;
    }
    if((posx-2>=0 && posy-1>=0) && chessboard[posx-2][posy-1]==NULL)
    {
        northcountertomove++;
        possiblemove[i].x=posx-2;
        possiblemove[i++].y=posy-1;
    }
    else if((posx-2>=0 && posy-1>=0) && chessboard[posx-2][posy-1]->givetypeofplayer()==1)
    {
        northcountertoattack++;
        possibleattack[j].x=posx-2;
        possibleattack[j++].y=posy-1;
    }

    //for east
    eastcountertoattack=0;
    eastcountertomove=0;
    if((posx-1>=0 && posy+2<=7) && chessboard[posx-1][posy+2]==NULL)
    {
        eastcountertomove++;
        possiblemove[i].x=posx-1;
        possiblemove[i++].y=posy+2;
    }
    else if((posx-1>=0 && posy+2<=7) && chessboard[posx-1][posy+2]->givetypeofplayer()==1)
    {
        eastcountertoattack++;
        possibleattack[j].x=posx-1;
        possibleattack[j++].y=posy+2;
    }
     if((posx+1<=7 && posy+2<=7) && chessboard[posx+1][posy+2]==NULL)
    {
        eastcountertomove++;
        possiblemove[i].x=posx+1;
        possiblemove[i++].y=posy+2;
    }
    else if((posx+1<=7 && posy+2<=7) && chessboard[posx+1][posy+2]->givetypeofplayer()==1)
    {
        eastcountertoattack++;
        possibleattack[j].x=posx+1;
        possibleattack[j++].y=posy+2;
    }
//for south
southcountertoattack=0;
southcountertomove=0;
    if((posx+2<=7 && posy-1>=0) && chessboard[posx+2][posy-1]==NULL)
    {
        southcountertomove++;
        possiblemove[i].x=posx+2;
        possiblemove[i++].y=posy-1;
    }
    else if((posx+2<=7 && posy-1>=0) && chessboard[posx+2][posy-1]->givetypeofplayer()==1)
    {
        southcountertoattack++;
        possibleattack[j].x=posx+2;
        possibleattack[j++].y=posy-1;
    }
    if((posx+2<=7 && posy+1<=7) && chessboard[posx+2][posy+1]==NULL)
    {
        southcountertomove++;
        possiblemove[i].x=posx+2;
        possiblemove[i++].y=posy+1;
    }
    else if((posx+2<=7 && posy+1<=7) && chessboard[posx+2][posy+1]->givetypeofplayer()==1)
    {
        southcountertoattack++;
        possibleattack[j].x=posx+2;
        possibleattack[j++].y=posy+1;
    }
//west
westcountertoattack=0;
westcountertomove=0;
if((posx-1>=0 && posy-2>=0) && chessboard[posx-1][posy-2]==NULL)
    {
        westcountertomove++;
        possiblemove[i].x=posx-1;
        possiblemove[i++].y=posy-2;
    }
    else if((posx-1>=0 && posy-2>=0) && chessboard[posx-1][posy-2]->givetypeofplayer()==1)
    {
        westcountertoattack++;
        possibleattack[j].x=posx-1;
        possibleattack[j++].y=posy-2;
    }
if((posx+1<=7 && posy-2>=0) && chessboard[posx+1][posy-2]==NULL)
    {
        westcountertomove++;
        possiblemove[i].x=posx+1;
        possiblemove[i++].y=posy-2;
    }
    else if((posx+1<=7 && posy-2>=0) && chessboard[posx+1][posy-2]->givetypeofplayer()==1)
    {
        westcountertoattack++;
        possibleattack[j].x=posx+1;
        possibleattack[j++].y=posy-2;
    }
noofattackpos=j;
noofmovepos=i;
if(noofmovepos)
{
    cout<<"\npossible to move from the blackhorse from position at ("<<posx<<","<<posy<<")\n";
    int tem;
    int i;
    i=0;
    if(northcountertomove)
    {
        cout<<"north:: ";
        for(i=0;i<northcountertomove;i++)
        {
            cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
    }
    if(eastcountertomove)
    {
        cout<<"\neast:: ";
        for(i=i,tem=i;i<tem+eastcountertomove;i++)
        {
            cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
    }
    if(southcountertomove)
    {
        cout<<"\nsouth:: ";
        for(i=i,tem=i;i<tem+southcountertomove;i++)
        {
             cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
    }
    if(westcountertomove)
    {
        cout<<"\nwest:: ";
        for(i=i,tem=i;i<tem+westcountertomove;i++)
        {
             cout<<"("<<possiblemove[i].x<<","<<possiblemove[i].y<<") ";
        }
    }
}
else
    cout<<"\nNo possible to move from the blackhorse from position at ("<<posx<<","<<posy<<")\n";

if(noofattackpos)
{
    cout<<"\npossible location to attack from blackhorse at ("<<posx<<","<<posy<<")\n";
    int i;
    i=0;
    if(northcountertoattack)
    { cout<<"north:: ";
        while(2){
        cout<<"("<<possibleattack[i].x<<","<<possibleattack[i].y<<") ";
        i++;
        northcountertoattack--;
        if(!northcountertoattack)break;
        }
    }
    if(eastcountertoattack)
    {
        cout<<"\neast:: ";
        while(2){
        cout<<"("<<possibleattack[i].x<<","<<possibleattack[i].y<<") ";
        i++;
        eastcountertoattack--;
        if(!eastcountertoattack)break;
        }
    }
    if(southcountertoattack)
    {
        cout<<"\nsouth:: ";
        while(2){
        cout<<"("<<possibleattack[i].x<<","<<possibleattack[i].y<<") ";
        i++;
        southcountertoattack--;
        if(!southcountertoattack)break;
        }
    }
    if(westcountertoattack)
    {
        cout<<"\nwest:: ";
        while(2){
        cout<<"("<<possibleattack[i].x<<","<<possibleattack[i].y<<") ";
        i++;
        westcountertoattack--;
        if(!westcountertoattack)break;
        }
    }
}
else
cout<<"\nNo possible location to attack from blackhorse at ("<<posx<<","<<posy<<")\n";

}
void blackhorse::move(){
if(noofmovepos)
    {
    int usrx;
    int usry;
    cout<<"\nenter positions to move from the blackhorse at ("<<posx<<","<<posy<<")\n";
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
void blackhorse::attack(){
    if(noofattackpos)
        {
            int usrx;
            int usry;
            cout<<"\nenter positions to attack from blackhorse at ("<<posx<<","<<posy<<")\n";
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
