#ifndef BLACKKING_H
#define BLACKKING_H
#include "black.h"
class blackking:public black
{

    public:
        blackking();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
        void getposition(int &a,int &b);

};
#endif // BLACKKING_H
