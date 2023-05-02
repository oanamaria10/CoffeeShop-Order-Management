# Proiect POO- Cafenea☕
Am ales să gestionez comenzile pentru o **cafenea**. Am utilizat următoarele **clase**: 
- clasa **OrderInterface**- este o interfață pentru clasa Order
- clasa **Product**-este o clasa abstracta pentru produsele cafenelei
- clasa **Coffee**-pentru a memora detalii despre cafea(tipul de cafea, mărimea cafelei, prețul cafelei)
- clasa **FlavouredCoffee**-pentru a memora detalii despre cafea cu aromă
- clasa **VegetalMilkCoffee**-pentru a memora detalii despre cafea cu lapte vegetal
- clasa **FlavouredCoffeeWithVegetalMilkCoffee**-pentru a memora detalii despre cafea cu aroma și lapte vegetal(utilizând moștenire în diamant)
- clasa **Pastry**-pentru a memora detalii despre un produs de patiserie(tipul de produs, prețul produsului)
- clasa **Tea**-pentru a memora detalii despre ceai(tipul de ceai, prețul ceaiului)
- clasa **Order**-este clasa de comenzi, care moștenește un vector de produse și interfața OrderInterface
- 4 clase de **excepții** *custom* : **NegativePriceException**, atunci când se setează preț negativ produselor, **ProductNotFoundException**, atunci când se încearcă să se șteargă din comandă un produs inexistent, **InvalidProductException**, atunci când se încearcă să se adauge în comandă un produs care nu e tip Coffee, FlavouredCoffee, VegetalMilkCoffee, FlavouredCoffeeWithVegetalMilkCoffee, Pastry sau Tea, **EmptyOrderException**, atunci când comanda este goală

**Funcționalități** 
- capabilă să adauge produse în comandă și să șteargă produse din comandă
- capabilă să calculeze totalul comenzii
- capabilă să afișeze cât are de plătit clientul
- capabilă să afișeze comanda sortată după prețul produselor
- capabilă să ofere o reducere de 15% pentru studenți
- capabilă să afișeze câte cafele, ceaiuri și produse de patiserie s-au vândut în total
