Spojový seznam 
==============

Napište spojový seznam pro prvek s obecnou datovou složkou typu <b>T</b>.

####  Základní metody

-   <b>konstruktor 0,5b </b> - povinné

-   konstruktor přes initializer_list <b>1b</b>

-   kopírovací konstruktor <b>1b</b>

-   <b> destruktor 1b</b> - povinné

-   <b> přidání prvku na začátek 1b</b> - povinné

-   <b>odstranění prvního prvku 1b</b> - povinné

-   <b>kontrola prázdnosti seznamu 0,5b</b>

-   přidání prvku na konec <b>1b</b>

-   odebrání posledního prvku <b>1b</b>

####  Další metody

-   vrácení délky seznamu <b>1b</b>

-   otočení seznamu <b>1b</b>

-   setřízení seznamu podle velikosti bez použití knihoven <b>2b</b> (v případě psaní šablonového seznamu je potřeba využít vlastního komparátoru nebo přežížení operátoru < za to budou případně další + body)

   V případě, že nebudete dělat iterátor, tak je potřeba udělat nějaké gettery, jinak se k datům uloženým v seznamu nedostanete. V případě, že iterátor budete implementovat se vás tahle povinnost netýká.

Bonus Iterátor - 6 bodů
----------------

#### Metody seznamu

-   Vrácení iterátoru na začátek (hlavu) seznamu 

-   Vrácení iterátoru na konec (ocas) seznamu 

#### Třída Iterátor
##### Metody Iterátoru

-   konstruktor

-   Posunutí iterátoru na další prvek seznamu (možnost přetížit operátor++)

-   získat data z prvku uloženého v iterátoru (možnost přetížit operátor*)

-   metoda pro zjištění, zda-li jsou dva iterátory různé (možnost přetížení operator!=)

Další možnost bonusových bodů
----------------

-   za implementaci obousměrně zřetězeného seznamu <b>+2 body</b>
-   za šablonovou implementaci seznamu <b>+3 body</b>
-   za implementaci seznamu s využitím smart pointrů <b>+3 body</b>

Uspořádaný spojový seznam
----------------

Implementujte třídu pro uspořádaný spojový seznam. Tento seznam bude mít skryté klasické metody pro přidání prvků. Naopak bude mít novou metodu:
-   insert <b> 2b </b>, která vloží prvek na správné místo (v případě šablonové třídy za využití komparátoru + další 2 body)

Knihy 
=====

Máte textový soubor knihy.csv, který obsahuje na každém řádku údaje k
jedné knize (název, autoři, isbn, počet stránek, datum
publikace). Jednotlivé údaje na řádku jsou oddělené čárkou. Vaším úkolem
bude napsat funkci, která jednotlivé knihy ze souboru uloží do vhodného
kontejneru, který si vyberete (např. vámi implementovaný seznam, chytré pole z hodiny nebo std::list či std::vector). Dále bude za úkol napsat funkce, které
knihy seřadí podle počtu stránek/isbn v daném kontejneru (seznamu) a na
závěr bude funkce, která seznam uloží do textového souboru. Každá kniha
bude uložená na vlastním řádku ve specifikovaném pořadí (název
knihy-autor/ilustrátor-isbn-počet stran-datum publikace)
V případě použití vámi implementovaného seznamu obdržíte + další bonus <b> 2 body</b>.
#### Funkce

-   Načtení knih do seznamu <b>3b</b>

-   Seřazení knih podle daného parametru <b>5b</b>

-   Uložení knih ze seznamu do textového souboru <b>2b</b>

<b>Aby jste mohli dostat body musí alespoň nějak fungovat všechny 3 funkce. Tedy program musí umět knihy ze souboru načíst a alespoň nějak je seřadit do jiného souboru.</b>
Podmínky k udělení zápočtu 
==========================

Podmínkou k udělení zápočtu je zisk alespoň 20 bodů. K bodům ze
zápočtové úlohy Vám budou přičteny body z domácích úloh.

Zápočtovou úlohu odevzdejte nejlépe do konce zimního zkouškového období (ještě lépe do konce ledna).

Programy ke kontrole posílejte tehdy, kdy půjdou přeložit a nebudou
házet žádné chybové hlášení. Dále kód musí být řádně okomentován.
