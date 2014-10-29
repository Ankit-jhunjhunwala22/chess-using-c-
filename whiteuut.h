#ifndef WHITEUUT_H
#define WHITEUUT_H
#include "white.h"
class whiteuut:public white
{
   private:
int northeastcountertomove,southeastcountertomove,southwestcountertomove,northwestcountertomove;
int northeastcountertoattack,southeastcountertoattack,southwestcountertoattack,northwestcountertoattack;
    public:
        whiteuut();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};
#endif // WHITEUUT_H
