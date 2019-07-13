//
// Created by px on 7/12/2019.
//

#ifndef OPENFILECOMMAND_H
#define OPENFILECOMMAND_H

#include "../../common/Command.h"


class ViewModel;

class OpenFileCommand:public CommandBase{
private:
    std::string Para_Path;
    ViewModel *PtrViewModel;
public:
    OpenFileCommand(ViewModel *ptr);
    void Exec() override;
    inline void SetParameters(const std::string path);
};




#endif //OPENFILECOMMAND_H
