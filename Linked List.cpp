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
		int length = 0;
		List()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int value)
		{
			length++;
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
			length++;
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, int value)
		{
			length++;
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
			length--;
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
			length--;
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
			length--;
		}
		bool in_list(int aData)
		{
			node *temp = new node;
			while(temp != NULL){
				if(temp->data == aData){
					return true;
				}
				temp = temp->next;
			}
			return false;
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
			if(pos != 0){
				if(pos == 1){
					delete_first();
				}else{
					delete_position(pos);
				}
			}
		}
		node *get_address(int pos)
		{
			node *address = new node;

			address = head;

			for (int i = 1; i < pos; ++i)
			{
				address = address->next;
			}

			return address;
		}
		List sublist_position(int posH, int posT)
		{
			node *tempH = new node;
			node *tempT = new node;

			tempH = get_address(posH);
			tempT = get_address(posT);

		return sublist(tempH, tempT);
		}
		List sublist(node *h = new node, node *t = new node)
		{
			if(h == NULL){
				h = head;
			}
			if(t == NULL){
				t = tail;
			}
			List newList;
			node *temp = new node;

			temp = h;
			while(temp != t->next){
				newList.createnode(temp->data);
				temp = temp->next;
			}
			
			return newList;
		}
		void sort()
		{
			if(head == NULL || head->next == NULL){
				return;
			}
			List a;
			List b;

			int mid = length / 2;
			
			a = sublist_position(1, mid);
			a.sort();

			b = sublist_position(mid+1, length);
			b.sort();

			head = merge(a, b).head;
		}
		List merge(List a, List b)
		{	
			List mergedList;
			node *checkA = new node;
			node *checkB = new node;

			checkA = a.head;
			checkB = b.head;

			while(checkA != NULL && checkB != NULL){
				if(checkA->data < checkB->data){
					mergedList.createnode(checkA->data);
					checkA = checkA->next;
				}else{
					mergedList.createnode(checkB->data);
					checkB = checkB->next;
				}
			}
			while(checkA != NULL){
				mergedList.createnode(checkA->data);
				checkA = checkA->next;
			}
			while(checkB != NULL){
				mergedList.createnode(checkB->data);
				checkB = checkB->next;
			}

			return mergedList;
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
	cout<<"---------------------Sub List---------------------";
	cout<<"\n--------------------------------------------------\n";	
	List newObj = obj.sublist_position(3, 5);
	newObj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------------Sort-----------------------";
	cout<<"\n--------------------------------------------------\n";	
	obj.sort();
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
	obj.delete_position(3);
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
	system("pause");
	return 0;
}
