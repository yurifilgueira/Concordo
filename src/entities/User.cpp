#include <User.h>

User::User(){
}

User::User(int id, string name, string email, string password){
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

User::~User(){
}

int User::getId(){
    return id;
}

string User::getName(){
    return name;
}

void User::setName(string name){
    this->name = name; 
}

string User::getEmail(){
    return email;
}

void User::setEmail(string email){
    this->email = email;
}

string User::getPassword(){
    return password;
}

void User::setPassword(string password){
    this->password = password;
}