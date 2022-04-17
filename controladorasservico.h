#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "containers.h"
#include <list>


//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços.
//
// Falta implementar códigos.

class CntrServicoAutenticacao:public IServicoAutenticacao{
public:
    bool autenticar(Usuario);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal:public IServicoPessoal{
public:
    bool cadastrarUsuario(Usuario);
    bool descadastrarUsuario(Email);
    bool consultarUsuario(Usuario*);
    bool atualizarSenha(Usuario);
    bool atualizarNome(Usuario);
    Usuario getUsuario(Email);

};

//--------------------------------------------------------------------------------------------

class CntrServicoExcursoes:public IServicoExcursoes{
private:

public:
    bool cadastrarExcursao(Excursao);
    bool descadastrarExcursao(Codigo);
    list<Excursao> getExcursoes();
    bool criarListaAvaliacao(Excursao);
    bool removerListaAvaliacao(Codigo);
    list<Avaliacao> getAvaliacoes(Codigo);
    bool cadastrarAvaliacao(Avaliacao,Codigo);
    bool descadastrarAvaliacao(Codigo, Codigo);
    bool cadastrarSessao(Sessao,Codigo);
    bool descadastrarSessao(Codigo,Codigo);
    list<Sessao> getSessoes(Codigo);
    bool criarListaSessao(Excursao);
    bool removerListaSessao(Codigo);
};

using namespace std;

// ----------------------------------------------------------------------


#endif // CONTROLADORASSERVICO_H_INCLUDED
