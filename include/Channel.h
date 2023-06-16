#ifndef CHANNEL
#define CHANNEL

#include <string>

using std::string;

class Channel{

private:
    string name;

public:
    Channel();
    Channel(string name);
    ~Channel();
    string getName();
    void setName(string name);
};
#endif