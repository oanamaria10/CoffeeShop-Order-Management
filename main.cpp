#include<iostream>
#include<cstring>
using namespace std;

class String{
private:
    char *data;
    int Size;
public:
    String(){ data=nullptr, Size=0 ;}
    ~String(){
        delete[]data;
    }
    String(const char*string_literal){
        Size=strlen(string_literal);
        data=new char[Size+1];
        strcpy(data,string_literal);
    }
    String(const String &sir){
        Size=sir.Size;
        data=new char[Size+1];
        strcpy(data,sir.data);
    }
    String &operator=(const String &sir)
    {
        if(this!= &sir)
        {
            delete[] data;
            Size= sir.Size;
            data=new char[Size+1];
            strcpy(data, sir.data);
        }
        return *this;
    }
    void adaugare_caracter_la_sir(const char*caracter){
        Size=Size+1;
        data=new char[Size+1];
        strcat(data,caracter);
    }
    void concatenare_a_doua_siruri(const String &sir){
        Size=Size+sir.Size;
        data=new char[Size+1];
        strcat(data,sir.data);
    }
    bool gasire_subsir(const String &sir){
        strstr(data,sir.data);
    }
    friend istream &operator>>(istream &in, String &sir)
    {
        in>>sir.Size;
        in>>sir.data;
        return in;
    }
    friend ostream &operator<<(ostream &out, const String &sir) {
        out<<sir.data;
        return out;
    }
};

class Coffee{
private:
    String CoffeeType;
    String CoffeeSize;
    double CoffeePrice;
public:
    void setCoffeeType(String coffee_type){
        CoffeeType=coffee_type;
    }
    String getCoffeeType(){
        return CoffeeType;
    }
    void setCoffeeSize(String coffee_size){
        CoffeeSize=coffee_size;
    }
    String getCoffeeSize(){
        return CoffeeSize;
    }
    void setCoffeePrice(double coffee_price){
        CoffeePrice=coffee_price;
    }
    double getCoffeePrice(){
        return CoffeePrice;
    }
    Coffee(String coffee_type, String coffee_size, double coffee_price){
        CoffeeType=coffee_type;
        CoffeeSize=coffee_size;
        CoffeePrice=coffee_price;
    }
    friend istream &operator>>(istream &in, Coffee &coffee)
    {
        in>>coffee.CoffeeType>>coffee.CoffeeSize>>coffee.CoffeePrice;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Coffee &coffee)
    {
        out<<coffee.CoffeeType<<coffee.CoffeeSize<<coffee.CoffeePrice;
        return out;
    }
    void afisare()
    {
        cout<<CoffeeType<<" "<<CoffeeSize<<" "<<CoffeePrice;
    }
};
class Pastry{
private:
    String PastryProduct;
    double PastryPrice;
public:
    void setPastryProduct(String pastry_product){
        PastryProduct=pastry_product;
    }
    String getPastryProduct(){
        return PastryProduct;
    }
    void setPastryPrice(double pastry_price){
        PastryPrice=pastry_price;
    }
    double getPastryPrice(){
        return PastryPrice;
    }
    Pastry(String pastry_product, double pastry_price){
        PastryProduct=pastry_product;
        PastryPrice=pastry_price;
    }
    friend istream &operator>>(istream &in, Pastry &pastry)
    {
        in>>pastry;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Pastry &pastry)
    {
        out<<pastry<<" ";
        return out;
    }
    void afisare()
    {
        cout<<PastryProduct<<" "<<PastryPrice;
    }
};

