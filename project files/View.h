//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_VIEW_H
#define ONLINE_SHOP2_VIEW_H
#include "Selection.h"
#include "Utils.h"
#include <map>

//#include "productInCart.h"
//#include"user.h"

using namespace std;

class View {
public:
    void displayProductsInCart(vector<ProductInCart> productsInCart);

    void setLoginCredentials(User* user) const;

    void setSignupCredentials(User* user) const;

    int getProductWantedQuantity(int availableAmount) const;

    Product showProductListAndSelectProduct(vector<Product> productList) const;

    void showProductData(Product) const;
};


#endif //ONLINE_SHOP2_VIEW_H

