#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do serviço autenticação.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço pessoal.

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço produtos financeiros.

class StubServicoExcursoes: public IServicoExcursoes {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarExcursao(Excursao);
        bool descadastrarExcursao(Codigo);
        bool cadastrarAvaliacao(Avaliacao);
        bool descadastrarAvaliacao(Codigo);
        bool cadastrarSessao(Avaliacao);
        bool descadastrarSessao(Codigo);

};

#endif // STUBS_H_INCLUDED
