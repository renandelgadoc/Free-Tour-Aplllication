//
// Created by Thiago 200073303
//

#ifndef PROJETO_TRABALHO_1_DOMINIOS_H
#define PROJETO_TRABALHO_1_DOMINIOS_H

#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de código para declaração de classe domínio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // Método para validar valor.
    public:
        void setValor(Tipo);             // Método para atribuir valor.
        Tipo getValor() const;           // Método para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

----------------------------------------------------------------------- */
///
/// Padrão para representação de Duração
///
/// Regras de formato para ser válido:
/// - Pertencer a seguinte lista: {30,60,90,120,180}
///

class Duracao {  //200073303
    private:
        int valoresValidos[5] = {30,60,90,120,180};
        int valorDuracao;
        ///
        /// Validação do valor informado
        /// @param valor Duração
        /// @return
        /// - Retorna true caso o valor seja válido
        /// - Retorna false caso o valor seja inválido
        ///
        bool validar(int);
    public:
        ///
        /// Armazena a duração
        ///@param valor Duração
        ///
        void setValor(int);
        ///
        /// Retorna a duração
        /// @return Duração
        ///
        int getValor() const;
};

inline int Duracao::getValor() const {  //200073303
    return valorDuracao;
}
///
/// Padrão para representação de Endereço
///
/// Regras de formato para ser válido:
///
/// - Número de caractéres entre 0 e 20
/// - Não há espaços em branco em sequência.
/// - Não há pontos (.) em sequência.
///
class Endereco {  //200073303
    private:
        static const int minCaracteres = 0;
        static const int maxCaracteres = 20;
        string valorEndereco;
        ///
        /// Validação do valor informado
        /// @param valor Endereço
        /// @return
        /// - Retorna true caso o valor seja válido
        /// - Retorna false caso o valor seja inválido
        ///
        bool validar(string);
    public:
        ///
        /// Armazena o endereço
        /// @param valor Endereço
        ///
        void setValor(string);
        ///
        /// Retorna o endereço
        /// @return Endereço
        ///
        string getValor() const;
};

inline string Endereco::getValor() const {  //200073303
    return valorEndereco;
}
///
/// Padrão para representação de Descrição
///
/// Regras de formato para ser válido:
/// - Número de caractéres entre 0 e 30
/// - Não há espaços em branco em sequência.
/// - Não há pontos (.) em sequência.
///
class Descricao {  //200073303
private:
    static const int minCaracteres = 0;
    static const int maxCaracteres = 30;
    string valorDescricao;
    ///
    /// Validação do valor informado
    /// @param valor Descrição
    /// @return
    /// - Retorna true caso o valor seja válido
    /// - Retorna false caso o valor seja inválido
    ///
    bool validar(string);
public:
    ///
    /// Armazena a descrição
    /// @param valor Descrição
    ///
    void setValor(string);
    ///
    /// Retorna a descrição
    /// @return Descrição
    ///
    string getValor() const;
};

inline string Descricao::getValor() const {  //200073303
    return valorDescricao;
}
///
/// Padrão para representação de Título
///
/// Regras de formato para ser válido:
/// - Número de caractéres entre 5 e 20
/// - Caractéres são somente letras do alfabeto
/// - Não há espaços em branco em sequência.
/// - Não há pontos (.) em sequência.
//
class Titulo {  //200073303
private:
    static const int minCaracteres = 5;
    static const int maxCaracteres = 20;
    string valorTitulo;
    ///
    /// Validação do valor informado
    /// @param valor Título
    /// @return
    /// - Retorna true caso o valor seja válido
    /// - Retorna false caso o valor seja inválido
    ///
    bool validar(string);
public:
    ///
    /// Armazena o título
    /// @param valor Título
    ///
    void setValor(string);
    ///
    /// Retorna o título
    /// @return Título
    ///
    string getValor() const;
};

inline string Titulo::getValor() const {  //200073303
    return valorTitulo;
}
///
/// Padrão para representação de Horário
///
/// Regras de formato para ser válido:
/// - Número de horas entre 0 e 23
/// - Número de minutos entre 0 e 59
/// - Formato HH:MM (HH -> Horas, MM -> Minutos)
///
class Horario {  //200073303
private:
    static const int maxHoras = 23;
    static const int minHoras = 0;
    static const int maxMinutos = 59;
    static const int minMinutos = 0;
    string valorHorario;
    ///
    /// Validação do valor informado
    /// @param valor Horário
    /// @return
    /// - Retorna true caso o valor seja válido
    /// - Retorna false caso o valor seja inválido
    ///
    bool validar(string);
public:
    ///
    /// Armazena o horário
    /// @param valor Horário
    ///
    void setValor(string);
    ///
    /// Retorna o horário
    /// @return Horário
    ///
    string getValor() const;
};

