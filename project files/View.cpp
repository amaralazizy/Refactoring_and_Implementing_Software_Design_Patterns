#include "View.h"



#include<iostream>
#include <limits>
using namespace std;

void View::displayProductsInCart(vector<ProductInCart> productsInCart){
    cout << "Products In Cart: " << endl;
    int counter = 1;
    double total = 0;
    for (ProductInCart productInCart : productsInCart) {
        Product product = productInCart.getProduct();
        double productTotal = productInCart.getCount() * product.getPrice();
        cout << counter << ") " << productInCart.getCount() << " of " << product.getName() << "\t\t" << productInCart.getCount() << " * " << product.getPrice() << " = " << productTotal << "$" << endl;
        total += productTotal;
        counter++;
    }
    cout << "TOTAL:\t" << total << endl;
}

void View::setLoginCredentials(User* user) const{
        cout << "Enter Email: " << endl;
        string email;
        cin >> email;
        user->setEmail(email);

        cout << "Enter Password: " << endl;
        string pass;
        cin >> pass;
        user->setPassword(pass);
}

void View::setSignupCredentials(User* user) const {
    cout << "Write your full name" << endl;
    string name;
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    user->setName(name);

    cout << "Write your Email" << endl;
    string email;
    cin >> email;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    user->setEmail(email);

    cout << "Enter password" << endl;
    string password;
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    user->setPassword(password);

    cout << "Enter address" << endl;
    string address;
    cin >> address;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    user->setUserAddress(address);

    cout << "Enter credit card number" << endl;
    string creditCardNumber;
    cin >> creditCardNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    user->setCreditCardNumber(creditCardNumber);
}

int View::getProductWantedQuantity(int availableAmount) const{
    if (!availableAmount) {
        cout << "Out of stock!\n";
        return 0;
    }
    cout << availableAmount << " Left in stock." << endl;
    
    cout << "How many do you want? " << endl;

    Utils* util = Utils::getInstance();
    int wantedQuantity = util->getValidNum(availableAmount);

    return wantedQuantity;
}

void View::showProductData(Product product) const {
    cout << "Description: " << product.getDescription() << endl;
    cout << "Price: " << product.getPrice() << endl;
    cout << "Quantity: " << product.getQuantity() << endl;
    cout << "User Rating: " << product.getUserRating() << endl;
}

Product View::showProductListAndSelectProduct(vector<Product> productList) const {
    int number;
    cout << endl;
    cout << "Click on the number of the product to show description" << endl;

    //For loop to display all products
    for (Product product : productList) {
        cout << product.getId() << ") " << product.getName() << endl;
    }

    //choosing a number to show the product description
    cout << "Chose a number: " << endl;
    cin >> number;

    //for loop to show the products description
    Product selectedProduct;
    for (Product product : productList) {
        if (number == product.getId()) {
            selectedProduct = product;
            showProductData(product);
            break;
        }
    }

    return selectedProduct;
}


