# Shunting Yard Calculator

Un évaluateur CLI d'expressions mathématiques complexes utilisant l'algorithme **Shunting Yard**.

## Fonctionnalités

- Support des opérations de base : `+`, `-`, `*`, `/`
- Support de la puissance : `^`
- Gestion des parenthèses
- Évaluation d'expressions complexes avec priorité des opérateurs

## Compilation et Exécution

```bash
cmake .
make
./calculator
```

## Tests

Pour exécuter les tests unitaires :

```bash
make
./unit_tests
```

## Utilisation

Lancez l'application et entrez des expressions mathématiques. Tapez `quit` pour quitter.

Exemples d'utilisation:
- `1 + 2 * 3`
- `(1 + 2) * 3`
- `2 ^ 3 + 1`
