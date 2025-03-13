#include <fstream>
#include <iostream>
#include <format>
#include "Inventory.h"

using std::string, std::format, std::stoi, std::cout, std::cin, std::endl;

/**
 *  This constructor attempts to load products from file
 *  If file is not found or is empty, system will load and save random data
 */
Inventory::Inventory(const char* owner) : owner(owner)
{
    std::ifstream file(fname());
    if (file.is_open())
    {
        string line; // UPC:XXXX Quantity:XXX
        while (getline(file, line))
        {
            // extract upc and qty from record
            size_t delim_pos = line.find(':') + 1;
            if (delim_pos != string::npos)
            {
                const size_t upc = stoi(line.substr(delim_pos));
                delim_pos = line.find(':', delim_pos) + 1;
                const size_t qty = stoi(line.substr(delim_pos, line.size() - delim_pos));

                products[upc] = qty;
            }
        }
        file.close();
    }
    if (!products.size())
        populate();
}

void Inventory::populate()
{
    // load random data into memory
    for (size_t i = 0; i < 11; i++)
    {
        const size_t upc = 1000 + i;
        const size_t qty = std::rand() % 1000;

        products[upc] = qty;
    }

    // save data to file
    std::ofstream file(fname());
    file << *this;
    file.close();
}

bool Inventory::in_keyes(const size_t _upc) const
{
    if (0 == _upc) return false;

    for (const auto& p : products)
    {
        if (_upc == p.first)
            return true;
    }
    return false;
}

void Inventory::sell()
{
    string inp;
    size_t upc = 0;
    while (!in_keyes(upc))
    {
        cout << "Enter a upc>";
        cin >> inp;
        upc = stoi(inp);
        if (!in_keyes(upc))
        {
            cout << "UPC not found" << endl;
        }
    }

    size_t qty = 0;
    while (!qty || qty > products[upc])
    {
        cout << "Enter a quantity>";
        cin >> inp;
        qty = stoi(inp);

        cout << (
            (!qty || qty > products[upc])
                ? format("Invalid amount\n")
                : format("Sold {} product(s)\n", qty)
        ) << format("UPC: {} QTY: {}", upc, (products[upc]-=qty)) << endl << endl;
    }
}

void Inventory::menu()
{
    string inp;
    bool repeat = true;
    while (repeat)
    {
        cout << menuOptions();
        cin >> inp;

        switch (stoi(inp))
        {
        case 0:
            repeat = false;
            break;

        case 1:
            cout << owner << "'s inventory" << endl
                << *this << endl;
            break;

        case 2: cout << "Under construction\n";
            break;

        case 3: sell();
            break;

        default: cout << "Invalid input\n";
            break;
        }
    }

    std::ofstream file(fname());
    file << *this;
    file.close();
    cout << "Changes persisted" << endl;
}

std::ostream& operator<<(std::ostream& os, const Inventory& other)
{
    for (const auto& [upc, qty] : other.getProducts())
    {
        os << "UPC: " << upc << " Quantity: " << qty << endl;
    }
    return os;
}
