#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
using std::map, std::string;

class Inventory
{
    map<const size_t, size_t> products;
    const char* owner;

    string fname() const
    {
        const std::string fname = owner;
        return fname + ".txt";
    }

    static string menuOptions()
    {
        return "Select an option\n"
            "0 - Exit\n"
            "1 - Display local inventory\n"
            "2 - Display server inventory\n"
            "3 - Buy from server\n>";
    }

    void sell();
    void populate();

    bool in_keyes(const size_t upc) const;


public:
    Inventory(const char* owner);

    map<const unsigned short, unsigned short> getProducts() const
    {
        return std::map<const unsigned short, unsigned short>(products.begin(), products.end());
    }

    void menu();
};

inline std::ostream& operator<<(std::ostream& os, const Inventory& other);

#endif //INVENTORY_H
