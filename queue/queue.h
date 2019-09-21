
template<typename T>
class Queue{

	T *arr;
	int f;
	int r;
	int cs;
	int ms;

public:
	Queue(int ds=5){
		ms = ds;
		arr = new T[ms];
		cs = 0;
		f = 0;
		r = ms - 1;
	}

	void push(T d){
		if(cs==ms){
			return;
		}
		r = (r+1)%ms;
		arr[r] = d;
		cs++;
	}
	void pop(){
		if(cs==0){
			return;
		}
		f = (f+1)%ms;
		cs--;
	}
	bool empty(){
		return cs==0;
	}
	bool full(){
		return cs==ms;
	}
	T front(){
		return arr[f];
	}
};