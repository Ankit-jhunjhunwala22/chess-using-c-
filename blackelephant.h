#ifndef BLACKELEPHANT_H
#define BLACKELEPHANT_H
#include "black.h"

class blackelephant:public black
{
    private:
int northcountertomove,eastcountertomove,southcountertomove,westcountertomove;
    public:

        blackelephant();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};

#endif // BLACKELEPHANT_H
