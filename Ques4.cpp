#include<iostream>
#include<cstring>
using namespace std;

void concat(){
	char str1[100];
	char str2[100];
	
	cout << "enter the first string: ";
	cin >> str1;
	cout << "enter the second string: ";
	cin >> str2;
	
	strcat(str1, str2);
	cout << "Concatenated string : "<< str1 << endl;
}

void reverse(){
	char str[100];
	cout << "enter the string : ";
	cin >> str;
	
	strrev(str);
	cout << "Reverse of string : "<< str << endl;
}

void deleteVowels(){
	char str[100];
	cout << "enter the string : ";
	cin >> str;
	char result[100];
	int k=0;
	
	for(int j=0; j<strlen(str); j++){
		if(str[j] != 'a'&& str[j] != 'e'&& str[j] != 'i'&& str[j] != 'o'&& str[j] != 'u'){
			result[k] = str[j];
			k++;
		}
	}
	result[k] = '\0';
	if(k>0)
	cout << "String without vowels : " << result << endl;
	else cout << "String is empty when vowels are removed." <<endl;
}

void sortString(){
	char str[100];
	cout << "enter the string : ";
	cin >> str;
	int n = strlen(str);
	
	for(int i=0; i<n; i++){
		bool flag = false;
		for(int j=0; j<n-i-1; j++){
			if(str[j] > str[j+1]){
				char temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	
	cout << "Sorted string : "<< str;
}

void upperCase(){
	char ch;
	cout << "enter the string : ";
	cin >> ch;
	if(ch >='A' && ch <='Z'){
		ch = ch+32;
		cout << ch << endl;
	} else{
		cout << "alreagu in uppercase." << endl;
	
}

int main(){
	concat();
	reverse();
	deleteVowels();
	sortString();
	upperCase();
	return 0;
}


