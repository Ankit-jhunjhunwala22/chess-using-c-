#ifndef BASE_H
#define BASE_H
#include <iostream>
using namespace std;
class Base
{
   public:
   int noofattackpos;
   int noofmovepos;
   virtual void findpossiblelocationtomoveorattack()=0;
   virtual void attack()=0;
   virtual void move()=0;
   virtual int givetypeofplayer()=0;
   virtual int getcheckbit()=0;
   virtual void setcheckbit()=0;
   virtual int ischeckisstillon(int x,int y)=0;
   /*
   black:-0
   white:-1
   */
   virtual int givemetheplayer()=0;
   /*
   200:-whitesoldier
   201:whiteking
   202:whitequeen
   100:blacksoldier
   101:blackking
   102:blackqueen
   103:blackelephant
   203:whiteelephant
   104:blackuut
   204:whiteuut
   105:blackhorse
   205:whitehorse
   */
   virtual void setposition(int x,int y)=0;//to set initial position to its position on chessboard
};

#endif // BASE_H
