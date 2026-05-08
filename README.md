# poke-match

## Sobre o Projeto
**Projeto:** Grupo 11 - PokeMatch

**Problema que resolve:** Auxilia treinadores a equilibrarem suas equipes sugerindo Pokémon que cubram as fraquezas elementais uns dos outros de forma estratégica.

**Como funciona:**
O projeto automatiza a criação de sugestões de times para Pokémon. A entrada acontece quando o usuário escolhe um Pokémon de sua preferência através de um formulário em Python. No processamento, o sistema consulta a PokéAPI para obter dados técnicos (como tipos e atributos), envia essas informações como contexto para a Google Gemini API gerar uma sugestão de time ideal e, por fim, processa um relatório. A saída é o envio desse relatório detalhado diretamente para o e-mail do usuário, utilizando o serviço da Brevo.

## Integrantes
| Nome | GitHub |
| --- | --- |
| Natã Ribeiro | [@natacarvalho] |
| Lucas Nascimento | [@lucass-nasc] |
| Jorge Rodrigues | [@jorgersn04-pixel] |

## Arquitetura

```mermaid
flowchart LR
    U([Usuário]) --> CT[Chat Trigger]
    CT -->|Envia nome do Pokémon| HR[HTTP Request\nPokeAPI]
    HR -->|Consulta dados do Pokémon| IF{IF\nPokémon existe?}
    IF -->|Envia contexto ao modelo| GM[Google Gemini API]
    IF -->|Pokémon não encontrado| ER[Edit Fields\nMensagem de erro]
    GM -->|Sugere time e curiosidades| EF[Edit Fields\nextrai output]
    EF -->|Exibe resposta ao usuário| R([Resposta no chat])
    ER -->|Exibe erro ao usuário| R
