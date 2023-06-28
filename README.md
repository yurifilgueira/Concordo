
# Concordo

### Clone do Discord, para humanos mais civilizados

Este é um sistema chamado `Concordo` com recursos similares ao `Discord`, porém funciona somente em modo texto e sem recursos de rede.

## Identificação

NOME: Yuri Filgueira Tavares de Medeiros

MATRÍCULA: 20220034872

TURMA: 02

## Como executar o Concordo

Certifique-se de ter o g++ e o CMake instalados em seu sistema antes de prosseguir.

1. No terminal, execute o comando `cmake .` para gerar os arquivos de configuração do CMake.

    1.1. Caso a sua versão seja diferente da do arquivo `CMakeLists.txt`, presente nesse projeto, não tem problema. Basta acessar o arquivo citado, e alterar a versão que está no arquivo para a versão que está no seu dispositivo.

2. Em seguida, execute o comando `make` para compilar o programa.
3. Após a compilação bem-sucedida, execute o programa digitando `./program` no terminal.
    
    3.1. Caso você possua um script — um arquivo `.txt` — com os comandos do Concordo, basta inserir `./program nomeDoArquivo.txt` no terminal.
    
    3.2. Caso o script não contenha o comando `quit` — comando que será explicado em breve — o Concordo continurá rodando normalmente, e você poderá inserir os comandos que desejar.

## Guia de uso

O `Concordo` funciona através de comandos inseridos no terminal. Portanto, aqui estão os comandos possíveis de se fazer e como fazer.

Ao iniciar o `Concordo` — sem estar logado —, você só poderá executar os três primeiros comandos. Caso tente executar algum comando além desses três — sem estar logado —, o programa acusará um erro.

Segue abaixo a lista de comandos possíveis:

1. **create-user**: Cria um usuário. Veja o exemplo:

    `create-user <email> <senha_sem_espaços> <nome com espaços>`

    `create-user ryangosling@example.com 12ab34cd Ryan Gosling`

2. **login**: Realiza o login no Concordo. Veja o exemplo:

    `login <nome> <senha>`

    `login ryangosling@example.com 12ab34cd`

3. **quit**: Encerra o programa, pode ser usado a qualquer momento. Veja o exemplo:

    `quit`

4. **disconnect**: Desconecta o usuário que está atualmente logado. Veja o exemplo: 

    `disconnect`

5. **create-server**: Cria um servidor. Veja o exemplo:

    `create-server <nome>`

    `create-server Javeiros-com-amor`

6. **set-server-desc**: Permite definir ou alterar uma descrição para o servidor. Caso você não seja o dono do servidor, não poderá alterar ou definir a descrição do servidor. Veja o exemplo: 

    `set-server-desc <nome-do-servidor> <descrição>`

    `set-server-desc Javeiros-com-amor Seja bem-vindo ao servidor da melhor linguagem do mundo.`

7. **set-server-invite-code**: Permite definir ou alterar um código de convite para o servidor. Somente pessoas com acesso a este código poderão entrar no servidor. Caso você não seja o dono do servidor, não poderá alterar ou definir o código de convite do servidor. Veja o exemplo:

    `set-server-invite-code <nome-do-servidor> <código-de-convite>`

    `set-server-invite-code Javeiros-com-amor j1a2v3a4`

8. **list-servers**: Lista os servidores presentes no Concordo. Veja o exemplo:

    `list-servers`

9. **remove-server**: Ao usar este comando, você, caso seja o dono, deletará o servidor. Veja o exemplo: 

    `remove-server <nome-do-servidor>`

    `remove-server Javeiros-com-amor`

10. **enter-server**: Permite entrar em um servidor. Entretanto, há dois tipos de servidores, os que possuem código de convite e os que não possuem. Veja o exemplo:

    **Com código de convite:**

    `enter-server <nome> <código-de-convite>`

    `enter-server Javeiros-com-amor j1a2v3a4`

    **Sem código de convite:**

    `enter-server <nome>`

    `enter-server Javeiros-com-amor`
    

    *É importante ressaltar que, ao entrar em um servidor, você entrará para a lista de participantes e ao mesmo tempo, estará visualizando o servidor.*

- **leave-server**: Você deixará de visualizar o servidor que estava visualizando antes. Mas ainda estará na lista de participantes do servidor que parou de visualizar. Veja o exemplo:

    `leave-server`


    *Uma observação muito importante é que, ao sair de um servidor, mesmo ainda permanecendo na lista de participantes dele, você terá que inserir o código de convite, para entrar novamente. Isso é válido somente para servidores que necessitam de código de convite.*

- **list-participants**: Lista os participantes do servidor que você está visualizando. Veja o exemplo:

    `list-participants`
