#include <Channel.h>

Channel::Channel(){
}

Channel::Channel(string name){
    this->name = name;
}

Channel::~Channel(){
}

string Channel::getName(){
    return name;
}

void Channel::setName(string name){
    this->name = name;
}