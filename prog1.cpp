//start
// Linked list
// include functions
#include <iostream>
#include <vector>

using namespace std;

// create node
class Node
{
public:
    int data;
    Node *next;
};

// Create class for link list functions

class LinkList
{
public: // declare variables
    int size;
    Node *head;
    vector<int> elements;

    // create constructor
    LinkList()
    {
        head = NULL;
        size = 0;
    }

    // create function to insert data at front in linklist
    void insertAtFront(int data)
    {
        Node *newNode = new Node(); // create new node
        newNode->data = data;       // give the value of data to data of newnode;
        newNode->next = head;
        head = newNode;
        elements.push_back(data); // push data in list
        size++;                   // increase size after push
    }

    // create function to insert data at end in linklist
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(); // create new node
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        { // check if head is NULL or not if yes then store newnode in head
            head = newNode;
        }
        else
        { // if not then create a pointer as tempp which always points towards head
            Node *temp = head;
            while (temp->next != NULL) // Move temp to the next node until the end of the list is reached
            {

                temp = temp->next;
            }
            temp->next = newNode;
        }
        elements.push_back(data); // push data in list
        size++;
    }

    // create function to insert data at index
    void insertAtIndex(int index, int value)
    {
        if (head == NULL) // if head is null therfore linklist is empty
        {
            cout << "List is Already Empty." << endl;
            return;
        }

        else if (index == 0) // else if index is equal to zero then call the function insertAtFront();
        {
            insertAtFront(value);
        }
        else // else create a new node
        {
            Node *newNode = new Node();
            Node *temp = head;
            int position = 0;

            while (temp->next != NULL && position < index - 1) // while temp next is not equal to null and position is smaller then index-1
            {
                temp = temp->next; // store temp->next in temp
                position++;        // increase position
            }

            newNode->next = temp->next;                                // store temp next into neNode next
            temp->next = newNode;                                      // store newnode into temp next
            cout << value << " Inserted at index : " << index << endl; // display index where the value is inserted
        }
    }

    // create function to delete at front
    void deleteAtFront()
    {
        if (head == NULL)
        {                                             // if head is equal to NULL
            cout << "List is already empty." << endl; // then list is empty
            return;
        }
        Node *temp = head;                // create a temp pointer which points at head
        head = head->next;                // store the value of head->next in head
        delete temp;                      // delete temp
        elements.erase(elements.begin()); // delete element using inbuilt function from vector
        size--;
    }

    // create function to insert data at end
    void DeleteAtEnd()
    {
        if (head == NULL) // if head is equal to null
        {
            cout << "List Already Empty." << endl; // display list is empty
            return;
        }

        else if (head->next == NULL) // else if  head next is null
        {
            delete head; // delete head
            cout << "Deleted Successfully From End." << endl;
            head = NULL;
            return;
        }

        Node *temp = head; // create temp pointer which point at head
        if (!elements.empty())
        {                        // if element is not empty
            elements.pop_back(); // pop back the element using vector inbuilt function
            size--;
        }
        while (temp->next->next != NULL) // while temp next nxt is not equal to null
        {
            temp = temp->next; // move temp towards temp->next
        }
        delete temp->next;
        cout << "Deleted Successfully From End." << endl; // display element is deleted
        temp->next = NULL;                                // declare temp->next=null
    }

    // create function to delete at index
    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < size) // if this condition matches
        {
            Node *temp = head; // create a temp pointer which always point at head
            if (index == 0)    // if index is 0
            {
                head = head->next; // then store head->next value in head
                delete temp;       // and delete temp
            }
            else
            {
                for (int i = 0; i < index - 1; i++) // run a for loop
                {
                    temp = temp->next; // store temp-> next value in temp;
                }
                Node *todelete = temp->next; // create a todelete pointer which point at temp next
                temp->next = todelete->next; // store the value of todelete->next in temp->next;
                delete todelete;             // delete to delete todelete var
            }
            // delete the element at the specified index from the elements using inbuilt function
            elements.erase(elements.begin() + index);
            size--; // decrement hte size
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    //create isempty function
  
    //create display function to display the list
     void displayData() {
        if(head != NULL){
            Node* current = head;        //create pointer current which point at head
        cout << "LinkList: ";
        while (current != NULL) {      //while current is not equal to null 
            cout << current->data << " "; //cout current tdata
            current = current->next;        //store current->next value in current;
        }
        cout << endl;
        }
        else{
            cout<<"List is empty\n";
        }
    }
};

int main(){
    LinkList list;    //create an object for class
    int choice;        

    //create do while loop
    do {
        //create menu
        cout << "\n========== Link List ===========\n";
        cout << "1. Insert at front\n" ;
        cout << "2. Insert at end\n" ;
        cout << "3. Insert at index\n" ;
        cout << "4. Delete from front\n" ;
        cout << "5. Delete from back\n" ;
        cout << "6. Delete from index\n" ;
        cout << "7. Display list\n" ;
        cout << "0. Exit" ;
        cout << "\n===================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        //create switch case according to use needs
        int value, index;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";    //calling inseratfront function
                cin >> value;
                list.insertAtFront(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);                   //calling insert at en function
                break;
            case 3:
                cout << "Enter index: ";                 //calling insert at index function
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtIndex(index, value);
                break;
            case 4:
                list.deleteAtFront();                   //calling delete at front function
                break;
            case 5:
                list.DeleteAtEnd();                 //calling delete at end function
                break;
            case 6:
                cout << "Enter index to delete: ";      //calling delete at index function      
                cin >> index;
                list.deleteAtIndex(index);
                break;
            case 7:
                list.displayData();                  //calling diplay fnction
                break;
            case 0:
                cout << "Exiting program. Thankyou!!!" << endl;        //exiting the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;    
        }
    } while (choice != 0);
    return 0; //return statments
}
//end
