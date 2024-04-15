# Laboratorio 6

In questo laboratorio introdurremo l'utilizzo di alcuni algoritmi della _standard library_ che vi potranno essere molto utili nella preparazione del vostro progetto finale. 

---

- [Laboratorio 6](#laboratorio-6)
  - [Area di lavoro](#area-di-lavoro)
  - [Somma di norme di vettori](#somma-di-norme-di-un-vettore)
  - [Accumulazione contemporanea di più elementi](#accumulazione-contemporanea-di-più-elementi)
  - [Ordinamento di vettori con criteri arbitrari](#ordinamento-di-vettori-con-criteri-arbitrari)
  - [Rimozione di elementi da vettori](#rimozione-di-elementi-da-vettori)
  - [Consegna facoltativa del lavoro svolto](#consegna-facoltativa-del-lavoro-svolto)
  
---

L'obiettivo principale di questo laboratorio è quello di impratichirsi con l'utilizzo di funzioni ed algoritmi presenti all'interno della _standard library_. Molto spesso, per eseguire semplici operazioni su vettori o strutture di dati, gli algortimi rappresentano la soluzione migliore, più sicura e veloce, rispetto a una implementazione ad-hoc pensata da voi. Insomma, non dobbiamo reinventare la ruota!
Vi verranno forniti dei test predefiniti che dovrete soddisfare con un'adeguata implementazione delle funzioni proposte nel testo.

Durante il laboratorio vi invitiamo a tenere aperte le
[slide](https://github.com/Programmazione-per-la-Fisica/pf2023/releases/latest)
presentate a lezione, così come la _webpage_
[cppreference.com](https://en.cppreference.com/w/).

## Area di lavoro

Creiamo una nuova directory di lavoro (ad esempio `pf_labs/lab6`) e aggiungiamo il file `.clang-format` (vi **suggeriamo caldamente** di eseguire il download col comando elencato sotto e di non copiarlo dalla directory di un laboratorio precedente in quanto questo file contiene numerose modifiche non presenti nella sua versione base):
```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ curl https://raw.githubusercontent.com/Programmazione-per-la-Fisica/labs2023/main/lab6/soluzioni/.clang-format -o .clang-format
```

In seguito eseguiamo il download il file
[`doctest.h`](https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h) tramite il seguente comando :

```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ curl https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h -o doctest.h
```

Dopo di questo, procediamo a scaricare il file `CMakeLists.txt` necessario per la compilazione tramite _CMake_:

```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ curl https://raw.githubusercontent.com/Programmazione-per-la-Fisica/labs2023/main/lab6/soluzioni/CMakeLists.txt -o CMakeLists.txt
```

Infine, eseguiamo il download il file contente i test che dovranno soddisfare le funzioni che svilupperemo durante il laboratorio:
```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ curl https://raw.githubusercontent.com/Programmazione-per-la-Fisica/labs2023/main/lab6/soluzioni/functions.test.cpp -o functions.test.cpp
```
> :exclamation: Il file contiene numerosi `TEST_CASE` commentati. Questo è normale. Vi verranno fornite istruzioni in seguito.

Fatto ciò, l'area di lavoro deve trovarsi in questo stato:

```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ ls -A
.clang-format  doctest.h  CMakeLists.txt functions.test.cpp
```

## Somma di norme di vettori
Supponiamo di voler calcolare la norma di una serie di vettori contenuti in uno `std::vector`. Per prima cosa dobbiamo definire una struttura dati che contenga la coordinate del punto che identifica il vettore rispetto all'origine del sistema di riferimento.
Prepariamo quindi una struttura dati denominata `Point3D` all'interno di un file `functions.hpp` (che dovrete creare) che contenga le tre coordinate del vettore:
```c++
namespace pf {
  struct Point3D {
    double x;
    double y;
    double z;
  };
}
```
> :exclamation: Ricordate di inserire una _include guard_!

Definiamo nello stesso file una funzione libera `double norm(Point3D const& p)` che data una _const reference_ ad un punto ne calcoli la norma (ci sarà utile in seguito):
```c++
namespace pf {
...
 double norm(Point3D const&);
}
```
> :exclamation: Come sempre, i `...` indicano parti di codice mancanti o non mostrate per brevità.

Implementiamo quindi in un file `functions.cpp` (che dovrete creare) la funzione `double norm(Point3D const&)`. L'implementazione è lasciata a voi.

> :exclamation: Abbiamo omesso volontariamente gli `#include` statement. Cercate di capire quali sono necessari e usateli.

Procediamo poi con l'implementazione della funzione che calcoli la somma delle norme di un numero arbitrario di `Point3D` contenuti in uno `std::vector` tramite un _ciclo for_ con indici. La funzione dovrà essere dichiarata nel file `functions.hpp` all'interno del namespace `pf` come:

```c++
namespace pf {
...
double sum_norms_index(std::vector<Point3D> const&);
}
```

e implementata nel rispettivo file `functions.cpp`, creato in precedenza.
Procediamo adesso con l'implementazione della funzione `sum_norms_index`. Anche in questo caso, come in quelli futuri, l'implementazione è lasciata interamente a voi.

Una volta terminata l'implementazione, rimuoviamo i commenti dal file `functions.test.cpp` da attorno il primo `TEST_CASE`, quello inerente alla funzione `sum_norms_index`, avendo cura di lasciare la restante parte commentata:

```c++
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "functions.hpp"
#include "doctest.h"

TEST_CASE("Testing sum_norms_index")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  REQUIRE(vals.size() == 2);

  const double sum_norms = pf::sum_norms_index(vals);
  CHECK(sum_norms == doctest::Approx(10.44986));
}
/*
...
```

Formattiamo, salviamo e compiliamo tramite _CMake_ utilizzando il `CMakeLists.txt` da noi fornito. Se non vi ricordate come fare, potete consultare il testo del [quinto laboratorio](../lab5/README.md) o eseguire i comandi qua sotto:

```bash
$ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
-- The C compiler identification is AppleClang 14.0.0.14000029
-- The CXX compiler identification is AppleClang 14.0.0.14000029
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (1.4s)
-- Generating done (0.1s)
-- Build files have been written to: /Users/fferrari/Desktop/pf2023_labs/lab6/build
$ cmake --build build 
[ 33%] Building CXX object CMakeFiles/functions.t.dir/functions.test.cpp.o
[ 66%] Building CXX object CMakeFiles/functions.t.dir/functions.cpp.o
[100%] Linking CXX executable functions.t
[100%] Built target functions.t
```




 Infine, verifichiamo che il test sia soddisfatto dall'implementazione delle funzione `sum_norms_index`:
 ```bash
$ cmake --build build --target test
Running tests...
Test project /Users/fferrari/Desktop/pf2023_labs/lab6/build
    Start 1: functions.t
1/1 Test #1: functions.t ......................   Passed    0.21 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.22 sec
```

Una volta soddisfatto il test procediamo con la dichiarazione di una funzione analoga chiamata `sum_norms_it` nel file `functions.hpp`:
```c++
namespace pf {
...
double sum_norms_it(std::vector<Point3D> const&);
}
```
Continuiamo adesso con l'implementazione all'interno di `functions.cpp`, questa volta usando gli iteratori invece degli indici per scorrere gli elementi del vettore. Formattiamo, salviamo e compiliamo.
Rimuoviamo il commento nel file `functions.test.cpp` che include relativo test e verifichiamo che sia soddisfatto `sum_norms_it` (ricordiamoci di compilare dopo aver rimosso il commento e di lasciare gli altri test commentati per il momento).

A questo punto possiamo procedere ulteriormente. Definiamo una terza funzione, denominata `sum_norms_range`, che sfrutti un _ciclo for range based_ per ottenere come risultato la somma delle norme dei vettori:
```c++
namespace pf {
...
double sum_norms_range(std::vector<Point3D> const&);
}
```
Procediamo con l'implementazione all'interno di `functions.cpp`, formattiamo, salviamo e compilamo. Rimuoviamo il commento che include il relativo test in `functions.test.cpp` (ricordiamoci di compilare dopo aver rimosso il commento e di lasciare gli altri test commentati per il momento) e verifichiamo che venga soddisfatto.

## Ordinamento di vettori con criteri arbitrari
Supponiamo di voler ordinare i vettori forniti nel test secondo un dato criterio. L'algoritmo `std::sort` sembra fare al caso nostro, ma l'ordinamento eseguito di default è crescente ed è implementato solo per tipi nativi.
È possibile però modificare il criterio di ordinamento dell'algoritmo `std::sort` tramite una _lambda exspression_. Una _lambda expression_ è una funzione del tipo `[](auto a) { return a; };`, cioè una funzione senza nome.

> :exclamation: Per maggiori informazioni sulle _lambda expression_ consultate la [pagina dedicata su cpp referenece](https://en.cppreference.com/w/cpp/language/lambda) e/o le slide presentate a lezione.

Implementiamo quindi due funzioni che ordino i vettori secondo criteri diversi: la prima, `sort_by_x` che ordini i vettori in modo crescente a seconda del valore della coordinata $x$ del punto, la seconda, `sort_by_norm`, che ordini i vettori in modo crescente a seconda del valore della loro norma. Il file `functions.hpp` dovrà quindi contenere due nuove dichiarazioni:
```c++
namespace pf {
...
 void sort_by_x(std::vector<Point3D> &);
 void sort_by_norm(std::vector<Point3D> &);
}
```
> :question: Perchè in questo caso il vettore viene passato _by reference_ e non _by const reference_?

Procediamo adesso con l'implementazione delle funzioni nel relativo file `functions.cpp` e controlliamo poi che i test definiti in `functions.test.cpp` siano soddisfatti (ricordiamoci di compilare dopo aver rimosso il commento attorno ai test e di lasciare gli altri test commentati per il momento).

## Accumulazione tramite algoritmi
Proviamo ora a sfruttare gli algoritmi e le _lambda expression_ per calcolare la somma delle norme dei vettori già calcolata negli esempi presenti nella sezione [Somma di norme di vettori](#somma-di-norme-di-un-vettore).
Procediamo quindi col dichiarare una funzione basata sull'algoritmo `std::accumulate`, chiamata `sum_norms_algo`, sempre in `functions.hpp`:
```c++
namespace pf {
...
double sum_norms_algo(std::vector<Point3D> const& v);
}
```
e continuiamo con la sua implementazione nel corrispondente file `functions.cpp`. 
> :exclamation: Dovrete utilizzare una _lambda expression_ per accumulare la somma delle norme.

Formattiamo, salviamo e compiliamo. Controlliamo poi che i test definiti in `functions.test.cpp` siano soddisfatti anche dalla funzione `sum_norms_algo`.

> :exclamation: Quale dei quattro approcci per sommare la norma dei vettori vi sembra il migliore?

### Accumulazione contemporanea di più valori
Supponiamo adesso di voler calcolare oltra alla somma delle norme di vettori anche la somma delle singole coordinate e di voler conservare il risultato in una struttura di tipo `Results` che aggiungeremo a `functions.hpp`:
```c++
namespace pf {
...
struct Results {
  double sum_norms;
  double sum_x;
  double sum_y;
  double sum_z;
};
}
```
Come fareste? 
Dichiariamo una funzione `sum_elems_algo` nel file `functions.hpp`, che ritorni un oggetto di tipo `Results`:
```c++
namespace pf {
...
Results sum_elems_algo(std::vector<Point3D> const &);
}
```
e implementiamola nel relativo `.cpp`.

> :exclamation: Dovremo modificare la _lambda expression_ introdotta nel punto precedente per riuscire a risolvere questa parte dell'esercizio.


Controlliamo poi che i test definiti in `functions.test.cpp` siano soddisfatti anche dalla funzione `sum_elems_algo` (ricordiamoci di compilare dopo aver rimosso il commento e di lasciare gli altri test commentati per il momento).

## Rimozione di elementi da vettori
Vogliamo adesso rimuovere dal vettore tutti gli elementi che abbiano una coordinata $x$ minore di un dato valore. La cosa più semplice che è possibile fare è controllare tutti gli elementi uno a uno tramite un ciclo for con indici ed eliminare solo quelli che hanno la coordinata $x$ minore di `double` passato come secondo argomento alla funzione.
Procediamo con la dichiarazione di una funzione `remove_basic` nel file `functions.hpp`:
```c++
namespace pf {
...
  void remove_basic(std::vector<Point3D> &, double);
}
```

Proviamo poi a implementarla nel respettivo `.cpp` e controlliamo che i test vengano superati (ricordiamoci di compilare dopo aver rimosso il commento e di lasciare gli altri test commentati per il momento).
Infine, proviamo a implementare un'altra funzione `remove_algo` che sfrutti appieno le potenzialità degli algoritmi per ottenere lo stesso risultato:
```c++
namespace pf {
...
  void remove_algo(std::vector<Point3D> &, double);
}
```

> :exclamation: `std::remove_if` farà probabilmente al vostro caso.

Proviamo poi a implementarla nel respettivo `.cpp` e controlliamo che i test vengano superati (ricordiamoci di compilare dopo aver rimosso il commento e di lasciare gli altri test commentati per il momento).

> :exclamation: un approccio altrettanto valido potrebbe basarsi su `std::erase_if`. Provate a controllare la [documentazione disponibile online](https://en.cppreference.com/w/cpp/container/vector/erase2).

## Consegna facoltativa del lavoro svolto
Per chi lo desiderasse, è possibile effettuare una consegna **facoltativa** del
lavoro svolto durante il laboratorio. Questa è un'opzione che lasciamo a quegli
studenti che, incerti su alcuni punti, vogliono chiarire i loro dubbi.

Le consegne **non verranno valutate** e **NON contribuiscono al risultato
dell'esame**.

Tutti coloro che effettuano una consegna facoltativa, sono pregati di
**riportare**, **come commento** alla consegna stessa, **dubbi o domande
sull'elaborato per i quali è richiesto feedback** esplicito da parte dei
docenti.

La consegna deve avvenire, da parte dei singoli studenti, tramite
[questo link](https://virtuale.unibo.it/mod/assign/view.php?id=1368323), il
quale prevede il solo caricamento di file `.zip` o `.tgz`.

Supponendo che tutto il materiale sia nella cartella `lab6` (e supponendo di
trovarsi in tale cartella), per creare un archivio `.zip` procedere come segue:

```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ cd ..
$ zip -r lab6.zip lab6
$ ls
lab6 lab6.zip
```

Per creare un archivio `.tgz` procedere invece come segue:

```bash
$ pwd
/home/fferrari/pf_labs/lab6
$ cd ..
$ tar czvf lab6.tgz lab6
$ ls
lab6 lab6.tgz
```

## Approfondimenti ed esercizi

Come di consueto, riportiamo alcune possibili esercizi aggiuntivi che potete svolgere:

- Implementate una funzione `sum_vectors_elem` che ritorni un vettore contenente la somma elemento per elemento delle norme dei punti contenuti nei due vettori. Potrete dapprima implementarla usando gli indici e poi usando `std::transform`.
- Implementate una funzione `find_max_el` che ritorni l'indice dell'elemento del vettore con la norma più grande. Potrete implementarla in un primo momento usando gli indici o gli iteratori e poi usando gli algoritmi della _standard library_.
