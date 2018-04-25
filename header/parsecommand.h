#ifndef PARSECOMMAND_H
#define PARSECOMMAND_H

#include <iostream>
#include <stdlib.h>

class ParseCommand
{
public:
    ParseCommand();
    ~ParseCommand();
    char str_command[256];
    bool executeCommand();
    void readCommand();

private:

};

#endif // PARSECOMMAND_H
