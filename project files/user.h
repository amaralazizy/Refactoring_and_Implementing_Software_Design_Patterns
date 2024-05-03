#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
#include "UserPersonalInfo.h"

#include "cart.h"

using namespace std;

//class User:DB {
class User : public BaseEntity, public UserPersonalInfo {
private:

    int cartId;
    static string filename;
    string password;

public:
    // Getter functions
    virtual string getName() const override;

    virtual string getEmail() const override;
    virtual string getUserAddress() const override;
    virtual string getCreditCardNumber() const override;
    // Setter functions
    virtual void setName(const string newName) override;

    virtual void setEmail(const string& newEmail) override;

    virtual void setUserAddress(const string& newUserAddress) override;

    virtual void setCreditCardNumber(const string& newCreditCardNumber) override;


    void setPassword(const string& newPassword);

    void setCartId(int newCartId);

    User* login(User* res);
    bool signUp();
    Cart getUserCart();
    string getPassword() const;
    int getCartId() const;

    vector<ProductInCart> getProductsInCart();

    string pay(float total);

    bool removeFromCart(int productId);

    // Functions for storing and reading users from file
    static void writeData(const vector<User>& users);
    static vector<User> readData();

};