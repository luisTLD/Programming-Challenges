#include <iostream>
#include <string.h>
#include <cstdlib>


//------------------------------------------------------------------------------------------------------------------------------------------
                                                // Classe Celula para a Pilha



class Celula{
    private:
    int valor;
    Celula* prox;

    // Construtor 
    public:
    Celula() : valor(0), prox(nullptr) {}
    Celula(int x) : valor(x), prox(nullptr) {}

    // Get's
    int getValor() const { return this->valor; }
    Celula* getProx() const { return this->prox; }

    // Set's
    void setValor(int x) { this->valor = x; }
    Celula* setProx(Celula* x) { this->prox = x; }
};



//------------------------------------------------------------------------------------------------------------------------------------------
                                                        // Classe Pilha



class Pilha{
    private:
    Celula* topo;

    // Construtor 
    public:
    Pilha() : topo(nullptr) {}

    // Get's
    Celula* getTopo() const { return this->topo; }

    // Set's
    void setTopo(Celula* ptr) { this->topo = ptr; }


    // Função para retornar o tamanho da Pilha
    int pilhaTamanho(){
        Celula* ptr = getTopo();
        int max = 0;

        while(ptr != nullptr){
            max++;
            ptr = ptr->getProx();
        }

        return max;
    }

    // Inserir um elemento na Pilha
    // OBS: Com a regra que so pode inserir um menor que topo
    void inserir(int x){
        Celula* tmp = new Celula(x);
        tmp->setProx(getTopo());
        setTopo(tmp);
        tmp = nullptr;
    }

    // Função para remover o topo da Pilha
    int remover(){
        int x = -1;

        if ( getTopo() == nullptr ) std::cerr << "Torre vazia" << std::endl;
        else {
            Celula* tmp = getTopo();
            x = tmp->getValor();
            setTopo(tmp->getProx());
            delete(tmp);
        }

        return x;
    }

    // Mostrar a Pilha na ordem que foram inseridos
    void mostrar() {
        if (getTopo() == nullptr) {
            std::cout << "Torre vazia";
        } else {
            mostrarCall(getTopo());
        }
    }

    // Chamada recursiva para mostrar a Pilha
    void mostrarCall(Celula* aux) const {
        if (aux != nullptr) {
            mostrarCall(aux->getProx());
            std::cout << aux->getValor() << " ";
        }
    }
};



//------------------------------------------------------------------------------------------------------------------------------------------
                                                        // Classe Hanoi
                                                        



//------------------------------------------------------------------------------------------------------------------------------------------
                                                        // Declaração das funções



bool verificarVitoria(int x, Pilha* fim);
bool verificarMovimento(Pilha* saida, Pilha* entrada);
void mostrarPilhas(Pilha* inicio, Pilha* aux, Pilha* fim);
int verificarEntradaNumerica();
void realizarMovimento(Pilha* inicio, Pilha* aux, Pilha* fim, int entrada, int saida);
void movimentar(Pilha* saida, Pilha* entrada);

void resolverTorreUm(Pilha* inicio, Pilha* aux, Pilha* fim);
void resolverTorreDois(Pilha* inicio, Pilha* aux, Pilha* fim);
void resolverTorreTres(Pilha* inicio, Pilha* aux, Pilha* fim);
void resolverTorre(Pilha* inicio, Pilha* aux, Pilha* fim, int n);


//------------------------------------------------------------------------------------------------------------------------------------------
                                                        // Main



int main(){
    // Limpar o Terminal
    std::system("cls || clear");

    // Declarar as 3 pilhas e a variavel do tamanho da inicio
    Pilha inicio;
    Pilha aux;
    Pilha fim;
    int max = 0;

    // Inicio
    std::cout << "\tTorre de Hanoi" << std::endl;
    std::cout << "Digite o tamanho da torre: ";

    // Tamanho da torre inicio
    max = verificarEntradaNumerica();

    // Preencher a Pilha inicio
    for ( int i = max; i > 0; i-- ) inicio.inserir(i);

    // Instruções para o jogo
    std::cout << "\nDigite dois numeros, o primeiro indicando de qual Torre retirar e o segundo de qual Torre inserir" << std::endl;

    // Loop enquanto a ultima pilha nao estiver em ordem
    while( verificarVitoria(max, &fim) ){
        mostrarPilhas(&inicio, &aux, &fim);

        // Variaveis para mostrar de qual pilha vai sair e em qual vai entrar
        int saida = 0;
        int entrada = 0;

        // Ler a ação do usuario
        std::cout << "\nRetirar da Torre: ";
        saida = verificarEntradaNumerica();

        std::cout << "Inserir na Torre: ";
        entrada = verificarEntradaNumerica();

        // Limpar o Terminal
        std::system("cls || clear");

        // Verificar se movimento é valido e realizar o movimento
        realizarMovimento(&inicio, &aux, &fim, entrada, saida);
    }

    // resolverTorre(&inicio, &aux, &fim, max);

    // Terminar o jogo e mostrar as Pilhas 
    std::cout << "\tTorre completa" << std::endl;
    mostrarPilhas(&inicio, &aux, &fim);
    std::cout << std::endl;

    return 0;
}



