//
//C++ ��һ������������������ʵ��һ�� String �࣬����ʱ�䣬������Ҫ��߱� std::string �Ĺ��ܣ�������Ҫ������ȷ������Դ��������˵��
// 
// ���� int ���������������������֧�ָ�ֵ�����ơ�
// �����������Ĳ������ͼ��������͡�
// ��������׼��������Ԫ�����ͣ��� vector/list/deque �� value_type�������� std::map �� key_type �Ǹ���һ����Ҫ�󣬱��Ĵ��ԣ���
// 
// ����֮����� String �������´����������ͨ��������û���ڴ淽��Ĵ���
// 
// [cpp] view plaincopy
// 
// void foo(String x)  
// {  
// }  
// 
// void bar(const String& x)  
// {  
// }  
// 
// String baz()  
// {  
// 	String ret("world");  
// 	return ret;  
// }  
// 
// int main()  
// {  
// 	String s0;  
// 	String s1("hello");  
// 	String s2(s0);  
// 	String s3 = s1;  
// 	s2 = s1;  
// 	
// 	foo(s1);  
// 	bar(s1);  
// 	foo("temporary");  
// 	bar("temporary");  
// 	String s4 = baz();  
// 	
// 	std::vector<String> svec;  
// 	svec.push_back(s0);  
// 	svec.push_back(s1);  
// 	svec.push_back(baz());  
// 	svec.push_back("good job");  
//     }  
class String{
public:
	String();
	String& operator= (const String& lvalue);
		
};