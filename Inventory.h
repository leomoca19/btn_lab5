#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include "Product.h"

using std::ostream, std::map;

class Inventory {
private:
    map<const unsigned short, unsigned short> products;

public:
    Inventory(const char *fname = "inventory.txt");

    void populate();

    void display() const;

    void printOptions() const;

    void load();

    void save();

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

