#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declarações das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoPessoal;
class IServicoExcursoes;

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        virtual void setCntrServicoExcursoes(IServicoExcursoes*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoExcursoes{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoExcursoes(IServicoExcursoes*) = 0;
        virtual ~IApresentacaoExcursoes(){}
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual ~IServicoPessoal(){}
};

class IServicoExcursoes{
public:
        virtual bool cadastrarExcursao(Excursao) = 0;
        virtual bool descadastrarExcursao(Codigo) = 0;
        virtual bool cadastrarAvaliacao(Avaliacao) = 0;
        virtual bool descadastrarAvaliacao(Codigo) = 0;
        virtual bool cadastrarSessao(Avaliacao) = 0;
        virtual bool descadastrarSessao(Codigo) = 0;
        virtual ~IServicoExcursoes(){}
};

#endif // INTERFACES_H_INCLUDED
