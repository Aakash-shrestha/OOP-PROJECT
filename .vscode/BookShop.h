#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>


using namespace  std;

class Book{
private:
    string bookName;
    string bookAuthor;
    int bookId;
    int bookQuantity;
    float bookPrice;
    fstream file;
public:
    //function to show the options to the users
    void controlPanel(){
        system("clear");
        cout<<"\n\n\t\t\tCONTROL PANEL"<<endl;
        cout<<"\n1. ADD BOOKS"<<endl;
        cout<<"2. DISPLAY BOOKS"<<endl;
        cout<<"3. CHECK PARTICULAR BOOKS"<<endl;
        cout<<"4. UPDATE BOOKS"<<endl;
        cout<<"5. DELETE BOOKS"<<endl;
        cout<<"6. EXIT"<<endl;
    }

    //function to add book to the file
    void addBook()
    {
        system("clear");
        cout<<"\n\n\t\t\t\tADD BOOKS"<<endl;
        cout << "Book ID : ";
        cin>>bookId;
        cout << "\nBook Name : ";
        cin.ignore();
        getline(cin, bookName);
        cout << "\nAuthor Name : ";
        getline(cin, bookAuthor);
        cout << "\nNo. of Books : ";
        cin>>bookQuantity;
        cout << "\nPrice: ";
        cin>> bookPrice;

        //opening a file and storing the informations inputed by users in the file
        file.open("book.txt", ios::out | ios::app);
        if(file.is_open())
        {
            file<<"Book Id- "<<bookId<<"\nBook Name- "<<bookName<<"\nAuthor name- "<<bookAuthor<<"\nNo of books-  "<<bookQuantity
            << "\nPrice of books-  "<<bookPrice <<endl<<endl;
        }
        file.close();
    }
    
    //function to display all the available books in console
    void showBook()
    {
        string line;
        system("clear");
        cout<<"\n\n\t\t\t\t\tALL BOOKS"<<endl;
        //opening a file in input mode to print the file info to the console
        file.open("book.txt", ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                cout << line << endl;
            }
         
            file.close();
             system( "read -n 1 -s -p \"Press any key to continue...\"" );
             }
               
             
        }
    
    void checkBook()
    {
        system("clear");
        int count = 0;
        string checkId;
        string line;
        cout<<"\n\n\t\t\t\tCHECK PARTICULAR BOOK"<<endl;
        //opening the file in input mode
        file.open("book.txt", ios::in);
        if(file.is_open())
        {
            cout << "Book Id- ";
            cin >> checkId;
            while(!file.eof())
            {
                getline(file, line);
                if(line.find(checkId) != string::npos)
                {
                     do
                    {
                        getline(file, line);
                        cout << line << endl;
                        count ++;
                        if( count == 4) break;
                    } while (count < 5);
                }

                       
                }
                system( "read -n 1 -s -p \"Press any key to continue...\"" );

                file.close();

            }

    }

    //function to update books infos
    void updateBook()
    {
        system("clear");
        fstream tempFile;
        int count = 0;
        int lineNumber = 0;
        string checkId;
        string line;
        cout<<"\n\n\t\t\t\tUPDATE BOOK"<<endl;
        file.open("book.txt", ios::in);
        tempFile.open("tempBook.txt", ios:: out | ios:: app);
        if(tempFile.is_open()){

            if(file.is_open())
        {
             cout << "\n\nBook ID : ";
             cin >> checkId;
             cout <<"\n[updated] No of Books- ";
             cin >> bookQuantity;
         while(!file.eof())
        {
            getline(file, line);
            tempFile << line << endl;
            if(line.find(checkId) != string::npos)
            {
                do{
                    getline(file, line);
                    if(lineNumber == 2) //not changed
                {
                    tempFile << "No of books- " << bookQuantity << endl;
                    break;
                }
                    tempFile << line << endl;
                    lineNumber++;
                
                }while(lineNumber < 4);
            }
            
            count++;
                
        }
        if (count == 0)
        cout << "\n\nBook ID Not Found..."<<endl;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        file.close();

        }
        tempFile.close();
        }   
        remove("book.txt");
        rename("tempBook.txt", "book.txt");
        
    }

    //function to delete a book
    void deleteBook()
    {
        system("clear");
        fstream tempFile;
        int count = 0;
        int lineNumber = 0;
        string checkId;
        string line;
        cout<<"\n\n\t\t\t\tDELETE BOOK"<<endl;
        file.open("book.txt", ios::in);
        tempFile.open("tempBook.txt", ios:: out | ios:: app);
        if(tempFile.is_open()){

            if(file.is_open())
        {
             cout << "\n\nBook ID [of the book you want to delete]: ";
             cin >> checkId;
         while(!file.eof())
        {
            getline(file, line);
            if(line.find(checkId) != string::npos)
            {
                do{
                    getline(file, line);
                    cout << " ";
                    lineNumber++;
                
                }while(lineNumber < 6);
            }
            tempFile << line << endl;
            count++;
                
        }
        cout << "Book deleted successfully..." << endl;
        if (count == 0)
        cout << "\n\nBook ID Not Found..."<<endl;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        file.close();
        }
        tempFile.close();
        }   
        remove("book.txt");
        rename("tempBook.txt", "book.txt");
    }
     
};
