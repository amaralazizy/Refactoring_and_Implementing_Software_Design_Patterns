#include "Model.h"
#include<iostream>

using std::cout;
using std::vector;

Model* Model::getInstance(){
    if (instance == nullptr)
    {
        instance = new Model();
    }
    return instance;
}

Model* Model::instance = nullptr;

double Model::getTotal(vector<ProductInCart> productsInCart){
    double total = 0;
    for (ProductInCart productInCart : productsInCart) {
        Product product = productInCart.getProduct();
        double productTotal = productInCart.getCount() * product.getPrice();
        total += productTotal;
    }
    return total;
}

void Model::proceedPayment(User** user){
    vector<ProductInCart> productsInCart = (*user)->getProductsInCart();
    cout << (*user)->pay((float)getTotal(productsInCart)) << endl << "Products will arrive you at " << (*user)->getUserAddress();
    for (ProductInCart productInCart : productsInCart) {
        productInCart.getProduct().decreaseProductQuantity(productInCart.getCount());
    }
}

void Model::removeProductFromCart(User** user){
    vector<ProductInCart> productsInCart = (*user)->getProductsInCart();
    int number;

    cout << "Enter the number of product to remove from cart: " << endl;
    cin >> number;
    if((*user)->removeFromCart(productsInCart[number-1].getProduct().getId())) cout << "Product removed successfully!" << endl;
}

vector<Product> Model::getProductList() const {
    return Product::readData();
}