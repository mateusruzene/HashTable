## Tabela Hash:

### gerarTabelaHash

```c
struct tabelaHash *gerarTabelaHash(size_t tamTabela)
```

- Essa função aloca memória para uma tabela hash e inicializa seus campos.
- Ela recebe um tamanho de tabela como parâmetro.
- A função aloca memória para a estrutura `tabelaHash` e para o array de ponteiros `tabela`.
- Retorna um ponteiro para a estrutura `tabelaHash` criada.

### hash

```c
int hash(int chave, size_t tamanhoTabela)
```

- Essa função calcula o índice da tabela hash para uma determinada chave e tamanho da tabela.
- Recebe a chave como parâmetro e retorna o índice calculado.

### inserir

```c
struct nodoHash *inserir(struct tabelaHash tabelaHash[], size_t tamTabela, int chave)
```

- Essa função insere um novo nó na tabela hash com base em uma chave fornecida.
- Recebe a tabela hash, o tamanho da tabela e a chave como parâmetros.
- A função calcula o índice usando a função `hash`.
- Um novo nó é alocado dinamicamente na memória e seus campos são preenchidos.
- O novo nó é adicionado à tabela hash no índice correspondente.
- A função retorna um ponteiro para o novo nó criado.

### liberarTabelaHash

```c
void liberarTabelaHash(struct tabelaHash tabelaHash[], size_t tamTabela)
```

- Essa função libera a memória alocada para a tabela hash e seus nós.
- Recebe a tabela hash e o tamanho da tabela como parâmetros.
- Itera sobre todos os nós da tabela hash, liberando a memória alocada para cada nó.
- Libera a memória alocada para o array de ponteiros `tabela`.
- Por fim, libera a memória alocada para a estrutura `tabelaHash`.

### imprimirTabelaHash

```c
void imprimirTabelaHash(struct tabelaHash tabelaHash[], size_t tamTabela)
```

- Essa função imprime o conteúdo da tabela hash.
- Recebe a tabela hash e o tamanho da tabela como parâmetros.
- Itera sobre todos os índices da tabela hash.
- Para cada índice, imprime o índice e os nós armazenados nele.

### buscar

```c
struct nodoHash *buscar(struct tabelaHash tabelaHash[], size_t tamTabela, int chave)
```

- Essa função busca um nó na tabela hash com base em uma chave fornecida.
- Recebe a tabela hash, o tamanho da tabela e a chave como parâmetros.
- A função calcula o índice usando a função `hash`.
- Percorre a lista encadeada de nós no índice calculado, comparando as chaves.
- Se a chave for encontrada, retorna um ponteiro para o nó correspondente.
- Se a chave não for encontrada, retorna um ponteiro nulo.

### excluir

```c
void excluir(struct tabelaHash tabelaHash[], size_t tamTabela, struct nodoHash *nodo)
```

- Essa função exclui um nó da tabela hash.
- Recebe a tabela hash, o tamanho da tabela e um ponteiro para o nó a ser excluído.
- A função calcula o índice usando a função `hash`.
- Percorre a lista encadeada de nós no índice calculado até encontrar o nó a ser excluído.
- Se o nó for encontrado, ele é removido da lista e a memória alocada para ele é liberada.