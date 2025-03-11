#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <format>
using std::ostream, std::cout, std::format;

/**
 * Represents a product with a universal product code upc and a quantity qty
 */
class Product {
public:
    unsigned short upc;
    unsigned short qty;

    Product(const unsigned short &upc, const unsigned short &qty) : upc(upc), qty(qty) {
    }

    /**
     *
     * @param other quantity to be added
     * @return reference to current object
     */
    Product &operator+=(const unsigned short &other) {
        qty += other;
        return *this;
    }

    /**
     *
     * @param other quantity to be subtracted
     * @return reference to current object
     */
    Product &operator-=(const unsigned short &other) {
        if (other > qty)
            cout << "not enough items in the system\n";
        else
            qty -= other;

        return *this;
    }
};

/**
 *
 * @param os output stream
 * @param p product to be printed
 * @return the reference to the output stream
 */
inline ostream &operator<<(ostream &os, const Product &p) {
    os << format("UPC: {} - quantity: {}", p.upc, p.qty);
    return os;
}


#endif //PRODUCT_H
