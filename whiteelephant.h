#ifndef WHITEELEPHANT_H
#define WHITEELEPHANT_H
#include "white.h"

class whiteelephant:public white
{
    private:
int northcountertomove,eastcountertomove,southcountertomove,westcountertomove;
    public:

        whiteelephant();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};
#endif // WHITEELEPHANT_H
