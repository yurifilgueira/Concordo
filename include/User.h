#ifndef USER
#define USER

#include <string>

using std::string;

class User
{
private:
    int id;
    string name;
    string email;
    string password;
public:
    User();
    User(int id, string name, string email, string password);
    ~User();
    int getId();
    string getName();
    void setName(string name);
    string getEmail();
    void setEmail(string email);
    string getPassword();
    void setPassword(string password);
};

#endif