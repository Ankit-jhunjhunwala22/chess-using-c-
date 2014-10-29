#ifndef BLACKHORSE_H
#define BLACKHORSE_H
#include "black.h"

class blackhorse:public black
{
int northcountertomove,eastcountertomove,southcountertomove,westcountertomove;
int northcountertoattack;
int eastcountertoattack;
int southcountertoattack;
int westcountertoattack;
    public:
        blackhorse();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};

#endif // BLACKHORSE_H
