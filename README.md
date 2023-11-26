# Prova-Intermedia-2023-2024
# Per eseguirlo
Potete compilare ed eseguirlo manualmente:
- `cd src/`
- `g++ main.cpp Date.cpp Book.cpp BookShelf.cpp -o main`
- `./main`

Oppure tramite CMake:
- `cmake .`
- `make && make install`
- `./Prova-Intermedia-2023-2024`

# Spiegazione del problema logico della data di default in Book
Nel pdf era richiesto che Book avesse una data, che poi viene stampata. Però viene anche richiesto che venga creato un Book senza passare una data per parametro.
Il che porta a diverse soluzioni
1. La soluzione più semplice: creare una data di default (che potrebbe essere 1/1/1970, nascita del timestamp). Però è ovviamente logicamente sbagliato, in quanto si sta assegnando una data valida e, apparentemente, casuale ad un oggetto a cui manca quel parametro.
2. Utilizzare diversi costruttori: si avrebbe però comunque bisogno di un costruttore di default di date. Quindi si avrebbe comunque una data "casuale" ma valida di default.
3. Creare la classe Date ad hoc. Quindi o si crea un costruttore di Date apposta. Oppure fare che Date accetti una data che non esiste (per esempio l'anno 0) così per permettere di controllare se la data sia presente o meno controllando in Book se l'anno == 0. Questa soluzione rovinerebbe completamente il senso di Date.

   
