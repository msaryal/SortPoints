#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int m = 1; int n = 1;
int getInt(){
	int x;
	while((scanf("%d", &x) != 1) || (getchar() != '\n')){
		while(getchar() != '\n')
			continue;
		std::cout << "Not a number..." << std::endl;
	}

	return x;
}

struct Numbers{
	int x;
	int y;
	int id;
	Numbers* next;
	Numbers* prev;
};

class List{
private:
	Numbers *head;
	Numbers *tail;
public:
	List();
	~List();
	void print();
	void add(int x, int y, int id);
	void sort();
	void sort2();
	void sort3();
	void sort4();
};

List::List(){
	head = 0;
	tail = 0;
}

List::~List(){
	while(head){
		tail = head->next;
		delete head;
		head = tail;
	}
}

void List::add(int x, int y, int id){
	Numbers * tmp = new Numbers;
	tmp->next = NULL;
	tmp->x = x;
	tmp->y = y;
	tmp->id = id;

	if(head != NULL){
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}else{
		tmp->prev = NULL;
		head = tmp;
		tail = tmp;
	}
}

void List::print(){
	Numbers *tmp = tail;
	std::cout << std::endl;
	tmp = head;
	while(tmp != NULL){
		std::cout << "[" << tmp->id << "]: ";
		std::cout << "x = " << tmp->x << ", " << "y = " << tmp->y << std::endl;
		tmp = tmp->next;
	}

	std::cout << std::endl;
}

void List::sort(){
	Numbers * list = head;
	Numbers * node, * node2;
	for(node = list; node; node = node->next){
		for(node2 = list; node2; node2 = node2->next){
			if(node->x > node2->x){
				int x = node->x;
				node->x = node2->x;
				node2->x = x;

				int y = node->y;
				node->y = node2->y;
				node2->y = y;

				int id = node->id;
				node->id = node2->id;
				node2->id = id;
			}
		}
	}

	std::cout << std::endl;
}

void List::sort2(){
	Numbers *list = head; 
    Numbers *node, *node2;
 
	for(node = list; node; node = node->next){
		for(node2 = list; node2; node2 = node2->next){
			if(node->y > node2->y){
				int y = node->y;
				node->y = node2->y;
				node2->y = y;

				int x = node->x;
				node->x = node2->x;
				node2->x = x;

				int id = node->id;
				node->id = node2->id;
				node2->id = id;
			}
		}
	}
}

void List::sort3(){
	Numbers * list = head;
	Numbers * node, * node2;

	for(node = list; node; node = node->next){
		for(node2 = list; node2; node2 = node2->next){
			if(node->x < node2->x){
				int x= node->x;
				node->x = node2->x;
				node2->x = x;

				int y = node->y;
				node->y = node2->y;
				node2->y = y;

				int id = node->id;
				node->id = node2->id;
				node2->id = id;
			}
		}
	}

	std::cout << std::endl;
}

void List::sort4(){
	Numbers * list = head;
	Numbers * node, * node2;

	for(node = list; node; node = node->next){
		for(node2 = list; node2; node2 = node2->next){
			if(node->y < node2->y){
				int y = node->y;
				node->y = node2->y;
				node2->y = y;

				int x = node->x;
				node->x = node2->x;
				node2->x = x;

				int id = node->id;
				node->id = node2->id;
				node2->id = id;
			}
		}
	}

	std::cout << std::endl;
}

int main(){
	int id = 0;
	int d = 0;
	List(list);

	while(n != 0 || m != 0){
		d += 1;
		std::cout << "[" << d << "] x = ";
		n = getInt();
		std::cout << "[" << d << "] y = ";
		m = getInt();

		if(n != 0 || m != 0){
			id += 1;
			list.add(n, m, id);
		}
	}

	std::cout << "List: " << std::endl;
	list.print();


	char button;
	std::cout << "Tap 1 to open sorting menu: ";
	std::cin >> button;
	button -= 48;
	while(button != 1){
		std::cout << "Error...\n";
		std::cin >> button;
		button -= 48;
	}

	while(button == 1){
		int sort = 0;
		std::cout << "1) Sort by first elem" << std::endl;
		std::cout << "2) Sort by second elem" << std::endl;
		std::cout << "3) Sort asceding" << std::endl;
		std::cout << "4) Sort descendingly" << std::endl;

		sort = getInt();
		switch(sort){
			case 1:
				list.sort();
				list.print();
				break;

			case 2:
				list.sort2();
				list.print();
				break;

			case 3:
				list.sort3();
				list.print();
				break;

			case 4:
				list.sort4();
				list.print();
				break;
		}

		std::cout << "Tap 1 to sort " << std::endl;
		std::cin >> button;
		button -= 48;
	}
}
