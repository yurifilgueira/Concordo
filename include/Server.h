#ifndef SERVER
#define SERVER

#include <string>
#include <vector>
#include <set>
#include <Channel.h>

using std::string;
using std::vector;
using std::set;

class Server{

private:
    int ownerUserId;
    string name;
    string description;
    string invitationCode;

    vector<Channel *> channels;
    vector<int> participantsIDs;

public:
    Server();
    Server(int ownerUserId, string name);
    Server(int ownerUserId, string name, string description, string invitationCode);
    ~Server();
    int getOwnerUserId();
    string getName();
    void setName(string name);
    string getDescription();
    void setDescription(string description);
    string getInvitationCode();
    void setInvitationCode(string invitationCode);
    vector<Channel *> getChannels();
    vector<int> getParticipantsIDs();
    bool hasInvationCode();
    void addParticipant(int id);
    bool containsUser(int id);
};
#endif