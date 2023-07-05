#ifndef VOICECHANNEL
#define VOICECHANNEL

#include <Channel.h>

/**
 * @brief Classe que representa um canal de voz.
 */
class VoiceChannel : public Channel {
private:
    Message lastMessage; ///< Última mensagem do canal de voz.
public:
    /**
     * @brief Construtor padrão da classe VoiceChannel.
     */
    VoiceChannel();
    
    /**
     * @brief Construtor da classe VoiceChannel que recebe o nome do canal.
     * @param name O nome do canal de voz.
     */
    VoiceChannel(string name);
    
    /**
     * @brief Destrutor da classe VoiceChannel.
     */
    ~VoiceChannel();
    
    /**
     * @brief Obtém a última mensagem do canal de voz.
     * @return A última mensagem.
     */
    Message getLastMessage();
    
    /**
     * @brief Adiciona uma mensagem como a última mensagem do canal de voz.
     * @param lastMessage A mensagem a ser adicionada.
     */
    void addMessage(Message lastMessage);
};

#endif
