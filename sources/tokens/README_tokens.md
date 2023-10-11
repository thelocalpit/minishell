# minishell_linux

check_single_quotes
	questa funzione va a controllare le single quotes.
	prima di tutto facciamo alcuni controlli:
	1. controlliamo che il carattere successivo non sia uno \0 ed è una '
		e allo stesso tempo anche due caratteri successivi non sia uno \0 e
		allo stesso tempo sia uno spazio 
	2.	altra condizione è che lo s[i + 2] è un \0 
			allora ritorniamo i + 2
	
	in questo caso non controlliamo che sia un token valido ma lo faremo
	più avanti 
	
	poi entriamo nel loop che semplicemente proseguirà fintanto che i non è
	uguale a len o che il numero di s_quotes che andremo a contare non è
	uguale a quello totale di single quote. questo ci dice che abbiamo 
	analizzato tutti quanti i casi di virgolette. 
	attiveremo un controllo all'interno del loop che ci dirà che quando il 
	conteggio del single quote è uguale a 0 quindi pari e s[i + 1]
	è uguale a spazio, ovvero che contenuto all'intenro delle virgolette
	è concluso. ritorniamo quindi i dopo aver aggiunto un carattere e aver
	mosso il contatore allo spazio.  



	/* in qeusta funzione andiamo a contarci il numero totali di "" e di '\'' 
	inoltre controlliamo se la prima virgoletta ad apparire è una singola. 
	i servirà in seguito come signal booleano */


count_tokens

	/* questa funzione dovrá contare gli elementi all-interno della linea di 
	comando */

/* é neccessario fin da subito individuare quando e quante quotes ci sono.
	questo ci permette di evitare problemi in fase di conteggio degli
	elementi. */