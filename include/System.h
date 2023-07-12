#ifndef SYSTEM
#define SYSTEM

#include <string>
#include <vector>
#include <User.h>
#include <Server.h>
#include <Channel.h>

using std::string;
using std::vector;

/**
 * @class System
 * @brief Representa o sistema de aplicativo de chat.
 */
class System {

private:
    User currentLoggedInUser; /**< O usuário atualmente logado no sistema. */
    Server *currentServer; /**< O servidor atualmente selecionado no sistema. */
    Channel *currentChannel; /**< O canal atualmente selecionado no sistema. */

    vector<User> users; /**< Os usuários cadastrados no sistema. */
    vector<Server> servers; /**< Os servidores disponíveis no sistema. */
    
    /**
    * @brief Salva os usuários.
    */
    void saveUsers();
    /**
    * @brief Salva os servidores.
    */
    void saveServers();

public:
    /**
     * @brief Construtor padrão para System.
     */
    System();

    /**
     * @brief Construtor para System com usuário, servidor e canal atual.
     * @param currentLoggedInUser O usuário atualmente logado no sistema.
     * @param currentServer O servidor atualmente selecionado no sistema.
     * @param currentChannel O canal atualmente selecionado no sistema.
     */
    System(User currentLoggedInUser, Server currentServer, Channel currentChannel);

    /**
     * @brief Destrutor para System.
     */
    ~System();

    /**
     * @brief Procura um usuário com base em seu ID.
     * @param id O ID do usuário a ser pesquisado.
     * @return O usuário correspondente ao ID fornecido. Retorna um objeto User vazio se não for encontrado.
     */
    User searchUserById(int &id);

    /**
     * @brief Verifica se um determinado endereço de e-mail já está em uso por outro usuário.
     * @param email O endereço de e-mail a ser verificado.
     * @return O ID do usuário associado ao endereço de e-mail se já estiver em uso, ou 0 caso contrário.
     */
    int emailAlreadyUsed(string email);

    /**
     * @brief Gera um novo ID para um usuário com base no ID do último usuário cadastrado.
     * @return O novo ID gerado.
     */
    int generateId();

    /**
     * @brief Obtém o usuário atualmente logado no sistema.
     * @return O usuário atualmente logado.
     */
    User getCurrentLoggedInUser();

    /**
     * @brief Define o usuário atualmente logado no sistema.
     * @param currentLoggedInUser O usuário a ser definido como usuário atualmente logado.
     */
    void setCurrentLoggedInUser(User currentLoggedInUser);

    /**
     * @brief Obtém o servidor atualmente selecionado no sistema.
     * @return O servidor atualmente selecionado.
     */
    Server *getCurrentServer();

    /**
     * @brief Define o servidor atualmente selecionado no sistema.
     * @param currentServer O servidor a ser definido como servidor atualmente selecionado.
     */
    void setCurrentServer(Server &currentServer);

    /**
     * @brief Obtém o canal atualmente selecionado no sistema.
     * @return O canal atualmente selecionado.
     */
    Channel *getCurrentChannel();

    /**
     * @brief Define o canal atualmente selecionado no sistema.
     * @param currentChannel O canal a ser definido como canal atualmente selecionado.
     */
    void setCurrentChannel(Channel &currentChannel);

    /**
     * @brief Obtém todos os usuários cadastrados no sistema.
     * @return Um vetor contendo todos os usuários cadastrados.
     */
    vector<User> getUsers();

    /**
     * @brief Obtém todos os servidores disponíveis no sistema.
     * @return Um vetor contendo todos os servidores disponíveis.
     */
    vector<Server> getServers();

    /**
     * @brief Adiciona um novo usuário ao sistema.
     * @param user O usuário a ser adicionado.
     */
    void addUser(User user);

    /**
     * @brief Procura um servidor pelo seu nome.
     * @param name O nome do servidor a ser procurado.
     * @return Um ponteiro para o servidor encontrado ou nullptr se não for encontrado.
     */
    Server* searchServer(string name);

    /**
     * @brief Verifica se um servidor com um determinado nome já existe no sistema.
     * @param name O nome do servidor a ser verificado.
     * @return True se o servidor já existe, caso contrário, false.
     */
    bool serverAlreadyExists(string name);

    /**
     * @brief Cria um novo servidor no sistema.
     * @param ownerUserId O ID do usuário que será o proprietário do servidor.
     * @param name O nome do servidor a ser criado.
     * @return True se o servidor foi criado com sucesso, caso contrário, false.
     */
    bool createServer(int ownerUserId, string name);

    /**
     * @brief Adiciona um servidor ao sistema.
     * @param server O servidor a ser adicionado.
     */
    void addServer(Server server);

    /**
     * @brief Remove um servidor do sistema com base em seu nome.
     * @param name O nome do servidor a ser removido.
     */
    void removeServer(string name);

    /**
     * @brief Realiza o login de um usuário no sistema.
     * @param email O endereço de e-mail do usuário.
     * @param password A senha do usuário.
     * @return True se o login for bem-sucedido, caso contrário, false.
     */
    bool login(string email, string password);

    /**
     * @brief Imprime os nomes de todos os servidores disponíveis no sistema.
     */
    void printServers();

    /**
     * @brief Entra em um servidor especificado pelo seu nome.
     * @param name O nome do servidor a ser acessado.
     */
    void enterServer(string name);

    /**
     * @brief Entra em um servidor especificado pelo seu nome e código de convite.
     * @param name O nome do servidor a ser acessado.
     * @param invitationCode O código de convite para entrar no servidor.
     */
    void enterServer(string name, string invitationCode);

    /**
     * @brief Sai do servidor atualmente visualizado no sistema.
     */
    void leaveServer();

    /**
     * @brief Desconecta o usuário atualmente logado do sistema.
     */
    void disconnectUser();

    /**
     * @brief Verifica se um servidor com um determinado nome está presente no sistema.
     * @param serverName O nome do servidor a ser verificado.
     * @return True se o servidor estiver presente, caso contrário, false.
     */
    
    /**
     * @brief Verifica se o sistema contém um servidor com o nome especificado.
     *
     * @param serverName O nome do servidor a ser verificado.
     * @return true se o sistema contém um servidor com o nome especificado, false caso contrário.
     */
    bool containsServer(string serverName);

    /**
     * @brief Entra no canal com o nome especificado.
     *
     * Define o canal atual como o canal encontrado com o nome especificado, se o canal atual estiver vazio.
     *
     * @param name O nome do canal a ser buscado.
     * @return true se o canal atual foi definido com sucesso, false caso contrário.
     */
    bool enterChannel(string name);

    /**
     * @brief Libera a memória alocada para os canais em todos os servidores.
     */
    void free();

    /**
     * @brief Sai do canal atual, definindo o canal atual como nullptr.
     */
    void leaveChannel();


    /**
     * @brief Imprime as mensagens do canal atual.
     *
     * @return Se o canal atual for um TextChannel, imprime todas as mensagens contidas nele. 
     * Se o canal atual for um VoiceChannel, imprime a última mensagem enviada nele.
     * 
     */
    void printMessages();


    /**
     * Verifica se um ponteiro é uma instância de uma determinada classe ou de uma de suas subclasses.
     *
     * @tparam Base O tipo da classe base.
     * @tparam T O tipo da classe a ser verificada.
     * @param ptr O ponteiro a ser verificado.
     * @return true se o ponteiro é uma instância de `Base` ou de uma de suas subclasses, false caso contrário.
     */
    template<typename Base, typename T>
    inline bool instanceOf(const T *ptr);

    /**
    * @brief Salva o sistema.
    */
    void save();
};

#endif