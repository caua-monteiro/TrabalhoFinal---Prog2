#include <iostream>
#include <cassert>
#include <ctime>
    
using namespace std;

typedef struct user{
    string login = "";
    string Senha = "";
    int Chave = -1;
    int idade = -1;
    string Linguagem = "";
};

user V[5] = {
        {"Allan", "senha1", 1234, 25, "C++"},
        {"Beatriz", "senha2", 5678, 30, "Python"},
        {"Carlos", "senha3", 9101, 22, "Java"},
        {"Eduardo", "senha4", 1121, 28, "JavaScript"},
        {"Fernanda", "senha5", 3141, 35, "C#"}
    };




string Coder_senha(string Senha, int chave){
    for(int i = 0; i < Senha.length(); i++){
        Senha[i] += chave;
    }
    return Senha;
}


string Decoder_senha(string Senha, int Chave){
    for(int i = 0; i < Senha.length(); i++){
        Senha[i] -= Chave;
    }
    return Senha;
}

bool Verifica_Login(string L){
    for(user *i = V; i < V+5; i++){
        if(i -> login == L){
            return true;
        }
    }
    return false;
}


int Gerador_Randomico(){
    srand(time(NULL));
    return rand()%30;
}


int Binary_search_user(int Start, int Fim, string Alvo, user *V){
    int Meio = (Fim+Start)/2;
    if(Fim < Start){
        return -1;
    }
    if(V[Meio].login == Alvo){
        return Meio;
    }
    if(V[Meio].login > Alvo)
        return Binary_search_user(Start, Meio-1, Alvo, V);
    else
        return Binary_search_user(Meio+1, Fim, Alvo, V);
}

void Teste_Coder(){
    assert(Coder_senha("ABCD", 1) == "BCDE");
    assert(Coder_senha("ABCD", 2) == "CDEF");
    assert(Coder_senha("ABCD", 3) == "DEFG");
}

void Teste_Decoder(){
    assert(Decoder_senha("BCDE", 1) == "ABCD");
    assert(Decoder_senha("CDEF", 2) == "ABCD");
    assert(Decoder_senha("DEFG", 3) == "ABCD");
}

void Teste_BuscaBinaria(){
    assert(Binary_search_user(0, 4, "Allan", V) == 0);
    assert(Binary_search_user(0, 4, "Carlos", V) == 2);
    assert(Binary_search_user(0, 4, "Fernanda", V) == 4);
    assert(Binary_search_user(0, 4, "Julia", V) == -1);
}

void Teste_Gerador(){
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
    assert(Gerador_Randomico() >= 0 && Gerador_Randomico() < 30);
}

void Teste_Verificador(){
    assert(Verifica_Login("Allan") == true);
    assert(Verifica_Login("Carlos") == true);
    assert(Verifica_Login("Patrick") == false);
}


int main()
{
    Teste_Coder();
    cout << "Todos os testes do codificador passaram" << endl;

    Teste_Decoder();
    cout << "Todos os testes do decodificador passaram" << endl;

    Teste_BuscaBinaria();
    cout << "Todos os testes da Busca Binaria passaram" << endl;

    Teste_Gerador();
    cout << "Todos os testes do gerador randomico passaram" << endl;

    Teste_Verificador();
    cout << "Todos os testes do verificador de login passaram" << endl;
    
    return 0;
}
