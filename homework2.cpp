#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <string>
using namespace std;
#define endl '\n'
//#define haha cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
struct node {
    int data;
    node* next=nullptr;
    node(int data) :data(data) {}
};
class linkedlist {
private:
    node* head{};node* tail{};
    int length = 0;
public:
    linkedlist(){}
    linkedlist(const linkedlist&) = delete;
    linkedlist& operator=(const linkedlist& another) = delete;
    void insert_end(int value) {
        node* entry = new node(value);
        if (head == nullptr) {
            head = tail = entry;
        }
        else {
            tail->next = entry;
            tail = entry;
        }
        length++;
    }
    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert_front(int value) {
        node* entry = new node(value);
        if (head == nullptr)head = tail = entry;
        else {
            entry->next = head;
            head = entry;
        }
        length++;
    }
    void delete_front() {
        if (length != 0) {
            node* newhead = head->next;
            delete head;
            head = newhead;
            length--;
        }
    }
    int get_nth_from_back(int value) {
        value--;
        int target = length - value - 1;
        int indx = 0;
        for (node* cur = head;cur;cur = cur->next,indx++) {
            if (indx == target) {
                return cur->data;
          }
        }
        return -1;
    }
    bool is_same_code1( linkedlist &list) {
        if (list.length == length) {
            for (node* cur = head, *cur2 = list.head;cur;cur = cur->next, cur2 = cur2->next) {
                if (cur2->data != cur->data)return false;
            }
        }
        else return false;
        return true;
}
    bool is_same_code2(const linkedlist &list) {
        node* cur = head;node* cur2 = list.head;
        while (cur != nullptr && cur2 != nullptr) {
            if (cur->data != cur2->data)return false;
            cur = cur->next;
            cur2=cur2->next;
        }
        if (cur && !cur2 || !cur && cur2)return false;
        return true;
    }
    ~linkedlist() {
        while (head) {
            node* current = head->next;
            delete head;
            head = current;
            }
        
    }
};
class version2_linkedlist {
private:node* head{};
public:
   version2_linkedlist(){}
    void add_element(int value) {
        node* element = new node(value);
        element->next = head;
        head = element;
    }
    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    node* get_tail() {
        node* cur=head;
        for (;cur->next;cur = cur->next);
        return cur;
    }
};
int main() {
    linkedlist list;
    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);
    cout << "insert front fun" << endl;
    list.insert_front(7);
    list.insert_front(5);
    list.insert_front(1);
    list.print();
    cout << "delete front fun" << endl;

    list.delete_front();
    list.print();
    cout << "get nth from back front fun" << endl;
    cout << list.get_nth_from_back(1);
    cout << "is same code 1 fun" << endl;
    linkedlist list1, list2;
    cout << list1.is_same_code1(list2)<<endl;
    list1.insert_end(6);
    list1.insert_end(10);
    list2.insert_end(6);
    cout << list1.is_same_code1(list2)<<endl;
    list2.insert_end(10);
    cout << list1.is_same_code1(list2)<<endl;
    list1.insert_end(8);
    list1.insert_end(15);
    list2.insert_end(8);
    list2.insert_end(77);
    cout << list1.is_same_code1(list2)<<endl;
    cout << "is same code 2 fun" << endl;
    linkedlist list0, list3;
    cout << list0.is_same_code2(list3) << endl;
    list0.insert_end(6);
    list0.insert_end(10);
    list3.insert_end(6);
    cout << list0.is_same_code2(list3) << endl;
    list3.insert_end(10);
    cout << list0.is_same_code1(list3) << endl;
    list0.insert_end(8);
    list0.insert_end(15);
    list3.insert_end(8);
    list3.insert_end(77);
    cout << list0.is_same_code1(list3) << endl;
    cout << "add element fun" << endl;
    version2_linkedlist list4;
    list4.add_element(6);
    list4.add_element(10);
    list4.add_element(8);
    list4.add_element(15);
    list4.print();
    cout<<list4.get_tail()->data;
}