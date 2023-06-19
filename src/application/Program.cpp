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

    string command, email, password, name; 
    getline(cin, command);

    while (command != "quit")
    {
        split(command, ' ');

        if (commandLine[0] == "create-user")
        {
            if (commandLine.size() != 4 && commandLine.size() != 5){
                cout << "Comando inválido!, você deve inserir o comando 'create-user' seguido do email, senha e nome de usuário, separados por espaço." << endl;
            }
            else {
                email = commandLine[1];

                if (system.emailAlredyUsed(email) != 0){
                    cout << "Desculpe, já existe um usuário com esse email." << endl;
                    cout << "Caso você seja o dono da conta, basta digitar o comando 'login' seguido do email e senha para acessá-la." << endl;
                }
                else {
                    password = commandLine[2];
                    name = commandLine[3];
                    for (int i = 4; i < commandLine.size(); i++){
                        name.append(" " + commandLine[i]);
                    }

                    system.addUser(new User(system.generateId(), email, password, name));

                    cout << "Criando novo usuário..." << endl;
                    cout << "O usuário " << system.getUsers()[system.getUsers().size() - 1]->getName() << " foi criado com sucesso!" << endl;
                }
            }

            commandLine.clear();
        }
        else if (commandLine[0] == "login"){

            if (system.getCurrentLoggedInUser().getName() != ""){
                cout << "Desconecte-se para realizar outro login, basta digitar o comando 'disconnect', para se desconectar." << endl;
            }
            else if (commandLine.size() != 3){
                cout << "Comando inválido!, você deve inserir o comando 'login' seguido do email e senha, separados por espaço." << endl;
            }
            else {
                email = commandLine[1];

                password = commandLine[2];

                if (system.login(email, password)){
                    cout << "Logado como " << email << endl;
                }
                else {
                    cout << "Senha ou usuário inválidos." << endl;
                }
            }

            commandLine.clear();
        }
        else if (commandLine[0] == "create-server"){
            if (commandLine.size() < 2){
                cout << "Para criar um servidor você deve inserir o comando 'create-server' seguido do nome do servidor" << endl;
            }
            else {
                for (int i = 1; i < commandLine.size(); i++){
                    if (i == 1){
                        name = commandLine[i];
                    }
                    else {
                        name.append(" " + commandLine[i]);
                    }
                }

                system.addServer(new Server(system.getCurrentLoggedInUser().getId(), name));

                cout << "O servidor " << name << " criado com sucesso!" << endl;
            }

            commandLine.clear();
        }
        else if (commandLine[0] == "disconnect"){
            system.disconnectUser();

            cout << "Usuário desconectado com sucesso!" << endl;

            commandLine.clear();
        }

        getline(cin, command);
    }

    cout << "Saindo do concordo, até mais!" << endl;

    return 0;
}