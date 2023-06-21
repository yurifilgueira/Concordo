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

string generateServerName(vector<string> commandLine){
    
    string name;

    for (int i = 1; i < commandLine.size(); i++){
        if (i == 1){
            name = commandLine[i];
        }
        else if (commandLine[i][0] != '\"'){
            name.append(" " + commandLine[i]);
        }
        else {
            break;
        }
    }

    return name;
}

string generateUserName(vector<string> commandLine){
    
    string name;

    for (int i = 3; i < commandLine.size(); i++){
        if (i == 3){
            name = commandLine[i];
        }
        else {
            name.append(" " + commandLine[i]);
        }
    }

    return name;
}

string getDesc(string command){
    int idxFirst = command.find_first_of("\"");
    int idxLast = command.find_last_of("\"");
    int sizeDesc = ( idxLast - idxFirst);

    string desc = command.substr(idxFirst + 1, sizeDesc - 1);

    return desc;
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
                    name = generateUserName(commandLine);

                    system.addUser(User(system.generateId(), email, password, name));

                    cout << "Criando novo usuário..." << endl;
                    cout << "O usuário " << system.getUsers()[system.getUsers().size() - 1].getName() << " foi criado com sucesso!" << endl;
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

                name = generateServerName(commandLine);

                bool isServerCreated = system.createServer(system.getCurrentLoggedInUser().getId(), name);

                if (isServerCreated){
                    cout << "O servidor " << name << " foi criado com sucesso!" << endl;
                }
                else {
                    cout << "Desculpe, não foi possível criar o servidor. Já existe um servidor com este nome." << endl;
                }

            }

            commandLine.clear();
        }
        else if (commandLine[0] == "set-server-desc"){
            if (commandLine.size() < 3){
                cout << "Para definir a descrição de um servidor você deve inserir o comando 'set-server-desc' seguido do nome do servidor e da descrição entre aspas." << endl;
            }
            else {

                name = generateServerName(commandLine);

                string desc = getDesc(command);

                if (system.searchServer(name).getName() != ""){
                    if (system.getCurrentLoggedInUser().getId() == system.searchServer(name).getOwnerUserId()){
                        
                        system.getCurrentServer().setDescription(desc);

                        cout << "A descrição do servidor " << system.getCurrentServer().getName() << " foi alterada com sucesso." << endl;
                    }
                    else{
                        cout << "Você não pode alterar a descrição de um servidor que não foi criado por você." << endl;
                    }
                }
                else {
                    cout << "Este servidor não existe." << endl;
                }

            }

            commandLine.clear();
        }
        else if (commandLine[0] == "set-server-invite-code"){
            if (commandLine.size() < 3){
                cout << "Para definir o código de convite de um servidor você deve inserir o comando 'set-server-invite-code' seguido do nome do servidor e do código de convite." << endl;
            }
            else {

                name = commandLine[1];

                if (system.searchServer(name).getName() != ""){
                    if (system.getCurrentLoggedInUser().getId() == system.searchServer(name).getOwnerUserId()){
                        
                        string invitationCode = commandLine[2];

                        if (invitationCode != ""){
                            system.getCurrentServer().setInvitationCode(invitationCode);

                            cout << "O código de convite do servidor " << system.getCurrentServer().getName() << " foi alterado com sucesso." << endl;
                        }
                        else {
                            cout << "O código de convite do servidor foi removido com sucesso." << endl;
                        }
                    }
                    else{
                        cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você." << endl;
                    }
                }
                else {
                    cout << "Este servidor não existe." << endl;
                }

            }

            commandLine.clear();
        }
        else if (commandLine[0] == "list-servers"){

            system.printServers();

            commandLine.clear();
        }
        else if (commandLine[0] == "remove-server"){

            if (system.searchServer(name).getName() != ""){
                if (system.getCurrentLoggedInUser().getId() == system.searchServer(name).getOwnerUserId()){
                    name = commandLine[1];

                    system.removeServer(name);

                    cout << "Servidor deletado com sucesso." << endl;
                }
                else{
                    cout << "Você não pode deletar um servidor que não foi criado por você." << endl;
                }
            }
            else{
                cout << "Este servidor não existe." << endl;
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