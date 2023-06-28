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

User System::searchUserById(int &id){
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

vector<User > System::getUsers(){
    return this->users;
}

vector<Server > System::getServers(){
    return this->servers;
}

void System::addUser(User user){
    users.push_back(user);
}

Server *System::searchServer(string name){

    for (int i = 0; i < servers.size(); i++){
        if (servers[i].getName() == name){
            return &servers[i];
        }
    }

    return nullptr;
}

bool System::serverAlredyExists(string name){

    for (int i = 0; i < servers.size(); i++){
        if (servers[i].getName() == name){
            return true;
        }
    }

    return false;
}

bool System::createServer(int ownerUserId, string name){
    if (serverAlredyExists(name)) {
        return false;
    }
    else {
        addServer(Server(ownerUserId, name));
        
        searchServer(name)->addParticipant(getCurrentLoggedInUser().getId());
        setCurrentServer(*searchServer(name));

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

void System::enterServer(string name){

    if (searchServer(name) != nullptr){
        Server server = *searchServer(name);

        if (server.getOwnerUserId() != getCurrentLoggedInUser().getId()){
            if (getCurrentServer().getName() == name){
                cout << "Você já está visualizando este servidor." << endl;
            }
            else if (getCurrentServer().getName() != ""){
                cout << "Você já está visualizando um servidor. Para trocar de servidor você deve inserir o comando 'leave-server' e" << 
                " em seguida você deve inserir o comando 'enter-server' seguido do nome do servidor e, caso o servidor possua, do código de convite." << endl;
            }
            else {
                if (server.getName() != ""){
                    if (server.hasInvationCode()){
                        cout << "Este servidor necessita de um código de convite. Insira o comando 'enter-server' seguido do nome do servidor e do código de convite." << endl;
                    }
                    else {
                        if (!server.containsUser(getCurrentLoggedInUser().getId())){
                            searchServer(name)->addParticipant(getCurrentLoggedInUser().getId());
                        }
                        setCurrentServer(*searchServer(name));
                        cout << "Você entrou no servidor com sucesso." << endl;
                    }
                }
            }
        }
        else {
            if (!server.containsUser(getCurrentLoggedInUser().getId())){
                searchServer(name)->addParticipant(getCurrentLoggedInUser().getId());
            }
            setCurrentServer(*searchServer(name));
            cout << "Você entrou no servidor com sucesso." << endl;
        }
    }
    else {
        cout << "Este servidor não existe." << endl;
    }
}


void System::enterServer(string name, string invitationCode){
    
    if (searchServer(name) != nullptr){
        Server server = *searchServer(name);

        if (server.getOwnerUserId() != getCurrentLoggedInUser().getId()){
            if (getCurrentServer().getName() == name){
                cout << "Você já está visualizando este servidor." << endl;
            }
            else if (getCurrentServer().getName() != ""){
                cout << "Você já está visualizando um servidor. Para trocar de servidor você deve inserir o comando 'leave-server' e" << 
                " em seguida você deve inserir o comando 'enter-server' seguido do nome do servidor e, caso o servidor possua, do código de convite." << endl;
            }
            else {
                if (!server.hasInvationCode()){
                    cout << "Este servidor não necessita de um código de convite. Insira o comando 'enter-server' seguido do nome do servidor, para entrar no servidor." << endl;
                }
                else if(server.getInvitationCode() == invitationCode) {
                    if (!server.containsUser(getCurrentLoggedInUser().getId())){
                        searchServer(name)->addParticipant(getCurrentLoggedInUser().getId());
                    }
                    setCurrentServer(*searchServer(name));
                    cout << "Você entrou no servidor com sucesso." << endl;
                }
                else {
                    cout << "Não foi possível entrar no servidor. Código de convite inválido." << endl;
                }
            }
        }
        else {
            if (!server.containsUser(getCurrentLoggedInUser().getId())){
                searchServer(name)->addParticipant(getCurrentLoggedInUser().getId());
            }
            setCurrentServer(*searchServer(name));
            cout << "Você entrou no servidor com sucesso." << endl;
        }
    }
    else {
        cout << "Este servidor não existe." << endl;
    }
}

void System::leaveServer(){
    if (getCurrentServer().getName() != ""){
        
        cout << "Saindo do servidor '" << getCurrentServer().getName() << "'" << endl;
        
        setCurrentServer(Server());
    }
    else{
        cout << "Você não está visualizando nenhum servidor." << endl;
    }
}

void System::disconnectUser(){

    User user = User();

    setCurrentLoggedInUser(User());
}

bool System::containsServer(string serverName){
    for (Server server : servers){
        if (server.getName() == serverName){
            return true;
        }
    }

    return false;
}