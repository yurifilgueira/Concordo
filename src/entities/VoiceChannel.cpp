#include <VoiceChannel.h>

VoiceChannel::VoiceChannel(){
}

VoiceChannel::VoiceChannel(string name){
    this->name = name;
}

VoiceChannel::~VoiceChannel(){
}

Message VoiceChannel::getLastMessage(){
    return lastMessage;
}

void VoiceChannel::addMessage(Message lastMessage){
    this->lastMessage = lastMessage;
}