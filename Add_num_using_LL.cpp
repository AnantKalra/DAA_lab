#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linked_list(int n){
    Node* head=nullptr;
    Node* tail=nullptr;

    while (n>0){

        int digit=n%10;
        Node* newNode=new Node();
        newNode->data=digit;
        newNode->next=nullptr;

        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }

        n=n/10;
        
    }
    return head;
}
void display (Node* head){
    Node* temp=head;

    while(temp!=nullptr){
        cout<<temp->data;

        if(temp->next!=nullptr){
            cout<<"->";
        }
        temp=temp->next;

    }
    cout<<endl;
}

int add(int a,int b){
    return a+b;
}

Node* add(Node* a,Node* b){
    Node* temp1=a;
    Node* temp2=b;
    int carry=0;
    Node* head=nullptr;
    Node* tail=nullptr;
    while (temp1!=nullptr||temp2!=nullptr||carry!=0){
        int sum=carry;

        if(temp1!=nullptr){
            sum+=temp1->data;
            temp1=temp1->next;}
        
        if(temp2!=nullptr){
            sum+=temp2->data;
            temp2=temp2->next;
        }
        
        int digi=sum%10;
        carry=sum/10;

        Node* NewNode=new Node();
        NewNode->data=digi;
        NewNode->next=nullptr;

        if(head==nullptr){
            head = NewNode;
            tail = NewNode;
        }
        else{
            tail->next = NewNode;
            tail = NewNode;
        }
    }

    return head;
}

int subtract(int a, int b) {
    return a - b;
}

Node* subtract(Node* a, Node* b) {
    Node* temp1 = a;
    Node* temp2 = b;
    int borrow = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (temp1 != nullptr) {
        int diff = borrow + temp1->data;
        if (temp2 != nullptr) {
            diff -= temp2->data;
            temp2 = temp2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        Node* NewNode = new Node();
        NewNode->data = diff;
        NewNode->next = nullptr;

        if (head == nullptr) {
            head = NewNode;
            tail = NewNode;
        } else {
            tail->next = NewNode;
            tail = NewNode;
        }
        temp1 = temp1->next;
    }
    return head;
}

int multiply(int a, int b) {
    return a * b;
}

Node* multiply(Node* a, Node* b) {
    Node* result = new Node(); 
    result->data = 0; 
    result->next = nullptr;
    
    Node* temp2 = b;
    int pos = 0;
    
    while (temp2 != nullptr) {
        Node* temp1 = a;
        int carry = 0;
        Node* current_res = result;
        
        // Shift position for the next digit of multiplier
        for (int i = 0; i < pos; i++) {
            if (current_res->next == nullptr) {
                current_res->next = new Node();
                current_res->next->data = 0;
                current_res->next->next = nullptr;
            }
            current_res = current_res->next;
        }
        
        while (temp1 != nullptr || carry != 0) {
            int prod = carry + current_res->data;
            if (temp1 != nullptr) {
                prod += temp1->data * temp2->data;
                temp1 = temp1->next;
            }
            
            current_res->data = prod % 10;
            carry = prod / 10;
            
            if ((temp1 != nullptr || carry != 0) && current_res->next == nullptr) {
                current_res->next = new Node();
                current_res->next->data = 0;
                current_res->next->next = nullptr;
            }
            
            if (temp1 != nullptr || carry != 0) {
                current_res = current_res->next;
            }
        }
        temp2 = temp2->next;
        pos++;
    }
    return result;
}


int main(){
    int num1,num2;
    char choice;
    cout<<"enter the first number\n";
    cin>>num1;
    cout<<"enter the second number\n";
    cin>>num2;

    int operation;
    cout<<"choose your operation(1,2,3).\n";
    cout<<"1.Addition\n";
    cout<<"2.Substraction\n";
    cout<<"3.Multiply\n";
    cin>>operation;

    cout << "Do you want to convert numbers into linked list? (Y/N): ";
    cin >> choice;

    if(choice=='y'||choice=='Y'){
        cout<<"Linked list mode";
        Node* list1=linked_list(num1);
        Node* list2=linked_list(num2);
        display(list1);
        display(list2);

        if(operation==1){
            Node* result=add(list1,list2);
            cout << "Result: ";
            display(result);
        }
        else if(operation==2){
            Node* result=subtract(list1,list2);
            cout << "Result: ";
            display(result);
        }
        else if(operation==3){
            Node* result=multiply(list1,list2);
            cout << "Result: ";
            display(result);
        }
        else {
            cout << "Invalid operation choice.\n";
        }

    }
    else {
        cout<<"int mode\n";
        if(operation==1){
            int result=add(num1,num2);
            cout<<"Result: "<<result<<endl;
        }
        else if(operation==2){
            int result=subtract(num1,num2);
            cout<<"Result: "<<result<<endl;
        }
        else if(operation==3){
            int result=multiply(num1,num2);
            cout<<"Result: "<<result<<endl;
        }
        else {
            cout << "Invalid operation choice.\n";
        }
    }

    

}
