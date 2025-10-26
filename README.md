# Objetivo
Esse repositorio tem por objetivo, tornar possivel de responder uma prova especifica.
Prova está que tem como topicos **vetores dinâmicos**, **realloc** e **malloc**, mas para entender ambos repassaremos por ponteiro.

# Ponteiros
### O que são ponteiros?<br>
Um computador basicamente funciona através de números, dentro do seu computador só tem números, não tem nada além disso.<br>
Sabendo disso, seu computador também tem algo chamado mmemoria, está memoria também só tem numeros, ela não fala, então como faremos para buscar coisas nessa memoria?<br>
Do ponto de vista do programador precisamos que algo aponte para ela, é ae que surge o ponteiro, em linguagens como C. Ponteiro é um nome nada intuitivo, então para entender melhor ponteiro é um apontador, ele aponta, ele diz em qual endereço de memoria o computador deve olhar.<br>
e isso é muito util, uma vez que podemos usar isso para apontar para diferentes posições no computador, imagina que queiramos modificar uma variavel especifica de diferentes fontes, ou até melhor, imagina que queremos que uma variavel aponte para outra variavel, e asism por diante, numa função em cadeia.<br>
Ponteiros são em base isso, **apontadores**.

<img width="940" height="529" alt="image" src="https://github.com/user-attachments/assets/d9e2ff94-3069-4f0e-bf47-05c5deae8cea" />

# Malloc
### O que o malloc faz?

C é uma linguagem que te permite fazer muitas coisas com memoria, tipo muitas mesmo, ponteiros por exemplo não é muito normal em outras linguagens.

Sabendo que C é realmente bem flexivel quanto a memoria, existe outra coisa que ele nos permite fazer, sendo ela alocar espaço de memoria.
#### E o que significa alocar espaço de memoria?
Imagine que você esteja em uma fila, e alguem pede para você guardar um lugar pra ela na fila. Isso é basicamente uma alocação, a pessoa pediu pra você guardar o lugar, então aquele lugar está ocupado.
O espaço foi alocado para esta pessoa, semelhante a isso assim funciona a memoria, seu codigo em C chega na memoria e fala *"guarda estas posições na memoria para mim"* então seu codigo em C também informa qual é o tamanho do dado que está sendo alocado.

<img width="415" height="32" alt="image" src="https://github.com/user-attachments/assets/367cf7b2-6913-482c-bb20-950894bc8b8f" /><br>
É basicamente assim, malloc(size) size representa o tamanho da memoria sendo alocada, no nosso caso da prova, representa 1*sizeof(int), sizeof retorna o tamanho de um inteiro (int).

<img width="984" height="545" alt="image" src="https://github.com/user-attachments/assets/9ba8cc2b-0141-48b0-9202-dda1052108ee" /><br>
Esses espaços estão alocados.<br>

# Realloc
Não há muito o que dizer sobre o realloc, mas basicamente imagine o exemplo anterior, agora a pessoa que te pediu para guardar 1 unico espaço, disse que se enganou e agora pede que você guarde mais de 9 espaços para ela.<br>
Sua alocação que antes era de 1 lugar agora passa a ser de 10 lugares, ou seja, existem 10 espaços reservados agora.

É isso que o codigo em C do realloc faz, pega a alocação feita atualmente e transforma em um novo valor desejado.<br>
<img width="531" height="36" alt="image" src="https://github.com/user-attachments/assets/cb1d59f3-d126-42c8-815b-48cca0104354" /><br>
O primeiro parâmetro de um realloc indica o valor atual da realocação, quem será realocado, o segundo parâmetro indica o novo tamanho, o retorno é dado pelo novo valor. <br>

# Lista Encadeada
<img width="493" height="500" alt="image" src="https://github.com/user-attachments/assets/08efac54-e593-4b95-b12e-0f86c8bf4cc0" /><br>
Para entender listas encadas é preciso ver uma corrente (sim, uma corrente), correntes tem elos (nós), nós esses que são ligados uns aos outros, esses nós em sua essência formam uma ligação um com outro e no fim formam uma corrente.<br>
Analogo a isto é a lista encadeada, possui nós que contem dados e esses nós apontam com ponteiros para outro nó, assim por diante, até chegar ao fim da lista encadeada.

<img width="196" height="109" alt="image" src="https://github.com/user-attachments/assets/1a1e7251-bfc6-4a1c-a326-9bc533683ff1" /> <br>
int data representa o dado que tem naquele nó especifico. Node*next representa o proximo nó sendo apontado.

Com essa representação temos uma lista encadeada que pode ser acessada em maneira sequencial.

