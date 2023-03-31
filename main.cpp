#include<iostream>
//#include<string>
#include <cstring>
using namespace std;

class String{
private:
    char *data;
    int Size;
public:
    String(){ data=nullptr, Size=0 ;}
    ~String(){
        if(data!= nullptr)
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
        char s[1000];
        in>>s;
        if(sir.data!= nullptr)
            delete[] sir.data;
        sir.data=new char[sizeof(s)];
        strcpy(sir.data, s);
        sir.Size=sizeof(s);
        return in;
    }
    friend ostream &operator<<(ostream &out, const String &sir) {
        if(sir.data!= nullptr)
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
        CoffeeType = coffee_type;
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
    Coffee(){
        CoffeeType= "";
        CoffeeSize= "";
        CoffeePrice=0;
    }
    Coffee(String coffee_type, String coffee_size, double coffee_price){
        CoffeeType=coffee_type;
        CoffeeSize=coffee_size;
        CoffeePrice=coffee_price;
    }
    ///copy constructor
    Coffee(const Coffee &other){
        this->CoffeeType=other.CoffeeType;
        this->CoffeeSize=other.CoffeeSize;
        this->CoffeePrice=other.CoffeePrice;
    }
    friend istream &operator>>(istream &in, Coffee &coffee)
    {
        in>>coffee.CoffeeType>>coffee.CoffeeSize>>coffee.CoffeePrice;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Coffee &coffee)
    {
        out<<coffee.CoffeeType<<" "<<coffee.CoffeeSize<<" "<<coffee.CoffeePrice<<"\n";
        return out;
    }
    void afisare()
    {
        cout<<"Sortiment de cafea: ";
        cout<<CoffeeType<<" "<<CoffeeSize<<" "<<CoffeePrice<<"\n";
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
    Pastry(){
        PastryProduct="";
        PastryPrice=0;
    }
    friend istream &operator>>(istream &in, Pastry &pastry)
    {
        in>>pastry.PastryProduct>>pastry.PastryPrice;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Pastry &pastry)
    {
        out<<pastry.PastryProduct<<" "<<pastry.PastryPrice<<"\n";
        return out;
    }
    void citire()
    {
        cout<<"Produs patiserie: ";
        cin>>PastryProduct>>PastryPrice;
    }
    void afisare()
    {
        cout<<"Produs de patiserie: "<<PastryProduct<<" "<<PastryPrice<<"\n";
    }
};
class Tea{
private:
    String TeaProduct;
    double TeaPrice;
public:
    void setTeaProduct(String tea_product){
        TeaProduct=tea_product;
    }
    String getTeaProduct(){
        return TeaProduct;
    }
    void setTeaPrice(double tea_price){
        TeaPrice=tea_price;
    }
    double getTeaPrice(){
        return TeaPrice;
    }
    Tea(String tea_product, double tea_price){
        TeaProduct=tea_product;
        TeaPrice=tea_price;
    }
    Tea(){
        TeaProduct="";
        TeaPrice=0;
    }
    friend istream &operator>>(istream &in, Tea &tea)
    {
        in>>tea.TeaProduct>>tea.TeaPrice;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Tea &tea)
    {
        out<<tea.TeaProduct<<" "<<tea.TeaPrice<<"\n";
        return out;
    }
    void citire()
    {
        cout<<"Ceai: ";
        cin>>TeaProduct>>TeaPrice;
    }
    void afisare()
    {
        cout<<"Sortiment de ceai: "<<TeaProduct<<" "<<TeaPrice<<"\n";
    }
};
/*
class Vector_produs{
private:
    int size;
    Coffee *data;
public:
    Vector_produs() {
        data= nullptr;
        size = 0;
    }
    Vector_produs(int k, Coffee &cof){
        size=k;
        data=new Coffee[size];
        for(int i=0;i<k;i++) {
            data[i].setCoffeeType(cof.getCoffeeType()) ;
            data[i].setCoffeeSize(cof.getCoffeeSize()) ;
            data[i].setCoffeePrice(cof.getCoffeePrice());
        }
    }
    ~Vector_produs(){
        delete []data;
    }
    Vector_produs(Vector_produs &coffee)
    {
        size=coffee.size;
        data=new Coffee[coffee.size];
        for(int i=0;i<size;i++)
            data[i]=coffee.data[i];
    }
    Vector_produs &operator=(const Vector_produs& coffee)
    {
        if(coffee.data== nullptr)
            return *this;
        for (int i = 0; i < size; i++){
            data[i].setCoffeeType(coffee.data[i].getCoffeeType())  ;
        data[i].setCoffeeSize(coffee.data[i].getCoffeeSize())  ;
        data[i].setCoffeePrice(coffee.data[i].getCoffeePrice()); }
        return *this;
    }
    friend ostream& operator << (ostream& out, const Vector_produs& coffee)
    {
        for (int i = 0; i < coffee.size; i++)
            out << coffee.data[i] << " ";

        return out;
    }
    friend istream& operator >> (istream& in, Vector_produs& coffee)
    {
        int n = 0;
        in >> n;
        if(coffee.data== nullptr)
            return in;
        for (int i = 0; i < coffee.size; i++)
            in >> coffee.data[i];
        return in;
    }
    void addElement(Coffee *element)
    {
        Coffee *data1 = nullptr;
        data1 = new Coffee [size+1];
        for (int i = 0; i < size; i++)
            data1[i] = data[i];
        data1[size].setCoffeeType(element->getCoffeeType())  ;
        data1[size].setCoffeeSize(element->getCoffeeSize());
        data1[size].setCoffeePrice(element->getCoffeePrice());
        if (data != nullptr)
        {
            delete[] data;
            data = nullptr;
        }
        data = data1;
        size++;
    }
    void afisare(){
        for(int i=0 ;i<size ;i++)
            cout<<data[i].getCoffeeType()<<" "<<data[i].getCoffeeSize()<<" "<<data[i].getCoffeePrice();
    }
};
*/
class Order{
private:
    Coffee *coffee;
    Pastry *pastry;
    Tea *tea;
    String client_occupation;
    double plata;
public:
    Order(){
        coffee= nullptr;
        pastry= nullptr;
        tea=nullptr;
        client_occupation= "";
        plata=0;
    }
    void setclient_occupation(String client_occupation){
        this->client_occupation=client_occupation;
    }
    String getclient_occupation(){
        return client_occupation;
    }
    void setcoffee(Coffee *coffee){
        this->coffee=coffee;
    }
    Coffee getcoffee(){
        return *coffee;
    }
    void setpastry(Pastry *pastry){
        this->pastry=pastry;
    }
    Pastry getpastry(){
        return *pastry;
    }
    void settea(Tea *tea){
        this->tea=tea;
    }
    Tea gettea(){
        return *tea;
    }
    void Ordering(){
        cout<<"What would you like to order?"<<"\n";
        if(coffee!=nullptr) cout<<"I would like to order one "<<coffee->getCoffeeSize()<<" "<<coffee->getCoffeeType()<<"\n";
        if(pastry!=nullptr) cout<<"I would like to order one "<<pastry->getPastryProduct()<<"\n";
        if(tea!=nullptr) cout<<"I would like to order one "<<tea->getTeaProduct()<<"\n";
    }
    void Paying(){
        if(coffee!=nullptr) plata+=coffee->getCoffeePrice();
        if(pastry!=nullptr) plata+=pastry->getPastryPrice();
        if(tea!=nullptr) plata+=tea->getTeaPrice();
        cout<<"You have to pay "<<plata<<" lei"<<"\n";
    }
    void PayingDiscount(){
        if(client_occupation.gasire_subsir("Student"))
            cout<<"Because you are a student, you have a discount of 15% and your total is "<<plata-plata*15/100<<" lei"<<"\n";
        else cout<<"Sorry, you cannot have a discount"<<"\n";
    }
};

int main()
{
    //initializare obiecte tip Coffee
    Coffee espresso1=Coffee("Espresso","Short",5); //folosim constructorul prin parametri
    Coffee espresso2=Coffee(espresso1); //folosim copy constructor
    espresso2.setCoffeeSize("Double"); //folosim setteri
    espresso2.setCoffeePrice(7);
    Coffee americano1=Coffee("Americano","Short",6);
    Coffee americano2=Coffee(americano1);
    americano2.setCoffeeSize("Double");
    americano2.setCoffeePrice(8);
    Coffee cappuccino1=Coffee("Cappuccino","Small",6);
    Coffee cappuccino2=Coffee(cappuccino1);
    cappuccino2.setCoffeeSize("Medium");
    cappuccino2.setCoffeePrice(8);
    Coffee cappuccino3=Coffee(cappuccino1);
    cappuccino3.setCoffeeSize("Large");
    cappuccino3.setCoffeePrice(10);
    Coffee latte1=Coffee("Caffe Latte","Small",7);
    Coffee latte2=Coffee(latte1);
    latte2.setCoffeeSize("Medium");
    latte2.setCoffeePrice(9);
    Coffee latte3=Coffee(latte1);
    latte3.setCoffeeSize("Large");
    latte3.setCoffeePrice(11);
    Coffee ice_coffee1=Coffee(); //constructor fara parametri
    ice_coffee1.setCoffeeType("Ice Coffee");
    ice_coffee1.setCoffeeSize("Regular");
    ice_coffee1.setCoffeePrice(cappuccino2.getCoffeePrice()); //getteri

    //initializare obiecte de tip Pastry
    Pastry croissant=Pastry("Croissant", 5); //Constructor cu parametri
    Pastry croissant_cioco=Pastry(); //Constructor fara parametri
    croissant_cioco.setPastryProduct("Croissant with Nutella"); //folosim setteri
    croissant_cioco.setPastryPrice(6);
    Pastry cookie=Pastry();
    cookie.citire(); //folosim functia de citire
    Pastry muffin=Pastry();
    cout<<"Alt produs de patiserie: ";
    cin>>muffin;

    //initializare obiecte de tip Tea
    Tea tea1=Tea("Black Tea",10); //constructor cu parametri
    Tea tea2=Tea(); //constructor fara parametri
    tea2.setTeaProduct("Green Tea"); //setteri
    tea2.setTeaPrice(tea1.getTeaPrice()); //getteri
    Tea tea3=Tea();
    tea3.citire(); //folosim functia de citire

    //afisari
    ///afisare obiecte de tip Coffee
    espresso1.afisare(); //folosim metoda de afisare
    espresso2.afisare();
    americano1.afisare();
    americano2.afisare();
    cappuccino1.afisare();
    cappuccino2.afisare();
    cappuccino3.afisare();
    latte1.afisare();
    latte2.afisare();
    latte3.afisare();
    cout<<"Sortiment de cafea:"<<" "<<ice_coffee1.getCoffeeType()<<" "<<ice_coffee1.getCoffeeSize()<<" "<<ice_coffee1.getCoffeePrice()<<"\n";

    ///afisare obiecte de tip Pastry
    croissant.afisare(); //folosim metoda de afisare
    cout<<"Produs de patiserie:"<<" "<<croissant_cioco.getPastryProduct()<<"\n";
    cookie.afisare();
    muffin.afisare();

    ///afisare obiecte de tip Tea
    tea1.afisare(); //metoda de afisare
    cout<<"Sortiment de ceai: "<<tea2.getTeaProduct()<<"\n";
    tea3.afisare();

    //construire obiect de tip Order
    Order comanda1=Order();
    comanda1.setcoffee(&espresso2);
    comanda1.setpastry(&muffin);
    comanda1.settea(&tea1);
    ///comanda1.setcoffee(&espresso1);
    ///comanda1.setpastry(&cookie);
    comanda1.setclient_occupation("Student");
    comanda1.setclient_occupation("Pensionar");
    comanda1.Ordering();
    comanda1.Paying();
    comanda1.PayingDiscount();
}
