#ifndef __REPS_CHANCERYTTER_SRC_EXPERTS_MOD_EXPERT_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERTS_MOD_EXPERT_CPP_

#include "../interfaces/expert.h"

class ModExpert: public Expert {
    public:
    ModExpert(int id, int nbarms, int mod) : _id(id), _nbarms(nbarms), _mod(mod) {
        advise = std::vector<double>(_nbarms, 0);
        for (int i = 0; i < _nbarms; i++) {
            advise[i] = i%_mod;
        }
    }
    std::vector<double> get_advise(int round) {
        _current_round = round;
        return std::vector<double>(_nbarms, 0);//advise;
    }
    private:
    std::vector<double> advise; 
    int _id;
    int _mod;
    int _nbarms;
    int _current_round = 0;
};


#endif // __REPS_CHANCERYTTER_SRC_EXPERTS_MOD_EXPERT_CPP_