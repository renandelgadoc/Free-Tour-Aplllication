#include "stubs.h"

// Adequar os valores.

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs.

bool StubServicoAutenticacao::autenticar(Email email, Senha senha){
    return true;
}

bool StubServicoPessoal::cadastrarUsuario(Usuario usuario){
    return true;
}

bool StubServicoExcursoes::cadastrarExcursao(Excursao excursao){
    return true;
}

bool StubServicoExcursoes::descadastrarExcursao(Codigo codigo){
    return true;
}

bool StubServicoExcursoes::cadastrarAvaliacao(Avaliacao avaliacao){
    return true;
}

bool StubServicoExcursoes::descadastrarAvaliacao(Codigo codigo){
    return true;
}

bool StubServicoExcursoes::cadastrarSessao(Avaliacao avaliacao){
    return true;
}

bool StubServicoExcursoes::descadastrarSessao(Codigo codigo){
    return true;
}



