//
// Created by px on 7/12/2019.
//

#ifndef COMMAND_H
#define COMMAND_H

#include<string>

class CommandBase{
protected:
    std::string Para_Path;
public:
    CommandBase();
    virtual void SetParameters(const std::string path);
    virtual void Exec() = 0;
};
#endif //COMMAND_H
