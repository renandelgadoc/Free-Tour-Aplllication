#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "containers.h"



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

};

//--------------------------------------------------------------------------------------------

class CntrServicoExcursoes:public IServicoExcursoes{
private:

public:
    bool cadastrarExcursao(Excursao);
    bool descadastrarExcursao(Codigo);
    bool autenticarExcursao(Codigo);
    bool cadastrarAvaliacao(Avaliacao);
    bool descadastrarAvaliacao(Codigo);
    bool cadastrarSessao(Sessao);
    bool descadastrarSessao(Codigo);
};

using namespace std;

// ----------------------------------------------------------------------


#endif // CONTROLADORASSERVICO_H_INCLUDED
