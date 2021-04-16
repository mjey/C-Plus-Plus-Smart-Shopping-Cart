#include <bits/stdc++.h>

using namespace std;
void read(int barcode[], int pieces[], int price[], int n) {
  int i;
  cout << "\n Use single space to separate the values, for example:\n";
  cout << "\tdata of an item : 10 20 30 \n";
  for (i = 0; i < n; i++) {
    cout << "enter barcode, number of pieces and price of item " << i + 1 << endl;
    cin >> barcode[i] >> pieces[i] >> price[i];
    cout << endl;
  }
  cout << endl;
  return;
}
void TotalPrice(int pieces[], int price[], int totalprice[], int n) {
  for (int i = 0; i < n; i++) {
    totalprice[i] = pieces[i] * price[i];
  }
  return;
}
void printItems(int barcode[], int pieces[], int price[], int totalprice[], int n) {
  cout << "Barcode\t Number of Pieces\t Price\t Total\n";
  for (int i = 0; i < n; i++) {
    cout << barcode[i] << " \t \t" << pieces[i] << " \t \t \t \t \t " << price[i] << " \t " << totalprice[i] << endl;
  }
  cout << endl;
  return;
}
int ndFovouriteItem(int barcode[], int pieces[], int n) {
  int fav = 0;
  for (int i = 0; i < n; i++) {
    if (pieces[fav] < pieces[i]) {
      fav = i;
    }
  }
  return barcode[fav];
}
int ndItemPriceByBarcode(int barcode[], int n, int bar) {
  for (int i = 0; i < n; i++) {
    if (barcode[i] == bar) {
      return i;
    }
  }
  return -1;
}
int main() {
  int barcode[20], pieces[20], price[20], totalprice[20], n, i;
  int fav, bar, price_index;
  cout << "How many items? ";
  cin >> n;
  cout << endl;
  read(barcode, pieces, price, n);
  TotalPrice(pieces, price, totalprice, n);
  printItems(barcode, pieces, price, totalprice, n);
  fav = ndFovouriteItem(barcode, totalprice, n);
  cout << "The barcode of your favourite item is: " << fav << endl;
  cout << endl;
  cout << "Enter the barcode for the total number of sales of the item\t";
  cin >> bar;
  price_index = ndItemPriceByBarcode(barcode, n, bar);
  if (price_index >= 0) {
    cout << "The total price of selected item " << bar << " is $" << totalprice[price_index] << endl;
  } else
    cout << "The barcode does not exist\n";
  return 0;
}