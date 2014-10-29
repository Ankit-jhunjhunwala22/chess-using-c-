#ifndef BLACK_H
#define BLACK_H
#include "base.h"
class black:public Base
{
        protected:
          struct {
    int x;
    int y;
    }possibleattack[30];

    struct {
    int x;
    int y;
    }possiblemove[30];
        int posx;
        int posy;
    static int typeofplayer;
    static int whiteclasscount;
    static int checkbit;
    int oneownsmovement;
       public:
   int getcheckbit();
   void setcheckbit();
   void resetcheckbit();
   int ischeckisstillon(int x,int y);
   void decrementwhitecount();
   int getwhiteclasscount();
   void attack();
   void move();
   int givetypeofplayer();
   int givemetheplayer();
   void findpossiblelocationtomoveorattack();
   void setposition(int x,int y);
   int isuserinputtomoveisvalid(int a,int b);
   int isuserinputtoattackisvalid(int a,int b);
};
#endif // BLACK_H
