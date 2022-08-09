// use recursion to find each arguments in “可变参数列表 mutable arguments list"

// 递归终止函数
template <class T>
void ShowList(const T& t)
{
	cout << t << endl << endl;
}


// 解析并打印参数包中每个参数的类型及值
template <class T, class ...Args>
void ShowList(T val, Args... args)
{
	cout << typeid(val).name() << ":" << val << endl;
	ShowList(args...);
}


// use array to find each arguments in “可变参数列表 mutable arguments list"

template <class T>
void PrintArg(T val)
{
	T copy(val);
	cout << typeid(T).name() << ":" << val << endl;
}

//展开函数
template <class ...Args>
void ShowList(Args... args)
{
	int arr[] = { (PrintArg(args), 0)... };
	cout << endl;
}