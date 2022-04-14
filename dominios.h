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
// Estrutura de c�digo para declara��o de classe dom�nio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // M�todo para validar valor.
    public:
        void setValor(Tipo);             // M�todo para atribuir valor.
        Tipo getValor() const;           // M�todo para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

----------------------------------------------------------------------- */
///
/// Padr�o para representa��o de Dura��o
///
/// Regras de formato para ser v�lido:
/// - Pertencer a seguinte lista: {30,60,90,120,180}
///

class Duracao {  //200073303
    private:
        int valoresValidos[5] = {30,60,90,120,180};
        int valorDuracao;
        ///
        /// Valida��o do valor informado
        /// @param valor Dura��o
        /// @return
        /// - Retorna true caso o valor seja v�lido
        /// - Retorna false caso o valor seja inv�lido
        ///
        bool validar(int);
    public:
        ///
        /// Armazena a dura��o
        ///@param valor Dura��o
        ///
        void setValor(int);
        ///
        /// Retorna a dura��o
        /// @return Dura��o
        ///
        int getValor() const;
};

inline int Duracao::getValor() const {  //200073303
    return valorDuracao;
}
///
/// Padr�o para representa��o de Endere�o
///
/// Regras de formato para ser v�lido:
///
/// - N�mero de caract�res entre 0 e 20
/// - N�o h� espa�os em branco em sequ�ncia.
/// - N�o h� pontos (.) em sequ�ncia.
///
class Endereco {  //200073303
    private:
        static const int minCaracteres = 0;
        static const int maxCaracteres = 20;
        string valorEndereco;
        ///
        /// Valida��o do valor informado
        /// @param valor Endere�o
        /// @return
        /// - Retorna true caso o valor seja v�lido
        /// - Retorna false caso o valor seja inv�lido
        ///
        bool validar(string);
    public:
        ///
        /// Armazena o endere�o
        /// @param valor Endere�o
        ///
        void setValor(string);
        ///
        /// Retorna o endere�o
        /// @return Endere�o
        ///
        string getValor() const;
};

inline string Endereco::getValor() const {  //200073303
    return valorEndereco;
}
///
/// Padr�o para representa��o de Descri��o
///
/// Regras de formato para ser v�lido:
/// - N�mero de caract�res entre 0 e 30
/// - N�o h� espa�os em branco em sequ�ncia.
/// - N�o h� pontos (.) em sequ�ncia.
///
class Descricao {  //200073303
private:
    static const int minCaracteres = 0;
    static const int maxCaracteres = 30;
    string valorDescricao;
    ///
    /// Valida��o do valor informado
    /// @param valor Descri��o
    /// @return
    /// - Retorna true caso o valor seja v�lido
    /// - Retorna false caso o valor seja inv�lido
    ///
    bool validar(string);
public:
    ///
    /// Armazena a descri��o
    /// @param valor Descri��o
    ///
    void setValor(string);
    ///
    /// Retorna a descri��o
    /// @return Descri��o
    ///
    string getValor() const;
};

inline string Descricao::getValor() const {  //200073303
    return valorDescricao;
}
///
/// Padr�o para representa��o de T�tulo
///
/// Regras de formato para ser v�lido:
/// - N�mero de caract�res entre 5 e 20
/// - Caract�res s�o somente letras do alfabeto
/// - N�o h� espa�os em branco em sequ�ncia.
/// - N�o h� pontos (.) em sequ�ncia.
//
class Titulo {  //200073303
private:
    static const int minCaracteres = 5;
    static const int maxCaracteres = 20;
    string valorTitulo;
    ///
    /// Valida��o do valor informado
    /// @param valor T�tulo
    /// @return
    /// - Retorna true caso o valor seja v�lido
    /// - Retorna false caso o valor seja inv�lido
    ///
    bool validar(string);
public:
    ///
    /// Armazena o t�tulo
    /// @param valor T�tulo
    ///
    void setValor(string);
    ///
    /// Retorna o t�tulo
    /// @return T�tulo
    ///
    string getValor() const;
};

inline string Titulo::getValor() const {  //200073303
    return valorTitulo;
}
///
/// Padr�o para representa��o de Hor�rio
///
/// Regras de formato para ser v�lido:
/// - N�mero de horas entre 0 e 23
/// - N�mero de minutos entre 0 e 59
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
    /// Valida��o do valor informado
    /// @param valor Hor�rio
    /// @return
    /// - Retorna true caso o valor seja v�lido
    /// - Retorna false caso o valor seja inv�lido
    ///
    bool validar(string);
public:
    ///
    /// Armazena o hor�rio
    /// @param valor Hor�rio
    ///
    void setValor(string);
    ///
    /// Retorna o hor�rio
    /// @return Hor�rio
    ///
    string getValor() const;
};

