Obliczanie n-tego wyrazu ciągu Fibonacciego zostało zaimplementowane na trzy sposoby:
1 - iteracyjnie
2 - rekurencyjnie, wprost
3 - rekurencyjnie, z wykorzystaniem wzorów na przysty i nieparzysty wyraz ciągu 			(rozwiązanie wydajniejsze czasowo niż 2.)

Każdy ze sposobów w końcu napotka problem dotyczący "pojemności" dostępnych zmiennych (maksymalna liczba jaką można przedstawić to 2^64 używając wbudowanych typów). W zadaniu użyto zmiennych unsigned long long int, czyli zmiennej liczbowej 64 bitowej bez znaku. Po jej przepełnieniu w 95. wyrazie ciągu kolejne wyniki są błędne.

Sposób iteracyjny jest prosty w implementacji i jego złożoność obliczeniowa to O(n), co nie dziwi, biorąc pod uwagę wykorzystanie pojedynczej pętli for(). Jest to algorytm wydajny także pod względem użycia pamięci, oponieważ używa stałej ilości pamięci przechowując w każdej iteracji trzy zmienne.

Przedstawiłem w zadaniu dwa sposoby rekurencyjne:

2., którego złożoność obliczeniowa nie pozwala na szybkie policzenie dużej liczby wyrazów ciągu. Wykonuje się długo dla wysokich n (w moich testach dla n = 44 było to ok. 16s a dla n = 45 już ok. 27s) Złozoność obliczeniową można zgrubnie określić jako O(2^n). 

3. Jest ulepszony pod względem złożoności obliczeniowej, która wynosi w tym przypadku O(log(n)). Osiągnięto to dzięki zastosowaniu wzorów na parzysty i nieparzysty wyraz ciągu. Dla porównania obliczenie 45 wyrazu ciągu zajmuje w tym wypadku około 0,0002s

Wykonywanie funkcji rekurencyjnych niesie ze sobą ryzyko przepełnienia stosu (stack overflow), gdzie przechowywane sa adresy kolejnych wywoływanych rekurencyjnie funkcji i ich lokalne zmienne.


Testy algorytmu 1. oraz 3. są zawarte w pliku fibonacci-test.c. 
Algorytm 1. zakłada, że dwa pierwsze wyrazy ciągu to 1, 1
Algorytm 3. zakłada, że dwa pierwsze wyrazy ciągu to 0, 1
