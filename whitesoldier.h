#ifndef WHITESOLDIER_H
#define WHITESOLDIER_H

#include "white.h"
//#include "white.cpp"


class whitesoldier:public white
{

    public:
        whitesoldier();
        int givemetheplayer();
        void findpossiblelocationtomoveorattack();
        void attack();
        void move();
        /*int isuserinputtomoveisvalid(int a,int b);
        int isuserinputtoattackisvalid(int a,int b);*/
};

#endif // WHITESOLDIER_H
