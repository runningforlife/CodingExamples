//#include<iostream>
#include<stdio.h>
#include<cstring>
#include<utility>

class String {

public:
	 String(): data(new char[1]) {
		 data[0] = '\0';	 	 
	 }

	 String(const char* str): data(new char[strlen(str) + 1]) {
		 if (str != nullptr) {
			 strncpy(data, str, strlen(str));
			 data[strlen(str)] = '\0';
		 }
	 }

	 String(const String& str): data(new char[str.size() + 1]) {
		 strncpy(data, str.c_str(), str.size());
		 data[str.size()] = '\0';
	 }

	 String(String &&str): data(str.data) {
		 str.data = nullptr;
	 }

	 String& operator=(String &rhs) {
		 swap(rhs);
		 return *this;
	 }

	 String& operator=(String&& rhs) {
		 data = rhs.data;
		 rhs.data = nullptr;

		 return *this;
	 }

	 ~String() {
		 delete[] data;
	 }

	 size_t size() const {
		 return strlen(data);
	 }

     char* c_str() const {
		 return data;
	 }

	 void swap(String &rhs) {
		 std::swap(data, rhs.data);
	 }

private:
	char* data;
};

String fcn() {
	String s("hi, move");
	...
	return s;
}

int main(void) {
	String str = "hi, buddy!!!";
	String str1 = "you'll shine";
	String str2("give it a try");

	printf("str: %s\n", str.c_str());
	printf("str1: %s\n", str1.c_str());
	printf("str2: %s\n", str2.c_str());

	String str3(str2);

	String str4 = str2;
	String str5 = std::move(str1);

	printf("str3: %s\n", str3.c_str());
	printf("str4: %s, str2:%s\n", str4.c_str(), str2.c_str());
	printf("str5: %s, str1:%s\n", str5.c_str(), str1.c_str());
}