inline string Horario::getValor() const {  //200073303
    return valorHorario;
}
///
/// Padrão para representação de Data
///
/// Regras de formato para ser válido:
/// - Número do dia entre 1 e 31 e válido conforme o mês
/// - Mês pertence a seguinte lista: {Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez}
/// - Ano entre 2000 e 9999
/// - Formato DD-MES-AAAA (DD -> Dia, MES -> Mês, AAAA -> Ano)
/// - Daata considera a ocorrência de anos bissextos
///
class Data {  //200073303
private:
    static const int minDiasTotal = 1;
    static const int maxDiasTotal = 31;
    map<string,int> mesesValidos = {
            {"Jan",31},
            {"Fev",28},
            {"Mar",31},
            {"Abr",30},
            {"Mai",31},
            {"Jun",30},
            {"Jul",31},
            {"Ago",31},
            {"Set",30},
            {"Out",31},
            {"Nov",30},
            {"Dez",31}
    };
    static const int minAnos = 2000;
    static const int maxAnos = 9999;
    string valorData;
    ///
    /// Validação do valor informado
    /// @param valor Data
    /// @return
    /// - Retorna true caso o valor seja válido
    /// - Retorna false caso o valor seja inválido
    //
    bool validar(string);
public:
    ///
    /// Armazena a data
    /// @param valor Data
    ///
    void setValor(string);
    ///
    /// Retorna a data
    /// @return Data
    ///
    string getValor() const;
};

inline string Data::getValor() const {  //200073303
    return valorData;
}

///
/// Created by Renan 200062743
///

using namespace std;
///
/// Padrão para representação de Cidade
///
/// Regras de formato para ser válido:
/// - Pertence a seguinte lista: {Hong Kong, Bangkok, Macau, Singapura, Londres, Paris, Dubai, Delhi, Istambul, Kuala
///Lumpur, Nova Iorque, Antalya, Mumbai, Shenzhen, Phuket}
///
class Cidade {   //200062743
private:
    string cidade;
    string cidadesValidas[16] = {"Hong Kong", "Bangkok", "Macau", "Singapura",
                                 "Londres","Paris", "Dubai", "Delhi",
                                 "Istambul", "Kuala","Lumpur", "Nova Iorque",
                                 "Antalya", "Mumbai", "Shenzhen", "Phuket"};
    ///
    /// Validação do valor informado
    /// @param valor Cidade
    ///
    void validar(string);

public:
    ///
    /// Armazena a cidade
    /// @param valor Cidade
    ///
    void setValor(string);
    ///
    /// Retorna a cidade
    /// @return Cidade
    ///
    string getValor() const;
};

inline string Cidade::getValor() const {   //200062743
    return cidade;
}

///
/// Padrão para representação de Idioma
///
/// Regras de formato para ser válido:
/// - Pertence a seguinte lista: {Inglês, Chinês Mandarim, Hindi, Espanhol, Francês, Árabe, Bengali, Russo, Português,
///Indonésio}
/// - Desconsiderar a acentuação.
///
class Idioma {   //200062743
private:
    string idioma;
    string idiomasValidos[16] = {"Ingles", "Chines Mandarim", "Hindi",
                                 "Espanhol", "Frances", "Arabe", "Bengali",
                                 "Russo", "Portugues", "Indonesio"};
    ///
    /// Validação do valor informado
    /// @param valor Cidade
    ///
    void validar(string);

public:
    ///
    /// Armazena o idioma
    /// @param valor Idioma
    ///
    void setValor(string);
    ///
    /// Retorna o idioma
    /// @return Idioma
    ///
    string getValor() const;
};

