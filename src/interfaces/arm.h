#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_ARM_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_ARM_H_

class Arm
{
    public:
        virtual ~Arm() = default;
        virtual double pull() = 0;
        virtual void setID(int) = 0;
        virtual void setRound(int) = 0;
};

#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_ARM_H_