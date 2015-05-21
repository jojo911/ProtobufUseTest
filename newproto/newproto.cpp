// newproto.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "im.hello.pb.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	im::hello t;
	t.set_id(99);
	t.set_str("qqq");
	cout<<t.id()<<endl;
	cout<<t.str()<<endl;
	im::all a;
	a.set_id(100);
	a.set_allocated_t(&t);

	std::string str;
	a.SerializeToString(&str);
	cout<<str<<endl;

	im::all g;
	g.ParseFromString(str);
	cout<<g.id()<<endl;

	const im::hello& pt = g.t();
	cout<<pt.str()<<endl;
	return 0;
}

