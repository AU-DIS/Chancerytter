#ifndef __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_EXP3_CPP_
#define __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_EXP3_CPP_

#include "../interfaces/single_policy.h"

class Exp3: public SinglePolicy {
    public:
    Exp3() {};
    int choose() {
        return 0;
    }
    void give_reward(int armid, double reward) {
        
    }
    std::string get_policy_name() {
        return "exp3";
    }
};

#endif // __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_EXP3_CPP_