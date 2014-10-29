#ifndef BLACKUUT_H
#define BLACKUUT_H
#include "black.h"
class blackuut:public black
{
   private:
int northeastcountertomove,southeastcountertomove,southwestcountertomove,northwestcountertomove;
int northeastcountertoattack,southeastcountertoattack,southwestcountertoattack,northwestcountertoattack;
    public:
        blackuut();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void move();
        void attack();
};

#endif // BLACKUUT_H
