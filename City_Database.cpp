#include<iostream>
#include<vector>
#include<string>
using namespace std;

class City{
public:
    string name;
    int x_cordinate;
    int y_cordinate;
    City* next;

    City(string n,int x,int y){
        name=n;
        x_cordinate=x;
        y_cordinate=y;
        next=nullptr;}};

class city_list{
private:
    City* head;
public:
    city_list(){
        head=nullptr;
    }
    void insert(string n,int x,int y){
        City* new_node=new City(n,x,y);
        new_node->next=head;
        head=new_node;
    }
    void search(string nm){
        City* tmp=head;
        while (tmp!=nullptr){
            if (tmp->name==nm){
                cout<<"Item found";
                return;

            }
            else{
                tmp=tmp->next;
            }
                }
        cout<<"item not found";

    }
    void search(int x,int y){
        City*tmp=head;
        while(tmp!=nullptr){
            if(tmp->x_cordinate==x && tmp->y_cordinate==y){
                cout<<"item found";
                return;}
            else {
                tmp=tmp->next;
                }
            }
        cout<<"item not found";    
        }
           
    void delete_city(string nm) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Case 1: Head needs to be deleted
        if (head->name == nm) {
            City* temp = head;
            head = head->next;
            delete temp;
            cout << "City deleted.\n";
            return;
        }

        // Case 2: In the middle or end
        City* curr = head->next;
        City* prev = head;

        while (curr != nullptr) {
            if (curr->name == nm) {
                prev->next = curr->next;
                delete curr;
                cout << "City deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "City not found.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "Database is empty.\n";
            return;
        }
        City* temp = head;
        cout << "\n--- City Database ---\n";
        while (temp != nullptr) {
            cout << "Name: " << temp->name << " | Coordinates: (" << temp->x_cordinate << ", " << temp->y_cordinate << ")\n";
            temp = temp->next;
        }
        cout << "---------------------\n";
    }

    ~city_list() {
        City* curr = head;
        while (curr != nullptr) {
            City* next = curr->next;
            delete curr;
            curr = next;
        }
    }

   


};


int main() {
    city_list myCities;
    int choice;
    string name;
    int x, y;

    while (true) {
        cout << "\n1. Insert City\n2. Search by Name\n3. Search by Coordinates\n4. Delete City\n5. Display All\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name, x, y: ";
                cin >> name >> x >> y;
                myCities.insert(name, x, y);
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                myCities.search(name);
                break;
            case 3:
                cout << "Enter x and y: ";
                cin >> x >> y;
                myCities.search(x, y);
                break;
            case 4:
                cout << "Enter name to delete: ";
                cin >> name;
                myCities.delete_city(name);
                break;
            case 5:
                myCities.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}