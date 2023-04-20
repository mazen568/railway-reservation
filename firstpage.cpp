#include <iostream>
#include <fstream>
#include<list>
using namespace std;
void Login();
void signup();
void admin();
void user();
void firstpage();
int main() {
    firstpage();
    return 0;
}
void firstpage() {

    int choice;
    cout << "____________________________WELCOME TO MAZEN RAILWAYS______________________________" << endl
        << endl;
    cout << " 1. Admin Mode    \t|" << endl;
    cout << " 2. User Mode     \t|" << endl;
    cout << " 3. Exit          \t|" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
    {
        admin();
        break;
    }
    case 2:
    {
        user();
        break;
    }
    case 3:
        exit(0);
    default:
        cout << "\n\nPlease Select From The Above Options!!!!" << endl;
        firstpage();

    }
}
void admin() {
    int count = 0;
    string adminId, adminPass, id, pass;
    cout << "please enter the username and password : ";
    cout << endl;
    cout << "username : ";
    cin >> adminId;
    cout << "password : ";
    cin >> adminPass;
    ifstream input("admin.txt");
    while (input >> id >> pass)
    {
        if (id == adminId && pass == adminPass)
        {
            count = 1;
        }

    }
    input.close();
    if (count == 1)
    {
        //hn7ot functions el trains w el trips
    }
    else
    {
        cout << "_______________________________login error check your username and password____________________________________" << endl;
        admin();
    }
}
void user() {
    int choice;
    cout << " 1. LOGIN            \t|" << endl;
    cout << " 2. SIGNUP           \t|" << endl;
    cout << " 3. MAIN MENU        \t|" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
    {
        Login();
        break;
    }
    case 2:
    {
        signup();
        break;
    }
    case 3:
    {
        main();
        break;
    }
    default:
        cout << "\n\nPlease Select From The Above Options!!!!" << endl;
        user();
    }

}
void Login() {
    int count = 0;
    string userId, userPass, id, pass;
    cout << "please enter username and password : " << endl;
    cout << "username : ";
    cin >> userId;
    cout << "password : ";
    cin >> userPass;
    cout << endl;
    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == userPass)
        {
            count = 1;
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "________________________login is completed successfully_________________________" << endl;
        cout << endl;

    }
    else
    {
        cout << "___________________________wrong email and password____________________________" << endl;
        cout << endl;
        Login();
    }

}
void signup() {
    int count = 0;
    string userId, userPass, id, pass;
    cout << "enter the username : ";
    cin >> userId;
    cout << "enter the password : ";
    cin >> userPass;
    ifstream input("records.txt", ios::app);
    while (input >> id >> pass) {
        if (id == userId && pass == userPass)
        {
            count = 1;
        }
    }
    if (count == 1)
    {
        cout << "this email and password already exist please try another email and password!!" << endl;
        cout << endl;
        signup();
    }
    else {
        ofstream output("records.txt", ios::app);
        output << userId << ' ' << userPass << endl;
        cout << "_______________________________the registration is completed succesfully______________________________________" << endl;
        cout << endl;
        Login();
    }
}