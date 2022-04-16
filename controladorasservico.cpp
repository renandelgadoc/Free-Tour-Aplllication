#include "controladorasservico.h"

//--------------------------------------------------------------------------------------------
bool CntrServicoAutenticacao::autenticar(Usuario usuario){
    return ContainerUsuario::getInstancia()->autenticar(usuario);
}

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario){
    return ContainerUsuario::getInstancia()->incluir(usuario);
}

bool CntrServicoPessoal::descadastrarUsuario(Email email) {
    return ContainerUsuario::getInstancia()->remover(email);
}

bool CntrServicoPessoal::consultarUsuario(Usuario* usuario) {
    return ContainerUsuario::getInstancia()->pesquisar(usuario);
}

bool CntrServicoPessoal::atualizarSenha(Usuario usuario) {
    return ContainerUsuario::getInstancia()->atualizarSenha(usuario);
}

bool CntrServicoPessoal::atualizarNome(Usuario usuario) {
    return ContainerUsuario::getInstancia()->atualizarNome(usuario);
}

Usuario CntrServicoPessoal::getUsuario(Email email) {
    return ContainerUsuario::getInstancia()->getUsuario(email);
}

bool CntrServicoExcursoes::cadastrarExcursao(Excursao excursao){
    return ContainerExcursao::getInstancia()->incluir(excursao);
}

bool CntrServicoExcursoes::descadastrarExcursao(Codigo codigo){
    return ContainerExcursao::getInstancia()->remover(codigo);
}

bool CntrServicoExcursoes::autenticarExcursao(Codigo codigo){
    return ContainerExcursao::getInstancia()->autenticar(codigo);
}

bool CntrServicoExcursoes::cadastrarAvaliacao(Avaliacao avaliacao){
    return ContainerAvaliacao::getInstancia()->incluir(avaliacao);
}

bool CntrServicoExcursoes::descadastrarAvaliacao(Codigo codigo){
    return ContainerAvaliacao::getInstancia()->remover(codigo);
}

bool CntrServicoExcursoes::cadastrarSessao(Sessao sessao){
    return ContainerSessao::getInstancia()->incluir(sessao);
}

bool CntrServicoExcursoes::descadastrarSessao(Codigo codigo){
    return ContainerSessao::getInstancia()->remover(codigo);
}

//---------------------------------------------------------------------
