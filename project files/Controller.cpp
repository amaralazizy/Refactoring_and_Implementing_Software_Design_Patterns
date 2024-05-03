//
// Created by NoteBook on 23/05/2023.
//

#include "Controller.h"
//#include "user.h"
#include <iostream>
#include <functional>

using namespace std;

Controller::Controller(){
    view = new View();

    model = Model::getInstance();
}

void Controller::handleCart(User** user) {
    view->displayProductsInCart((*user)->getProductsInCart());
    if ((*user)->getProductsInCart().size() > 0){
        ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
        Selection* actionSelect = selectionPool->acquireObject();
        function<void(User**)> proceedPaymentCallback = bind(&Model::proceedPayment, model, placeholders::_1);
        actionSelect->addChoice("Proceed Payment", proceedPaymentCallback);

        function<void(User**)> removeProductCallback = bind(&Model::removeProductFromCart, model, placeholders::_1);
        actionSelect->addChoice("Remove product from cart", removeProductCallback);
        actionSelect->handleUserChoice(user);
    }
}

void Controller::loginUser(User** user) {
    cout << "Login Please:" << endl;
    do {
        *user = new User();

        view->setLoginCredentials(*user);
        /*
        (*user)->setEmail(c.first);
        (*user)->setPassword(c.second);
        */

        *user = (*user)->login(*user);

        if (!(*user)) cout << "Wrong email or password. Try Again: " << endl;
    } while (!(*user));
    cout << "Logged in successfully!\n" << endl;
}

void Controller::signupUser(User** user){
    *user = new User();
    view->setSignupCredentials(*user);
    if((*user)->signUp()) {
        cout << "Signed up successfully!\n" << endl;
        loginUser(user);
    }
}

void Controller::addProductToCart(User** user){
    if (!(*user))  {
        ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
        Selection* authSelect = selectionPool->acquireObject();
        authSelect->addChoice("Login",  bind(&Controller::loginUser, this, placeholders::_1));
        authSelect->addChoice("Signup",  bind(&Controller::signupUser, this, placeholders::_1));
        authSelect->handleUserChoice(user);
    }

    int wantedQuantity = view->getProductWantedQuantity(selectedProduct.getQuantity());
    if (wantedQuantity) {
        Cart userCart = (*user)->getUserCart();
        if (userCart.add_toCart(selectedProduct, wantedQuantity)) {
            cout << selectedProduct.getName() << " Added to Cart Successfully" << endl;
        }
        else cout << "Unknown error adding product to cart" << endl;
    }
}

void Controller::shop(User** user) {
    selectedProduct = view->showProductListAndSelectProduct(model->getProductList());

    ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
    Selection* actionSelect = selectionPool->acquireObject();

    actionSelect->addChoice("Add to cart", bind(&Controller::addProductToCart, this, placeholders::_1));
    actionSelect->addChoice("Continue shopping", bind(&Controller::shop, this, placeholders::_1));
    actionSelect->addChoice("Exit");
    actionSelect->handleUserChoice(user);
}

void Controller::loggedInUser(User** user) {
    while (true) {
        ObjectPool<Selection>* selectionPool = ObjectPool<Selection>::getInstance();
        Selection* actionSelect = selectionPool->acquireObject();

        actionSelect->addChoice("Go shopping", bind(&Controller::shop, this, placeholders::_1));
        actionSelect->addChoice("Show cart", bind(&Controller::handleCart, this, placeholders::_1));
        actionSelect->handleUserChoice(user);
    }
}


