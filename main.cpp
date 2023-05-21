#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<memory>
#include<functional>
#include<chrono>
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
class InsufficientStockException : public exception {
public:
    const char* what() const throw() {
        return "Produsul nu mai este in stoc!";
    }
};
class InsufficientStockFlavourException : public exception {
public:
    const char* what() const throw() {
        return "Nu mai avem aceasta aroma!";
    }
};
class InsufficientStockMilkException : public exception {
public:
    const char* what() const throw() {
        return "Nu mai avem acest fel de lapte vegetal!";
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
    virtual void setType(string Type){
        this->Type=Type;
    }
    virtual string getType() const{
        return Type;
    }
    virtual void setPrice(double Price){
        if(Price<0)
            throw NegativePriceException();
        this->Price=Price;
    }
    virtual double getPrice() const{
        return Price;
    }
};

class Coffee : public Product{
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
    virtual void setSize(string Size){
        this->Size=Size;
    }
    virtual string getSize() const{
        return Size;
    }
};
//mostenire in diamant
class FlavouredCoffee: virtual public Coffee{
protected:
    string Size;
    string Flavour;

public:
    FlavouredCoffee():Coffee(){
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
    void setFlavour(string Flavour){
        this->Flavour=Flavour;
    }
    string getFlavour(){
        return Flavour;
    }
};
class VegetalMilkCoffee: virtual public Coffee{
protected:
    string Size;
    string VegetalMilk;
public:
    VegetalMilkCoffee():Coffee(){
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
    void setSize(string Size){
        this->Size=Size;
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
    Pastry(const Pastry &other) {
        this->Type=Type;
        this->Price=Price;
    }
};

//functie
bool CompareProductsByPrice(const unique_ptr<Product>& pr1, const unique_ptr<Product>& pr2){
    return pr1->getPrice()<pr2->getPrice();
}

template <typename T>
class Stock {
private:
    map<T,int> inventar;
public:
    void add_item(const T& item, int count) {
        inventar[item]+=count;
    }
    void remove_item(const T& item, int count) {
        auto it=inventar.find(item);
        if (it!=inventar.end() && it->second>=count) {
            it->second-=count;
        } else {
            throw InsufficientStockException();
        }
    }
    int get_stoc(const T& item) const {
        auto it = inventar.find(item);
        if (it != inventar.end()) {
            return it->second;
        }
        return 0;
    }
};

template <>
class Stock<FlavouredCoffee> {
private:
    map<string,int> inventar;
public:
    void add_item(FlavouredCoffee& item, int count) {
        inventar[item.getFlavour()] += count;
    }
    void remove_item(FlavouredCoffee& item, int count) {
        if (inventar[item.getFlavour()] >= count) {
            inventar[item.getFlavour()] -= count;
        } else {
            throw InsufficientStockFlavourException();
        }
    }
    int get_stoc(FlavouredCoffee& item) {
        auto it = inventar.find(item.getFlavour());
        if (it != inventar.end()) {
            return it->second;
        }
        return 0;
    }

};

template <>
class Stock<VegetalMilkCoffee> {
private:
    map<string,int> inventar;
public:
    void add_item(VegetalMilkCoffee& item, int count) {
        inventar[item.getVegetalMilk()] += count;
    }
    void remove_item(VegetalMilkCoffee& item, int count) {
        if (inventar[item.getVegetalMilk()] >= count) {
            inventar[item.getVegetalMilk()] -= count;
        } else {
            throw InsufficientStockMilkException();
        }
    }
    int get_stoc(VegetalMilkCoffee& item) {
        auto it = inventar.find(item.getVegetalMilk());
        if (it != inventar.end()) {
            return it->second;
        }
        return 0;
    }
};

//mostenire private
class Order : private vector<unique_ptr<Product>>, public OrderInterface {
    static int nr_coffee;
    static int nr_tea;
    static int nr_pastry;
public:
    Order(Stock<Product>& stock) : stoc(stock) {
    }
    void addProduct(unique_ptr<Product> &product) {
        if (!dynamic_cast<Coffee*>(product.get()) && !dynamic_cast<FlavouredCoffee*>(product.get()) && !dynamic_cast<VegetalMilkCoffee*>(product.get()) && !dynamic_cast<FlavouredCoffeeWithVegetalMilk*>(product.get()) && !dynamic_cast<Tea*>(product.get()) && !dynamic_cast<Pastry*>(product.get())) {
            throw InvalidProductException();
        }
        push_back(std::move(product));
        if (dynamic_cast<Coffee *>(product.get()))
            ++nr_coffee;
        else if (dynamic_cast<FlavouredCoffee *>(product.get()))
            ++nr_coffee;
        else if (dynamic_cast<VegetalMilkCoffee *>(product.get()))
            ++nr_coffee;
        else if (dynamic_cast<FlavouredCoffeeWithVegetalMilk *>(product.get()))
            ++nr_coffee;
        else if (dynamic_cast<Tea *>(product.get()))
            ++nr_tea;
        else if (dynamic_cast<Pastry *>(product.get()))
            ++nr_pastry;
    }
    void removeProduct(unique_ptr<Product> &product) {
        for (auto it = begin(); it != end(); it++) {
            bool found=false;
            if (it->get() == product.get()) {
                if (dynamic_cast<Coffee *>(product.get())) {
                    product.reset();
                    --nr_coffee;
                } else if (dynamic_cast<FlavouredCoffee *>(product.get())) {
                    product.reset();
                    --nr_coffee;
                } else if (dynamic_cast<VegetalMilkCoffee *>(product.get())) {
                    product.reset();
                    --nr_coffee;
                } else if (dynamic_cast<FlavouredCoffeeWithVegetalMilk *>(product.get())) {
                    product.reset();
                    --nr_coffee;
                } else if (dynamic_cast<Tea *>(product.get())) {
                    product.reset();
                    --nr_tea;
                } else if (dynamic_cast<Pastry *>(product.get())) {
                    product.reset();
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

        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        int day_of_week = local_time->tm_wday;
        // Verificați dacă ziua curentă este sâmbătă(=6) sau duminică(=0)
        if (day_of_week == 0 || day_of_week == 6) {
            cout << "Deoarece este weekend, beneficiezi de o reducere de 10%. Totalul dumneavoastra este: " << getTotal() - getTotal() * 0.1 << ".\n";
        } else {
            cout << "Totalul dumneavoastra este: " << getTotal() << ".\n";
        }
    }
    void printOrder(){
        if(getTotal()<=0)
            throw EmptyOrderException();
        //sortare dupa pret
        sort(begin(),end(), CompareProductsByPrice);
        for (int i=0;i<size();i++) {
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

template <typename T>
void add_a_product(Order& order, unique_ptr<T>& product) {
    order.addProduct(product);
}

template <typename T>
void remove_a_product(Order& order, unique_ptr<T>& product) {
    order.removeProduct(product);
}

int main()
{
    //initializam obiecte de tip Coffee
    unique_ptr<Product> espresso1= make_unique<Coffee>("Espresso", "Short", 5);
    unique_ptr<Product> espresso2=make_unique<Coffee>("Espresso", "Double", 5);
    unique_ptr<Product> americano1=make_unique<Coffee>("Americano","Short",6);
    unique_ptr<Product> americano2=make_unique<Coffee>("Americano","Double",8);
    unique_ptr<Product> cappuccino1=make_unique<Coffee>("Cappuccino","Small",6);
    unique_ptr<Product> cappuccino2=make_unique<Coffee>("Cappuccino","Medium",8);
    unique_ptr<Product> cappuccino3=make_unique<Coffee>("Cappuccino","Large",10);
    unique_ptr<Product> latte1=make_unique<Coffee>("Caffe Latte","Small",7);
    unique_ptr<Product> latte2=make_unique<Coffee>("Caffe Latte","Medium",9);
    unique_ptr<Product> latte3=make_unique<Coffee>("Caffe Latte","Large",11);
    unique_ptr<Product> ice_coffee1=make_unique<Coffee>("Ice Coffee","Small",8);
    unique_ptr<Product> ice_coffee2=make_unique<Coffee>("Ice Coffee","Medium",10);
    unique_ptr<Product> ice_coffee3=make_unique<Coffee>("Ice Coffee","Large",12);

    //initializare obiecte de tip FlavouredCoffee
    unique_ptr<Product> caramel_cappuccino=make_unique<FlavouredCoffee>("Cappuccino", "Medium", "Caramel", cappuccino2->getPrice()+1);
    unique_ptr<Product> vanilla_cappuccino=make_unique<FlavouredCoffee>("Cappuccino", "Medium", "Vanilla", cappuccino2->getPrice()+1);

    //initializare obiecte de tip VegetalMilkCoffee
    unique_ptr<Product> oat_cappuccino= make_unique<VegetalMilkCoffee>("Cappuccino", "Medium", "Oat", cappuccino2->getPrice()+3);
    unique_ptr<Product> soya_cappuccino=make_unique<VegetalMilkCoffee>("Cappuccino", "Medium", "Soya", cappuccino2->getPrice()+3);

    //initializare obiecte de tip FlavouredCoffeeWithVegetalMilk
    unique_ptr<Product> caramel_oat_cappuccino=make_unique<FlavouredCoffeeWithVegetalMilk>("Cappuccino", "Medium", "Caramel", "Oat", oat_cappuccino->getPrice()+1);
    unique_ptr<Product> caramel_soya_cappuccino= make_unique<FlavouredCoffeeWithVegetalMilk>("Cappuccino", "Medium", "Caramel", "Soya", oat_cappuccino->getPrice()+1);

    //initializare obiecte de tip Pastry
    unique_ptr<Product> croissant= make_unique<Pastry>("Croissant", 5);
    unique_ptr<Product> croissant_cioco=make_unique<Pastry>("Croissant with Nutella",6);
    unique_ptr<Product> cookie=make_unique<Pastry>("Cookie", 5);
    unique_ptr<Product> muffin=make_unique<Pastry>("Muffin",6);

    //initializare obiecte de tip Tea
    unique_ptr<Product> tea1= make_unique<Tea>("Black Tea",10); //constructor cu parametri
    unique_ptr<Product> tea2= make_unique<Tea>("Green Tea",tea1->getPrice()); //constructor fara parametri

    //initializare comenzi
    Order order1;
    add_a_product(order1,espresso1);
    add_a_product(order1,croissant);
    add_a_product(order1,cookie);
    add_a_product(order1,cappuccino3);
    order1.getTotal();
    order1.printTotal();
    order1.printOrder();
    Order::printNr_coffee();
    Order::printNr_tea();
    Order::printNr_pastry();

    //bloc try_catch
//    try{
//        order2.printTotal();
//    }
//    catch (const EmptyOrderException& e){
//        cout<<"Am prins exceptia. "<<e.what()<<"\n";
//    }
    //bloc try_catch care rearunca o exceptie
//    try{
//        cappuccino2->setPrice(-2);
//    }
//    catch (const NegativePriceException& e){
//        cout<<"Am prins exceptia. "<<e.what()<<"\n";
//        throw InvalidProductException();
//    }
}
