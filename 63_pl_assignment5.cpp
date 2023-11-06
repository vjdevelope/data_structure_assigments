// Name: Jadhav vaibhav Satish
//  R0ll No:63 
//   PRN:202201040027
// batch:A(A-4)

# include <iostream>
# include <string>
using namespace std;
class node{
	public: 
		node *next;
		int ch;
	    int id;
	    string name;
	    string size;
	    float price;
	    int quantity;
		node(){
			next=NULL;
		}
};
class pizza{
	private: 
		node *head;
	public:
		pizza(){
			head = NULL;
		}	
	void create();
	void display();
	void Delete();
	void search();
};
void pizza::create(){
	int ch;
	do{
		node *temp=new (node);
		cout<<"Enter the Id :";
		cin>>temp->id;
		cout<<"Enter the pizza name : ";
		cin>>temp->name;
		cout<<"Enter the pizza size : ";
		cin>>temp->size;
		cout<<"Enter the quantity : ";
		cin>>temp->quantity;
		cout<<"Enter the price : ";
		cin>>temp->price;
		if(head==NULL){
			head=temp;
			head->next=head;
		}
		else{
			node *p=head;
			while(p->next!=head){
				p=p->next;
			}
			p->next=temp;
			temp->next=head;
		}
		cout<<"Enter your choice 1. Insert 2. exit = ";
		cin>>ch;
	}while(ch==1); 
};
void pizza::display(){
	node *p=head;
	if(p==NULL){
		cout<<"List is Empty"<<endl;
	}
	do{
		cout<<p->id<<" "<<p->name<<" "<<p->size<<" "<<p->quantity<<" "<<p->price<<" ->";
		p = p->next; 
	}while(p!= head);
}
void pizza::search() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    node *temp = head;
    int no;
    bool flag = false;

    cout << "Enter the id you want to search: ";
    cin >> no;

    do {
        if (temp->id == no) {
            cout << "ID found" << endl;
            flag = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!flag) {
        cout << "ID is not found" << endl;
    }
}

void pizza::Delete(){
	node *temp=head;
	int ch;
	cout<<"Enter the Status 1.Complete 2.Incomplete = ";
	cin>>ch;
	if(ch==1){
	if(head==NULL){
		cout<<"\n List is empty";
	}
	if(head->next==head){
		delete temp;
		head=NULL;
	}
	else{
		node *p=head;
		while(p->next!=head){
			p=p->next;
		}
		p->next=head->next;
		head=head->next;
		delete temp;
	}
	}
	else if(ch==2){
		cout<<"Complete the order"<<endl;
		node *p=head;
		while(p->next!=head){
			p=p->next;
		}
	}
	else{
		cout<<"\n Invaild choice"<<endl;
	}	
}
int main(){
	pizza p1;
	p1.create();
	p1.display();
	p1.search();
	p1.Delete();
	p1.display();
}
