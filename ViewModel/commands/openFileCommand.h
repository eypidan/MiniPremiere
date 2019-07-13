//
// Created by px on 7/12/2019.
//

#ifndef OPENFILECOMMAND_H
#define OPENFILECOMMAND_H

#include "../../common/Command.h"
#include "../../model/Model.h"
class OpenFileCommand:CommandBase{
public:
    void Exec() override{

    }
    void SetParameters(const std::string path){
        Para_Path = path;
    }
};


class FetchQimageCommand:CommandBase{
public:
    void Exec() override{

    }
};

#endif //OPENFILECOMMAND_H
