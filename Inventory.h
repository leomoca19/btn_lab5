#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include "Product.h"

using std::ostream, std::map;

class Inventory {
public:
    map<const unsigned short, unsigned short> products;

    Inventory(const char *fname = "inventory.txt");

    void populate(const char* fname);

    static std::string menuOptions();

    // void display() const;

    // void load(const char *fname);

    // void save() const;

    void sell();

    void menu();
};

inline ostream &operator<<(const ostream &os, const Inventory &other);

#endif //INVENTORY_H


/*
class ItemManager():

    def __init__(self, fname: str) -> None:
    def loadBackup(self) -> None:
    @staticmethod
    def printOpts() -> None:
    def __len__(self) -> int:
    def __str__(self) -> str:
    def save(self) -> None:
    def addItem(self, upc: str, qty: int) -> None:
    def findItemByUpc(self, upc: str) -> Optional[Item]:
    def getItemQty(self) -> Tuple[Item, int]:
    def display(self) -> None:
    def sell(self) -> None:
    def restock(self) -> None:
    def menu(self) -> None:
*/

