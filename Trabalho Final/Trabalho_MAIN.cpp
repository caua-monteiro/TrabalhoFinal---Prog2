#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
    
using namespace std;

typedef struct user{
    string login = "";
    string Senha = "";
    int Chave = -1;
    int idade = -1;
    string Linguagem = "";
};


user *Data;
int Iteracoes = 0;


void Limpeza_Terminal(){
    
    system("pause");

    system("cls");
    
}


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


string Resposta_Linguagem(){
    string input = "";
    while (cin >> input && input != "C++" && input != "Python"){
        cout << "Entrada invalida, tente uma das opcoes (C++ ou Python), CaseSensitive" << endl;
    }
    return input;
    
}


void Resposta_main(char *R){
    cin >> *R;
    while (*R != 'N' && *R != 'n' && *R != 'S' && *R != 's' && *R != '@'){
        cout << "Resposta invalida, escreva S ou N" << endl;
        cin >> *R;
    }
}


void Resposta_Int(int *N){
    while (!(cin >> *N))
    {
        cout << "Entrada invalida, Insira apenas numeros" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
}


bool Verifica_Login(string L){
    for(user *i = Data; i < Data+Iteracoes; i++){
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


void cocktail_sort_user(int T, user *V){
    int Inicio = 0, Fim = T - 1;
    for(int i = 0; i < (T/2) + 1; i++){
        for(int j = Inicio + 1; j <= Fim; j++){
            if(V[j-1].login > V[j].login){
                swap(V[j-1], V[j]);
            }
        }
        for(int j = Fim - 1; j >= Inicio; j--){
            if(V[j+1].login < V[j].login){
                swap(V[j+1], V[j]);
            }
        }
        Inicio ++;
        Fim --;
    }
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


void Opcao01(string Linguagem){
    cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/entrada_saida.html" << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl;
    if(Linguagem == "C++"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre entrada e saida em C++" << endl
             << "https://www.youtube.com/watch?v=WYCKFyBii_Q" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre entrada e saida em Python" << endl
             << "https://www.youtube.com/watch?v=UyDsFTM28ZU" << endl;
    }
   
    Limpeza_Terminal();
}


void Opcao02(string Linguagem){
    cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/estruturas_selecao.html" << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl;
    if(Linguagem == "C++"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre estruturas de selecao em C++" << endl
             << "https://www.youtube.com/watch?v=Iq8VcY6d6AM" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre estruturas de selecao em Python" << endl
             << "https://www.youtube.com/watch?v=zouf7AkISR4" << endl;
    }
    Limpeza_Terminal();
   
}

void Opcao03(string Linguagem){
    cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/estruturas_repeticao.html" << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl; 
    if(Linguagem == "C++"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre estruturas de repeticao em C++" << endl
             << "https://www.youtube.com/watch?v=N0eRzGbTBKc" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Se tiver alguma duvida acesse essa videoaula sobre estruturas de repeticao em Python" << endl
             << "https://www.youtube.com/watch?v=o-1ciQ_I8-4" << endl;
    }
    Limpeza_Terminal();
   
}

void Opcao04(string Linguagem){
    if(Linguagem == "C++"){
        cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/vetores.html" << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl
         << "Se tiver alguma duvida acesse essa videoaula sobre vetores em C++" << endl
         << "https://www.youtube.com/watch?v=aNNqxVeEv-k" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Aqui esta seu link para estudo" << endl
             << "https://awari.com.br/vetor-python-aprenda-a-utilizar-a-linguagem-de-programacao-para-manipular-vetores/" << endl
             << "Para treinar faca os exercicios indicados nesse link" << endl
             << "https://e2pc.unicentro.br/treinamento/vetores.html" << endl
             << "Se tiver alguma duvida acesse a video aula essa videoaula sobre vetores em Python" << endl
             << "https://www.youtube.com/watch?v=QbMURXg6zoA" << endl;
    }
   
   Limpeza_Terminal();
}

void Opcao05(string Linguagem){
    if(Linguagem == "C++"){
        cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/strings.html" << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl
         << "Se tiver alguma duvida acesse essa videoaula sobre strings em C++" << endl
         << "https://www.youtube.com/watch?v=kxPiX0GaHuo" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Aqui esta seu link para estudo" << endl
             << "https://www.hashtagtreinamentos.com/string-no-python?gad_source=1&gclid=CjwKCAiA6t-6BhA3EiwAltRFGFSRxoTcTBIHzHCU-vUP5Cn0cZohSwhcA7iajW9hyu663n3-MkSrvRoCed0QAvD_BwE" << endl
             << "Para treinar faca os exercicios indicados nesse link" << endl
             << "https://e2pc.unicentro.br/treinamento/strings.html" << endl
             << "Se tiver alguma duvida acesse a video aula essa videoaula sobre Strings em Python" << endl
             << "https://www.youtube.com/watch?v=x0tDDrkmeQE" << endl;
    }
    Limpeza_Terminal();
}


void Opcao06(string Linguagem){
    if(Linguagem == "C++"){
        cout << "Aqui esta seu link para estudo" << endl
         << "https://e2pc.unicentro.br/treinamento/matrizes.html " << endl
         << "Para treinar acesse os exercicios sugeridos do site!" << endl
         << "Se tiver alguma duvida acesse essa videoaula sobre matrizes em C++" << endl
         << "https://www.youtube.com/watch?v=rXiCpNlNlQI" << endl;
    }
    if(Linguagem == "Python"){
        cout << "Aqui esta seu link para estudo" << endl
             << "https://awari.com.br/como-criar-e-manipular-matrizes-em-python-guia-completo-para-iniciantes/" << endl
             << "Para treinar faca os exercicios indicados nesse link" << endl
             << "https://e2pc.unicentro.br/treinamento/matrizes.html" << endl
             << "Se tiver alguma duvida acesse a video aula essa videoaula sobre matrizes em Python" << endl
             << "https://www.youtube.com/watch?v=zBLCSLW5Y54" << endl;
    }

    Limpeza_Terminal();
}


void Tutorial(){
    cout << "Bem vindo ao tutorial de uso!" << endl;

    cout << "Todas as opcoes de topicos para treinamento te daram um link para estudo em varias linguagens" << endl
         << "Sugiro que Foque apenas na lnguagem que escolheu no seu cadastro" << endl
         << "Para tirar proveito total da aplicacao veja os link e as videoaulas sobre os assuntos escolhidos e em seguida treine fazendo os exercicios propostos" << endl
         << "Aproveite o conteudo e boa sorte em seus estudos!" << endl;
}




void sistema(int Posicao){
    bool ContinuarAcesso = true;

    cout << "Bem vindo " << Data[Posicao].login << "!" << endl;
    while (ContinuarAcesso){

        cout << "Qual dos conteudos deseja estudar?" << endl
             << "1 - Entrada e saida" << endl
            << "2 - Estruturas de selecao" << endl
             << "3 - Estruturas de selecao" << endl
             << "4 - Vetores" << endl
             << "5 - String" << endl
             << "6 - Matrizes" << endl
             << "7 - Tutorial de uso" << endl;

        int Resp;
        Resposta_Int(&Resp);
        while (Resp < 0 || Resp > 7)
        {
            cout << "Opcao invalida, insira o numero da alguma opcao acima" << endl;
            Resposta_Int(&Resp);
        }
    
        if(Resp == 1)
            Opcao01(Data[Posicao].Linguagem);
        if(Resp == 2)
            Opcao02(Data[Posicao].Linguagem);
        if(Resp == 3)
            Opcao03(Data[Posicao].Linguagem);
        if(Resp == 4)
            Opcao04(Data[Posicao].Linguagem);
        if(Resp == 5)
            Opcao05(Data[Posicao].Linguagem);
        if(Resp == 6)
            Opcao06(Data[Posicao].Linguagem);
        if(Resp == 7)
            Tutorial();

        char R;
        cout << "Deseja escolher uma nova opcao?" << endl;
        Resposta_main(&R);
        if(R == 'N' || R == 'n')
            ContinuarAcesso = false;
    
    }

}


void cadastro(){

    user *NewData;
    if(!(NewData = new(nothrow) user[Iteracoes + 1])){
        cout << "Falha na alocacao de memoria" << endl;
        return;
    }

    for(int i = 0; i< Iteracoes; i++){
        NewData[i] = Data[i];
    }

    delete[] Data;
    Data = NewData;

    string New_Login;
    cout << "Preencha seu Login" << endl;
    cin >> New_Login;

    while (Verifica_Login(New_Login)){
        cout << "Login ja cadastrado, tente outro por favor" << endl;
        cin >> New_Login;
    }
    
    Data[Iteracoes].login = New_Login;

    cout << "Preencha sua senha" << endl;
    cin >> Data[Iteracoes].Senha;

    cout << "Preencha sua idade (Apenas numeros)" << endl;
    Resposta_Int(&Data[Iteracoes].idade);

    cout << "Qual linguagem deseja Aprender? (C++ ou Python)" << endl;
    Data[Iteracoes].Linguagem = Resposta_Linguagem();
    
    Data[Iteracoes].Chave = Gerador_Randomico();

    Data[Iteracoes].Senha = Coder_senha(Data[Iteracoes].Senha, Data[Iteracoes].Chave);
    cocktail_sort_user(Iteracoes, Data);

    int p = Binary_search_user(0, Iteracoes, New_Login, Data);
    sistema(p);
    Iteracoes++;
    Limpeza_Terminal();
}

int acesso(){

    string LoginAcesso;
    cout << "Insira seu login" << endl;

    while (cin >> LoginAcesso && Binary_search_user(0, Iteracoes, LoginAcesso, Data) == -1){
        cout << "Login nao encontrado, verifique se voce esta cadastrado e se escreveu corretamente" << endl;
    }

    string SenhaAcesso;
    int Posicao = Binary_search_user(0, Iteracoes, LoginAcesso, Data);
    cout << "Insira sua senha" << endl;
    while (cin >> SenhaAcesso && SenhaAcesso != Decoder_senha(Data[Posicao].Senha, Data[Posicao].Chave)){
        cout << "Senha incorreta, tente novamente" << endl;
    }

    sistema(Posicao);

    Limpeza_Terminal();
        
}




void ADM(){
    cout << "Visualizacao dos logins:" << endl;
    for(int i = 0; i < Iteracoes; i++){
        cout << i+1 << ": " 
             << (Data+i) -> login << " "
             << (Data+i) -> Senha << " "
             << (Data+i) -> Chave << " "
             << (Data+i) -> idade << " "
             << (Data+i) -> Linguagem << " " << endl;
    }
}





int main()
{
    cout << "Bem vindo ao CodeSprout!" << endl
         << "Este sistema tem o objetijetivo de ajudar no inicio do seu caminho na programacao competitiva" << endl
         << "Aproveite ao maximo os links para aprender e exercicios disponibilizados!" << endl << endl;
    
    Limpeza_Terminal();


    bool Continuar = true;
    while (Continuar){
        char Resp;
        cout << "Seu usuario ja esta cadastrado? (S ou N)" << endl;
    
        Resposta_main(&Resp);
    
        if(Resp == 'S' || Resp == 's'){
            acesso();
        }
        if(Resp == 'N' || Resp == 'n'){
            cadastro();
        }
        if(Resp == '@'){
            cout << "ADM MODE" << endl;
            ADM();
        }


        cout << "Deseja Repetir o programa?" << endl;
        Resposta_main(&Resp);
        if(Resp == 'N' || Resp == 'n')
            Continuar = false;
    }
    
    delete[] Data;
    return 0;
}
