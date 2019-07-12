//
// Created by px on 7/12/2019.
//

#ifndef COMMAND_H
#define COMMAND_H

class CommandBase{
protected:
    std::shared_ptr<Parameters> params;
public:
    CommandBase();
    void set_parameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }
    virtual void exec() = 0;
};
#endif //COMMAND_H