//------------------------------------------------------------------------------------------------------------------------------------------
                                                        // Funções



// Movimentar de saida para entrada
void movimentar(Pilha* saida, Pilha* entrada){
    if ( verificarMovimento(saida, entrada) ) entrada->inserir(saida->remover());
}


// Escolher qual o movimento
void realizarMovimento(Pilha* inicio, Pilha* aux, Pilha* fim, int entrada, int saida){
    switch (entrada){
            case 1:
                switch (saida){
                    case 2:
                        movimentar(aux, inicio);
                        break;
                    case 3: 
                        movimentar(fim, inicio);
                        break;
                    default:
                        std::cout << "Movimento invalido: Torre inexistente" << std::endl;
                        break;
                    }
                break;
            case 2:
                switch (saida){
                    case 1:
                        movimentar(inicio, aux);
                        break;
                    case 3:
                        movimentar(fim, aux);
                        break;
                    default:
                        std::cout << "Movimento invalido: Torre inexistente" << std::endl;
                        break;
                    }
                break;
            case 3:
                switch (saida){
                    case 1:
                        movimentar(inicio, fim);
                        break; 
                    case 2:
                        movimentar(aux, fim);
                        break;
                    default:
                        std::cout << "Movimento invalido: Torre inexistente" << std::endl;
                        break;
                    }
                break;
            default:
                std::cout << "Movimento invalido: Torre inexistente" << std::endl;
                break;
        }
}


// Forçar usuario a entrar com um numero como primeiro digito
int verificarEntradaNumerica(){
    int aux = 0;
    std::string lixo;

    while ( !(std::cin >> aux) ){
        std::cout << "Erro, insira um numero: ";
        std::cin.clear();
        std::cin >> lixo;
    }

    return aux;
}


// Verificar se o movimento é valido
bool verificarMovimento(Pilha* saida, Pilha* entrada){
    bool aux = false;

    if ( (saida->getTopo() != nullptr) && (entrada->getTopo() != nullptr) ){
        aux = saida->getTopo()->getValor() < entrada->getTopo()->getValor() ? true : false;
    }
    else if ( (saida->getTopo() != nullptr) && (entrada->getTopo() == nullptr) ) aux = true;

    if ( !aux ) std::cout << "Movimento invalido" << std::endl;

    return aux;
}


// Verificar se a ultima Pilha esta completa
bool verificarVitoria(int x, Pilha* fim){
    return fim->pilhaTamanho() == x ? false : true;
}


// Printar as 3 Pilhas
void mostrarPilhas(Pilha* inicio, Pilha* aux, Pilha* fim){
    std::cout << "\nTorre 1: ";
    inicio->mostrar();
    std::cout << std::endl;

    std::cout << "Torre 2: ";
    aux->mostrar();
    std::cout << std::endl;

    std::cout << "Torre 3: ";
    fim->mostrar();
    std::cout << std::endl;
}



//------------------------------------------------------------------------------------------------------------------------------------------
                                                // Logica para Resolver a torre

/* Como para resolver a torre 2 temos q resolver a torre 1 em aux, para resolver a torre 3 temos q resolver a torre 2 em aux e assim
por diante, seguindo essa logica, entramos em uma recursividade ond para resolver a torre N, temos que resolver a torre N-1, para a N-1
temos que resolver a N-2, e assim ate chegar em 1, e voltar resolvendo*/



void resolverTorreUm(Pilha* inicio, Pilha* aux, Pilha* fim){
    movimentar(inicio, fim);
}

void resolverTorreDois(Pilha* inicio, Pilha* aux, Pilha* fim){
    resolverTorreUm(inicio, fim, aux);
    movimentar(inicio, fim);
    resolverTorreUm(aux, inicio, fim);
}

void resolverTorreTres(Pilha* inicio, Pilha* aux, Pilha* fim){
    resolverTorreDois(inicio, fim, aux);
    movimentar(inicio, fim);
    resolverTorreDois(aux, inicio, fim);
}

void resolverTorre(Pilha* inicio, Pilha* aux, Pilha* fim, int n){
    if ( n == 1 ) resolverTorreUm(inicio, aux, fim);
    else{
        resolverTorre(inicio, fim, aux, n - 1);
        movimentar(inicio, fim);
        resolverTorre(aux, inicio, fim, n - 1);
    }
}



