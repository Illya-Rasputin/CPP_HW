#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
    int year;
    double price;
};
void ShowBooks(Book books[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << "\nTitle: " << books[i].title
            << "\nAuthor: " << books[i].author
            << "\nPublisher: " << books[i].publisher
            << "\nGenre: " << books[i].genre
            << "\nYear: " << books[i].year
            << "\nPrice: " << books[i].price << " UAH\n";
    }
}

void ChangeData(Book books[], int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!\n";
        return;
    }
    cout << "Enter new data:\n";
    cout << "Title: "; cin.ignore(); getline(cin, books[index].title);
    cout << "Author: "; getline(cin, books[index].author);
    cout << "Publisher: "; getline(cin, books[index].publisher);
    cout << "Genre: "; getline(cin, books[index].genre);
    cout << "Year: "; cin >> books[index].year;
    cout << "Price: "; cin >> books[index].price;
}
void SearchByAuthor(Book books[], int count, const string& author) {
    for (int i = 0; i < count; ++i) {
        if (books[i].author == author) {
            cout << "Book found: " << books[i].title << "\n";
        }
    }
}

void SearchByTitle(Book books[], int count, const string& title) {
    for (int i = 0; i < count; ++i) {
        if (books[i].title == title) {
            cout << "Book found: " << books[i].title << "\n";
        }
    }
}

void SearchByPublisher(Book books[], int count, const string& publisher) {
    for (int i = 0; i < count; ++i) {
        if (books[i].publisher == publisher) {
            cout << "Book found: " << books[i].title << "\n";
        }
    }
}

void SearchByGenre(Book books[], int count, const string& genre) {
    for (int i = 0; i < count; ++i) {
        if (books[i].genre == genre) {
            cout << "Book found: " << books[i].title << "\n";
        }
    }
}

void AddBook(Book books[], int& count) {
    if (count >= MAX_BOOKS) {
        cout << "Maximum number of books reached!\n";
        return;
    }
    cout << "Enter data for new book:\n";
    cout << "Title: "; cin.ignore(); getline(cin, books[count].title);
    cout << "Author: "; getline(cin, books[count].author);
    cout << "Publisher: "; getline(cin, books[count].publisher);
    cout << "Genre: "; getline(cin, books[count].genre);
    cout << "Year: "; cin >> books[count].year;
    cout << "Price: "; cin >> books[count].price;
    ++count;
}

void SaveToFile(Book books[], int count, const string& filename) {
    ofstream fout(filename);
    for (int i = 0; i < count; ++i) {
        fout << books[i].title << '\n'
            << books[i].author << '\n'
            << books[i].publisher << '\n'
            << books[i].genre << '\n'
            << books[i].year << '\n'
            << books[i].price << '\n';
    }
    fout.close();
    cout << "Saved to file.\n";
}

void LoadFromFile(Book books[], int& count, const string& filename) {
    ifstream fin(filename);
    count = 0;
    while (getline(fin, books[count].title)) {
        getline(fin, books[count].author);
        getline(fin, books[count].publisher);
        getline(fin, books[count].genre);
        fin >> books[count].year;
        fin >> books[count].price;
        fin.ignore();
        ++count;
        if (count >= MAX_BOOKS) break;
    }
    fin.close();
    cout << "Loaded from file.\n";
}

int main()
{
    int bookCount = 10;
    Book library[MAX_BOOKS] = {
    {"The Master and Margarita", "M. Bulgakov", "Folio", "Novel", 1940, 200.0},
    {"Kobzar", "T. Shevchenko", "Veselka", "Poetry", 1840, 150.0},
    {"One Hundred Years of Solitude", "G. G. Marquez", "KSD", "Novel", 1967, 250.0},
    {"1984", "G. Orwell", "Nash Format", "Dystopia", 1949, 220.0},
    {"Crime and Punishment", "F. Dostoevsky", "Folio", "Novel", 1866, 180.0},
    {"Crime and Punishment", "F. Dostoevsky", "Fact", "Novel", 1866, 190.0},
    {"The Catcher in the Rye", "J. Salinger", "KM-Books", "Novel", 1951, 210.0},
    {"Ivanhoe", "W. Scott", "Shkola", "Adventure", 1819, 170.0},
    {"Faust", "J. W. Goethe", "A-BA-BA-HA-LA-MA-HA", "Drama", 1808, 230.0},
    {"The Picture of Dorian Gray", "O. Wilde", "Folio", "Novel", 1890, 200.0}
    };
    int choice;
    do {
        cout << "\nMenu:\n"
            << "1. Show all books\n"
            << "2. Edit a book\n"
            << "3. Search by author\n"
            << "4. Search by title\n"
            << "5. Search by publisher\n"
            << "6. Search by genre\n"
            << "7. Add new book\n"
            << "8. Save to file\n"
            << "9. Load from file\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            ShowBooks(library, bookCount); break;
        }
        case 2: {
            int id;
            cout << "Book index (0-" << bookCount - 1 << "): ";
            cin >> id;
            ChangeData(library, bookCount, id);
            break;
        }
        case 3: {
            string author;
            cout << "Author: "; cin.ignore(); getline(cin, author);
            SearchByAuthor(library, bookCount, author);
            break;
        }
        case 4: {
            string title;
            cout << "Title: "; cin.ignore(); getline(cin, title);
            SearchByTitle(library, bookCount, title);
            break;
        }
        case 5: {
            string pub;
            cout << "Publisher: "; cin.ignore(); getline(cin, pub);
            SearchByPublisher(library, bookCount, pub);
            break;
        }
        case 6: {
            string genre;
            cout << "Genre: "; cin.ignore(); getline(cin, genre);
            SearchByGenre(library, bookCount, genre);
            break;
        }
        case 7: AddBook(library, bookCount); break;
        case 8: SaveToFile(library, bookCount, "library.txt"); break;
        case 9: LoadFromFile(library, bookCount, "library.txt"); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

}

