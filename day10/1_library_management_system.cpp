#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Book
{
private:
    int id;
    char title[100];
    char author[100];
    float price;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); // ignore newline after ID input
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const
    {
        cout << left << setw(10) << id
             << setw(30) << title
             << setw(25) << author
             << "₹" << price << endl;
    }

    int getId() const
    {
        return id;
    }

    void update()
    {
        cout << "Update Book Details (ID: " << id << ")\n";
        cin.ignore();
        cout << "Enter New Title: ";
        cin >> title;
        cout << "Enter New Author: ";
        cin >> author;
        cout << "Enter New Price: ";
        cin >> price;
    }
};

// Function Prototypes
void addBook();
void displayBooks();
void searchBook();
void updateBook();
void deleteBook();

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                throw runtime_error("Invalid Choice! Please try again.");
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}

// Add Book
void addBook()
{
    ofstream fout("library.dat", ios::binary | ios::app);
    if (!fout)
        throw runtime_error("Unable to open file!");

    Book b;
    b.input();
    fout.write(reinterpret_cast<char *>(&b), sizeof(b));
    fout.close();
    cout << "Book added successfully!\n";
}

// Display All Books
void displayBooks()
{
    ifstream fin("library.dat", ios::binary);
    if (!fin)
        throw runtime_error("Unable to open file!");

    Book b;
    cout << "\n--- Book List ---\n";
    cout << left << setw(10) << "ID" << setw(30) << "Title"
         << setw(25) << "Author" << "Price\n";
    cout << "-------------------------------------------------------------\n";
    while (fin.read(reinterpret_cast<char *>(&b), sizeof(b)))
    {
        b.display();
    }
    fin.close();
}

// Search Book by ID
void searchBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to search: ";
    cin >> id;

    ifstream fin("library.dat", ios::binary);
    if (!fin)
        throw runtime_error("Unable to open file!");

    Book b;
    while (fin.read(reinterpret_cast<char *>(&b), sizeof(b)))
    {
        if (b.getId() == id)
        {
            cout << "Book found:\n";
            b.display();
            found = true;
            break;
        }
    }
    fin.close();

    if (!found)
        throw runtime_error("Book not found!");
}

// Update Book
void updateBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to update: ";
    cin >> id;

    fstream file("library.dat", ios::binary | ios::in | ios::out);
    if (!file)
        throw runtime_error("Unable to open file!");

    Book b;
    while (!file.eof())
    {
        streampos pos = file.tellg();
        if (file.read(reinterpret_cast<char *>(&b), sizeof(b)))
        {
            if (b.getId() == id)
            {
                b.update();
                file.seekp(pos);
                file.write(reinterpret_cast<char *>(&b), sizeof(b));
                found = true;
                cout << "Book updated successfully!\n";
                break;
            }
        }
    }
    file.close();
    if (!found)
        throw runtime_error("Book not found!");
}

// Delete Book
void deleteBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    ifstream fin("library.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin || !fout)
        throw runtime_error("Unable to open file!");

    Book b;
    while (fin.read(reinterpret_cast<char *>(&b), sizeof(b)))
    {
        if (b.getId() != id)
        {
            fout.write(reinterpret_cast<char *>(&b), sizeof(b));
        }
        else
        {
            found = true;
        }
    }

    fin.close();
    fout.close();
    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        cout << "Book deleted successfully!\n";
    else
        throw runtime_error("Book not found!");
}