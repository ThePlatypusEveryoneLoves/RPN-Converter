#include <iterator>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>
#include <exception>
#include <iostream>
#include <initializer_list>

template <typename T>
bool inline is_in(const T& v, std::initializer_list<T> lst)
{
    return std::find(std::begin(lst), std::end(lst), v) != std::end(lst);
}



enum class Ops : char {Add = 50, Subtract = 50, Mulitply = 75, Divide = 75, Exponent = 100};
	



std::unordered_map<char, Ops> OperatorMap{
	{'+', Ops::Add},
	{'-', Ops::Subtract},
	{'*', Ops::Mulitply},
	{'/', Ops::Divide},
	{'^', Ops::Exponent}
};


std::string ConvertToRpn(std::string input){
	std::string EndResult;
	std::vector<double> numbers;
	std::vector<char> Operations;
	while(input.length()){
		std::cout<<input<<"\n"<<EndResult<<"\n";
		char cur_char = input.at(0);
		if(std::isdigit(cur_char)){
			try{
				size_t pos{};
				EndResult.append(std::to_string(std::stod(input,&pos)) + " ");
				input = input.substr(pos);
			} catch(std::out_of_range& ex){
				//TODO: Write error handling
				std::cerr<<"Error happened while turing into number";
			} 
		} else if (is_in(cur_char, {'*','+','-','/'})) {
		//	std::cout<<cur_char<<"\n";
			if (Operations.size()&&static_cast<int>(OperatorMap.at(Operations.back()))>static_cast<int>(OperatorMap.at(cur_char))) {
				char Op = Operations.back();
				Operations.pop_back();
				Operations.push_back(cur_char);
				EndResult.append(1,Op);
				std::cout<<input<<"\n";
				input.erase(0,1);
				std::cout<<input<<"\n";
			} else {
				Operations.push_back(cur_char);
				input.erase(0,1);	
			}
		} else if (std::isspace(cur_char)) {
				std::cout<<"space";
				input.erase(0,1);	
		} else {
			throw std::invalid_argument(""); //TODO: write error message
		}
	}
	EndResult.append(Operations.begin(),Operations.end());
	return EndResult;
}

int main(){
	std::cout<<"Im here\n";
	std::cout<<ConvertToRpn("3 + 4 * 2");
//	std::cout<<isdigit('3');
}
