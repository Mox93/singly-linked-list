#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;	
};
class List
{
		private:
		node *head, *tail;
		public:
		List()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		void insert_start(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, int value)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;	
			temp->next=cur;
		}
		void delete_first()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last()
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;	
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
			delete current;
		}
		int element_position(int aData)
		{
			node *temp = new node;
			int pos = 1;

			temp = head;
			while(temp != NULL){
				if(temp->data == aData){
					return pos;
				}
				temp = temp->next;
				pos++;
			}
			return 0;
		}
		void delete_element(int aData)
		{

			int pos = element_position(aData);
			if(pos == 1){
				delete_first();
			}else{
				delete_position(pos);
			}
		}
		void sort(node *anker = new node){
			node *temp = new node;
			node *checked = new node;
			if(anker == NULL){
				anker = head;
			}
			if(anker != NULL){
				temp = anker;
				while(temp->next != NULL){
					checked = temp->next;
					if(checked->data < anker->data){
						temp->next = checked->next;
						checked->next = head;
						head = checked;
					}
					temp = temp->next;
				}
				if(anker == head){
					sort(anker->next);
				}else{
					sort(NULL);
				}
			}
		}
};
int main()
{
	List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"------------------Deleting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Element Position-----------------";
	cout<<"\n--------------------------------------------------\n";	
	int ele = 90;
	cout << ele << " -> " << obj.element_position(ele);
	cout<<"\n--------------------------------------------------\n";
	cout<<"------------------Delete Element------------------";
	cout<<"\n--------------------------------------------------\n";	
	obj.delete_element(ele);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------------Sort-----------------------";
	cout<<"\n--------------------------------------------------\n";	
	obj.sort(NULL);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	system("pause");
	return 0;
}
