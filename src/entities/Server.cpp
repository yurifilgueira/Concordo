#include <iostream>
#include <Server.h>
#include <User.h>
#include <VoiceChannel.h>
#include <TextChannel.h>

using std::cout;
using std::endl;

Server::Server(){
    this->name = "";
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

bool Server::hasInvitationCode(){
    if (invitationCode.empty()){
        return false;
    }
    else {
        return true;
    }
}

void Server::addParticipant(int id){
    participantsIDs.push_back(id);
}

bool Server::containsUser(int userId){
    for (int id : participantsIDs){
        if (id == userId){
            return true;
        }
    }

    return false;
}

void Server::addChannel(Channel *channel){
    channels.push_back(channel);
}

Channel *Server::searchChannel(string name){
    for (Channel *ch : channels){
        if (name == ch->getName()){
            return ch;
        }
    }

    return nullptr;
}

void Server::printChannels(){
    
    cout << "#Canais de texto" << endl;
    for (Channel *ch : channels){
        if (instanceof<TextChannel>(ch)){
            cout << ch->getName() << endl;
        }
    }

    cout << "#Canais de voz" << endl;
    for (Channel *ch : channels){
        if (instanceof<VoiceChannel>(ch)){
            cout << ch->getName() << endl;
        }
    }
}

template<typename Base, typename T>
inline bool Server::instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}