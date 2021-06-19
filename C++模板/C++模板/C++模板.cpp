#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
# if 0
int add(int a, int b)
{

}
template<class T>//或者 template<typename T>
T add(T a, T b)
{
	return a + b;
}
int main()
{
	cout << add<int>(1, 'c') << endl;;
	system("pause");
	return 0;
}

template<class T>
T add(T a, T b)
{
	return a + b;

}
template<class P>
P add(P a, P b, P c)
{
	return a + b + c;

}
int main()
{
	cout << add(1, 2, 3) << endl;
	cout << add(1, 2) << endl;
	return 0;
}
#endif
#if 0
template<class T>
T add(const  T& t1, const T& t2)
{
	return t1 + t2;
}
class complex
{
public:
	complex(double real , double image ) :_real(real), _image(image)
	{

	}
	~complex()
	{

	}
	complex operator+(const complex& t1)const
	{
		complex ret(_real + t1._real, _image + t1._image);
		return ret;
	}

private:
	double _real;
	double _image;
	friend  ostream& operator<<(ostream& _cout, const complex& d);
};
ostream& operator<<(ostream& _cout, const complex& d)
{
	_cout << "实部" << d._real << "虚部" << d._image;
	return _cout;
}
int main()
{
	complex t1(0.3, 0.4);
	complex t2(0.4, 0.5);

	complex ret = t1 + t2;
	cout << ret << endl;
	return 0;
}
#endif
#if 0
//之前我们是这么写的
//typedef int datatype;//发现每次需要存储不同对象时，都得对它进行修改，显得很鸡肋，接下来看下面这种
template<class T>
class seqlist
{
public:
	seqlist(int init = 10) :arr(new T[init + 3]), size(0), capacity(init + 3)
	{

	}
	~seqlist()
	{
		if (arr)
		{
			delete[]arr;
		}
	}
	void push(const T& num)
	{
		if (is_full())
		{
			Extend();
			arr[size++] = num;
			
		}
		else
		{
			arr[size++] = num;
		}

	}
	void pop()
	{
		if (is_empty())
			size--;
		else
			return;
	}
	bool is_full()const
	{
		if (size == capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool is_empty()const
	{
		return 0==size;
	}
	
	size_t return_size()const
	{
		return size;
	}
	size_t return_capacity()
	{
		return capacity;
	}
	T operator[](int index)const
	{
		if (index < 0 || index >= size)
		{
			return -1;
		}
		return arr[index];
	}
private:
	 void Extend();
private:
	T* arr;
	size_t size;
	size_t capacity;
};
template<class T>
void seqlist<T>::Extend()
{

		T* arr1 = new T[2 * capacity];
		memcpy(arr1, arr, sizeof(T) * capacity);
		delete[](arr);
		arr = arr1;
		capacity *= 2;
}
int main()
{
	//对于类来说，必须显式实例化，不可以让它去推演
	//seqlist s(0);
	seqlist<int>s(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s[2] << endl;
	//用来看生成的类型的
	cout << typeid(s).name() << endl;
	seqlist<double>s1(0);
	s1.push(1.0);
	s1.push(2.0);
	s1.push(3.0);
	s1.push(4.0);
	s1.push(5.0);
	s1.push(6.1);
	cout << s1[5] << endl;
	cout << typeid(s1).name() << endl;
	return 0;

}
#endif
#if 0
template<class T>
class seqlist
{
public:
	seqlist(int init = 10) :arr(new T[init + 3]), size(0), capacity(init + 3)
	{

	}
	~seqlist()
	{
		if (arr)
		{
			delete[]arr;
		}
	}
	seqlist(T* first, T* last)
	{
		T* t1 = first;
		int count = 0;
		while (t1 != last)
		{
			++t1;
			++count;
		}
		arr = new T[count];
		size = count;
		capacity = count;
		for (int i = 0; i < size; i++)
		{
			arr[i] = *first;
			++first;
		}
	}
	void push(const T& num)
	{
		if (is_full())
		{
			Extend();
			arr[size++] = num;

		}
		else
		{
			arr[size++] = num;
		}

	}
	void pop()
	{
		if (is_empty())
			size--;
		else
			return;
	}
	bool is_full()const
	{
		if (size == capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool is_empty()const
	{
		return 0 == size;
	}

	size_t return_size()const
	{
		return size;
	}
	size_t return_capacity()const
	{
		return capacity;
	}
	const T&operator[](int index)const
	{
		if (index < 0 || index >= size)
		{
			return -1;
		}
		return arr[index];
	}
private:
	void Extend();
private:
	T* arr;
	size_t size;
	size_t capacity;
};
template<class T>
void seqlist<T>::Extend()
{

	T* arr1 = new T[2 * capacity];
	memcpy(arr1, arr, sizeof(T) * capacity);
	delete[](arr);
	arr = arr1;
	capacity *= 2;
}
int main()
{
	////对于类来说，必须显式实例化，不可以让它去推演
	////seqlist s(0);
	//seqlist<int>s(0);
	//s.push(1);
	//s.push(2);
	//s.push(3);
	//s.push(4);
	//s.push(5);
	//cout << s[2] << endl;
	////用来看生成的类型的
	//cout << typeid(s).name() << endl;
	//seqlist<double>s1(0);
	//s1.push(1.0);
	//s1.push(2.0);
	//s1.push(3.0);
	//s1.push(4.0);
	//s1.push(5.0);
	//s1.push(6.1);
	//cout << s1[5] << endl;
	//cout << typeid(s1).name() << endl;
	int arr[6] = { 1,2,3,4,5,6 };
	const seqlist<int>s3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << s3.return_size() << endl;
	cout << s3.return_capacity() << endl;
	cout << s3[4] << endl;
	cout << typeid(s3).name() << endl;
	return 0;

}
#endif
int main()
{
	cout << sizeof(string) << endl;
	return 0;
}