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
    node* next = nullptr;
    node(int data) :data(data) {}
};
class linkedlist {
private:
    node* head{};node* tail{};
    int length = 0;
public:
    linkedlist() {}
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    node* get_node(int value){
        int indx=0;
        for(node*cur=head;cur;cur=cur->next,indx++){
            if(value==indx){
                return cur;
            }
        }
        return nullptr;
    }
    void delete_with_key(int value) {
        value--;
        if (length < 1)return;
        if (length <= 2) {
            delete get_node(value);
            head = tail = get_node(abs(value - 1));
        } else {
            if (value == 0) {
                node*current=head->next;
                delete head;
                head = current;
            } else if (value == length - 1) {
                node*before_tail=get_node(value-1);
                delete tail;
                tail = before_tail;
                tail->next=nullptr;
            } else {
                node *before = get_node(value - 1);
                node *after = get_node(value + 1);
                delete get_node(value);
                before->next = after;
            }
        }
        length--;
    }
    void swap_pairs(){
        if(length==1)return;
            for(node*cur=head;cur&&cur->next;cur=cur->next->next) {
                if (cur->next != nullptr) {
                    node *after = cur->next;
                    swap(cur->data, after->data);
                }
            }
    }
    void delete_even_positions() {
        if (length <= 1) return;
        int indx = 1;
        node* cur = head;
        while (cur && cur->next) {
            if (indx % 2 == 0) {
                node* next_node = cur->next;
                delete_with_key(indx);
                cur = next_node;
            } else {
                cur = cur->next;
            }
            indx++;
        }
    }
    void reverse(){
        node* pre = nullptr;
        node* cur = head;
        node* after = nullptr;

        while (cur != nullptr) {
            after = cur->next;
            cur->next = pre;
            pre = cur;
            cur = after;
        }
        tail = head;
        head = pre;
    }

 };
int main() {
    linkedlist list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
   list.delete_with_key(3);
    list.swap_pairs();
list.reverse();
    list.delete_even_positions();
    list.print();
}