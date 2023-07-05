#ifndef TEXTCHANNEL
#define TEXTCHANNEL

#include <Channel.h>
#include <Message.h>
#include <vector>

using std::vector;

/**
 * @brief Classe que representa um canal de texto.
 */
class TextChannel : public Channel {
private:
    vector<Message> messages; ///< Lista de mensagens no canal de texto.
public:
    /**
     * @brief Construtor padrão da classe TextChannel.
     */
    TextChannel();
    
    /**
     * @brief Construtor da classe TextChannel que recebe o nome do canal.
     * @param name O nome do canal de texto.
     */
    TextChannel(string name);
    
    /**
     * @brief Destrutor da classe TextChannel.
     */
    ~TextChannel();
    
    /**
     * @brief Obtém a lista de mensagens no canal de texto.
     * @return A lista de mensagens.
     */
    vector<Message> getMessages();
    
    /**
     * @brief Adiciona uma mensagem à lista de mensagens do canal de texto.
     * @param message A mensagem a ser adicionada.
     */
    void addMessage(Message message);
    
    /**
     * @brief Imprime as mensagens do canal de texto.
     */
    void printMessages();
};

#endif
