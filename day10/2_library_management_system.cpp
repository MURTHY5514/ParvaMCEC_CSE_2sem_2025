#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    float price;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
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
        cout << "Update Book (ID: " << id << ")\n";
        cin.ignore();
        cout << "Enter New Title: ";
        getline(cin, title);
        cout << "Enter New Author: ";
        getline(cin, author);
        cout << "Enter New Price: ";
        cin >> price;
    }
};

// Dynamic Array Storage
Book *books = nullptr;
int bookCount = 0;

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
                delete[] books; // Free memory
                cout << "Exiting...\n";
                return 0;
            default:
                throw runtime_error("Invalid choice! Try again.");
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}

void addBook()
{
    Book *temp = new Book[bookCount + 1];
    for (int i = 0; i < bookCount; i++)
    {
        temp[i] = books[i];
    }

    cout << "\nEnter Book Details:\n";
    temp[bookCount].input();

    delete[] books;
    books = temp;
    bookCount++;

    cout << "Book added successfully!\n";
}

void displayBooks()
{
    if (bookCount == 0)
        throw runtime_error("No books available!");

    cout << "\n--- Book List ---\n";
    cout << left << setw(10) << "ID" << setw(30) << "Title"
         << setw(25) << "Author" << "Price\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < bookCount; i++)
    {
        books[i].display();
    }
}

void searchBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getId() == id)
        {
            cout << "Book found:\n";
            books[i].display();
            found = true;
            break;
        }
    }

    if (!found)
        throw runtime_error("Book not found!");
}

void updateBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to update: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getId() == id)
        {
            books[i].update();
            found = true;
            cout << "Book updated successfully!\n";
            break;
        }
    }

    if (!found)
        throw runtime_error("Book not found!");
}

void deleteBook()
{
    int id;
    bool found = false;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    int newbookCount = bookCount - 1;
    Book *temp = new Book[newbookCount];
    int j = 0;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getId() == id)
        {
            found = true;
            continue;
        }
        if (j < newbookCount)
            temp[j++] = books[i];
    }

    if (found)
    {
        delete[] books;
        books = temp;
        bookCount = newbookCount;
        cout << "Book deleted successfully!\n";
    }
    else
    {
        delete[] temp;
        throw runtime_error("Book not found!");
    }
}