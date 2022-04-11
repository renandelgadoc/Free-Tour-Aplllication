#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include <ncurses.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IApresentacaoExcursoes *cntrApresentacaoExcursoes;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
        void setCntrApresentacaoExcursoes(IApresentacaoExcursoes*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr){
            cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursoes(IApresentacaoExcursoes *cntr){
    cntrApresentacaoExcursoes = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntrServicoAutenticacao;
        IServicoPessoal *cntrServicoPessoal;

public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
        void setCntrServicoPessoal(IServicoPessoal*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    cntrServicoAutenticacao = cntr;
}

inline void CntrApresentacaoAutenticacao::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        IServicoExcursoes *cntrServicoExcursoes;
        void consultarDadosPessoais(Email email);
    public:
        bool executar(Email);
        void cadastrar();
        bool descadrastar(Email);
        void setCntrServicoPessoal(IServicoPessoal*);
        void setCntrServicoExcursoes(IServicoExcursoes*);
        void atualizar(Email);
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

inline void CntrApresentacaoPessoal::setCntrServicoExcursoes(IServicoExcursoes *cntr){
    cntrServicoExcursoes = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoExcursoes: public IApresentacaoExcursoes{
    private:
        IServicoExcursoes *cntr;
        void cadastrarExcursao();
        void descadastrarExcursao();
        void consultarExcursao();
        void cadastrarAvaliacao() ;
        void descadastrarAvaliacao() ;
        void cadastrarSessao() ;
        void descadastrarSessao() ;
    public:
        void executar();
        void executar(Email);
        void setCntrServicoExcursoes(IServicoExcursoes*);
};

inline void CntrApresentacaoExcursoes::setCntrServicoExcursoes(IServicoExcursoes *cntr){
    this->cntr = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
