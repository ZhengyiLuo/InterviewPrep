//#include<iostream>
//#include<math.h>
//
//using namespace std;
//
//struct Student{
//	int num;
//	float score;
//	Student *next;
//
//};
//
//Student *creat();
//void print(Student *head);
//int count(Student *head);
//Student *find(Student *head, int x);
//Student *insert(Student *head, Student *stud);
//Student *delete_node(Student *head, int num);
//
//int main(){
//	int number,x,i;
//	Student *p,*q,*head;
//	/*head = NULL;
//	while (1){
//		cout << "insert??  (yes--1/no--0):";
//		cin >> i;
//		if (i == 0) break;
//		p = new Student;
//		cout << "please type in score and num" << endl;
//		cin >> p->num;
//		cin >> p->score;
//		head = insert(head, p);
//
//	}
//	print(head);*/
//
//	p = creat();
//	print(p);
//	cout << "please typein the num you wanna delete" << endl;
//	cin >> number;
//	p = delete_node(p, number);
//	print(p);
//	/*number = count(p);
//	cout << "The number of students are " << number << endl;
//	cout << "please type in the number you wanna find" << endl;
//	cin >> x;
//	q = find(p, x);
//	cout << q->num << "    " << q->score << endl;*/
//	system("pause");
//	return 0;
//}
//
//Student *creat(){
//	Student *p1, *p2, *head;
//	head = NULL;
//	p1 = new Student;
//	p2 = p1;
//	cout << "Pleas type in the number" << endl;
//	cin >> p1->num;
//	cout << "Pleas type in the score" << endl;
//	cin >> p1->score;
//	while (p1->num != -1){
//		if (head == NULL)
//			head = p1;
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = new Student;
//		cout << "Pleas type in the number" << endl;
//		cin >> p1->num;
//		cout << "Pleas type in the score" << endl;
//		cin >> p1->score;
//	}
//	cout << "the end of entry" << endl;
//
//	p2->next = NULL;
//	delete p1;
//	return head;
//}
//
//
//void print(Student *head){
//	Student *p;
//	p = head;
//	cout << "num" << "    " << "score"<<endl;
//	while (p != NULL){
//
//		
//		cout << p->num << "    ";
//		cout << p->score << endl;
//		p = p->next;
//	}
//
//
//
//}
//
//int count(Student *head){
//	Student *p;
//	int i;
//	p = head;
//	i = 0;
//	while (p != NULL){
//		i++;
//		p = p->next;
//		
//	}
//	
//	return i;
//
//
//
//}
//
//Student *find(Student *head, int x){
//	Student *p;
//	p = head;
//	while (p != NULL){
//		if (p->num == x){
//			return p;
//		}
//		else
//			p = p->next;
//	}
//		return NULL;
//	
//
//}
//
//Student *insert(Student *head, Student *stud){
//	Student *p;
//	p = head;
//	if (p == NULL){
//		head = stud;
//		stud->next = NULL;
//		return head;
//	}
//	if (p->num > stud->num){
//		stud->next = head;
//		head = stud;
//		return head;
//	}
//	while (p->next && p->next->num < stud->num)
//		p = p->next;
//	stud->next = p->next;
//	p->next = stud;
//	return head;
//}
//
//Student *delete_node(Student *head, int num){
//	Student *p, *q;
//	if (head == NULL){
//		cout << "List is NULL" << endl;
//		return head;
//	}
//	if (head->num == num){
//		p = head;
//		head = head->next;
//		delete p;
//		return head;
//	}
//	for (q = head; q->next; q=q->next)
//		if (q->next->num == num){
//			p = q->next;
//			q->next = p->next;
//			delete p;
//			return head;
//		}
//
//	cout << num << "not in the form" << endl;
//	return head;
//
//
//
//
//
//}