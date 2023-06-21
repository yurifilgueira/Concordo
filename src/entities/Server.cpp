#include <Server.h>

Server::Server(){
}

Server::Server(int ownerUserId, string name){
    this->ownerUserId = ownerUserId;
    this->name = name;
}

Server::Server(int ownerUserId, string name, string description, string invitationCode){
    this->ownerUserId = ownerUserId;
    this->name = name;
    this->description = description;
    this->invitationCode = invitationCode;
}

Server::~Server(){

    for (Channel *channel : channels){
        delete channel;
    }

}

int Server::getOwnerUserId(){
    return ownerUserId;
}

string Server::getName(){
    return name;
}

void Server::setName(string name){
    this->name = name;
}

string Server::getDescription(){
    return description;
}

void Server::setDescription(string description){
    this->description = description;
}

string Server::getInvitationCode(){
    return invitationCode;
}

void Server::setInvitationCode(string invitationCode){
    this->invitationCode = invitationCode;
}

vector<Channel *> Server::getChannels(){
    return channels;
}

vector<int> Server::getParticipantsIDs(){
    return participantsIDs;
}