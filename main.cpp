#include <string.h>
#include <stdexcept>
#include <iostream>

#include "curses.h"
#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"
#include "containers.h"

using namespace std;

// Instanciar containers com valor nullptr

    ContainerUsuario* ContainerUsuario::instancia = nullptr;
    ContainerExcursao* ContainerExcursao::instancia = nullptr;
    ContainerSessao* ContainerSessao::instancia = nullptr;
    ContainerAvaliacao* ContainerAvaliacao::instancia = nullptr;

int main(){

    // Instanciar controladoras de apresenta��o.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;
    IApresentacaoExcursoes *cntrApresentacaoExcursoes;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    cntrApresentacaoExcursoes = new CntrApresentacaoExcursoes();

    // Instanciar stubs de servi�o.

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoPessoal *cntrServicoPessoal;
    IServicoExcursoes *cntrServicoExcursoes;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoPessoal = new CntrServicoPessoal();
    cntrServicoExcursoes = new CntrServicoExcursoes();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrApresentacaoExcursoes(cntrApresentacaoExcursoes);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoAutenticacao->setCntrServicoPessoal(cntrServicoPessoal);

    cntrApresentacaoPessoal->setCntrServicoPessoal(cntrServicoPessoal);
    cntrApresentacaoPessoal->setCntrServicoExcursoes(cntrServicoExcursoes);

    cntrApresentacaoExcursoes->setCntrServicoExcursoes(cntrServicoExcursoes);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar servi�o apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}

