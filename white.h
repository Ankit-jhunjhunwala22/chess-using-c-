#ifndef WHITE_H
#define WHITE_H
#include "base.h"
class white:public Base
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
    static int blackclasscount;
    static int checkbit;
    int oneownsmovement;
   public:
   int getcheckbit();
   void setcheckbit();
   void resetcheckbit();
   int ischeckisstillon(int x,int y);
   void decrementblackcount();
   int getblackclasscount();
   void attack();
   void move();
   int givetypeofplayer();
   void findpossiblelocationtomoveorattack();
   int givemetheplayer();
   void setposition(int x,int y);
    int isuserinputtomoveisvalid(int a,int b);
    int isuserinputtoattackisvalid(int a,int b);
};
#endif // WHITE_H
