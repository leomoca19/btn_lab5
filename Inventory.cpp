#include <fstream>
#include "Inventory.h"

using std::string, std::stoi;

/**
 *  This constructor attempts to load products from file
 *  If file is not found or is empty, system will load and save random data
 */
Inventory::Inventory(const char *fname) {
    std::ifstream file(fname);
    if (file.is_open()) {
        string line;
        while (getline(file, line, '\n')) {
            // UPC:XXXX Quantity:XXX

            // extract upc and qty from record
            unsigned short delim_pos = line.find(':');
            const unsigned short upc = stoi(line.substr(0, delim_pos));
            delim_pos = line.find(':', delim_pos + 1);
            const unsigned short qty = stoi(line.substr(delim_pos, line.size() - delim_pos));

            // if upc already exists, panic
            if (products.contains(upc)) { throw "Upc already exists"; }

            products[upc] = qty;
        }
    }
    if (!products.size())
        populate();
}

void Inventory::populate() {
    // open file for wiritng
    // create random data
    // load random data to memory
    // save random data to file
}

/*
class ItemManager():

    def __init__(self, fname: str) -> None:
        self.fname = fname
        self.items = []

        try:
            with open(self.fname, 'rb') as file:
                self.items = pickle.load(file)
        except:
            self.save()

        # if fname == 'items.pkl' and len(self) < 1:
        #     self.loadBackup()

        print('items loaded:', len(self))

    def loadBackup(self) -> None:
        with open('items.bkp') as file:
            while line := file.readline():
                upc, qty = line.split()
                self.items.append(Item(upc, int(qty)))

    @staticmethod
    def printOpts() -> None:
        print('Choose an option\n'
              '  0 exit\n'
              '  1 view local inventory\n'
              '  2 view server inventory\n'
              '  3 buy item\n'
              '  4 restock item\n',
              end=': ')

    def __len__(self) -> int:
        return len(self.items)

    def __str__(self) -> str:
        return ''.join(str(item) + '\n' for item in self.items)

    def save(self) -> None:
        with open(self.fname, 'wb') as file:
            pickle.dump(self.items, file)
        print(f'Changes persisted successfully to {self.fname}')

    def addItem(self, upc: str, qty: int) -> None:
        item = self.findItemByUpc(upc)
        if item is not None:
            item += qty
        else:
            item = Item(upc, qty)
            self.items.append(item)

        print(f'Item updated: {item}')

    def findItemByUpc(self, upc: str) -> Optional[Item]:
        for item in self.items:
            if item.upc == upc:
                return item
        return None

    def getItemQty(self) -> Tuple[Item, int]:
        upc_msg = 'enter upc code: '
        qty_msg = 'enter quantity: '
        while not (item := self.findItemByUpc(input(upc_msg))):
            print(('upc not found'))

        while item.qty > (qty := int(input(qty_msg))) < 0:
            print('invalid input\nselected item:', item)

        return item, qty

    def display(self) -> None:
        if len(self) < 1:
            print('No items in system')
        else:
            print(str(self))

    def sell(self) -> None:
        item, qty = self.getItemQty()
        item -= qty
        print('item updated: ', item)

    def restock(self) -> None:
        item, qty = self.getItemQty()
        item += qty
        print('item updated: ', item)

    def menu(self) -> None:
        self.display()
        while True:
            self.printOpts()

            match int(input()):
                case 0: break
                case 1: self.display()
                case 2: self.sell()
                case 3: self.restock()
                case _: print('invalid input')
        print('You exit the item manager\'s menu')

        self.save()


if __name__ == '__main__':
    i = ItemManager('items.pkl')
    i.menu()
 */
