//
// Created by renan on 06/04/2022.
//

#ifndef TP1T2_CONTAINERS_H
#define TP1T2_CONTAINERS_H
#include <list>
#include "dominios.h"
#include "entidades.h"

// Declara��o de classe container.

class ContainerUsuario{
private:
    list<Usuario> container;                        // Lista de usu�rios.
    static ContainerUsuario *instancia;             // Ponteiro para inst�ncia da classe.     // Construtor.
public:
    static ContainerUsuario* getInstancia();       // M�todo para instanciar classe.
    bool incluir(Usuario);
    bool remover(Email);
    bool pesquisar(Usuario*);
    bool atualizarSenha(Usuario);
    bool atualizarNome(Usuario);
    bool autenticar(Usuario);
    Usuario getUsuario(Email);
};


class ContainerExcursao{
private:
    list<Excursao> container;
    static ContainerExcursao *instancia;
public:
    static ContainerExcursao* getInstancia();
    bool incluir(Excursao);
    bool remover(Codigo);
    bool pesquisar(Excursao*);
    bool atualizar(Excursao);
    bool autenticar(Codigo);
    list<Excursao> getExcursoes();
};


class ContainerSessao{
private:
    list<Sessao> container;
    static ContainerSessao *instancia;
public:
    static ContainerSessao* getInstancia();
    bool incluir(Sessao);
    bool remover(Codigo);
    bool pesquisar(Sessao*);
    bool atualizar(Sessao);
};

class ContainerAvaliacao{
private:
    list<Avaliacao> container;
    Excursao excursao;
public:
    ContainerAvaliacao(){};
    bool incluir(Avaliacao);
    bool remover(Codigo);
    bool pesquisar(Avaliacao*);
    bool atualizar(Avaliacao);
    Excursao getExcursao() const;
    list<Avaliacao> getAvaliacoes();
    void setExcursao(Excursao);
};

inline Excursao ContainerAvaliacao::getExcursao() const {
    return excursao;
}

class ContainerListaAvaliacao{
private:
    list<ContainerAvaliacao> container;
    static ContainerListaAvaliacao *instancia;
public:
    static ContainerListaAvaliacao* getInstancia();
    bool incluir(Excursao);
    bool remover(Codigo);
    ContainerAvaliacao* getContainerAvaliacao(Codigo);
};

#endif //TP1T2_CONTAINERS_H
