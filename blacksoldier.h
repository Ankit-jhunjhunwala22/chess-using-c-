#ifndef BLACKSOLDIER_H
#define BLACKSOLDIER_H
#include "black.h"
class blacksoldier:public black
{


    public:
        blacksoldier();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void attack();
        void move();

};

#endif // BLACKSOLDIER_H
