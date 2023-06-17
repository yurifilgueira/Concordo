#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <System.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

vector<string> commandLine;

void split(string str, char separator)
{
    istringstream iss(str);
    string word;

    while (getline(iss, word, separator))
    {
        commandLine.push_back(word);
    }
}

int main()
{
    system("clear");

    cout << "---Bem vindo ao Concordo!---" << endl;

    System system;

    string command;

    getline(cin, command);

    while (command != "quit")
    {
        split(command, ' ');

        if (commandLine[0] == "create-user")
        {
            if (commandLine.size() != 4){
                cout << "Comando inválido!, você deve inserir o comando 'create-user' seguido do email, senha e nome de usuário, separados por espaço." << endl;
            }
            else {
                string email = commandLine[1];

                if (system.emailAlredyUsed(email)){
                    cout << "Desculpe, já existe um usuário com esse email." << endl;
                    cout << "Caso você seja o dono da conta, basta digitar o comando 'login' seguido do email e senha para acessá-la." << endl;
                }
                else {
                    string password = commandLine[2];
                    string name = commandLine[3];

                    system.addUser(new User(system.generateId(), email, password, name));

                    cout << "Criando novo usuário..." << endl;
                    cout << "O usuário" << system.getUsers()[system.getUsers().size()]->getName() << "foi criado com sucesso!" << endl;
                }
            }

            commandLine.clear();
        }
        else if (commandLine[0] == "login"){

        }

        getline(cin, command);
    }

    cout << "Saindo do concordo, até mais!" << endl;

    return 0;
}