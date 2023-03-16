#include "BookShop.h"
//hello bookshop
void bookShop()
{
    int choice;
    char x;
    string back;
    Book b;
    while(1)
    {
        b.controlPanel();
        cout<<"\n\n Enter your choice: ";
        cin>>choice;
        switch(choice){
            //to add book
            case 1: 
            do {
                b.addBook();
                cout<<"\n\nDo you want to add another book? (y/n)";
                cin>>x;
            }while(x == 'y');
            break;

            //to display all the available books
            case 2:
                b.showBook();
                break;
                
            //to display a particular book
            case 3:
                b.checkBook();
                break;
            
            //to update book
            case 4:
                b.updateBook();
                break;
            
            //to delete book
            case 5:
                b.deleteBook();
                break;
            
            // to exit
            case 6:
            system("clear");
            cout << "THANKS FOR USING OUR SERVICE!! " << endl;
            exit(1);
        }
    }
}
int main()
{
    bookShop();
}
