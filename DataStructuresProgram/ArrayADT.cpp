# include<iostream>
# define MAXSIZE 50
using namespace std;
class Array{
	int arr[MAXSIZE];
	public:
	int size=0;
	void add(int h){
		arr[size++]=h;
	}
	void display(){
		for(int i=0;i<size;i++){
			cout<<arr[i]<<"->";
		}
	}
	void insert(int val,int pos){
		for(int i=size-1;i>=pos;i--){
			arr[i+1]=arr[i];
		}
		arr[pos]=val;
		size++;
		//cout<<"Element Added";
	}
	void deletea(int pos){
		for(int i=pos;i<size;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
};
int main()
{
	Array a;
	a.add(40);
	a.add(100);
	a.insert(1000,0);
	a.display();
	a.deletea(1);
	a.display();
}
