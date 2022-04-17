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

list<Excursao> CntrServicoExcursoes::getExcursoes() {
    return ContainerExcursao::getInstancia()->getExcursoes();
}

bool CntrServicoExcursoes::criarListaAvaliacao(Excursao excursao) {
    return ContainerListaAvaliacao::getInstancia()->incluir(excursao);
}

bool CntrServicoExcursoes::removerListaAvaliacao(Codigo codigo) {
    return ContainerListaAvaliacao::getInstancia()->remover(codigo);
}

list<Avaliacao> CntrServicoExcursoes::getAvaliacoes(Codigo codigo) {
    return ContainerListaAvaliacao::getInstancia()->getContainerAvaliacao(codigo)->getAvaliacoes();
}

bool CntrServicoExcursoes::cadastrarAvaliacao(Avaliacao avaliacao, Codigo codigo){
    return ContainerListaAvaliacao::getInstancia()->getContainerAvaliacao(codigo)->incluir(avaliacao);
}

bool CntrServicoExcursoes::descadastrarAvaliacao(Codigo codigoAvaliacao, Codigo codigoExcursao){
    return ContainerListaAvaliacao::getInstancia()->getContainerAvaliacao(codigoExcursao)->remover(codigoAvaliacao);
}

bool CntrServicoExcursoes::cadastrarSessao(Sessao sessao, Codigo codigo){
    return ContainerListaSessao::getInstancia()->getContainerSessao(codigo)->incluir(sessao);
}

bool CntrServicoExcursoes::descadastrarSessao(Codigo codigoSessao, Codigo codigoExcursao){
    return ContainerListaSessao::getInstancia()->getContainerSessao(codigoExcursao)->remover(codigoSessao);
}

bool CntrServicoExcursoes::criarListaSessao(Excursao excursao) {
    return ContainerListaSessao::getInstancia()->incluir(excursao);
}

bool CntrServicoExcursoes::removerListaSessao(Codigo codigo) {
    return ContainerListaSessao::getInstancia()->remover(codigo);
}

list<Sessao> CntrServicoExcursoes::getSessoes(Codigo codigo) {
    return ContainerListaSessao::getInstancia()->getContainerSessao(codigo)->getSessoes();
}

//---------------------------------------------------------------------
