#include <iostream>

using namespace std;

template<typename E>

class Entity{
	private:
		Entity *subscriber;
		bool has_subscriber;
		E value;
	
	public:
		Entity(){
			has_subscriber = false;
		}
		void subscribe_to(Entity *ent){
			ent->subscriber = this;
			ent->has_subscriber = true;
		}
		void unsubscribe_to(Entity *ent){
			ent->subscriber = 0;
			ent->has_subscriber = false;
		}
		void set_value(E val){
			value = val;
			if(has_subscriber && val != subscriber->get_value()){
				subscriber->set_value(val);
			}
		}
		E get_value(){
			return value;
		}
};

int main(){
	cout<<"Hello world!"<<endl;
	
	Entity<int> e1;
	e1.set_value(1);
	
	Entity<int> e2;
	e2.set_value(2);
	
	cout<<"e1: "<<e1.get_value()<<" e2: "<<e2.get_value()<<endl;
	
	e2.subscribe_to(&e1);
	cout<<"e2 subscribes to e1"<<endl;
	
	e2.set_value(4);
	cout<<"e1: "<<e1.get_value()<<" e2: "<<e2.get_value()<<endl;
	
	e1.set_value(3);
	cout<<"e1: "<<e1.get_value()<<" e2: "<<e2.get_value()<<endl;
	
	return 0;
}
