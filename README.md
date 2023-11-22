# Prova-Intermedia-2023-2024
# GitExplained
Brevi spiegazioni su Git

Per la prova intermedia teniamo un branch main,e uno test al massimo. Oggi provo già a vedere cosa conviene.
## Per ora facciamo sul main

## Converrebbe fare dei branch
Andate qui
![image](https://github.com/UniPd-Programmazione-Borgo-Bislacco/Prova-Intermedia-2023-2024/assets/84403208/5f403e90-fc6e-4775-97c9-3a51d3be464e)
![image](https://github.com/UniPd-Programmazione-Borgo-Bislacco/Prova-Intermedia-2023-2024/assets/84403208/807bb986-a115-42c7-9897-a85a5fbd8b03)

Create un branch con la task che dovete fare.

Pullate da quel branch. Usando Vs Code è molto comodo farlo senza sbagliare. Altrimenti: 
- git pull origin nome_branch

Poi come sempre:
- git add .
- git commit -m "Descrizione"
- git push origin nome_branch
  Se dovesse dar problemi perché prima avete pushato in un altro branch dovreste fare:
- git push origin branch_originario:branch_nuovo

  ## TENETE A MENTE
  Potete fare più commit (e quindi più descrizioni per ogni modifica) senza pushare ogni volta. Ancora una volta è comodo VS code, altrimenti:
  - git add file_da_mettere_nel_commit
  - git commit -m "descrizione"
