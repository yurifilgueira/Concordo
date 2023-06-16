#include <Message.h>

Message::Message(){
}

Message::Message(string dataHora, string sentyBy, string content){
    this->dataHora = dataHora;
    this->sentyBy = sentyBy;
    this->content = content;
}

Message::~Message(){
}


string Message::getdataHora(){
    return dataHora;
}

void Message::setdataHora(string dataHora){
    this->dataHora = dataHora; 
}

string Message::getsentyBy(){
    return sentyBy;
}

void Message::setsentyBy(string sentyBy){
    this->sentyBy = sentyBy;
}

string Message::getcontent(){
    return content;
}

void Message::setcontent(string content){
    this->content = content;
}