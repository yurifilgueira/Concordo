#include <iostream>
#include <System.h>

using std::cout;
using std::endl;

System::System(){
}

System::System(User currentLoggedInUser, Server currentServer, Channel currentChannel){
    this->currentLoggedInUser = currentLoggedInUser;
    this->currentServer = currentServer;
    this->currentChannel = currentChannel;
}

System::~System(){
}

User System::searchUserById(int id){
    int low = 0;
    int high = users.size();

    while (low <= high)
    {
        int half = (high + low) / 2;

        if (id < users[half].getId()){
            high = half - 1;
        }
        else if (id > users[half].getId()){
            low = half + 1;
        }
        else{
            return users[half];
        }
    }

    return User();
}

int System::emailAlredyUsed(string email){
    for (int i = 0; i < users.size(); i++){
        if (users[i].getEmail() == email){
            return users[i].getId();
        }
    }

    return 0;
}

int System::generateId(){

    int id = 1;

    if (!users.empty()){
        id = users[users.size() - 1].getId() + 1;
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

vector<User> System::getUsers(){
    return this->users;
}

vector<Server> System::getServers(){
    return this->servers;
}

void System::addUser(User user){
    users.push_back(user);
}

Server System::searchServer(string name){

    for (int i = 0; i < servers.size(); i++){
        if (servers[i].getName() == name){
            return servers[i];
        }
    }

    return Server();
}

bool System::createServer(int ownerUserId, string name){
    if (searchServer(name).getName() == name) {
        return false;
    }
    else {
        addServer(Server(ownerUserId, name));

        return true;
    }
}

void System::addServer(Server server){
    servers.push_back(server);
}

void System::removeServer(string name){
    
    int idx = 0;

    for (int i = 0; i < servers.size(); i++){
        if (servers[i].getName() == name){
            idx = i;
        }
    }

    servers.erase(servers.begin() + idx);
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

void System::printServers(){
    if (servers.size() > 0){
        for (Server server : servers){
            cout << server.getName() << endl;
        }
    }
    else {
        cout << "Não há servidores cadastrados." << endl;
    }
}

void System::disconnectUser(){
    setCurrentLoggedInUser(User());
}

