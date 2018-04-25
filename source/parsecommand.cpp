#include "../header/parsecommand.h"

ParseCommand::ParseCommand()
{

}

ParseCommand::~ParseCommand()
{

}

bool ParseCommand::executeCommand(){
    return system(this->str_command);
}

void ParseCommand::readCommand(){

}
