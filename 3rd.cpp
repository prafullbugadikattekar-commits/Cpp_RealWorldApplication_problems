#include <iostream>
#include <string>
using namespace std;

class Product{
    private:
        int productId;
        string productName;
        double price;
        int stockQuantity;
        static int totalProduct;

    public:
        Product(int id,string name,double p,int stock)
            :productId(id),productName(name),price(p),stockQuantity(stock){
                totalProduct++;
            }
        inline int getId() const{return productId;}
        inline string getName() const {return productName;}
        inline double getPrice() const {return price;}

        void updateStock(int quantity){
            stockQuantity = quantity;
        }

        static int getTotalProduct(){
            return totalProduct;
        }

        void display() const{
            cout<<"ID:"<<productId<<"|Product: "<<productName<<"| Price:RS "<<price<<"|Stock: "<<stockQuantity<<endl;
        }

        ~Product(){
            totalProduct--;
        }

};

int Product::totalProduct = 0;

int main()
{
    Product p1(1001,"Laptop",55000,15);
    Product p2(1002,"Mouse",450,50);
    Product p3(1003,"Keyboard",1200,30);

    cout<<"===Product Catalog==="<<endl;
    p1.display();
    p2.display();
    p3.display();

    cout<<"\n Total Products in Catalog: "<<Product::getTotalProduct()<<endl;
}
