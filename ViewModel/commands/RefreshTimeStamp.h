//
// Created by px on 7/14/2019.
//

#ifndef REFRESHTIMESTAMP_H
#define REFRESHTIMESTAMP_H

#include "../../common/Command.h"

class ViewModel;
class RefreshTimeStamp : public  CommandBase{
private:
    int StampTime;
    ViewModel *PtrViewModel;
public:
    RefreshTimeStamp(ViewModel *ptr);
    ~RefreshTimeStamp()= default;
    virtual void Exec();
    virtual void SetParameters(int stamptime);
};


#endif //REFRESHTIMESTAMP_H