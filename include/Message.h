#ifndef MESSAGE
#define MESSAGE

#include <string>

using std::string;

/**
 * @brief Classe que representa uma mensagem.
 */
class Message {
private:
    string dataHora; /**< Data e hora da mensagem. */
    string sentyBy; /**< Remetente da mensagem. */
    string content; /**< Conteúdo da mensagem. */

public:
    /**
     * @brief Construtor padrão da classe Message.
     */
    Message();

    /**
     * @brief Construtor da classe Message que recebe a data e hora, o remetente e o conteúdo da mensagem como parâmetros.
     * @param dataHora Data e hora da mensagem.
     * @param sentyBy Remetente da mensagem.
     * @param content Conteúdo da mensagem.
     */
    Message(string dataHora, string sentyBy, string content);

    /**
     * @brief Destrutor da classe Message.
     */
    ~Message();

    /**
     * @brief Obtém a data e hora da mensagem.
     * @return Data e hora da mensagem.
     */
    string getdataHora();

    /**
     * @brief Define a data e hora da mensagem.
     * @param dataHora Data e hora da mensagem.
     */
    void setdataHora(string dataHora);

    /**
     * @brief Obtém o remetente da mensagem.
     * @return Remetente da mensagem.
     */
    string getsentyBy();

    /**
     * @brief Define o remetente da mensagem.
     * @param sentyBy Remetente da mensagem.
     */
    void setsentyBy(string sentyBy);

    /**
     * @brief Obtém o conteúdo da mensagem.
     * @return Conteúdo da mensagem.
     */
    string getcontent();

    /**
     * @brief Define o conteúdo da mensagem.
     * @param content Conteúdo da mensagem.
     */
    void setcontent(string content);
};

#endif
