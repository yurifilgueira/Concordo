#ifndef SYSTEM
#define SYSTEM

#include <string>
#include <vector>
#include <User.h>
#include <Server.h>
#include <Channel.h>

using std::string;
using std::vector;

class System{

private:
    User currentLoggedInUser;
    Server currentServer;
    Channel currentChannel;

    vector<User *> users;
    vector<Server *> servers;

public:
    System();
    System(User CurrentLoggedInUser, Server currentServer, Channel currentChannel);
    ~System();
    User searchUserById(int id);
    bool emailAlredyUsed(string email);
    int generateId();
    User getCurrentLoggedInUser();
    void setCurrentLoggedInUser(User currentLoggedInUser);
    Server getCurrentServer();
    void setCurrentServer(Server currentServer);
    Channel getCurrentChannel();
    void setCurrentChannel(Channel currentChannel);
    vector<User *> getUsers();
    vector<Server *> getServers();
    void addUser(User *user);
};
#endif