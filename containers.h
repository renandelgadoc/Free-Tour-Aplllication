#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

// ----------------------------------------------------------------------
// Declaração de classe container.

class ContainerUsuario{
private:
    list<Usuario> container;
public:
    bool incluir(Usuario);
    bool remover(Email);
    bool pesquisar(Usuario*);
    bool atualizar(Usuario);
};

class ContainerExcursao{
private:
    list<Excursao> container;
public:
    bool incluir(Excursao);
    bool remover(Codigo);
    bool pesquisar(Excursao*);
    bool atualizar(Excursao);
};

class ContainerSessao{
private:
    list<Sessao> container;
public:
    bool incluir(Sessao);
    bool remover(Codigo);
    bool pesquisar(Sessao*);
    bool atualizar(Sessao);
};

class ContainerAvaliacao{
private:
    list<Avaliacao> container;
public:
    bool incluir(Avaliacao);
    bool remover(Codigo);
    bool pesquisar(Avaliacao*);
    bool atualizar(Avaliacao);
};

#endif // CONTAINERS_H_INCLUDED
