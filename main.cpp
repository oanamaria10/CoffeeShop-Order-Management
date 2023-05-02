#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//exceptii custom
class NegativePriceException : public exception {
public:
    const char* what() const throw() {
        return "Pretul nu poate fi negativ!";
    }
};
class ProductNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "Produsul nu a fost gasit!";
    }
};
class InvalidProductException : public exception  {
public:
    const char* what() const throw() {
        return "Produsul este invalid!";
    }
};
class EmptyOrderException : public exception {
public:
    const char* what() const throw() {
        return "Comanda nu are produse!";
    }
};

//interfata pentru comenzi
class OrderInterface{
public:
    virtual ~OrderInterface(){}
    virtual double getTotal()=0;
    virtual void printTotal()=0;
    virtual void printOrder()=0;
};

//clasa abstracta
class Product {
protected:
    string Type;
    double Price;
public:
    virtual ~Product(){}
    virtual void setType(string Type)=0;
    virtual void setPrice(double Price){
        if(Price<0) {
            throw NegativePriceException();
        }
    }
    virtual string getType() const=0;
    virtual double getPrice() const=0;
};
class Coffee : public Product {
protected:
    string Size;
public:
    Coffee():Product(){
        Type="";
        Size="";
        Price=0;
    }
    Coffee(string Type,string Size, double Price){
        this->Type=Type;
        this->Size=Size;
        this->Price=Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
    void setSize(string Size){
        this->Size=Size;
    }
    string getSize() const{
        return Size;
    }
};
//mostenire in diamant
class FlavouredCoffee: virtual public Product{
protected:
    string Size;
    string Flavour;

public:
    FlavouredCoffee():Product(){
        Type="";
        Size="";
        Flavour="";
        Price=0;
    }
    FlavouredCoffee(string Type,string Size, string Flavour, double Price){
        this->Type=Type;
        this->Size=Size;
        this->Flavour=Flavour;
        this->Price=Price;
    }
    FlavouredCoffee(const FlavouredCoffee &other){
        this->Type=other.Type;
        this->Size=other.Size;
        this->Flavour=other.Flavour;
        this->Price=other.Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
    void setSize(string Size){
        this->Size=Size;
    }
    string getSize() const{
        return Size;
    }
    void setFlavour(string Flavour){
        this->Flavour=Flavour;
    }
    string getFlavour(){
        return Flavour;
    }
};
class VegetalMilkCoffee: virtual public Product{
protected:
    string Size;
    string VegetalMilk;
public:
    VegetalMilkCoffee():Product(){
        Type="";
        Size="";
        VegetalMilk="";
        Price=0;
    }
    VegetalMilkCoffee(string Type,string Size, string VegetalMilk, double Price){
        this->Type=Type;
        this->Size=Size;
        this->VegetalMilk=VegetalMilk;
        this->Price=Price;
    }
    VegetalMilkCoffee(const VegetalMilkCoffee &other){
        this->Type=other.Type;
        this->Size=other.Size;
        this->VegetalMilk=other.VegetalMilk;
        this->Price=other.Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
    void setSize(string Size){
        this->Size=Size;
    }
    string getSize() const{
        return Size;
    }
    void setVegetalMilk(string VegetalMilk){
        this->VegetalMilk=VegetalMilk;
    }
    string getVegetalMilk(){
        return VegetalMilk;
    }
};
class FlavouredCoffeeWithVegetalMilk : public FlavouredCoffee, public VegetalMilkCoffee {
    string Size;
public:
    FlavouredCoffeeWithVegetalMilk(): FlavouredCoffee(), VegetalMilkCoffee(){
        Type="";
        Size="";
        Flavour="";
        VegetalMilk="";
        Price=0;
    }
    FlavouredCoffeeWithVegetalMilk(string Type,string Size, string Flavour, string VegetalMilk, double Price){
        this->Type=Type;
        this->Size=Size;
        this->Flavour=Flavour;
        this->VegetalMilk=VegetalMilk;
        this->Price=Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
    void setSize(string Size){
        this->Size=Size;
    }
    string getSize() const{
        return Size;
    }
    void setFlavour(string Flavour){
        this->Flavour=Flavour;
    }
    string getFlavour(){
        return Flavour;
    }
    void setVegetalMilk(string VegetalMilk){
        this->VegetalMilk=VegetalMilk;
    }
    string getVegetalMilk(){
        return VegetalMilk;
    }
};
class Tea : public Product{
public:
    Tea():Product(){
        this->Type="";
        this->Price=0;
    }
    Tea(string Type, double Price){
        this->Type=Type;
        this->Price=Price;
    }
    Tea(const Tea &other){
        this->Type=Type;
        this->Price=Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
};
class Pastry : public Product{
public:
    Pastry():Product(){
        this->Type="";
        this->Price=0;
    }
    Pastry(string Type, double Price){
        this->Type=Type;
        this->Price=Price;
    }
    Pastry(const Pastry &other){
        this->Type=Type;
        this->Price=Price;
    }
    void setType(string Type){
        this->Type=Type;
    }
    string getType() const{
        return Type;
    }
    void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    double getPrice() const{
        return Price;
    }
};

//functie
bool CompareProductsByPrice(const Product* pr1, const Product* pr2){
    return pr1->getPrice()<pr2->getPrice();
}

//mostenire private
class Order : private vector<Product*>, public OrderInterface {
    static int nr_coffee;
    static int nr_tea;
    static int nr_pastry;
public:
    Order(){}
    void addProduct(Product* product) {
        if (!dynamic_cast<Coffee*>(product) && !dynamic_cast<FlavouredCoffee*>(product) && !dynamic_cast<VegetalMilkCoffee*>(product) && !dynamic_cast<FlavouredCoffeeWithVegetalMilk*>(product) && !dynamic_cast<Tea*>(product) && !dynamic_cast<Pastry*>(product)) {
            throw InvalidProductException();
        }
        this->push_back(product);
        if (dynamic_cast<Coffee*>(product))
            ++nr_coffee;
        else if(dynamic_cast<FlavouredCoffee*>(product))
            ++nr_coffee;
            else if(dynamic_cast<VegetalMilkCoffee*>(product))
                ++nr_coffee;
                else if(dynamic_cast<FlavouredCoffeeWithVegetalMilk*>(product))
                    ++nr_coffee;
                    else if (dynamic_cast<Tea*>(product))
                        ++nr_tea;
                        else if (dynamic_cast<Pastry*>(product))
                            ++nr_pastry;
    }
    void removeProduct(Product* product) {
        for (auto it = begin(); it != end(); it++) {
            bool found=false;
            if (*it == product) {
                if (dynamic_cast<Coffee*>(product)) {
                    delete dynamic_cast<Coffee*>(product);
                    --nr_coffee;
                }
                    else if(dynamic_cast<FlavouredCoffee*>(product)) {
                        delete dynamic_cast<FlavouredCoffee*>(product);
                        --nr_coffee;
                    }
                        else if(dynamic_cast<VegetalMilkCoffee*>(product)){
                            delete dynamic_cast<VegetalMilkCoffee*>(product);
                            --nr_coffee;
                        }
                            else if(dynamic_cast<FlavouredCoffeeWithVegetalMilk*>(product)){
                                delete dynamic_cast<FlavouredCoffeeWithVegetalMilk*>(product);
                                --nr_coffee;
                            }
                                else if (dynamic_cast<Tea*>(product)) {
                                    delete dynamic_cast<Tea*>(product);
                                    --nr_tea;
                                }
                                    else if (dynamic_cast<Pastry*>(product)) {
                                        delete dynamic_cast<Pastry*>(product);
                                        --nr_pastry;
                                    }
                found=true;
                erase(it);
                break;
            }
            if (!found) {
                throw ProductNotFoundException();
            }
        }
    }
    double getTotal() {
        double total=0;
        for (int i=0;i<this->size();i++) {
            total+=at(i)->getPrice();
        }
        return total;
    }
    void printTotal() {
        if(getTotal()<=0)
            throw EmptyOrderException();
        string ocupatie;
        cout<<"Ce ocupatie aveti?";
        cin>>ocupatie;
        if(ocupatie=="Student" || ocupatie=="student" || ocupatie=="STUDENT")
            cout<<"Deoarece sunteti student, aveti o reducere de 15%. Totalul dumneavostra este: "<<getTotal()-getTotal()*15/100<<"."<<"\n";
        else cout<<"Deoarece nu sunteti student, nu va putem oferi reducere. Totalul dumneavostra este: "<<getTotal()<<"."<<"\n";
    }
    void printOrder(){
        if(getTotal()<=0)
            throw EmptyOrderException();
        //sortare dupa pret
        sort(this->begin(),this->end(), CompareProductsByPrice);
        for (int i=0;i<this->size();i++) {
            cout<<at(i)->getType()<<" ";
        }
    }
    static void printNr_coffee(){
        cout<<"S-au vandut "<<nr_coffee<<" cafele."<<"\n";
    }
    static void printNr_tea(){
        cout<<"S-au vandut "<<nr_tea<<" ceaiuri."<<"\n";
    }
    static void printNr_pastry(){
        cout<<"S-au vandut "<<nr_pastry<<" produse de patiserie."<<"\n";
    }
};
int Order::nr_coffee=0;
int Order::nr_tea=0;
int Order::nr_pastry=0;
int main()
{
    //initializam obiecte de tip Coffee
    Coffee* espresso1=new Coffee("Espresso","Short", 5);
    Coffee* espresso2=new Coffee(*espresso1); //folosim copyconstructor
    espresso2->setSize("Double"); //folosim setteri
    espresso2->setPrice(7);
    Coffee* americano1=new Coffee("Americano","Short",6);
    Coffee* americano2=new Coffee(*americano2);
    americano2->setSize("Double");
    americano2->setPrice(8);
    Coffee* cappuccino1=new Coffee("Cappuccino","Small",6);
    Coffee* cappuccino2=new Coffee(*cappuccino1);
    cappuccino2->setSize("Medium");
    cappuccino2->setPrice(8);
    Coffee* cappuccino3=new Coffee(*cappuccino1);
    cappuccino3->setSize("Large");
    cappuccino3->setPrice(10);
    Coffee* latte1=new Coffee("Caffe Latte","Small",7);
    Coffee* latte2=new Coffee(*latte1);
    latte2->setSize("Medium");
    latte2->setPrice(9);
    Coffee* latte3=new Coffee(*latte1);
    latte3->setSize("Large");
    latte3->setPrice(11);
    Coffee* ice_coffee1=new Coffee("Ice Coffee","Small",8);
    Coffee* ice_coffee2=new Coffee("Ice Coffee","Medium",10);
    Coffee* ice_coffee3=new Coffee("Ice Coffee","Large",12);

    //initializare obiecte de tip FlavouredCoffee
    FlavouredCoffee* caramel_cappuccino=new FlavouredCoffee("Cappuccino", "Medium", "Caramel", cappuccino2->getPrice()+1);
    FlavouredCoffee* vanilla_cappuccino=new FlavouredCoffee(*caramel_cappuccino);
    vanilla_cappuccino->setFlavour("Vanilla");

    //initializare obiecte de tip VegetalMilkCoffee
    VegetalMilkCoffee* oat_cappuccino=new VegetalMilkCoffee("Cappuccino", "Medium", "Oat", cappuccino2->getPrice()+3);
    VegetalMilkCoffee* soya_cappuccino=new VegetalMilkCoffee(*oat_cappuccino);
    soya_cappuccino->setVegetalMilk("Soya");

    //initializare obiecte de tip FlavouredCoffeeWithVegetalMilk
    FlavouredCoffeeWithVegetalMilk* caramel_oat_cappuccino=new FlavouredCoffeeWithVegetalMilk("Cappuccino", "Medium", "Caramel", "Oat", oat_cappuccino->getPrice()+1);
    FlavouredCoffeeWithVegetalMilk* caramel_soya_cappuccino=new FlavouredCoffeeWithVegetalMilk(*caramel_oat_cappuccino);
    caramel_soya_cappuccino->setVegetalMilk("Soya");

    //initializare obiecte de tip Pastry
    Pastry* croissant=new Pastry("Croissant", 5);
    Pastry* croissant_cioco=new Pastry("Croissant with Nutella",6);
    Pastry* cookie=new Pastry("Cookie", 5);
    Pastry* muffin=new Pastry("Muffin",6);

    //initializare obiecte de tip Tea
    Tea* tea1=new Tea("Black Tea",10); //constructor cu parametri
    Tea* tea2=new Tea(); //constructor fara parametri
    tea2->setType("Green Tea"); //setteri
    tea2->setPrice(tea1->getPrice()); //getteri

    //initializare comenzi
    Order order1;
    order1.addProduct(espresso1);
    order1.addProduct(croissant);
    order1.addProduct(cookie);
    order1.removeProduct(espresso1);
    order1.addProduct(cappuccino3);
    order1.getTotal();
    order1.printTotal();
    order1.printOrder();
    Order::printNr_coffee();
    Order::printNr_tea();
    Order::printNr_pastry();
    Order order2;

    //bloc try_catch
    try{
        order2.printTotal();
    }
    catch (const EmptyOrderException& e){
        cout<<"Am prins exceptia. "<<e.what()<<"\n";
    }
    //bloc try_catch care rearunca o exceptie
    try{
        cappuccino2->setPrice(-2);
    }
    catch (const NegativePriceException& e){
        cout<<"Am prins exceptia. "<<e.what()<<"\n";
        throw InvalidProductException();
    }
}