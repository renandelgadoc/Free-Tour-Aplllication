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


    int campo;

    int linha,coluna;

    getmaxyx(stdscr,linha,coluna);

    bool apresentar1 = true;
    bool apresentar2 = true;

    while(apresentar1){

        // Apresenta tela inicial.

        clear();
        mvprintw(linha/4,coluna/4,"%s",texto1);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);

        noecho();
        campo = getch() - 48;
        echo();

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&email)){
                        bool apresentar2 = true;
                        while(apresentar2){

                            // Apresenta tela de seleção de serviço.
                            clear();
                            mvprintw(linha/4,coluna/4,"%s",texto6);
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);
                            noecho();
                            campo = getch() - 48;
                            echo();
                            endwin();
                            switch(campo){
                                case 1:
                                    apresentar2 = cntrApresentacaoPessoal->executar(email);
                                    break;
                                case 2: cntrApresentacaoExcursoes->executar(email);
                                        break;
                                case 3: apresentar2 = false;
                                        break;
                            }
                        }
                    }
                    break;
            case 2: cntrApresentacaoPessoal->cadastrar();
                    break;
            case 3: cntrApresentacaoExcursoes->executar();
                    break;
            case 4: apresentar1 = false;
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
    char texto4[] ="1. Retornar";
    char texto5[] ="2. Tentar novamente";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    bool login = true;
    int linha,coluna;

    getmaxyx(stdscr,linha,coluna);

    Usuario usuario;

    Senha senha;

    echo();

    while(login){



        clear();
        mvprintw(linha/4,coluna/4,"%s",texto1);
        getstr(campo1);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
        getstr(campo2);

        try{
            email->setValor(string(campo1));
            senha.setValor(string(campo2));
            break;
        }
        catch(invalid_argument &exp){
            int campo;

            clear();
            mvprintw(linha/4,coluna/4,"%s",texto3);
            mvprintw(linha/4 + 2,coluna/4,"%s",texto4);
            mvprintw(linha/4 + 4,coluna/4,"%s",texto5);
            noecho();
            campo = getch() - 48;
            echo();
            switch(campo){
                case 1:
                    login = false;
                    break;
            }
        }
    }

    usuario.setEmail(*email);
    usuario.setSenha(senha);

    return (cntrServicoAutenticacao->autenticar(usuario));
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoPessoal::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Excluir conta";
    char texto4[]="3 - Editar dados pessoais.";
    char texto5[]="4 - Retornar.";


    int campo;

    int linha,coluna;

    getmaxyx(stdscr,linha,coluna);

    bool apresentar;

    apresentar = true;

    echo();

    while(apresentar){

        // Apresenta tela de selação de serviço.

        clear();
        mvprintw(linha/4,coluna/4,"%s",texto1);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
        mvprintw(linha/4 + 6,coluna/4,"%s",texto5);

        noecho();
        campo = getch() - 48;
        echo();

        switch(campo){
            case 1:
                consultarDadosPessoais(email);
                break;
            case 2:
                if(descadrastar(email)){
                    apresentar = false;
                    return false;
                }
                break;
            case 3:
                atualizar(email);
                break;
            case 4: apresentar = false;
                    break;
        }
    }
    return true;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::consultarDadosPessoais(Email email) {

    Usuario* usuario;

    usuario->setEmail(email);

    char texto7[80] = "Usuario nao encontrado.";

    int linha,coluna;

    getmaxyx(stdscr,linha,coluna);

    if(cntrServicoPessoal->consultarUsuario(usuario)){
        string texto4 = "Nome: " + usuario->getNome()
                .getValor();
        string texto5 = "Email: " + email.getValor();
        string texto6 = "Senha: " + usuario->getSenha()
                .getValor();
        echo();
        clear();
        mvprintw(linha/4,coluna/4,"%s",texto4.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",texto5.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",texto6.c_str());
        noecho();
        getch();
        echo();
        return;
    }
    echo();
    clear();
    mvprintw(linha/4,coluna/4,"%s",texto7);
    noecho();
    getch();
    echo();
    return;

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

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];
    char campo6[80], campo7[80], campo8[80];

    // Instancia os domínios.

    Nome nome;
    Email email;
    Senha senha;

    int linha,coluna;

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
        clear();
        mvprintw(linha/4,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
        }
    clear();
    mvprintw(linha/4 ,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoPessoal::descadrastar(Email email) {
    char texto1[] = "A conta sera excluida permanentemente";
    char texto2[] = "1. Prosseguir ";
    char texto3[] = "2. Retornar ";
    char texto4[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no descadastramento. Digite algo.";
    char texto12[]="Falha no descadastramento. Digite algo.";

    int campo;
    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    echo();
    campo = getch() - 48;
    noecho();

    switch (campo) {
        case 1:
            if(cntrServicoPessoal->descadastrarUsuario(email)){
                clear();
                mvprintw(linha/4,coluna/4,"%s",texto11);                                               // Informa sucesso.
                noecho();
                getch();
                echo();
                return true;
            }
            clear();
            mvprintw(linha/4 ,coluna/4,"%s",texto12);                                                       // Informa falha.
            noecho();
            getch();
            echo();
            return false;
        case 2:
            return false;
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::atualizar(Email email) {

    Usuario usuario;
    usuario.setEmail(email);
    Nome nome;
    Senha senha;
    char campo2[7];
    char campo1[21];

    char texto1[] ="O que você deseja altera?";
    char texto2[] ="1. Nome";
    char texto3[] ="2. Senha";
    char texto4[] ="Digite novo nome: ";
    char texto5[] ="Digite nova senha: ";
    char texto6[]="Dado em formato incorreto. Digite algo.";
    char texto7[] ="3. Retornar";
    char texto11[]="Sucesso no atualização. Digite algo.";
    char texto12[]="Falha no atualização. Digite algo.";

    int linha,coluna;
    int campo;

    getmaxyx(stdscr,linha,coluna);

    clear();
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto7);
    echo();
    campo = getch() - 48;
    noecho();

    switch(campo){
        case 1:
            echo();
            clear();
            mvprintw(linha/4,coluna/4,"%s",texto4);
            getstr(campo1);
            try {
                nome.setValor(campo1);
            }
            catch(invalid_argument &exp){
                mvprintw(linha/4,coluna/4,"%s",texto6);
                noecho();
                getch();
                echo();
                break;
            }
            usuario.setNome(nome);
            if(cntrServicoPessoal->atualizarNome(usuario)){
                clear();
                mvprintw(linha/4,coluna/4,"%s",texto11);                                               // Informa sucesso.
                noecho();
                getch();
                echo();
                break;
            }
            clear();
            mvprintw(linha/4,coluna/4,"%s",texto12);                                                       // Informa falha.
            noecho();
            getch();
            echo();
            break;
        case 2:
            echo();
            clear();
            mvprintw(linha/4,coluna/4,"%s",texto5);
            getstr(campo2);
            try {
                senha.setValor(campo2);
            }
            catch(invalid_argument &exp){
                mvprintw(linha/4 + 18,coluna/4,"%s",texto6);
                noecho();
                getch();
                echo();
                break;
            }
            usuario.setSenha(senha);
            if(cntrServicoPessoal->atualizarSenha(usuario)){
                clear();
                mvprintw(linha/4,coluna/4,"%s",texto11);                                               // Informa sucesso.
                noecho();
                getch();
                echo();
                break;
            }
            clear();
            mvprintw(linha/4,coluna/4,"%s",texto12);                                                       // Informa falha.
            noecho();
            getch();
            echo();
            break;
        case 3:
            return;
    }


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

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Titulo            :";
    char texto3[] ="Cidade            :";
    char texto4[] ="Duracao           :";
    char texto5[] ="Descricao           :";
    char texto6[] ="Endereco           :";
    char texto7[]="Dados em formato incorreto. Digite algo.";
    char texto8[]="Sucesso no cadastramento. Digite algo.";
    char texto9[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo4[80], campo5[80];
    int campo3;

    // Instancia os domínios.

    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.     // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                // Imprime nome do campo.
    campo3 = getch() - 48;
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                // Imprime nome do campo.
    getstr(campo4);
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);

    try{
        titulo.setValor(string(campo1));
        cidade.setValor(string(campo2));
        duracao.setValor(campo3);
        descricao.setValor(string(campo4));
        endereco.setValor(string(campo5));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Excursao excursao;

    // Cadastra excursao

    excursao.setTitulo(titulo);
    excursao.setCidade(cidade);
    excursao.setDuracao(duracao);
    excursao.setDescricao(descricao);
    excursao.setEndereco(endereco);
    excursao.setNota(nota);
    excursao.setCodigo(codigo);

    if(cntr->cadastrarExcursao(excursao)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto9);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
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



        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto1);
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto3);
        noecho();
        campo = getch() - 48;
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