#ifndef COMMAND_H
#define COMMAND_H

class CommandBase{
public:
    Command();
    virtual void SetParameters(std::string &filepath);
    virtual void Exec() = 0;
};
#endif //COMMAND_H
