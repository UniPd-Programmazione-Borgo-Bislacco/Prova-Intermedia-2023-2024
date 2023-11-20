# Prova-Intermedia-2023-2024
# GitExplained
Brevi spiegazioni su Git

Per la prova intermedia teniamo un branch main,e uno test al massimo. Oggi provo già a vedere cosa conviene.
## Per ora facciamo sul main

 Fate il seguente comando per copiare la repo sulla directory
- git clone https://github.com/UniPd-Programmazione-Borgo-Bislacco/Prova-Intermedia-2023-2024.git

Vi chiederà di **autenticarvi**: inserire mail e poi password. Se non funziona andate in **Settings> Developer** (in fondo) e generate un **token** (meglio se non quello in beta). Conservatelo, se lo perdete dove rigenerarlo ad ogni accesso.
Entrate nela cartella, mettete i file se avete iniziato.

Poi:
- git config --global user.email "you@example.com"
- git config --global user.name "Your Name"

Fate **DENTRO** la directory della repo:
- git add .
- git commit -m "Repo inizializzata"
- git push

Se non dà errori avrete aggiunto le modifiche sulla repo su github.
  
## Prima di iniziare a scrivere codice:
Dovete aggiornare dal main, in caso nel frattempo qualcuno lo abbia modificato.
- git fetch
- git pull origin master

Per pushare, fetchare e pullare è molto comodo usare VS Code. Ma non fa molta differenza. 
