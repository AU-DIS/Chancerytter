#ifndef __REPS_CHANCERYTTER_SRC_ARMS_MOD2_CPP_
#define __REPS_CHANCERYTTER_SRC_ARMS_MOD2_CPP_

#include "../interfaces/arm.h"

class Mod2Arm: public Arm {
    public:
    Mod2Arm(int id, int round = 0) : _id(id),_round(round) {
    };
    double pull() {
        return _id%2; 
    };
    void setID(int id) {
        _id = id;
    }
    void setRound(int round) {
        _round = round;
    }

    private:
    int _id;
    int _round;
};

#endif // __REPS_CHANCERYTTER_SRC_ARMS_MOD2_CPP_