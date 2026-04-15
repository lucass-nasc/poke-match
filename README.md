# poke-match

## Sobre o Projeto
**Projeto:** Grupo 11 - PokeMatch

**Problema que resolve:** Auxilia treinadores a equilibrarem suas equipes sugerindo Pokémon que cubram as fraquezas elementais uns dos outros de forma estratégica.

## Integrantes
| Nome | GitHub |
|------|--------|
| Lucas Nascimento | [@lucass-nasc] |
| Jorge Rodrigues | [@jorgersn04-pixel] |

## Arquitetura

```mermaid
graph LR
    A[Usuário] -->|Escolhe Pokémon| B(Formulário Python)
    B -->|Consulta Tipos| C[PokéAPI]
    C -->|Retorna Dados| B
    B -->|Envia Contexto| D[Google Gemini API]
    D -->|Sugere Time| B
    B -->|Envia Relatório| E[Brevo SMTP/API]
    E -->|Entrega| F[E-mail do Usuário]
