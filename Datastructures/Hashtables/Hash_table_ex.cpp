#include<iostream>
#include<list>

using namespace std;
//Allocate memory for ht.
class HashTable{
	private:
		static const int Table_size=10;
		//create a hash table list of To handle collisions using separate chaining:
		list<pair<int,string>> table[Table_size];

		int hashkey(int key)
		{
			return key%Table_size;
		}
	public:
             void insert(int key , string value)
	     {
	       int index = hashkey(key);
               table[index].push_back({key,value});
	     }
	     void display()
	     {
		for(int i=0;i<Table_size;i++)
		{
		 cout<<i<<"--->"<<endl;
		 for(auto &pair:table[i])
			 cout<<"["<<pair.first<<","<<pair.second<<"]"<<endl;
		}
	     }
};	     

int main()
{
	HashTable ht;
	ht.insert(1,"Apple");
	ht.insert(2,"Mango");
	ht.insert(12,"pomo");
	ht.display();
	return 0;
}

