#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Acessar dados sobre excursoes.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de pessoal.";
    char texto8[]="2 - Selecionar servicos relacionados a excursoes.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.

        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&email)){                         // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleção de serviço.
                            initscr();
                            clear();                                                            // Limpa janela.
                            printw(texto6);                             // Imprime nome do campo.
                            printw(texto7);                         // Imprime nome do campo.
                            printw(texto8);                         // Imprime nome do campo.
                            printw(texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.
                            echo();
                            endwin();
                            switch(campo){
                                case 1: cntrApresentacaoPessoal->executar(email);                 // Solicita serviço de pessoal.
                                        break;
                                case 2: cntrApresentacaoExcursoes->executar(email);     // Solicita serviço de produto financeiro.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 2: cntrApresentacaoPessoal->cadastrar();
                    break;
            case 3: cntrApresentacaoExcursoes->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o Email  : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Senha senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autenticação.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lê valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // Lê valor do campo.

        try{
            email->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor à senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lê caracter digitado.
            echo();
        }
    }
    return (cntr->autenticar(*email, senha));                                                     // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.         // Imprime nome do campo.

        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarDadosPessoais();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto5[] ="Email             :";
    char texto6[] ="Senha           :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];                            // Cria campos para entrada dos dados.
    char campo6[80], campo7[80], campo8[80];                                                    // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Email email;
    Senha senha;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.     // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.     // Lê valor do campo.

    try{
        nome.setValor(string(campo1));
        email.setValor(string(campo4));
        senha.setValor(string(campo5));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);

    // Cadastra usuário

    if(cntrServicoPessoal->cadastrarUsuario(usuario)){
            mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
            noecho();
            getch();
            echo();
            return;
        }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::consultarDadosPessoais(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::executar(){

    // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar Excursao.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela simplificada de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarExcursao();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::executar(Email){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="Selecione um dos servicos : ";
    char texto3[] ="1 - Cadastrar Excursao.";
    char texto4[] ="2 - Descadastrar Excursao.";
    char texto5[] ="3 - Consultar Excursao.";
    char texto8[] ="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.         // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.         // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: cadastrarExcursao();
                    break;
            case 2: descadastrarExcursao();
                    break;
            case 3: consultarExcursao();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------


void CntrApresentacaoExcursoes::cadastrarExcursao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico cadastrar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::descadastrarExcursao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar produto investimento nao implementado. Digite algo.";    // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::consultarExcursao(){

    char texto1[] ="1. Cadastrar Avaliacao ";
    char texto2[] ="2. Descadastrar Avaliacao ";
    char texto3[] ="3. Cadastrar Sessao ";
    char texto4[] ="4. Desadastrar Sessao ";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar) {

        // Apresenta tela completa de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha / 4, coluna / 4, "%s", texto1);
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto3);               // Imprime nome do campo.         // Imprime nome do campo.         // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch (campo) {
            case 1: cadastrarAvaliacao();
                break;
            case 2: descadastrarAvaliacao();
                break;
            case 3: cadastrarSessao();
                break;
            case 4: descadastrarSessao();
                break;
        }
    }
}
//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::cadastrarAvaliacao() {

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::descadastrarAvaliacao() {

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::cadastrarSessao() {

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursoes::descadastrarSessao() {

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------