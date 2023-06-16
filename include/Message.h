#ifndef MESSAGE
#define MESSAGE

#include <string>

using std::string;

class Message
{
private:
    string dataHora;
    string sentyBy;
    string content;
public:
    Message();
    Message(string dataHora, string sentyBy, string content);
    ~Message();
    string getdataHora();
    void setdataHora(string dataHora);
    string getsentyBy();
    void setsentyBy(string sentyBy);
    string getcontent();
    void setcontent(string content);
};

#endif