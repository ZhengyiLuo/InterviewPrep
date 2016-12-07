#include<iostream>
#include<math.h>

using namespace std;

struct Form{
	char num;
	Form *next;

};

Form *creat();
Form *invert(Form *head);
Form *delete_node(Form *head, char num);
Form *insert(Form *head, char num, Form *add);
Form *slice(Form *p, Form  *q);
Form *invert_better(Form *head);
void sequence(Form *head);
int count(Form *head);
void print(Form *head);
void find_node();

int main(){
	int number, x, i, insert_number;
	char num, position;
	Form *p, *q, *head;
    
	cout << "please creat creat the list" << endl;
	p = creat();
	
	/*q = creat();
	print(p);
	print(q);
	p = slice(p, q);
	cout << endl;
	cout << endl;
	cout << endl;
	print(p);*/
	//easy slice up

	/*cout << "please enter the num of nodes you wyanna add" << endl;
	cin >> insert_number;

	Form *add ;
	for (i = 0; i < insert_number; i++)
	{
		cout << "plase enter the num you wanna add" << endl;
		add = new Form;
	}
	
	cin >> add->num;
	cout << "please enter the position you wanna to add" << endl;
	cin >> position;
	p = insert(p, position, add);
	print(p);*/
	//insert to certain position

	/*cout << "please enter the num that you want to delete" << endl;
	cin >> num;
		p = delete_node(p, num);
		print(p);*/
	//delete certain node

	/*print(p);
	p = invert(p);
	cout << endl;
	cout << endl;
	cout << endl;
	print(p);*/
	//bad invert method

	/*print(p);
	p = invert_better(p);
	cout << endl;
	cout << endl;
	cout << endl;
	print(p);*/
	//better invert mthod

	/*print(p);
	cout << endl;
	cout << endl;
	sequence(p);
	print(p);*/
	//test sequence

	/*sequence(p);
	print(p);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "please creat creat the second list" << endl;
	q = creat();
	sequence(q);
	print(q);
	cout << endl;
	cout << endl;
	cout << endl;
	p = slice(p, q);
	print(p);*/
	//better slice up two form


	system("pause");
	return 0;
}

Form *creat(){
	Form *p1, *p2, *head;
	head = NULL;
	p1 = new Form;
	p2 = p1;
	cout << "Pleas type in the number" << endl;
	cin >> p1->num;
	while (p1->num != '0'){
		if (head == NULL)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = new Form;
		cout << "Pleas type in the number" << endl;
		cin >> p1->num;
	}
	cout << "the end of entry" << endl;
	p2->next = NULL;
	delete p1;
	return head;
}

void print(Form *head){
	Form *p;
	p = head;
	cout << "num" << endl;
	while (p != NULL){
		cout << p->num << endl;
		p = p->next;
	}



}

int count(Form *head){
	Form *p;
	int i = 0;
	p = head;
	while (p->next){
		i++;
		p = p->next;
	}
	return i+1;
}

Form *invert(Form *head){
	Form *p, *q, *store_head;
	p = head;
	store_head = head;
	while (p->next != NULL){
		p = p->next;
	}
	head = p;
	q = p;
//	cout << p->num << "   " << q->num << endl;
	while (1){

		p = store_head;
		while (p->next != q){
			p = p->next;
		}
		q->next = p;
		q = p;
		if (p == store_head)
		{
			p->next = NULL;
			break;
		}		

	}

	return head;


}

Form *delete_node(Form *head, char num){
	Form *p, *q;
	if (head == NULL){
		cout << "List is NULL" << endl;
		return head;
	}
	if (head->num == num){
		p = head;
		head = head->next;
		delete p;
		return head;
	}
	for (q = head; q->next; q = q->next){
		if (q->next->num == num){
			p = q->next;
			q->next = p->next;
			delete p;
			return head;
		}

	}
	
	cout << "Num is not in the list" << endl;
	return head;

}

Form *insert(Form *head, char num, Form *add){
	Form *p, *q;
	for (p = head; p->next ; p = p->next){
		if (p->num == num)
		{
			q = p->next;
			p->next = add;
			add->next = q;
			return head;
		}
		 
	}
	cout << "the num is not right" << endl;
	return head;


}

Form *invert_better(Form *head){
	Form *p1, *p2, *p3;
	if (head->next == NULL ){
		return head;

	}

	if (head->next->next == NULL){
		p1 = head;
		p1->next->next = p1;
		p2 = p1->next;
		p1->next = NULL;
		return p2;
			

	}
	p1 = head;
	p2 = head->next;
	p3 = head->next->next;
	p1->next = NULL;

	while (p3->next != NULL){
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}

	p2->next = p1;
	p3->next = p2;
	head = p3;
	return head;

}

void sequence(Form *head){
	Form *p;
	int i, num, j;
	char temp;
	p = head;

	num = count(head);
	for (i = 0; i<num - 1; i++){
		p = head;
		for (j = 0; j < num - i - 1; j++, p = p->next){
			if (p == NULL)
				break;
			if ( p->next != NULL && p->num > p->next->num){
			temp = p->num;
			p->num = p->next->num;
			p->next->num = temp;
		}
		
	}
	}

}

Form *slice(Form *p, Form  *q){
	Form *p1, *p2, *temp, *store;
	p1 = p; 
	p2 = q;
	
	if (p1->num > p2->num){
		while (p1->num > p2->num){
			temp = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = temp;
			if (p2 == NULL)
				break;
		}

	}

	p = p1;
	temp = NULL;
	while (p2!=NULL && p2!= NULL){
		for ( ; p1->next !=NULL && p1->next->num < p2->num;p1 = p1->next) {
		}
		store = p2->next;
		temp = p1->next;
		p1->next = p2;
		p2->next = temp;
		p2 = store;
	}
	return p;

}
