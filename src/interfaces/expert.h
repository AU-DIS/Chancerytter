#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERT_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERT_H_

#include <vector>

class Expert {
    public:
    virtual ~Expert() = default;
    virtual std::vector<double> get_advise(int round) = 0;

};

#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERT_H_ _id(id), _nbarms(nbarms), _mod(mod)