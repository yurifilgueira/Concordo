#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <System.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

vector<string> commandLine;

/**
 * Função para dividir uma string em substrings usando um separador específico.
 * @param str A string a ser dividida.
 * @param separator O caractere separador.
 */
void split(string str, char separator)
{
    size_t idx = str.find_first_of(separator);
    size_t startPos = 0;

    while (idx != std::string::npos) {
        std::string token = str.substr(startPos, idx - startPos);
        commandLine.push_back(token);

        startPos = idx + 1;
        idx = str.find_first_of(separator, startPos);
    }

    string arg = str.substr(startPos);
    commandLine.push_back(arg);
}

/**
 * Função para gerar o nome do servidor a partir da linha de comando.
 * @param commandLine A linha de comando dividida em tokens.
 * @return O nome do servidor.
 */
string generateServerName(vector<string> commandLine){
    
    string name;

    for (int i = 1; i < commandLine.size(); i++){
        if (i == 1){
            name = commandLine[i];
        }
        else if (commandLine[i][0] != '"'){
            name.append(" " + commandLine[i]);
        }
        else {
            break;
        }
    }

    return name;
}

/**
 * Função para gerar o nome do usuário a partir da linha de comando.
 * @param commandLine A linha de comando dividida em tokens.
 * @return O nome do usuário.
 */

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

/**
 * Função para obter a descrição de um comando.
 * @param command O comando contendo a descrição entre aspas.
 * @return A descrição.
 */
string getDesc(string command){
    int idxFirst = command.find_first_of("\"");
    int idxLast = command.find_last_of("\"");
    int sizeDesc = ( idxLast - idxFirst);

    string desc = command.substr(idxFirst + 1, sizeDesc - 1);

    return desc;
}

