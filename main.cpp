#include <string.h>
#include <stdexcept>
#include <iostream>

#include <ncurses.h>
#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Instanciar controladoras de apresentação.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;
    IApresentacaoExcursoes *cntrApresentacaoExcursoes;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    cntrApresentacaoExcursoes = new CntrApresentacaoExcursoes();

    // Instanciar stubs de serviço.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoPessoal *stubServicoPessoal;
    IServicoExcursoes *stubServicoExcursoes;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoPessoal = new StubServicoPessoal();
    stubServicoExcursoes = new StubServicoExcursoes();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrApresentacaoExcursoes(cntrApresentacaoExcursoes);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoPessoal->setCntrServicoPessoal(stubServicoPessoal);
    cntrApresentacaoPessoal->setCntrServicoExcursoes(stubServicoExcursoes);

    cntrApresentacaoExcursoes->setCntrServicoExcursoes(stubServicoExcursoes);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar serviço apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}