class Product{
private:
    Coffee *coffee;
    Pastry *pastry;
public:
    Product(){
        coffee=nullptr,pastry=nullptr;
    }
    Product &operator=(const Product &product)
    {
        if(this!=&product)
        {
            coffee=product.coffee;
            pastry=product.pastry;
        }
        return *this;
    }
    bool alloc_coffee(Coffee *coffee_product){
        return coffee_product!=nullptr;
    }
    bool alloc_pastry(Pastry *pastry_product){
        return pastry_product!=nullptr;
    }
    void setcoffee(Coffee *coffee_product){
        coffee=coffee_product;
    }
    Coffee getcoffee(){
        return *coffee;
    }
    void setpastry(Pastry *pastry_product){
        pastry=pastry_product;
    }
    Pastry getpastry(){
        return *pastry;
    }
    friend istream &operator>>(istream &in, Product &product)
    {
        in>>product;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Product &product)
    {
        out<<product<<" ";
        return out;
    }
};
class Order{
private:
    int Size;
    Product *product;
public:
    Order(){
        Size=0;
        product=nullptr;
    }
    Order(int other_Size, Product other_product){
         Size=other_Size;
         product=new Product[other_Size];
         for(int i=0;i<other_Size;i++)
            product[i]=other_product;
    }
    ~Order()
    {
        if(product!=nullptr)
            delete []product;
        product=nullptr;
    }
    Order(const Order &other_product)
    {
        Size=other_product.Size;
        product=new Product[other_product.Size];
        for(int i=0;i<Size;i++)
            product[i]=other_product.product[i];
    }
    bool allocationOrder(int other_Size)
    {
        if(product!=nullptr)
        {
            delete[] product;
            product=nullptr;
        }
        Size=other_Size;
        if(Size!=0)
            product=new Product[Size];
        return product!=nullptr;
    }
    Order &operator=(const Order &other_product)
    {
        if(allocationOrder(other_product.Size)==false)
            return *this;
        for(int i=0;i<Size;i++)
            product[i]=other_product.product[i];
        return *this;
    }
    friend istream &operator>>(istream &in, Order &other_product)
    {
        int other_size;
        in>>other_size;
        if(other_product.allocationOrder(other_size)==false)
            return in;
        for(int i=0;i<other_product.Size;i++)
            in>>other_product.product[i];
        return in;
    }
    friend ostream &operator<<(ostream &out,const Order &other_product)
    {
        for(int i=0;i<other_product.Size;i++)
            out<<other_product.product[i]<<" ";
        return out;
    }
    void add_coffee(Coffee &one_product)
    {
        if(&product->alloc_coffee){
        Product *new_product=nullptr;
        new_product=new Product[Size+1];
        for(int i=0;i<Size;i++)
            new_product[i]=product[i];
        new_product[Size].setcoffee(&one_product);
        if(product!=nullptr)
        {
            delete[] product;
            product=nullptr;
        }
        product=new_product;
        Size++;
        }
    }
    void add_pastry(Pastry &one_product)
    {
        if(&product->alloc_pastry){
        Product *new_product=nullptr;
        new_product=new Product[Size+1];
        for(int i=0;i<Size;i++)
            new_product[i]=product[i];
        new_product[Size].setpastry(&one_product);
        if(product!=nullptr)
        {
            delete[] product;
            product=nullptr;
        }
        product=new_product;
        Size++;
        }
    }
};
class Cafenea{
private:
    Order order;
    String client_occupation;
    double plata;
public:
    Cafenea(Order _order, String _client_occupation, double _plata){
        order=_order;
        client_occupation=_client_occupation;
        plata=_plata;
    }
    void setorder(Order _order){
        order=_order;
    }
    Order getorder(){
        return order;
    }
    void setclient_occupation(String _client_occupation){
        client_occupation=_client_occupation;
    }
    String getclient_occupation(){
        return client_occupation;
    }
    void setplata(double _plata){
        plata=_plata;
    }
    double getplata(){
        return plata;
    }
    void ClientOrdering(){
        cout<<"I would like to order "<<order<<"\n";
    }
    void Paying(){
        cout<<"You have to pay "<<plata<<" lei"<<"\n";
    }
    void PayingDiscount(){
        if(client_occupation.gasire_subsir("Student"))
            cout<<"Because you are a student, you have a discount of 15% and your total is "<<plata-plata*15/100<<" lei"<<"\n";
        else cout<<"Sorry, you cannot have a discount";
    }
    friend istream &operator>>(istream &in, Cafenea &var)
    {
        in>>var.order>>var.client_occupation>>var.plata;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Cafenea &var)
    {
        out<<var.order<<var.client_occupation<<var.plata;
        return out;
    }
};

int main()
{
    Coffee espresso1=Coffee("Espresso","Short",5);
    Coffee espresso2=Coffee("Espresso","Double",7);
    Coffee americano1=Coffee("Americano","Short",6);
    Coffee americano2=Coffee("Americano","Double",8);
    Coffee cappuccino1=Coffee("Cappuccino","Small",6);
    Coffee cappuccino2=Coffee("Cappuccino","Medium",8);
    Coffee cappuccino3=Coffee("Cappuccino","Large",10);
    Coffee latte1=Coffee("Caffe Latte","Small",7);
    Coffee latte2=Coffee("Caffe Latte","Medium",9);
    Coffee latte3=Coffee("Caffe Latte","Large",11);
    Coffee ice_coffee1=Coffee("Ice Coffee","Small",8);
    ice_coffee1.setCoffeePrice(7);
    Coffee ice_coffee2=Coffee("Ice Coffee","Medium",10);
    ice_coffee1.setCoffeePrice(9);
    Coffee ice_coffee3=Coffee("Ice Coffee","Large",12);
    ice_coffee1.setCoffeePrice(11);
    Pastry croissant=Pastry("Croissant", 5);
    Pastry croissant_cioco=Pastry("Croissant with Nutella",6);
    Pastry cookie=Pastry("Cookie",5);
    Pastry muffin=Pastry("Muffin",6);
    Order comanda1=Order();
    comanda1.add_coffee(espresso1);
    comanda1.add_coffee(espresso2);
    comanda1.add_pastry(croissant);
    Cafenea _comanda1=Cafenea(comanda1,"Student",0);
    _comanda1.setplata(12);
    _comanda1.PayingDiscount();
    Order comanda2=Order();
    comanda2.add_coffee(cappuccino2);
    comanda2.add_pastry(muffin);
    Cafenea _comanda2=Cafenea(comanda2,"Pensionar",0);
    _comanda2.setplata(14);
    _comanda2.ClientOrdering();
    _comanda2.Paying();
    _comanda2.PayingDiscount();
}