inline string Horario::getValor() const {  //200073303
    return valorHorario;
}
///
/// Padr�o para representa��o de Data
///
/// Regras de formato para ser v�lido:
/// - N�mero do dia entre 1 e 31 e v�lido conforme o m�s
/// - M�s pertence a seguinte lista: {Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez}
/// - Ano entre 2000 e 9999
/// - Formato DD-MES-AAAA (DD -> Dia, MES -> M�s, AAAA -> Ano)
/// - Daata considera a ocorr�ncia de anos bissextos
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
    /// Valida��o do valor informado
    /// @param valor Data
    /// @return
    /// - Retorna true caso o valor seja v�lido
    /// - Retorna false caso o valor seja inv�lido
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
/// Padr�o para representa��o de Cidade
///
/// Regras de formato para ser v�lido:
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
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de Idioma
///
/// Regras de formato para ser v�lido:
/// - Pertence a seguinte lista: {Ingl�s, Chin�s Mandarim, Hindi, Espanhol, Franc�s, �rabe, Bengali, Russo, Portugu�s,
///Indon�sio}
/// - Desconsiderar a acentua��o.
///
class Idioma {   //200062743
private:
    string idioma;
    string idiomasValidos[16] = {"Ingles", "Chines Mandarim", "Hindi",
                                 "Espanhol", "Frances", "Arabe", "Bengali",
                                 "Russo", "Portugues", "Indonesio"};
    ///
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de Senha
///
/// Regras de formato para ser v�lido:
/// - Formato: XXXXXX
/// - Cada caractere X � letra (A-Z ou a-z) ou d�gito (0-9).
/// - N�o existe caracter repetido.
/// - Existe pelo menos uma letra mai�scula, uma letra min�scula e um d�gito
///
class Senha {   //200062743
private:
    string senha;
    ///
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de Nome
///
/// Regras de formato para ser v�lido:
/// - N�mero de caracteres entre 5 e 20
/// - Cada caractere � letra (A-Z ou a-z), ponto (.) ou espa�o em branco.
/// - Ponto (.) � precedido por letra.
/// - Ponto (.) � �ltimo caractere ou � seguido por um espa�o em branco.
/// - N�o h� espa�os em branco em sequ�ncia.
/// - Primeira letra de cada termo � letra mai�scula (A-Z).
///
class Nome {   //200062743
private:
    string nome;
    ///
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de Nota
///
/// Regras de formato para ser v�lido:
/// - Pertence a seguinte lista: {0, 1, 2, 3, 4, 5}
///
class Nota {   //200062743
private:
    float nota = 0;
    int numeroNotas = 0;
    ///
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de Email
///
/// Regras de formato para ser v�lido:
/// - Formato parte-local@dom�nio
/// - parte-local � composta por at� 64 caracteres.
/// - Caractere de parte local pode ser letra mai�scula (A-Z) ou min�scula (a-z).
/// - Caractere de parte local pode ser d�gito (0-9).
/// - Caractere de parte local pode ser ! # $ % & ' * + - / = ? ^ _ ` { | } ~
/// - Caractere de parte local pode ser ponto (.) desde que n�o seja o primeiro ou o �ltimocaractere e que n�o ocorra em sequ�ncia.
/// - dom�nio � composto por at� 253 caracteres.
/// - Caractere de dom�nio pode ser letra mai�scula (A-Z) ou min�scula (a-z).
/// - Caractere de dom�nio pode ser d�gito (0-9).
/// - Caractere de dom�nio pode h�fen (-).
/// - Caractere de dom�nio pode ser ponto (.) desde que n�o seja o primeiro caractere e n�o ocorra em sequ�ncia.
///
class Email {   //200062743
private:
    string email;
    ///
    /// Valida��o do valor informado
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
/// Padr�o para representa��o de C�digo
///
/// Regras de formato para ser v�lido:
/// - Formato DDDDDDX
/// - D � d�gito (0-9).
/// - N�o existe o c�digo 000000.
/// - X � d�gito verificador.
///
class Codigo { //200062743
private:
    string codigo;
    static int semente;
    static string codigosExistentes[100];
    ///
    /// Valida��o do valor informado
    /// @param valor C�digo
    /// @return
    /// - Retorna true caso o valor seja v�lido
    /// - Retorna false caso o valor seja inv�lido
    ///
    bool verificar(string);
public:
    Codigo();
    ///
    /// Armazena o c�digo
    /// @param valor C�digo
    ///
    void setValor(string);
    ///
    /// Retorna o c�digo
    /// @return C�digo
    ///
    string getValor() const;
    void createValor();
};


inline string Codigo::getValor() const {
    return codigo;
}

#endif //PROJETO_TRABALHO_1_DOMINIOS_H
