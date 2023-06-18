#include <iostream>
#include <System.h>

using namespace std;

System::System(){
}

System::System(User currentLoggedInUser, Server currentServer, Channel currentChannel){
    this->currentLoggedInUser = currentLoggedInUser;
    this->currentServer = currentServer;
    this->currentChannel = currentChannel;
}

System::~System(){
    for (int i = 0; i < this->users.size(); i++){
        delete this->users[i];
    }
    for (int i = 0; i < this->servers.size(); i++){
        delete this->servers[i];
    }
}

User System::searchUserById(int id){
    int low = 0;
    int high = users.size();

    while (low <= high)
    {
        int half = (high + low) / 2;

        if (id < users[half]->getId()){
            high = half - 1;
        }
        else if (id > users[half]->getId()){
            low = half + 1;
        }
        else{
            return *users[half];
        }
    }

    return User();
}

int System::emailAlredyUsed(string email){
    for (int i = 0; i < users.size(); i++){
        if (users[i]->getEmail() == email){
            return users[i]->getId();
        }
    }

    return 0;
}

int System::generateId(){

    int id = 1;

    if (!users.empty()){
        id = users[users.size() - 1]->getId() + 1;
    }

    return id;
}

User System::getCurrentLoggedInUser(){
    return this->currentLoggedInUser;
}

void System::setCurrentLoggedInUser(User currentLoggedInUser){
    this->currentLoggedInUser = currentLoggedInUser;
}

Server System::getCurrentServer(){
    return this->currentServer;
}

void System::setCurrentServer(Server currentServer){
    this->currentServer = currentServer;
}

Channel System::getCurrentChannel(){
    return this->currentChannel;
}

void System::setCurrentChannel(Channel currentChannel){
    this->currentChannel = currentChannel;
}

vector<User *> System::getUsers(){
    return this->users;
}

vector<Server *> System::getServers(){
    return this->servers;
}

void System::addUser(User *user){
    users.push_back(user);
}

bool System::login(string email, string password){
    
    int id = emailAlredyUsed(email);

    if (id != 0){
        if (searchUserById(id).getPassword() == password){

            setCurrentLoggedInUser(searchUserById(id));
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}