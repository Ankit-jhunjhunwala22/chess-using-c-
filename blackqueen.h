#ifndef BLACKQUEEN_H
#define BLACKQUEEN_H
#include "black.h"
class blackqueen:public black
{
    private:
int northcountertomove,northeastcountertomove,eastcountertomove,southeastcountertomove,southcountertomove,southwestcountertomove,westcountertomove,northwestcountertomove;
int northcountertoattack;
int northeastcountertoattack;
int eastcountertoattack;
int southeastcountertoattack;
int southcountertoattack;
int southwestcountertoattack;
int westcountertoattack;
int northwestcountertoattack;
    public:
        blackqueen();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};

#endif // BLACKQUEEN_H
