#ifndef WHITEQUEEN_H
#define WHITEQUEEN_H
#include "white.h"
class whitequeen:public white
{
        private:
    int northcountertomove,northeastcountertomove,eastcountertomove;
    int southeastcountertomove,southcountertomove,southwestcountertomove;
    int westcountertomove,northwestcountertomove;
    int northcountertoattack;
int northeastcountertoattack;
int eastcountertoattack;
int southeastcountertoattack;
int southcountertoattack;
int southwestcountertoattack;
int westcountertoattack;
int northwestcountertoattack;
    public:
        whitequeen();
       int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};

#endif // WHITEQUEEN_H
