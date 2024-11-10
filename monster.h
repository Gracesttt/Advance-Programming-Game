#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Monster{
public:
    int hp;
    Monster(int h):hp(h) {}

    bool alive(){
        return hp>0;
    }

    void takeDmg(int damage){
        hp-=damage;
    }

    bool HvyAtt() {
      int success = rand() % 10;  
      return success < 2; //chanceตีหนัก 20%
    }

    int calAttDmg(){
        return rand()%10+5;  //ดาเมจ5-10
    }

    bool dropPotion(){
      int drop=rand()%10; 
        return drop<7;  //ยาดรอป70%
    }
};

#endif