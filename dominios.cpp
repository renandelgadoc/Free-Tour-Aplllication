//
// Created by Thiago Vale Giffoni 200073303
//

#include "dominios.h"

bool Duracao::validar(int valorDuracao) {  //200073303
    int i;
    bool valido = false;
    for (i=0; i < 5; i++) {
        if (valoresValidos[i] == valorDuracao) {
            valido = true;
            break;
        }
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;
}

void Duracao::setValor(int valorDuracao) {  //200073303
    if (validar(valorDuracao)) {
        this->valorDuracao=valorDuracao;
    }
}

bool Endereco::validar(string valorEndereco) {  //200073303
    bool valido = false;
    int quantidadeCaracteres = valorEndereco.length();
    if (quantidadeCaracteres > maxCaracteres) {
        valido = false;
    } else if (quantidadeCaracteres < minCaracteres) {
        valido = false;
    } else {
        valido = true;
    }
    if (valorEndereco.find("  ") <= quantidadeCaracteres or valorEndereco.find("..") <= quantidadeCaracteres) {
        valido = false;
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;
}

void Endereco::setValor(string valorEndereco) {  //200073303
    if (validar(valorEndereco)) {
        this->valorEndereco=valorEndereco;
    }
}

bool Descricao::validar(string valorDescricao) {  //200073303
    bool valido = true;
    int quantidadeCaracteres = valorDescricao.length();
    if (quantidadeCaracteres > maxCaracteres) {
        valido = false;
    } else if (quantidadeCaracteres < minCaracteres) {
        valido = false;
    } else {
        valido = true;
    }
    if (valorDescricao.find("  ") <= quantidadeCaracteres or valorDescricao.find("..") <= quantidadeCaracteres) {
        valido = false;
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;
}

void Descricao::setValor(string valorDescricao) {  //200073303
    if (validar(valorDescricao)) {
        this->valorDescricao=valorDescricao;
    }
}

bool Titulo::validar(string valorTitulo) {  //200073303
    bool valido = false;
    int quantidadeCaracteres = valorTitulo.length();
    if (quantidadeCaracteres > maxCaracteres) {
        valido = false;
    } else if (quantidadeCaracteres < minCaracteres) {
        valido = false;
    } else {
        valido = true;
    }
    if (valorTitulo.find("  ") <= quantidadeCaracteres or valorTitulo.find("..") <= quantidadeCaracteres) {
        valido = false;
    }
    for (int i = 0; i < valorTitulo.length(); i++) {
        if (valorTitulo[i] < 'A' or valorTitulo[i] > 'Z' and valorTitulo[i] < 'a' or valorTitulo[i] > 'z') {
            if (valorTitulo[i] != ' ' and valorTitulo[i] != '.') {
                valido = false;
            }
        }
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;
}

void Titulo::setValor(string valorTitulo) {  //200073303
    if (validar(valorTitulo)) {
        this->valorTitulo=valorTitulo;
    }
}

bool Horario::validar(string valorHorario) {  //200073303
    bool valido = false;
    string stringHora;
    string stringMinuto;
    int doisPontos = 0;
    for (int i = 0; i<valorHorario.length(); i++) {
        if (valorHorario[i] == ':') {
            doisPontos = 1;
        } else if (doisPontos == 0) {
            stringHora = stringHora + valorHorario[i];
        } else {
            stringMinuto = stringMinuto + valorHorario[i];
        }
    }
    int inteiroHora;
    int inteiroMinuto;
    stringstream converteHora(stringHora);
    stringstream converteMinuto(stringMinuto);
    converteHora >> inteiroHora;
    converteMinuto >> inteiroMinuto;

    if (inteiroHora >= minHoras and inteiroHora <= maxHoras) {
        if (inteiroMinuto >= minMinutos and inteiroMinuto <= maxMinutos) {
            valido = true;
        }
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;

}

void Horario::setValor(string valorHorario) {  //200073303
    if (validar(valorHorario)) {
        this->valorHorario = valorHorario;
    }
}

bool Data::validar(string valorData) {  //200073303
    bool valido = true;
    string stringDia;
    string stringMes;
    string stringAno;
    int hifen = 0;
    for (int i = 0; i < valorData.length(); i++) {
        if (valorData[i] == '-') {
            hifen = hifen + 1;
        } else if (hifen == 0) {
            stringDia = stringDia + valorData[i];
        } else if (hifen == 1) {
            stringMes = stringMes + valorData[i];
        } else {
            stringAno = stringAno + valorData[i];
        }
    }
    int inteiroDia;
    int inteiroAno;
    stringstream converteDia(stringDia);
    stringstream converteAno(stringAno);
    converteDia >> inteiroDia;
    converteAno >> inteiroAno;

    if (inteiroDia < minDiasTotal or inteiroDia > maxDiasTotal) {
        valido = false;
    }
    if (inteiroAno < minAnos or inteiroAno > maxAnos) {
        valido = false;
    }

    int anoBissexto = 0;
    if (inteiroAno % 400 == 0){
        anoBissexto = 1;
    } else if ((inteiroAno % 4 == 0) and (inteiroAno % 100 != 0)) {
        anoBissexto = 1;
    }

    int maxDiasMes;
    if (mesesValidos.count(stringMes) > 0) {
        maxDiasMes = mesesValidos.find(stringMes)->second;
    } else {
        maxDiasMes = 0;
    }
    if (stringMes == "Fev" and anoBissexto == 1) {
        maxDiasMes = maxDiasMes + 1;
    }
    if (inteiroDia > maxDiasMes or inteiroDia < minDiasTotal) {
        valido = false;
    }
    if (valido == false) {
        throw invalid_argument("Argumento Invalido.");
    }
    return valido;
}

void Data::setValor(string valorData) {  //200073303
    if (validar(valorData)) {
        this->valorData = valorData;
    }
}

//
// Created by Renan 200062743
//

//Cidade

void Cidade::validar(string cidade) {   //200062743
    for (const string &c : cidadesValidas){
        if (cidade == c) {
            return;
        }
    }
    throw invalid_argument("Argumento Invalido.");
}

void Cidade::setValor(string cidade) {   //200062743
    validar(cidade);
    this->cidade = cidade;
}

//-----------------------------------------------------------------
//Idioma

void Idioma::validar(string idioma) {   //200062743
    for (const string &i : idiomasValidos){
        if (idioma == i) {
            return;
        }
    }
    throw invalid_argument("Argumento Invalido.");
}

void Idioma::setValor(string idioma) {   //200062743
    validar(idioma);
    this->idioma = idioma;
}

//-------------------------------------------------------------------
//Senha

void Senha::validar(string senha){   //200062743
    if(senha.length() != 6){
        throw invalid_argument("Argumento Invalido.");
    }
    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temNumero = false;
    for (int i = 0; i< senha.length();i++) {
        if (islower(senha[i])) {
            temMinuscula = true;
        }
        else if (isupper(senha[i])) {
            temMaiuscula = true;
        }
        else if (isdigit(senha[i])) {
            temNumero = true;
        }
        else {
            throw invalid_argument("Argumento Invalido.");
        }
        if (senha[i] == senha[i+1]){
            throw invalid_argument("Argumento Invalido.");
        }
    }
    if (!temMaiuscula or !temMinuscula or !temNumero) {
        throw invalid_argument("Argumento Invalido.");
    }
}

void Senha::setValor(string senha) {   //200062743
    validar(senha);
    this->senha = senha;
}

//---------------------------------------------------------------------------

void Nome::validar(string nome){   //200062743

    int tamanhoNome = nome.length();

    if (tamanhoNome < 5 or tamanhoNome > 20){
        throw invalid_argument("Argumento Invalido.");
    }

    string nomesParciais = "";

    for(int l = 0 ; l < tamanhoNome; l++) {
        if (isspace(nome[l]) && nome[l + 1] != ' '){
            nomesParciais = "";
        } else if(isupper(nome[l]) && nomesParciais == ""){
            nomesParciais += nome[l];
        } else if (islower(nome[l]) && nomesParciais != ""){
            nomesParciais += nome[l];
        } else if( (nome[l] == '.') && ((nome[l+1]==' ') or (islower(nome[l-1])
                                                             or (isupper(nome[l-1]) or (l==(tamanhoNome-1)))))){
            nomesParciais += nome[l];
        } else{
            throw invalid_argument("Argumento Invalido.");
        }
    }
}

void Nome::setValor(string nome) {   //200062743
    validar(nome);
    this->nome = nome;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Nota::validar(float nota) {   //200062743
    if(nota<0 or nota>5){
        throw invalid_argument("Argumento Invalido.");
    }
}

void Nota::setValor(float nota) {   //200062743
    validar(nota);
    this->nota = nota;
}


//------------------------------------------------------------------------------



void Email::validar(string email) {   //200062743
    string parteLocal;
    string dominio;
    bool separador = false;
    for(int i = 0; i<email.length();i++) {

        if (email[i] == '@' && !separador) {
            separador = true;
            continue;
        }

        if (!separador) {

            if (email[i] == '.' && (i != 0) && (email[i + 1] != '@') && (email[i + 1] != '.')) {
                parteLocal += email[i];
            } else if (isupper(email[i]) or islower(email[i]) or ((ispunct(email[i]) && email[i] != '.')) or isdigit(email[i])) {
                parteLocal += email[i];
            } else {
                throw invalid_argument("Argumento Invalido.");
            }
            if(parteLocal.length() > 64){
                throw invalid_argument("Argumento Invalido.");
            }
        } else {
            if (email[i] == '.' && (email[i - 1] != '@') && (email[i + 1] != '.')) {
                dominio += email[i];
            } else if (isupper(email[i]) or islower(email[i]) or isdigit(email[i]) or (email[i] == '-')) {
                dominio += email[i];
            } else {
                throw invalid_argument("Argumento Invalido.");
            }
            if(dominio.length() > 253) {
                throw invalid_argument("Argumento Invalido.");
            }
        }
    }
}

void Email::setValor(string email) {   //200062743
    validar(email);
    this->email=email;
}

//--------------------------------------------------------------------

string Codigo::codigosExistentes[] = {};

bool Codigo::verificar(string codigo) {
    for (const string &c : Codigo::codigosExistentes){
        if (codigo == c) {
            return false;
        }
    }
    return true;
}

void Codigo::createValor() {
    srand(Codigo::semente);
    string codigo = "";
    int randomNumber = 0;
    int soma = 0;
    for (int i= 0; i < 6; i++) {
        randomNumber = (rand() % 10);
        codigo += to_string(randomNumber) ;
        soma+=randomNumber;
    }
    int digitoVerificador = soma % 9;
    codigo += to_string(digitoVerificador);
    Codigo::semente++;
    if(verificar(codigo)){
        Codigo::codigosExistentes[Codigo::semente - 1] = codigo;
        this->codigo = codigo;
    } else {
        createValor();
    }
}

void Codigo::setValor(string codigo) {
this->codigo=codigo;
}

Codigo::Codigo() {
    createValor();
}

int Codigo::semente = 1;

