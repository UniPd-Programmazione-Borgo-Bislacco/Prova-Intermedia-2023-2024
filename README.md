# Prova-Intermedia-2023-2024
## Per eseguirlo
Potete compilare ed eseguirlo manualmente:

```
cd src/
g++ main.cpp Date.cpp Book.cpp BookShelf.cpp -o main
./main 
```

Oppure tramite CMake:

```
mkdir build
cd build
cmake ..
make
./Prova-Intermedia-2023-2024
```

## Style guide
Abbiamo seguito, il più possibile, i [fondamenti dello stile di C++](https://google.github.io/styleguide/cppguide.html) . Vale a dire funzioni in camel case, variabili in snake case, costanti camel case con una "k" iniziale, formattazione senza tab ecc...


# Spiegazione del problema logico della data di default in Book
Nel pdf era richiesto che Book avesse una data, che poi viene stampata. Però viene anche richiesto che venga creato un Book senza passare una data per parametro.
Il che porta a diverse soluzioni
1. La soluzione più semplice: creare una data di default (che potrebbe essere 1/1/1970, nascita del timestamp). Però è ovviamente logicamente sbagliato, in quanto si sta assegnando una data valida e, apparentemente, casuale ad un oggetto a cui manca quel parametro.
2. Utilizzare diversi costruttori: si avrebbe però comunque bisogno di un costruttore di default di date. Quindi si avrebbe comunque una data "casuale" ma valida di default.
3. Creare la classe Date apposta per Book. Quindi o si crea un costruttore di Date apposta. Oppure fare che Date accetti una data che non esiste (per esempio l'anno 0) così per permettere di controllare se la data sia presente o meno controllando in Book se l'anno == 0. Questa soluzione rovinerebbe completamente il senso di Date.
4. Aggiungere come parametro a Book una flag booleana. In caso non venisse passata una data, tutti le funzioni e operazioni che richiedono Date in Book lancerebbero un'eccezione o comunque non permettono di utilizzare una data non esistente. Questo metodo, forse il migliore, ha riscontrato non pochi problemi; non risolvibili dato il ristretto tempo.

## Soluzione utilizzata
Abbiamo optato per la creazione di Date totalmente indipendente da Book, con tutti i controlli per una data gregoriana. Mentre in Book si è scelto di usare una data di default: 1709, la data di riferimento per la nascita del copyright, visto che nella consegna era richiesta questo tipo di data nello specifico.
   
