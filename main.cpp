#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAX_BOOKS = 10;
const int MAX_USERS = 10;

struct Books {
    int id {};
    string name {};
    int total_quantity {};
    int total_borrowed {};

    vector<pair<string, string>> borrowed_books; // user name .. book name
};
Books books[MAX_BOOKS + 1]; // from 1 to 10 distinct books
bool cmp_books_by_id(Books x, Books y){
    return x.id < y.id;
}

struct Users {
    int id {};
    string name {};
    int borrowed_books_ids[];

};
Users users[MAX_USERS + 1]; // from 1 to 10 distinct users

int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nLibrary Menu:\n";
        cout << "1) add_book\n";
        cout << "2) search_books_by_prefix\n";
        cout << "3) print_who_borrowed_book_by_name\n";
        cout << "4) print_library_by_id\n";
        cout << "5) print_library_by_name\n";
        cout << "6) add_user\n";
        cout << "7) user_borrow_book\n";
        cout << "8) user_return_book\n";
        cout << "9) print_users\n";
        cout << "10) Exit\n";
        cin >> choice;

        if (!(1 <= choice && choice <= 10)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

bool add_book() {
    int pos {0};
    while(books[pos].id != 0){ // gets next free position in books array;
        if (pos == 10){ // reaching maximum book number handled
            cout << "Maximum books reached [10].\n"
                << "YOU CAN'T ADD MORE!\n";
            return false;
        }
        pos++;
    }
    cout << "Enter book info: id & name & total quantity: ";
    cin >> books[pos].id >> books[pos].name >> books[pos].total_quantity;
    return true;
}

void print_library_by_id(){
    sort(books, books + MAX_BOOKS + 1, cmp_books_by_id);
    for (auto book: books) {
        if (book.id != 0) {
            cout << "Id = " << book.id << " name = " << book.name
                 << " total_quantity = " << book.total_quantity
                 << " total_borrowed = " << book.total_borrowed << endl;
        }
    }
}

void system() {
    while (true){
        int choice = menu();
        if (choice == 1)
            add_book();
        else if (choice == 4)
            print_library_by_id();
        else if (choice == 10)
            break;
    }
}

int main() {
    system();
    return 0;
}