//
// Created by Thiago 200073303
//

#ifndef PROJETO_TRABALHO_1_ENTIDADES_H
#define PROJETO_TRABALHO_1_ENTIDADES_H

#include "dominios.h"

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de c�digo sugerida para declara��o de classe entidade.
// Substituir Entidade por nome da classe.
// Substituir Dominio.
// Substituir nomeAtributo.

class Entidade {
    private:
            Dominio nomeAtributo;                   // Declarar cada atributo da classe.
    public:
            void setnomeAtributo(const Dominio&);   // Declarar m�todo set para cada atributo.
            Dominio getnomeAtributo() const;        // Declarar m�todo get para cada atributo.
};

inline void Entidade::setnomeAtributo(const Dominio &nomeAtributo){
    this->nomeAtributo = nomeAtributo;
}

inline Dominio Entidade::getnomeAtributo() const{
    return nomeAtributo;
}

----------------------------------------------------------------------- */
///
/// Padr�o para representa��o de Usu�rio
///
/// Regras de formato para ser v�lido:
/// - Ter um nome v�lido
/// - Ter um email v�lido
/// - Ter uma senha v�lida
///
class Usuario {
private:
    Nome nome;
    Email email;
    Senha senha;
public:
    void setNome(const Nome&);
    Nome getNome() const;
    void setEmail(const Email&);
    Email getEmail() const;
    void setSenha(const Senha&);
    Senha getSenha() const;
};

inline void Usuario::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Usuario::getNome() const {
    return nome;
}

inline void Usuario::setEmail(const Email& email) {
    this->email = email;
}

inline Email Usuario::getEmail() const {
    return email;
}

inline void Usuario::setSenha(const Senha& senha) {
    this->senha = senha;
}

inline Senha Usuario::getSenha() const {
    return senha;
}
///
/// Padr�o para representa��o de Avalia��o
///
/// Regras de formato para ser v�lido:
/// - Ter um c�digo v�lido
/// - Ter uma nota v�lida
/// - Ter uma descri��o v�lida
///
class Avaliacao {
private:
    Codigo codigo;
    Nota nota;
    Descricao descricao;
public:
    void setCodigo(const Codigo&);
    Codigo getCodigo() const;
    void setNota(const Nota&);
    Nota getNota() const;
    void setDescricao(const Descricao&);
    Descricao getDescricao() const;
};

inline void Avaliacao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Avaliacao::getCodigo() const {
   return codigo;
}

inline void Avaliacao::setNota(const Nota& nota) {
    this->nota = nota;
}

inline Nota Avaliacao::getNota() const {
    return nota;
}

inline void Avaliacao::setDescricao(const Descricao& descricao) {
    this->descricao = descricao;
}

inline Descricao Avaliacao::getDescricao() const {
    return descricao;
}
///
/// Padr�o para representa��o de Sess�o
///
/// Regras de formato para ser v�lido:
/// - Ter um c�digo v�lido
/// - Ter uma data v�lida
/// - Ter um hor�rio v�lido
/// - Ter um idioma v�lido
///
class Sessao {
private:
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;
public:
    void setCodigo(const Codigo&);
    Codigo getCodigo() const;
    void setData(const Data&);
    Data getData() const;
    void setHorario(const Horario&);
    Horario getHorario() const;
    void setIdioma(const Idioma&);
    Idioma getIdioma() const;
};

inline void Sessao::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Codigo Sessao::getCodigo() const {
    return codigo;
}

inline void Sessao::setData(const Data& data) {
    this->data = data;
}

inline Data Sessao::getData() const {
    return data;
}

inline void Sessao::setHorario(const Horario& horario) {
    this->horario = horario;
}

inline Horario Sessao::getHorario() const {
    return horario;
}

inline void Sessao::setIdioma(const Idioma& idioma) {
    this->idioma = idioma;
}

inline Idioma Sessao::getIdioma() const {
    return idioma;
}
///
/// Padr�o para representa��o de Excurs�o
///
/// Regras de formato para ser v�lido:
/// - Ter um c�digo v�lido
/// - Ter um t�tulo v�lido
/// - Ter uma cidade v�lida
/// - Ter uma dura��o v�lida
/// - Ter uma descri��o v�lida
/// - Ter um endere�o v�lido
///
class Excursao {
private:
    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
public:
    void setCodigo(const Codigo&);
    Codigo getCodigo() const;
    void setTitulo(const Titulo&);
    Titulo getTitulo() const;
    void setNota(const Nota&);
    Nota getNota() const;
    void setCidade(const Cidade&);
    Cidade getCidade() const;
    void setDuracao(const Duracao&);
    Duracao getDuracao() const;
    void setDescricao(const Descricao&);
    Descricao getDescricao() const;
    void setEndereco(const Endereco&);
    Endereco getEndereco() const;
};

inline void Excursao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Excursao::getCodigo() const {
   return codigo;
}

inline void Excursao::setTitulo(const Titulo& titulo) {
    this->titulo = titulo;
}

inline Titulo Excursao::getTitulo() const {
    return titulo;
}

inline void Excursao::setNota(const Nota& nota) {
    this->nota = nota;
}

inline Nota Excursao::getNota() const {
    return nota;
}

inline void Excursao::setCidade(const Cidade& cidade) {
    this->cidade = cidade;
}

inline Cidade Excursao::getCidade() const {
    return cidade;
}

inline void Excursao::setDuracao(const Duracao& duracao) {
    this->duracao = duracao;
}

inline Duracao Excursao::getDuracao() const {
    return duracao;
}

inline void Excursao::setDescricao(const Descricao& descricao) {
    this->descricao = descricao;
}

inline Descricao Excursao::getDescricao() const {
    return descricao;
}

inline void Excursao::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

inline Endereco Excursao::getEndereco() const {
    return endereco;
}

#endif //PROJETO_TRABALHO_1_ENTIDADES_H
