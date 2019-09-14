#include<iostream>
using namespace std;

class Car{
private:
	int price;
public:
	string model;
	char *number_plate;
	//Default Constructor
	Car(){
		number_plate = NULL;
	}
	//Params Constructors
	Car(string m,int p){
		model = m;
		price =p;
		number_plate = new char[5];
		strcpy(number_plate,"ABC1");
	}
	//Copy Constructor
	
	Car(Car &x){
		//cout<<"Overwritten Copy Constructor";
		model = x.model;
		price = x.price;
		//Deep Copy
		number_plate = new char[strlen(x.number_plate)+1];
		strcpy(number_plate,x.number_plate);
	}
	
	//Copy Assignment Operator(Operator Loading)
	void operator=(const Car &x){
		//cout<<"In copy asssingment operator";
		model = x.model;
		price = x.price;
	}
	void operator!() const{
		cout<<model<<" isn't available";
	}
	void operator[](string driver) const{
		cout<<driver<<" is driving "<<model;
	}

	void update(const string m_name,const int p){
		model = m_name;
		price = p;
	}
	//Getters & Setters 
	int getPrice() const{
		return price;
	}
	int setPrice(int p){
		if(p>0){
			price = p;
		}
	}

	void print() const{
		cout<<"Car Model "<<model<<endl;
		cout<<"Car Price "<<price<<endl;
	}
	~Car(){
		cout<<"Destroying a car!"<<model<<endl;
		delete [] number_plate;
	}

};

ostream& operator<<(ostream& o,Car &x){
	o<<x.model;
	o<<x.getPrice();
	o<<endl;
	return o;
}
istream& operator>>(istream& i, Car &x){
	string m;
	int p;
	cin>>m>>p;
	x.update(m,p);
	return i;
}

int fun(){
	int x;
	x = 5;
	return x;
}

//Function Overloading
//Constructor Overloading

/*
//Class has these 4 member functions by default
	- Constructor
	- Copy Constructor
	- Copy Assignment Operator
	- Destructor
*/

int main(){

	Car c1("Audi",100);
	Car c2(c1);

	/*
	//	!c1;
	//	c1["Raju"];
	//Car c3(c1);
	Car c3 =  c1; 
	Car c4; //-->Default Constructor
	c4 = c3; //--> Copy Assignment Operator (Hidden)
	//cin>>c1>>c2;
	cout<<c1<<c2<<c3; //Cascading of Operators
	*/

	c2.number_plate[3] = '2';
	cout<<c1.number_plate<<endl;
	cout<<c2.number_plate<<endl;
	return 0;
}
