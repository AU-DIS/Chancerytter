#ifndef __REPS_CHANCERYTTER_SRC_ENVIRONMENTS_MOD2_FIXED_CPP_
#define __REPS_CHANCERYTTER_SRC_ENVIRONMENTS_MOD2_FIXED_CPP_

#include "../interfaces/environment.h"
#include "../interfaces/arm.h"
#include "../interfaces/expert.h"
#include "../arms/mod2.cpp"
#include "../experts/mod_expert.cpp"

#include <vector>
#include <memory>

class Mod2FixedEnvironment: public Environment {
    public:
    Mod2FixedEnvironment(int nbarms, int nbexperts) : _nbarms(nbarms), _nbexperts(nbexperts) {
        arms = std::vector<std::unique_ptr<Arm>>(_nbarms);

        for (int i = 0; i < _nbarms; i++) {
            arms[i] = std::make_unique<Mod2Arm>(i);
        }

        experts = std::vector<std::unique_ptr<Expert>>(_nbexperts);
        for (int i = 0; i < _nbexperts; i++) {
            experts[i] = std::make_unique<ModExpert>(i, _nbarms, 2);
        }
    };
    
    void create_game_matrix(int round) {
        game_matrix = std::vector<std::vector<double>>(_nbarms, std::vector<double>(round, 0));
        for (int a=0; a < _nbarms; a++) {
            _current_round = 0;
            for (int r=0; r < round; r++) {
                game_matrix[a][r] = arms[a]->pull();
            }
        }
    };

    double pull(int armid) {
        _current_round++;
        return arms[armid]->pull();
    }

    double pull_matrix(int armid, int round) {
        return game_matrix[armid][round];
    }

    std::vector<std::vector<double>> get_advise() {
        std::vector<std::vector<double>> advise = std::vector<std::vector<double>>(_nbarms);
        for (int i = 0; i < _nbexperts; i++) {
            advise[i] = experts[i]->get_advise(_current_round);
        }
        return advise;
    }

    private:
    int _current_round = 0;
    int _nbarms;
    int _nbexperts;
    std::vector<std::unique_ptr<Expert>> experts;
    std::vector<std::unique_ptr<Arm>> arms;
    std::vector<std::vector<double>> game_matrix;
};

#endif // __REPS_CHANCERYTTER_SRC_ENVIRONMENTS_MOD2_FIXED_CPP_