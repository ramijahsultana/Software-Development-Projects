#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class User
{
public:
    string username;
    string name;
    string email;
    int age;
    string skin_type;
    string skin_tone;

    void create_account(string username, string name, string email, int age, string skin_type, string skin_tone)
    {
        this->username = username;
        this->name = name;
        this->email = email;
        this->age = age;
        this->skin_type = skin_type;
        this->skin_tone = skin_tone;
    }
    void display_profile()
    {
        cout << "\n=== User Profile ===\n";
        cout << "Username   : " << username << endl;
        cout << "Name       : " << name << endl;
        cout << "Email      : " << email << endl;
        cout << "Age        : " << age << endl;
        cout << "Skin Type  : " << skin_type << endl;
        cout << "Skin Tone  : " << skin_tone << endl;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<User> users;
    int choice;

    do
    {
        cout << "\n===== Consumer Certified Seal =====\n";
        cout << "1. Create Account\n";
        cout << "2. View My Profile\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string username, name, email, skin_type, skin_tone;
            int age;

            cout << "\nEnter Username: ";
            cin >> username;
            cin.ignore();

            cout << "Enter Full Name: ";
            getline(cin, name);

            cout << "Enter Email: ";
            getline(cin, email);

            cout << "Enter Age: ";
            cin >> age;
            cin.ignore();

            cout << "Enter Skin Type (e.g. Oily, Dry): ";
            getline(cin, skin_type);

            cout << "Enter Skin Tone (e.g. Fair, Medium): ";
            getline(cin, skin_tone);

            bool usernameExists = false;
            bool emailExists = false;

            for (const auto &u : users)
            {
                if (u.username == username)
                    usernameExists = true;
                if (u.email == email)
                    emailExists = true;
            }

            if (usernameExists)
                cout << "\n❌ Username already exists!\n";
            else if (emailExists)
                cout << "\n❌ Email already registered!\n";
            else if (age < 13)
                cout << "\n❌ Age must be 13 or above!\n";
            else
            {
                User newUser;
                newUser.create_account(username, name, email, age, skin_type, skin_tone);
                users.push_back(newUser);

                cout << "\n✅ Account created successfully!\n";
                newUser.display_profile();
            }
        }
        else if (choice == 2)
        {
            string username;
            cout << "\nEnter username: ";
            cin >> username;

            bool found = false;
            for (auto &u : users)
            {
                if (u.username == username)
                {
                    u.display_profile();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "\n❌ Account not found!\n";
        }
        else if (choice == 3)
            cout << "\nThank you for using TrustMark BD!\n";
        else
            cout << "\nInvalid choice!\n";

    } while (choice != 3);

  
    cout << "\nProgram finished. Press any key to exit...";
    cin.ignore();
    cin.get(); 

    return 0;
}