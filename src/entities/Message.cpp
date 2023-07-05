#include <Message.h>

Message::Message(){
}

Message::Message(string dateHour, int sentBy, string content){
    this->dateHour = dateHour;
    this->sentBy = sentBy;
    this->content = content;
}

Message::~Message(){
}


string Message::getDateHour(){
    return dateHour;
}

void Message::setDateHour(string dateHour){
    this->dateHour = dateHour; 
}

int Message::getSentBy(){
    return sentBy;
}

void Message::setSentBy(int sentBy){
    this->sentBy = sentBy;
}

string Message::getContent(){
    return content;
}

void Message::setContent(string content){
    this->content = content;
}