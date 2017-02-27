#include<iostream>

using namespace std;

struct node
{
	int val;
	node *link;
};

node *insertBeg (node *start, int value)
{
	node *newnode = new node();
	newnode ->val=value;
	newnode ->link= start;
}
void traverse (node *start)
{
	
	while(start!=NULL)
	{
	cout<<start->val;
	start=start->link;
	}
}

void add(node *start1, node *start2)
{
	node *as=NULL;
	int val1=0,val2=0,sum=0,carry=0;
	while((start1!=NULL) && (start2!=NULL))
	{
		val1 = start1->val;
		val2 =start2->val;
		
		sum = (val1 + val2 + carry)% 10;
	
		as = insertBeg(as,sum);
		carry =(val1 + val2 + carry)/ 10;
		start1=start1->link;
		start2=start2->link;
		
	}

		while(start1 !=NULL)
		{

			val1 = start1->val;
			sum = (val1 + carry)%10;
			as= insertBeg(as,sum);
			carry = (val1 + carry)/10;
			start1 = start1->link;
		}

		while(start2 !=NULL)
		{
			val2 = start2->val;
			sum = (val2 + carry)%10;
			as= insertBeg(as,sum);
			carry = (val2 + carry)/10;
			start2 = start2->link;
		}

	if(carry!=0)
	{
		as= insertBeg(as,carry);
	}
	cout<<"\nSum is :";
	traverse(as);
}


int main()
{
	node *start1=NULL, *start2 =NULL;
	int number;
	char ch = 'y';
	
	while(ch=='y'||ch=='Y')
	{
		
		cout<<"Enter a digit to your first number: ";
		cin>>number;
		cout<<"\nEnter y or Y to enter more digits in the number: ";
		cin>>ch;
		start1= insertBeg(start1,number);
	}
	ch ='y';
	
		while(ch=='y'||ch=='Y')
	{
		
		cout<<"Enter a digit to your second number: ";
		cin>>number;
		cout<<"\nEnter y or Y to enter more digits in the number: ";
		cin>>ch;
		start2= insertBeg(start2,number);
	}
	
	
	add(start1,start2);
}
