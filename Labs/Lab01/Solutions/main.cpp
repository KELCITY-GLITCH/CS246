#include <iostream>  //cout 
#include <string>    //string 
#include <cctype>    //isupper(), islower(), isdigit()

class Password
{
	private:
	std::string value;
	bool view;

	public:
	//Default Constructor
	Password() : value("12345678"), view(false) {}
	//Copy Constructor
	Password(const Password& obj)
	{
		value = obj.value;
		view = obj.view;
	}
	//Assignment Operator
	Password& operator=(const Password& rhs)
	{
		if(this != &rhs)
		{
			value = rhs.value;
			view = rhs.view;
		}
		return *this;
	}
	//Destructor
	~Password() {std::cout << value << "\n";}
	
	void set(std::string str)
	{
		int cnts[3] = {0,0,0}, sm = 0;

		for(char ch : str)
		{
			if(isupper(ch)) {cnts[0] += 1;}
			else if(islower(ch)) {cnts[1] += 1;}
			else if(isdigit(ch)) {cnts[2] += 1;}
			else {return;}
		}

		for(int i = 0;i < 3;i += 1) 
		{
			if(cnts[i] == 0) {return;}
			sm += cnts[i];
		}	

		if(sm >= 8 && sm == str.length()) {value = str;}
	}

	void show(bool v) {view = v;}

	bool valid(std::string str) const {return value == str;}

	std::string toString() const 
	{
		if(view) {return value;}
		return std::string(value.length(),'*');
	}

	friend std::ostream& operator<<(std::ostream& out,const Password& obj)
	{
		out << obj.toString();
		return out;
	}
};


int main()
{
	std::string str;
	Password pswd;
	
	pswd.set("Pa33W0rd");

	while(true) 
	{
		std::cout << "Enter password: ";
		std::cin >> str;

		if(pswd.valid(str)) {break;}
		std::cout << "Invalid. Try Again\n";
	}

	pswd.show(true);
	std::cout << pswd << "\n";

	pswd.show(false);
	std::cout << pswd << "\n";

	return 0;
}
