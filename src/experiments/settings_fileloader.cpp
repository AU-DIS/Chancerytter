#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_

#include "../csv.h"

class SettingsLoader {
    
    csv::CSVReader reader;
    csv::CSVRow current_row;

    public:
    SettingsLoader(std::string path) : reader(path){
    };

    std::vector<std::string> next_row() {
        reader.read_row(current_row);
        return current_row.get_col_names();
    }

    std::string get_bandit() {
        return current_row["bandit"].get();
    }

    int get_rounds() {
        return current_row["rounds"].get<int>();
    }

    //Total number of arms
    int get_nbarms() {
        return current_row["nbarms"].get<int>();
    }

    //Arms to select in every round
    int get_chosarms() {
        return current_row["chosarms"].get<int>();
    }
    
};

#endif // __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_