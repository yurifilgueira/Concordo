#include <TextChannel.h>
#include <iostream>

using std::cout;
using std::endl;

TextChannel::TextChannel(){
}

TextChannel::TextChannel(string name){
    this->name = name;
}

TextChannel::~TextChannel(){
}

vector<Message> TextChannel::getMessages(){
    return messages;
}

void TextChannel::addMessage(Message message){
    messages.push_back(message);
}