//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_CONTROLLER_H
#define ONLINE_SHOP2_CONTROLLER_H

//#include "View.h"
//#include "user.h"
//#include "Selection.h"
#include "Model.h"

class Controller {
    View* view;
    Model* model;
    Product selectedProduct;
public:
    Controller();

    void handleCart(User** user);

    void loginUser(User** user);

    void signupUser(User** user);

    void addProductToCart(User** user);

    void shop(User** user);

    void loggedInUser(User** user);
};


#endif //ONLINE_SHOP2_CONTROLLER_H
