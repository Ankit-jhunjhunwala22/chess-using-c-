#include "black.h"
extern Base *chessboard[8][8];
int black::whiteclasscount=16;
int black::typeofplayer=0;//using 0 as sign to indicate black player
int black::checkbit=0;
int black::getcheckbit()
{
    return black::checkbit;
}
void black::setcheckbit()
{
    black::checkbit=1;
}
void black::resetcheckbit()
{
    black::checkbit=0;
}
int black:: givemetheplayer()
{
      cout<<"currently in blackclass\n";
      return -1;
}
void black::findpossiblelocationtomoveorattack()
{
    cout<<"currently in blackclass\n";
}
void black::attack()
{
     cout<<"currently in blackclass\n";
}
int black::getwhiteclasscount()
{
     return black::whiteclasscount;
}
void black::decrementwhitecount()
{
    black::whiteclasscount--;
}

void black::move()
{
    cout<<"currently in blackclass\n";
}
int black::givetypeofplayer()
{
    return black::typeofplayer;

}
void black::setposition(int x,int y)
{
    posx=x;
    posy=y;
}
int black::isuserinputtomoveisvalid(int a,int b)
{
     for(int i=0;i<noofmovepos;i++)
    {
        if(a==possiblemove[i].x && b==possiblemove[i].y) return 1;
    }
    return 0;
}
int black::isuserinputtoattackisvalid(int a,int b)
{
    for(int i=0;i<noofattackpos;i++)
    {
        if(a==possibleattack[i].x && b==possibleattack[i].y) return 1;
    }
    return 0;
}
int black::ischeckisstillon(int x,int y)
{
    int noofpossibleattack=0;
    int curx;
    int cury;
    //north
    curx=x-1;
    cury=y;
    while(curx>=0 )
    {
            if(chessboard[curx][cury]==NULL)
            {
                curx=curx-1;
                if(curx<0)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==203)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }
    }
    //north east
    curx=x-1;
    cury=y+1;
    while((curx>=0&&cury<=7) )
    {
                 if( chessboard[curx][cury]==NULL)
            {
                curx=curx-1;
                cury=cury+1;
                if(curx<0 || cury>7)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==202||chessboard[curx][cury]->givemetheplayer()==200 || chessboard[curx][cury]->givemetheplayer()==204)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
    //east
    curx=x;
    cury=y+1;
     while(cury<=7 )
    {
                 if( chessboard[curx][cury]==NULL)
            {
                cury=cury+1;
                if(cury>7)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==203)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
//south-east
curx=x+1;
cury=y+1;
while((curx<=7&&cury<=7))
    {
                 if(chessboard[curx][cury]==NULL)
            {
                curx=curx+1;
                cury=cury+1;
                if(curx>7 || cury>7)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==202|| chessboard[curx][cury]->givemetheplayer()==204)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
//south
curx=x;
cury=y-1;
 while(cury>=0)
    {
                 if( chessboard[curx][cury]==NULL)
            {
                cury=cury-1;
                if(cury<7)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==203)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
//south-west
curx=x+1;
cury=y-1;
while((curx<=7&&cury>=0) )
    {
                 if( chessboard[curx][cury]==NULL)
            {
                curx=curx+1;
                cury=cury-1;
                if(curx>7 || cury>7)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==202|| chessboard[curx][cury]->givemetheplayer()==204)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
//west
curx=x-1;
cury=y;
 while(curx>=0)
    {
                 if(  chessboard[curx][cury]==NULL)
            {
                curx=curx-1;
                if(curx<0)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==203)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
//north-west
curx=x-1;
cury=y-1;
while((curx>=0&&cury>=0) )
    {
                 if(chessboard[curx][cury]==NULL)
            {
                curx=curx-1;
                cury=cury-1;
                if(curx<0 || cury<0)break;
            }
            else if(chessboard[curx][cury]!=NULL && chessboard[curx][cury]->givetypeofplayer()==0)
            {
                break;
            }
            else if(chessboard[curx][cury]->givemetheplayer()==202||chessboard[curx][cury]->givemetheplayer()==200 || chessboard[curx][cury]->givemetheplayer()==204)
            {
               noofpossibleattack=noofpossibleattack+1;
               break;
            }
            else
            {
                break;
            }

    }
    //checking against white horse
    //north
    if(x-2>=0)
    {
        if(y-1>=0 && chessboard[x-2][y-1]!=NULL && chessboard[x-2][y-1]->givemetheplayer()==205)
        {
            noofpossibleattack=noofpossibleattack+1;
        }
        else if(y+1<=7&&chessboard[x-2][y+1]!=NULL && chessboard[x-2][y+1]->givemetheplayer()==205)
        {
            noofpossibleattack=noofpossibleattack+1;
        }
    }
    //east
    if(y+2<=7)
    {
        if(x-1>=0 && chessboard[x-1][y+2]!=NULL &&chessboard[x-1][y+2]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }
       else if(x+1<=7 && chessboard[x+1][y+2]!=NULL &&chessboard[x+1][y+2]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }
    }
    //south
    if(x+2<=7)
    {
         if(y-1>=0 && chessboard[x+2][y-1]!=NULL &&chessboard[x+2][y-1]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }
       else if(y+1<=7 && chessboard[x+2][y+1]!=NULL &&chessboard[x+2][y+1]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }

    }
    //west
    if(y-2>=0)
    {
        if(x-1>=0 &&chessboard[x-1][y-2]!=NULL && chessboard[x-1][y-2]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }
       else if(x+1<=7 &&chessboard[x+1][y-2]!=NULL && chessboard[x+1][y-2]->givemetheplayer()==205)
       {
          noofpossibleattack=noofpossibleattack+1;
       }
    }
    if(noofpossibleattack)
        return noofpossibleattack;
    else
        return 0;
}
