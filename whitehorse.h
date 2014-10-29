#ifndef WHITEHORSE_H
#define WHITEHORSE_H

#include "white.h"

class whitehorse:public white
{
int northcountertomove,eastcountertomove,southcountertomove,westcountertomove;
int northcountertoattack;
int eastcountertoattack;
int southcountertoattack;
int westcountertoattack;
    public:
        whitehorse();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};


#endif // whiteHORSE_H
