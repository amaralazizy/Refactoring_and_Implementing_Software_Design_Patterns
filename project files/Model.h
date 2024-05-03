#ifndef ONLINE_SHOP2_MODEL_H
#define ONLINE_SHOP2_MODEL_H

//#include "user.h"
#include "View.h"
class Model {
    static Model* instance;

public:
    static Model* getInstance();

    void proceedPayment(User** user);
    void removeProductFromCart(User** user);
    double getTotal(vector<ProductInCart> productsInCart);
    vector<Product> getProductList() const;
};

#endif //ONLINE_SHOP2_MODEL_H
