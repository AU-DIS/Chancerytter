#ifndef __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_QBL_CPP_
#define __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_QBL_CPP_

#include "../interfaces/single_policy.h"

class QBL: public SinglePolicy {
    public:
    QBL() {};
    int choose() {
        return 0;
    }
    void give_reward(int armid, double reward) {
        
    }
    std::string get_policy_name() {
        return "qbl";
    }

};

#endif // __REPS_CHANCERYTTER_SRC_SINGLEPOLICIES_QBL_CPP_