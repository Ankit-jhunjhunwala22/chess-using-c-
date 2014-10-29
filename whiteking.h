#ifndef WHITEKING_H
#define WHITEKING_H
#include "white.h"
class whiteking:public white
{

    public:

        whiteking();
         void getposition(int &a,int &b);
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();

};



#endif // WHITEKING_H
