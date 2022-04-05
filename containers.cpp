#include "containers.h"

// ----------------------------------------------------------------------
// Implementações de métodos de classe container.

bool ContainerUsuario::incluir(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == usuario.getEmail().getValor()){
            return false;
        }
    }
    container.push_back(usuario);                               // Incluir objeto.
    return true;
}

bool ContainerUsuario::remover(Email email){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == email.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::pesquisar(Usuario* usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == usuario->getEmail().getValor()){
            usuario->setEmail(elemento->getEmail());    // Copiar atributos de objeto localizado.
            usuario->setSenha(elemento->getSenha());
			usuario->setNome(elemento->getNome());
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::atualizar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == usuario.getEmail().getValor()){
            elemento->setEmail(usuario.getEmail());     // Copiar atributos para objeto localizado.
            elemento->setSenha(usuario.getSenha());
			elemento->setNome(usuario.getNome());
            return true;
        }
    }
    return false;
}

// Excursao =-=-=-=-=-=-=

bool ContainerExcursao::incluir(Excursao excursao){
    for(list<Excursao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == excursao.getCodigo().getValor()){
            return false;
        }
    }
    container.push_back(excursao);                               // Incluir objeto.
    return true;
}

bool ContainerExcursao::remover(Codigo codigo){
    for(list<Excursao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerExcursao::pesquisar(Excursao* excursao){
    for(list<Excursao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == excursao->getCodigo().getValor()){
            excursao->setCodigo(elemento->getCodigo());    // Copiar atributos de objeto localizado.
            excursao->setTitulo(elemento->getTitulo());
			excursao->setNota(elemento->getNota());
			excursao->setCidade(elemento->getCidade());
			excursao->setDuracao(elemento->getDuracao());
			excursao->setDescricao(elemento->getDescricao());
			excursao->setEndereco(elemento->getEndereco());
            return true;
        }
    }
    return false;
}

bool ContainerExcursao::atualizar(Excursao excursao){
    for(list<Excursao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == excursao.getCodigo().getValor()){
            elemento->setCodigo(excursao.getCodigo());     // Copiar atributos para objeto localizado.
            elemento->setTitulo(excursao.getTitulo());
			elemento->setNota(excursao.getNota());
			elemento->setCidade(excursao.getCidade());
			elemento->setDuracao(excursao.getDuracao());
			elemento->setDescricao(excursao.getDescricao());
			elemento->setEndereco(excursao.getEndereco());
            return true;
        }
    }
    return false;
}

// Sessao =-=-=-=-=-=-=

bool ContainerSessao::incluir(Sessao sessao){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sessao.getCodigo().getValor()){
            return false;
        }
    }
    container.push_back(sessao);                               // Incluir objeto.
    return true;
}

bool ContainerSessao::remover(Codigo codigo){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerSessao::pesquisar(Sessao* sessao){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sessao->getCodigo().getValor()){
            sessao->setCodigo(elemento->getCodigo());    // Copiar atributos de objeto localizado.
            sessao->setData(elemento->getData());
			sessao->setHorario(elemento->getHorario());
			sessao->setIdioma(elemento->getIdioma());
            return true;
        }
    }
    return false;
}

bool ContainerSessao::atualizar(Sessao sessao){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sessao.getCodigo().getValor()){
            elemento->setCodigo(sessao.getCodigo());     // Copiar atributos para objeto localizado.
            elemento->setData(sessao.getData());
			elemento->setHorario(sessao.getHorario());
			elemento->setIdioma(sessao.getIdioma());
            return true;
        }
    }
    return false;
}

// Avaliacao =-=-=-=-=-=-=

bool ContainerAvaliacao::incluir(Avaliacao avaliacao){
    for(list<Avaliacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == avaliacao.getCodigo().getValor()){
            return false;
        }
    }
    container.push_back(avaliacao);                               // Incluir objeto.
    return true;
}

bool ContainerAvaliacao::remover(Codigo codigo){
    for(list<Avaliacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerAvaliacao::pesquisar(Avaliacao* avaliacao){
    for(list<Avaliacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == avaliacao->getCodigo().getValor()){
            avaliacao->setCodigo(elemento->getCodigo());    // Copiar atributos de objeto localizado.
            avaliacao->setNota(elemento->getNota());
			avaliacao->setDescricao(elemento->getDescricao());
            return true;
        }
    }
    return false;
}

bool ContainerAvaliacao::atualizar(Avaliacao avaliacao){
    for(list<Avaliacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == avaliacao.getCodigo().getValor()){
            elemento->setCodigo(avaliacao.getCodigo());     // Copiar atributos para objeto localizado.
            elemento->setNota(avaliacao.getNota());
			elemento->setDescricao(avaliacao.getDescricao());
            return true;
        }
    }
    return false;
}