int main(int argc, char* argv[])
{

    string linha;
    string command, email, password, name;
    System sys;

     system("clear");

    cout << "---Bem vindo ao Concordo!---" << endl;

    const char* arquivo = argv[1];

    std::ifstream file(arquivo);

    if (argc == 2) {
        if (!file.is_open()) {
            std::cout << "Erro ao abrir o arquivo." << std::endl;
            return 1;
        }
    }

    while (command != "quit") {

        command.clear();
        if (argc == 2){
            if (std::getline(file, linha)){
                command = linha;
            }
            else {
                getline(cin, command);
            }
        }
        else {
            getline(cin, command);
        }

        split(command, ' ');

        if (commandLine[0] == "create-user")
        {
            if (sys.getCurrentLoggedInUser().getId() != 0){
                cout << "Desconecte-se do Concordo para poder criar outro usuário." << endl;
            }
            else if (commandLine.size() != 4 && commandLine.size() != 5){
                cout << "Comando inválido!, você deve inserir o comando 'create-user' seguido do email, senha e nome de usuário, separados por espaço." << endl;
            }
            else {
                email = commandLine[1];

                if (sys.emailAlreadyUsed(email) != 0){
                    cout << "Desculpe, já existe um usuário com esse email." << endl;
                    cout << "Caso você seja o dono da conta, basta digitar o comando 'login' seguido do email e senha para acessá-la." << endl;
                }
                else {
                    password = commandLine[2];
                    name = generateUserName(commandLine);

                    sys.addUser(User(sys.generateId(), email, password, name));

                    cout << "Criando novo usuário..." << endl;
                    cout << "O usuário " << sys.getUsers()[sys.getUsers().size() - 1].getName() << " foi criado com sucesso!" << endl;
                }
            }

            commandLine.clear();
        }

        else if (commandLine[0] == "login"){
            
            if (sys.getCurrentLoggedInUser().getName() != ""){
                cout << "Desconecte-se para realizar outro login, basta digitar o comando 'disconnect', para se desconectar." << endl;
            }
            else if (commandLine.size() != 3){
                cout << "Comando inválido!, você deve inserir o comando 'login' seguido do email e senha, separados por espaço." << endl;
            }
            else {
                email = commandLine[1];

                password = commandLine[2];

                cout << email << "-" << password <<endl;

                if (sys.login(email, password)){
                    cout << "Logado como " << email << endl;
                }
                else {
                    cout << "Senha ou usuário inválidos." << endl;
                }
            }

            
            commandLine.clear();
        }
        else if (sys.getCurrentLoggedInUser().getId() > 0){
            if (commandLine[0] == "create-server"){
                if (commandLine.size() < 2){
                    cout << "Para criar um servidor você deve inserir o comando 'create-server' seguido do nome do servidor" << endl;
                }
                else {

                    name = generateServerName(commandLine);

                    if (name != ""){
                        bool isServerCreated = sys.createServer(sys.getCurrentLoggedInUser().getId(), name);
                                            if (isServerCreated){
                        cout << "O servidor " << name << " foi criado com sucesso! (Agora você está visualizando este servidor)" << endl;
                        }
                        else {
                            cout << "Desculpe, não foi possível criar o servidor. Já existe um servidor com este nome." << endl;
                        }
                    }
                    else {
                        cout << "Desculpe, nome inválido." << endl;
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

                    if (sys.searchServer(name) != nullptr){
                        if (sys.getCurrentLoggedInUser().getId() == sys.searchServer(name)->getOwnerUserId()){
                            
                            sys.getCurrentServer().setDescription(desc);

                            cout << "A descrição do servidor " << sys.searchServer(name)->getName() << " foi alterada com sucesso." << endl;
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

                    if (sys.searchServer(name) != nullptr){
                        if (sys.getCurrentLoggedInUser().getId() == sys.searchServer(name)->getOwnerUserId()){
                            
                            string invitationCode = commandLine[2];

                            if (invitationCode != ""){
                                
                                sys.searchServer(name)->setInvitationCode(invitationCode);

                                cout << "O código de convite do servidor " << sys.searchServer(name)->getName() << " foi alterado com sucesso." << endl;
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

                sys.printServers();

                
                commandLine.clear();
            }
            else if (commandLine[0] == "list-participants"){

                for (int id : sys.getCurrentServer().getParticipantsIDs()){
                    cout << sys.searchUserById(id).getName() << endl;
                }

                commandLine.clear();
            }
            else if (commandLine[0] == "remove-server"){

                if (sys.searchServer(name)->getName() != ""){
                    if (sys.getCurrentLoggedInUser().getId() == sys.searchServer(name)->getOwnerUserId()){
                        name = commandLine[1];

                        sys.removeServer(name);

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
            else if (commandLine[0] == "enter-server"){

                if (commandLine[0].size() < 2){
                    cout << "Para definir o código de convite de um servidor você deve inserir o comando 'enter-server' seguido do nome do servidor e,"
                                    << " caso o servidor possua, do código de convite." << endl;
                }
                else {

                    name = commandLine[1];

                    if (commandLine.size() == 3){

                        string invitationCode = commandLine[2];

                        sys.enterServer(name, invitationCode);

                    }
                    else {

                        sys.enterServer(name);
                    }
                }

                
                commandLine.clear();
            }
            else if (commandLine[0] == "leave-server"){
                sys.leaveServer();

                
                commandLine.clear();
            }
            else if (commandLine[0] == "disconnect"){

                if (sys.getCurrentLoggedInUser().getId() > 0){

                    sys.disconnectUser();

                    if (sys.getCurrentServer().getName() != ""){
                        sys.leaveServer();
                    }

                    cout << "Usuário desconectado com sucesso!" << endl;
                }
                else {
                    cout << "Não há ninguém logado no sistema" << endl;
                }

                
                commandLine.clear();
            }
        }
        else if (sys.getCurrentLoggedInUser().getId() == 0){
            cout << "Você só pode usar este comando, se estiver logado." << endl;
        }
        else if (command != "quit"){
    
            cout << "Comando inválido." << endl;
            
            commandLine.clear();
        }
    }

    cout << "Saindo do concordo, até mais!" << endl;

    return 0;
}