inline string Idioma::getValor() const {   //200062743
    return idioma;
}
///
/// Padrão para representação de Senha
///
/// Regras de formato para ser válido:
/// - Formato: XXXXXX
/// - Cada caractere X é letra (A-Z ou a-z) ou dígito (0-9).
/// - Não existe caracter repetido.
/// - Existe pelo menos uma letra maiúscula, uma letra minúscula e um dígito
///
class Senha {   //200062743
private:
    string senha;
    ///
    /// Validação do valor informado
    /// @param valor Senha
    ///
    void validar(string);

public:
    ///
    /// Armazena a senha
    /// @param valor Senha
    ///
    void setValor(string);
    ///
    /// Retorna a senha
    /// @return Senha
    ///
    string getValor() const;

};

inline string Senha::getValor() const {   //200062743
    return senha;
}
///
/// Padrão para representação de Nome
///
/// Regras de formato para ser válido:
/// - Número de caracteres entre 5 e 20
/// - Cada caractere é letra (A-Z ou a-z), ponto (.) ou espaço em branco.
/// - Ponto (.) é precedido por letra.
/// - Ponto (.) é último caractere ou é seguido por um espaço em branco.
/// - Não há espaços em branco em sequência.
/// - Primeira letra de cada termo é letra maiúscula (A-Z).
///
class Nome {   //200062743
private:
    string nome;
    ///
    /// Validação do valor informado
    /// @param valor Nome
    ///
    void validar(string);
public:
    ///
    /// Armazena o nome
    /// @param valor Nome
    ///
    void setValor(string);
    ///
    /// Retorna o nome
    /// @return Nome
    ///
    string getValor() const;
};

inline string Nome::getValor() const {   //200062743
    return nome;
}
///
/// Padrão para representação de Nota
///
/// Regras de formato para ser válido:
/// - Pertence a seguinte lista: {0, 1, 2, 3, 4, 5}
///
class Nota {   //200062743
private:
    float nota = 0;
    int numeroNotas = 0;
    ///
    /// Validação do valor informado
    /// @param valor Nome
    ///
    void validar(int);
public:
    ///
    /// Armazena a nota
    /// @param valor Nota
    ///
    void setValor(int);
    ///
    /// Retorna a nota
    /// @return Nota
    ///
    float getValor() const;
};

inline float Nota::getValor() const {   //200062743
    return nota;
}
///
/// Padrão para representação de Email
///
/// Regras de formato para ser válido:
/// - Formato parte-local@domínio
/// - parte-local é composta por até 64 caracteres.
/// - Caractere de parte local pode ser letra maiúscula (A-Z) ou minúscula (a-z).
/// - Caractere de parte local pode ser dígito (0-9).
/// - Caractere de parte local pode ser ! # $ % & ' * + - / = ? ^ _ ` { | } ~
/// - Caractere de parte local pode ser ponto (.) desde que não seja o primeiro ou o últimocaractere e que não ocorra em sequência.
/// - domínio é composto por até 253 caracteres.
/// - Caractere de domínio pode ser letra maiúscula (A-Z) ou minúscula (a-z).
/// - Caractere de domínio pode ser dígito (0-9).
/// - Caractere de domínio pode hífen (-).
/// - Caractere de domínio pode ser ponto (.) desde que não seja o primeiro caractere e não ocorra em sequência.
///
class Email {   //200062743
private:
    string email;
    ///
    /// Validação do valor informado
    /// @param valor Email
    ///
    void validar(string);
public:
    ///
    /// Armazena o email
    /// @param valor Email
    ///
    void setValor(string);
    ///
    /// Retorna o email
    /// @return Email
    ///
    string getValor() const;
};

inline string Email::getValor() const {   //200062743
    return email;
}
///
/// Padrão para representação de Código
///
/// Regras de formato para ser válido:
/// - Formato DDDDDDX
/// - D é dígito (0-9).
/// - Não existe o código 000000.
/// - X é dígito verificador.
///
class Codigo { //200062743
private:
    string codigo;
    static int semente;
    static string codigosExistentes[100];
    ///
    /// Validação do valor informado
    /// @param valor Código
    /// @return
    /// - Retorna true caso o valor seja válido
    /// - Retorna false caso o valor seja inválido
    ///
    bool verificar(string);
public:
    Codigo();
    ///
    /// Armazena o código
    /// @param valor Código
    ///
    void setValor();
    ///
    /// Retorna o código
    /// @return Código
    ///
    string getValor() const;
};


inline string Codigo::getValor() const {
    return codigo;
}

#endif //PROJETO_TRABALHO_1_DOMINIOS_H
